#include "Company.h"
#include <sstream>
#include <iostream>
using namespace std;

void Company::ReadInputFile() {
    if (!InputFileHandler) {
        cerr << "Failed to open the input file." << endl;
        return;
    }

    InputFileHandler >> NumberOfStation >> TimeBetweenEachStation;
    InputFileHandler >> NumberOfWBuses >> NumberOfMBuses;
    InputFileHandler >> WBusCapacity >> MBusCapacity;
    InputFileHandler >> NumOfTripsBeforeCheckup >> WBusCheckupDur >> MBusCheckupDur;
    InputFileHandler >> MaxNormalPassengerWaiting >> GetOnOffDur;
    InputFileHandler >> NumOfEvents;

    string line;
    PassengersEvents = new Queue<PassengerEvent*>(NumOfEvents);
    std::getline(InputFileHandler, line);
    for (int i = 0; i < NumOfEvents; i++) {
        getline(InputFileHandler, line);
        stringstream ss(line);

        PassengerEvent* event = nullptr;
        char eventType;
        string passengerType, timeStr, passengerID, startStation, endStation, specificPassengerType;
        ss >> eventType;
        if (eventType == 'A') { 
            ss >> passengerType >> timeStr >> passengerID >> startStation >> endStation >> specificPassengerType;

            int hour, minutes;
            size_t colonPos = timeStr.find(':');
            if (colonPos != string::npos) {
                string hourStr = timeStr.substr(0, colonPos);
                string minutesStr = timeStr.substr(colonPos + 1);
                hour = stoi(hourStr);
                minutes = stoi(minutesStr);
            }
            Time timeStamp(hour, minutes);
            int passengerIDINT, startStationINT, endStationINT;
            passengerIDINT = stoi(passengerID);
            startStationINT = stoi(startStation);
            endStationINT = stoi(endStation);

            event = new ArrivalEvent(timeStamp, startStationINT, endStationINT, passengerIDINT, passengerType, specificPassengerType);
        } else if (eventType == 'L') {
            string timeStrL, startStationL, passengerIDL;
            ss >> timeStrL >> passengerIDL >> startStationL;

            int passengerIDLINT, startStationLINT;
            passengerIDLINT = stoi(passengerIDL);
            int hour, minutes;
            size_t colonPos = timeStrL.find(':');
            if (colonPos != string::npos) {
                string hourStr = timeStrL.substr(0, colonPos);
                string minutesStr = timeStrL.substr(colonPos + 1);

                hour = stoi(hourStr);
                minutes = stoi(minutesStr);
            }
            Time timeStampL(hour, minutes);
            startStationLINT = stoi(startStationL);
            event = new LeaveEvent(timeStampL, startStationLINT, passengerIDLINT);
        }


        if (event != nullptr) {
            PassengersEvents->enqueue(event);
        }
    } 
}


ostream& operator<<(ostream& os, Time& timeObj) {
   os << timeObj.display();
   return os;
}


void Company::ProduceOutputFile() {
   OutputFileHandler << "FT" << "   " << "ID" << "     " << "AT" << "      " << "WT" << "      " << "TT\n";

   int totalNP = 0, totalSP = 0, totalWP = 0;
   Time totalTT;
   Time totalWT;

   int finishedPassengersSize = FinishedPassengers->size();
   Passenger* p;
   for (int i=0; i < finishedPassengersSize; i++) {
       FinishedPassengers->peek(p);
       OutputFileHandler << p->getFinishTime().display() << p->getPassengerID() << p->getStationArrivalTime().display() << p->getWaitTime().display() << p->getTripTime().display() << '\n';
       if (p->getPassengerType() == "NP") totalNP++;
       else if (p->getPassengerType() == "WP") totalWP++;
       else totalSP++;

       totalTT = totalTT + p->getTripTime();
       totalWT = totalWT + p->getWaitTime();

       FinishedPassengers->dequeue(p);
   }
   Time avgTT = avgTT.CalcAvgTimeOfTrip(totalTT, finishedPassengersSize);
   Time avgWT = avgWT.CalcAvgTimeOfTrip(totalWT, finishedPassengersSize);

   double npPercentage = 100. * NumberOfPromotedPassengers / totalNP;
   // Utilization
   // Busy Time

   OutputFileHandler << "passengers: " << finishedPassengersSize << "  " << "[NP: "<<totalNP<<", SP: "<<totalSP<<", WP: "<<totalWP<<"]\n";
   OutputFileHandler << "passenger Avg Wait time= " << avgWT.display() << '\n';
   OutputFileHandler << "passenger Avg trip time= " << avgTT.display() << '\n';
   OutputFileHandler << "Auto-promoted passengers: " << npPercentage << "%";
   OutputFileHandler << "buses: " << NumberOfWBuses+NumberOfMBuses << "    " << "[WBus: "<<NumberOfWBuses << ", MBus: "<<NumberOfMBuses << "]\n";
   OutputFileHandler << "Avg Busy time = " << "%\n";
   OutputFileHandler << "Avg utilization = " << "%\n";
}