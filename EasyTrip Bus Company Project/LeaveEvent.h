#ifndef _LEAVEEVENT_H_
#define _LEAVEEVENT_H_

#include "PassengerEvent.h"

class LeaveEvent : public PassengerEvent
{
public:
    LeaveEvent(Time EventTime, int StartStation, int PassengerID);
    void Execute(arrayList<Station*> &Stations, arrayList<Passenger*> &Passengers);
};

#endif