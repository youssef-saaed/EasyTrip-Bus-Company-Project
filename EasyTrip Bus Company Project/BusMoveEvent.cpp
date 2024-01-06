#include "BusMoveEvent.h"

BusMoveEvent::BusMoveEvent(Time EventTime, int From, int To, int BusID): Event('M', EventTime)
{  
    this->From = From;
    this->To = To;
    this->BusID = BusID;
}

void BusMoveEvent::Execute(arrayList<Station*> &StationsList, Queue<Passenger*> &Passengers)
{
    Bus* b;
    char type;
    if (To == 0)
    {
        if (((Stations*)StationsList.LookAt(From))->PopFromMovedBuses(BusID, type, b))
        {
            ((StationZero*)StationsList.LookAt(0))->addBusToStation(b, type);
        }
    }
    else
    {
        if (((Stations*)StationsList.LookAt(From))->PopFromMovedBuses(BusID, type, b))
        {
            ((Stations*)StationsList.LookAt(To))->addRecentBus(b);
        }
    }
}