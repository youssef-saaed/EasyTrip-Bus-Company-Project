#pragma once
#include "PassengerEvent.h"

class LeaveEvent : public PassengerEvent
{
public:
    LeaveEvent(Time EventTime, int StartStation, int PassengerID);
    void Execute(arrayList<Station*> &Stations, Queue<Passenger*> &Passengers);
};