#include "LeaveEvent.h"

LeaveEvent::LeaveEvent(Time EventTime, int StartStation, int PassengerID)
{
    PassengerEvent('L', EventTime, StartStation, PassengerID);
} 

void LeaveEvent::Execute(arrayList<Station*> &Stations, arrayList<Passenger*> &Passengers)
{
    Passenger *p;
    for (int i = 0; i < Passengers.size(); i++) {
        p = Passengers.get(i);
        if (p->getID() == PassengerID) {
            Passengers.pop(i);
            break;
        }
    }
}