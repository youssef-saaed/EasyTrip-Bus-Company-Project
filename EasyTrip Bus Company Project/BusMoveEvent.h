#pragma once

#include "Event.h"
#include "Bus.h"
#include <typeinfo>

class BusMoveEvent : public Event
{
private:
    int From;
    int To;
    int BusID;
public:
    BusMoveEvent(Time EventTime, int From, int To, int BusID);
    void Execute(arrayList<Station*> &StationsList, Queue<Passenger*> &Passengers);    
};