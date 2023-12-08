#include "BusMoveEvent.h"

BusMoveEvent::BusMoveEvent(Time EventTime, int From, int To, int BusID)
{
    Event('M', EventTime);
    this->From = From;
    this->To = To;
    this->BusID = BusID;
}

void BusMoveEvent::Execute(arrayList<Station*> &Stations, arrayList<Passenger*> &Passengers)
{
    Bus *b;
    for (int i = 0; i < Stations[From].MovingBuses.size(); i++) 
    {
        if (Stations[From].MovingBuses[i]->ID == BusID) {
            b = Stations[From].MovingBuses[i];
            break;
        }
    }
    StationsStations[To].WaitingBuses.Enqueue(b);
}