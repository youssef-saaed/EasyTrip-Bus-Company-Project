#include "BusMoveEvent.h"

BusMoveEvent::BusMoveEvent(Time EventTime, int From, int To, int BusID, char busType)
{
    this->From = From;
    this->To = To;
    this->BusID = BusID;
    this->EventTime = EventTime;
}

void BusMoveEvent::Execute(arrayList<Station*> &StationsList, Queue<Passenger*> &Passengers, int TripsBeforeCheckup, Time Mbus, Time WBus)
{
    Bus* b;
    char type;
    if (To == 0)
    {
        if ((StationsList.LookAt(From))->PopFromMovedBuses(BusID, type, b))
        {
            b->AddOneTrip();
            if (b->getTripCount() % TripsBeforeCheckup == 0 && typeid(*b).name() == "Mbus")
            {
                ((StationZero*)StationsList.LookAt(0))->AddToCheckup(b, EventTime + Mbus);
            }
            else if (b->getTripCount() % TripsBeforeCheckup == 0 && typeid(*b).name() == "Wbus")
            {
                ((StationZero*)StationsList.LookAt(0))->AddToCheckup(b, EventTime + WBus);
            }
            else
            {
                ((StationZero*)StationsList.LookAt(0))->addBusToStation(b, type);
            }
        }
    }
    else
    {
        if ((StationsList.LookAt(From))->PopFromMovedBuses(BusID, type, b))
        {
            (StationsList.LookAt(To))->addRecentBus(b);
        }
    }
}

Time BusMoveEvent::getEventTime()
{
    return EventTime;
}
void BusMoveEvent::setEventTime(Time EventTime)
{
    this->EventTime = EventTime;
}