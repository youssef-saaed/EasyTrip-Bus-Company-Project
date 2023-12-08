#ifndef _EVENT_H_
#define _EVENT_H_

#include "Time.h"
#include "Station.h"
#include "Passenger.h"
#include "arrayList.h"

class Event
{
private:
    char Type;
    Time EventTime;
public:
    Event(char Type, Time EventTime);
    virtual void Execute(arrayList<Station*> &Stations, arrayList<Passenger*> &Passengers) = 0;    
};

#endif