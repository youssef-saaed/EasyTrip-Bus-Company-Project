#pragma once
#include "Bus.h"
#include "Queue.h"
#include "arrayList.h"

class Station {
protected:
    int stationNumber;
    arrayList<Bus*> movedBuses;

public:
    Station(int number, int maxNumberOfBuses);
    /*Bus* removeBus(int id);*/
    arrayList<Bus*> getMovedBuses() const;
    int getStationNumber();
};
