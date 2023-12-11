#ifndef _EVENT_H_
#define _EVENT_H_

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
    Time getEventTime() const;
    char getType();
    virtual void Execute(arrayList<Station*> &Stations, arrayList<Passenger*> &FinishedPassengers) = 0;    
};

#endif