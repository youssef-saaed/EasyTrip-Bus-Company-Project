#include "LeaveEvent.h"
#include <iostream>

LeaveEvent::LeaveEvent(Time EventTime, int StartStation, int PassengerID) : PassengerEvent('L', EventTime, StartStation, PassengerID)
{
} 

void LeaveEvent::Execute(arrayList<Station*> &StationsList, Queue<Passenger*> &Passengers)
{
	Stations *s = (Stations*)StationsList.LookAt(StartStation);
	s->RemovePassengerFromStation(PassengerID);
	std::cout << "L" << "\n";
}