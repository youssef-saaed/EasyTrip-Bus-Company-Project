#include "ArrivalEvent.h"

ArrivalEvent::ArrivalEvent(Time EventTime, int StartStation, int EndStation, int PassengerID, std::string PassengerType, std::string SpecialPassengerType) : PassengerEvent('A', EventTime, StartStation, PassengerID)
{
    this->EndStation = EndStation;
    this->PassengerType = PassengerType;
} 

void ArrivalEvent::Execute(arrayList<Station*> &Stations, arrayList<Passenger*> &Passengers)
{
    int priority = 0;
    if (SpecialPassengerType == "Aged")
    {
        priority = 4;
    }
    else if (SpecialPassengerType == "POD")
    {
        priority = 3;
    }
    else if (SpecialPassengerType == "Pregnant")
    {
        priority = 2;
    }
    else if (PassengerType == "NP")
    {
        priority = 1;
    }
    std
    if (EndStation > StartStation)
    Passenger *p = new Passenger(PassengerID, StartStation, EndStation, priority, PassengerType);
    Passengers.push(p);
    Stations.get(StartStation)->WatingPassengers->Enqueue(p);
}