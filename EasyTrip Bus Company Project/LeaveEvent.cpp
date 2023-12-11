#include "LeaveEvent.h"

LeaveEvent::LeaveEvent(Time EventTime, int StartStation, int PassengerID) : PassengerEvent('L', EventTime, StartStation, PassengerID)
{
} 

void LeaveEvent::Execute(arrayList<Station*> &Stations, arrayList<Passenger*> &Passengers)
{
	Station* curr = Stations.LookAt(StartStation);
	while (curr.)
}