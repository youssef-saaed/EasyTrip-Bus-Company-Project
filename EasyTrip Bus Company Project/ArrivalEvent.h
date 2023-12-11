#ifndef _ARRIVALEVENT_H_
#define _ARRIVALEVENT_H_

#include "PassengerEvent.h"
#include <string>

class ArrivalEvent : public PassengerEvent
{
private:
    int EndStation;
    std::string PassengerType;
    std::string SpecialPassengerType;
public:
    ArrivalEvent(Time EventTime, int StartStation, int EndStation, int PassengerID, std::string PassengerType, std::string SpecialPassengerType);
    void Execute(arrayList<Stations*> &StationsList, arrayList<Passenger*> &Passengers);
};

#endif