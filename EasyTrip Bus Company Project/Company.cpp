#include "Company.h"

void Company::initialize() {
    StationsList = new arrayList<Station*>(NumberOfStation);
    int maxNumberOfBuses = NumberOfMBuses + NumberOfWBuses;
    for (int i = 0; i < NumberOfStation; i++)
    {
        Station* station = new Station(i + 1, maxNumberOfBuses);

        StationsList->insert(station, i+1);
    }

    Station0 = new Queue<Bus*>(maxNumberOfBuses);
    int mBusCount = 0;
    int wBusCount = 0;

    for (int i = 0; i < max(NumberOfMBuses, NumberOfWBuses); i++)
    {
        Bus* bus = nullptr;
        if (mBusCount < NumberOfMBuses)
        {
            bus = new MBus(MBusCapacity, 0); 
            Station0->enqueue(bus);
            mBusCount++;
        }

        if (wBusCount < NumberOfWBuses)
        {
            bus = new WBus(WBusCapacity, 0);  
            Station0->enqueue(bus);
            wBusCount++;
        }

        if (mBusCount == NumberOfMBuses && wBusCount < NumberOfWBuses)
        {
            for (; wBusCount < NumberOfWBuses; wBusCount++)
            {
                bus = new WBus(WBusCapacity, 0);  
                Station0->enqueue(bus);
            }
        }
        else if (wBusCount == NumberOfWBuses && mBusCount < NumberOfMBuses)
        {
            for (; mBusCount < NumberOfMBuses; mBusCount++)
            {
                bus = new MBus(MBusCapacity, 0); 
                Station0->enqueue(bus);
            }
        }
    }
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
        if (passenger->getBusType() == p->getBusType() && passenger->getBusID() == p->getBusID()) {
            gettingoffallpassengerstime = gettingoffallpassengerstime + passenger->getOffBusTime();
        }
        FinishedPassengersCopy->dequeue();
        FinishedPassengersCopy->enqueue(passenger);
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
   else if (p.getStatus() == "waiting") {
       Time WT = now - p.getStationArrivalTime();
       int WTMinutes = (WT.getHour() * 60) + WT.getMinute() + (WT.getSecond() / 60);
       if ((WTMinutes >= maxW) && p.getPassengerType() == "NP") p.changePriority(agedPriority);
       p.setWaitTime(WT);
       return WTMinutes;
   }
}
