#pragma once

#include "Station.h"
#include "StationZero.h"
#include "Bus.h"
#include <typeinfo>

class BusMoveEvent
{
private:
    int From;
    int To;
    int BusID;
    Time EventTime;

public:
    BusMoveEvent(Time EventTime, int From, int To, int BusID, char busType = 'M');
    void Execute(arrayList<Station*>& StationsList, Queue<Passenger*>& Passengers);
    Time getEventTime();
    void setEventTime(Time EventTime);
};