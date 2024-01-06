#include "Station.h"


Station::Station(int number, int maxNumberOfBusess) : stationNumber(number), movedBuses(maxNumberOfBusess) {}
//Bus* Station::removeBus(int id)
//{
//    for (int i = 0; i < movedBuses.Size(); i++)
//    {
//        if (movedBuses.LookAt(i)->)
//    }
//}


int Station::getStationNumber() {
    return this->stationNumber;
}

arrayList<Bus*> Station::getMovedBuses() const {
    return movedBuses;
}



