#include "Company.h"
#include <sstream>
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
    std::getline(InputFileHandler, line);
    for (int i = 0; i < NumOfEvents; i++) {
        getline(InputFileHandler, line);
        stringstream ss(line);

        Event* event = nullptr;
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
            ss >> timeStr >> startStation >> passengerID;

            int passengerIDLINT, startStationLINT;
            passengerIDLINT = stoi(passengerIDL);
            int hour, minutes;
            size_t colonPos = timeStr.find(':');
            if (colonPos != string::npos) {
                string hourStr = timeStrL.substr(0, colonPos);
                string minutesStr = timeStrL.substr(colonPos + 1);

                hour = stoi(hourStr);
                minutes = stoi(minutesStr);
            }
            Time timeStampL(hour, minutes);
            event = new LeaveEvent(timeStampL, startStationLINT, passengerIDLINT);
        }

        int priority = 0;
        if (passengerType == "SP" || passengerType == "sp" ) {
            if (specificPassengerType == "aged" || specificPassengerType == "Aged") priority = 4;
            else if (specificPassengerType == "pod" || specificPassengerType == "POD") priority = 3;
            else if (specificPassengerType == "pregnant" || specificPassengerType == "Pregnant")  priority = 2;
        }
        else if (passengerType == "NP" || passengerType == "np")  priority = 1;

        if (event != nullptr) {
            Events.Enqueue(event, priority);
        }
    }   
}


ostream& operator<<(ostream& os, const Time& timeObj) {
    os << timeObj.display();
    return os;
}


void Company::ProduceOutputFile() {
    OutputFileHandler << "FT" << "   " << "ID" << "     " << "AT" << "      " << "WT" << "      " << "TT";

    int totalNP, totalSP, totalWP;
    Time totalTT;
    Time totalWT;

    size_t finishedPassengersSize = FinishedPassengers.size();
    for (int i=0; i < finishedPassengersSize; i++) {
        OutputFileHandler << FinishedPassengers.peek()->getFinishTime().display() << FinishedPassengers.peek()->getPassengerID() << FinishedPassengers.peek()->getStationArrivalTime() << FinishedPassengers.peek()->getWaitTime() << FinishedPassengers.peek()->getTripTime();
        if (FinishedPassengers.peek()->getPassengerType() == "NP") totalNP++;
        else if (FinishedPassengers.peek()->getPassengerType() == "WP") totalWP++;
        else totalSP++;

        totalTT = totalTT + FinishedPassengers.peek()->getTripTime();
        totalWT = totalWT + FinishedPassengers.peek()->getWaitTime();

        FinishedPassengers.dequeue();
    }
    Time avgTT = avgTT.CalcAvgTimeOfTrip(totalTT, finishedPassengersSize);
    Time avgWT = avgWT.CalcAvgTimeOfTrip(totalWT, finishedPassengersSize);

    OutputFileHandler << "passengers: " << finishedPassengersSize << "  " << "[NP: "<<totalNP<<", SP: "<<totalSP<<", WP: "<<totalWP<<"]";
    OutputFileHandler << "passenger Avg Wait time= " << avgWT.display();
    OutputFileHandler << "passenger Avg trip time= " << avgTT.display();
    OutputFileHandler << "Auto-promoted passengers: " << "%";
    OutputFileHandler << "buses: " << NumberOfWBuses+NumberOfMBuses << "    " << "[WBus: "<<NumberOfWBuses << ", MBus: "<<NumberOfMBuses << "]";
    OutputFileHandler << "Avg Busy time = " << "%";
    OutputFileHandler << "Avg utilization = " << "%";
}