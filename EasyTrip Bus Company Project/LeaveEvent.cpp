#include "LeaveEvent.h"

LeaveEvent::LeaveEvent(Time EventTime, int StartStation, int PassengerID) : PassengerEvent('L', EventTime, StartStation, PassengerID)
{
} 

void LeaveEvent::Execute(arrayList<Station*> &StationsList, arrayList<Passenger*> &Passengers)
{
	Stations *s = (Stations*)StationsList.LookAt(StartStation);
	s->RemovePassengerFromStation(PassengerID);
}