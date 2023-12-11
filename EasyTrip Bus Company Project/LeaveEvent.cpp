#include "LeaveEvent.h"

LeaveEvent::LeaveEvent(Time EventTime, int StartStation, int PassengerID) : PassengerEvent('L', EventTime, StartStation, PassengerID)
{
} 

void LeaveEvent::Execute(arrayList<Stations*> &StationsList, arrayList<Passenger*> &Passengers)
{
	Stations *curr = StationsList.LookAt(StartStation);
	while (curr.)
}