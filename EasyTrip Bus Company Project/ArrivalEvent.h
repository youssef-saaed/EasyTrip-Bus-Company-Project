#pragma once

#include "PassengerEvent.h"
#include <string>

class ArrivalEvent : public PassengerEvent
{
private:
    int EndStation;
    std::string PassengerType;
    std::string SpecialPassengerType;
public:
    ArrivalEvent(Time EventTime, int StartStation, int EndStation, int PassengerID, std::string PassengerType, std::string SpecialPassengerType = "NA");
    void Execute(arrayList<Station*> &StationsList, Queue<Passenger*> &Passengers);
};
