#include "Company.h"
#include <iostream>

void Company::PassengerBoarding()
{
    for (int i = 1; i <= NumberOfStation; i++)
    {   
        BoardingTime = 0;
        Stations* s = (Stations*)StationsList->LookAt(i);
        s->unloadPassengers(FinishedPassengers, NumberOfStation, GetOnOffDur, BoardingTime);
        s->loadPassengers(BusesEvents, GetOnOffDur, BoardingTime, currentTime, MBusCapacity, WBusCapacity);
    }
}

void Company::initialize() {
    StationsList = new arrayList<Station*>(NumberOfStation + 1);
    StationZero* s0 = new StationZero(NumberOfMBuses, NumberOfWBuses, MBusCapacity, WBusCapacity);
    StationsList->push(s0);
    int maxNumberOfBuses = NumberOfMBuses + NumberOfWBuses;
    for (int i = 0; i < NumberOfStation; i++)
    {
        Station* station;
        station = new Stations(i + 1, maxNumberOfBuses, NumOfEvents);
        StationsList->insert(station, i+1);
    }

    FinishedPassengers = new Queue<Passenger*>(NumOfEvents);
    WBusCheckup = new Queue<Bus*>(NumberOfWBuses);
    MBusCheckup = new Queue<Bus*>(NumberOfMBuses);
    WBusMoving = new Queue<Bus*>(NumberOfWBuses);
    MBusMoving = new Queue<Bus*>(NumberOfMBuses);

    
}

void Company::calcFinishTime(Time busarrivaltime, Passenger* p) {
    Time gettingoffallpassengerstime = 0;
    Queue<Passenger*> *FinishedPassengersCopy = FinishedPassengers;
    bool found = false;

    while (!FinishedPassengersCopy->isEmpty()) {
        Passenger* passenger;
        FinishedPassengersCopy->peek(passenger);
        if (passenger == p) {
            found = true;
            break;
        }
        if (passenger->getBusType() == p->getBusType() && passenger->getBusID() == p->getBusID() && passenger->getEndStation() == p->getEndStation()) {
            gettingoffallpassengerstime = gettingoffallpassengerstime + passenger->getOffBusTime();
        }
        Passenger* p1;
        FinishedPassengersCopy->dequeue(p1);
        //FinishedPassengersCopy->enqueue(passenger);
    }

    if (found) {
        gettingoffallpassengerstime = gettingoffallpassengerstime + p->getOffBusTime();
        Time totalft = gettingoffallpassengerstime + busarrivaltime;
        p->setFinishTime(totalft);
    }
}

void Company::calcTripTime(Time busMoveTime, Passenger* p) {
    Time TT = p->getFinishTime() - busMoveTime;
    p->setTripTime(TT);
}

int Company::calcWT(Time busMoveTime, Time now, int agedPriority, int maxW, Passenger p) {
   if (p.getStatus() == "moved") {
       Time WT = busMoveTime - p.getStationArrivalTime();
       int WTMinutes = (WT.getHour() * 60) + WT.getMinute() + (WT.getSecond() / 60);
       p.setWaitTime(WT);
       return WTMinutes;
   }
   else {
       Time WT = now - p.getStationArrivalTime();
       int WTMinutes = (WT.getHour() * 60) + WT.getMinute() + (WT.getSecond() / 60);
       //if ((WTMinutes >= maxW) && p.getPassengerType() == "NP") p.changePriority(agedPriority);
       p.setWaitTime(WT);
       return WTMinutes;
   }
   return 0;
}
