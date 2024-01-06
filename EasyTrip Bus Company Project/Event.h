#pragma once

#include "Time.h"
#include "Station.h"
#include "Stations.h"
#include "StationZero.h"
#include "Passenger.h"
#include "arrayList.h"

class Event
{
protected:
    char Type;
    Time EventTime;   
public:
    Event(char Type, Time EventTime);
    Time getEventTime();
    char getType();
    virtual void Execute(arrayList<Station*> &StationsList, Queue<Passenger*> &FinishedPassengers) = 0;    
};