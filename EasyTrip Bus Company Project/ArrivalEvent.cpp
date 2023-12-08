#include "ArrivalEvent.h"

ArrivalEvent::ArrivalEvent(Time EventTime, int StartStation, int EndStation, int PassengerID, std::string PassengerType): PassengerEvent('A', EventTime, StartStation, PassengerID)
{
    this->EndStation = EndStation;
    this->PassengerType = PassengerType;
} 

void ArrivalEvent::Execute(arrayList<Station*> &Stations, arrayList<Passenger*> &Passengers)
{
    Passenger *p = new Passenger(PassengerID, StartStation, EndStation, PassengerType);
    Passengers.push(p);
    Stations.get(StartStation)->WatingPassengers->Enqueue(p);
}