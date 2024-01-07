#include "Station.h"


Station::Station(int number, int maxNumberOfBusess) : stationNumber(number) {
    MovedMBus = new Queue<Bus*>(maxNumberOfBusess);
    MovedWBus = new Queue<Bus*>(maxNumberOfBusess);
    recentBuses = new Queue<Bus*>(maxNumberOfBusess);
}
//Bus* Station::removeBus(int id)
//{
//    for (int i = 0; i < movedBuses.Size(); i++)
//    {
//        if (movedBuses.LookAt(i)->)
//    }
//}


bool Station::PopFromMovedBuses(int BusID, char &type, Bus*& b)
{
    if (MovedMBus->peek(b) && b->getBusID() == BusID)
    {
        MovedMBus->dequeue(b);
        type = 'M';
        return true;
    }
    else if (MovedWBus->peek(b) && b->getBusID() == BusID)
    {
        MovedWBus->dequeue(b);
        type = 'W';
        return true;
    }
    return false;
}

int Station::getStationNumber() {
    return this->stationNumber;
}

void Station::addRecentBus(Bus* bus) {
    recentBuses->enqueue(bus);
}

Queue<Bus*>* Station::getRecentBuses() {
    return this->recentBuses;
}


