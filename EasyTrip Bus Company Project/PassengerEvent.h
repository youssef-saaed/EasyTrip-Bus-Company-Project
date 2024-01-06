#pragma once

#include "Event.h"

class PassengerEvent : public Event
{
protected:
    int StartStation;
    int PassengerID;
public:
    PassengerEvent(char Type, Time EventTime, int StartStation, int PassengerID);
    virtual void Execute(arrayList<Station*> &StationsList, Queue<Passenger*> &FinishedPassengers) = 0;    
};