#pragma once
#include "Bus.h"
#include "Queue.h"
#include "arrayList.h"

class Station {
protected:
    int stationNumber;
    Queue<Bus*> *MovedMBus;
    Queue<Bus*> *MovedWBus;
    Queue<Bus*> *recentBuses;
public:
    Station(int number, int maxNumberOfBuses);
    /*Bus* removeBus(int id);*/
    bool PopFromMovedBuses(int BusID, char& type, Bus*& b);
    int getStationNumber();
    void addRecentBus(Bus* bus);
};
