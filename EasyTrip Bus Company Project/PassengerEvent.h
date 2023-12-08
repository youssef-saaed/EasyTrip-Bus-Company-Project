#ifndef _PASSENGEREVENT_H_
#define _PASSENGEREVENT_H_

#include "Event.h"

class PassengerEvent : public Event
{
private:
    int StartStation;
    int PassengerID;
public:
    PassengerEvent(char Type, Time EventTime, int StartStation, int PassengerID);
    virtual void Execute(arrayList<Station*> &Stations, arrayList<Passenger*> &Passengers) = 0;    
};

#endif