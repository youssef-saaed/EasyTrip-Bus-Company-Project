#include "BusMoveEvent.h"

BusMoveEvent::BusMoveEvent(Time EventTime, int From, int To, int BusID): Event('M', EventTime)
{  
    this->From = From;
    this->To = To;
    this->BusID = BusID;
}

void BusMoveEvent::Execute(arrayList<Station*> &Stations, Queue<Passenger*> &Passengers)
{

}