#ifndef _PASSENGEREVENT_H_
#define _PASSENGEREVENT_H_

#include "Event.h"

class PassengerEvent : public Event
{
protected:
    int StartStation;
    int PassengerID;
public:
    PassengerEvent(char Type, Time EventTime, int StartStation, int PassengerID);
    virtual void Execute(arrayList<Stations*> &StationsList, arrayList<Passenger*> &FinishedPassengers) = 0;    
};

#endif