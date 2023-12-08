#include "PassengerEvent.h"

PassengerEvent::PassengerEvent(char Type, Time EventTime, int StartStation, int PassengerID)
{
    Event(Type, EventTime);
    this->StartStation = StartStation;
    this->PassengerID = PassengerID;
}