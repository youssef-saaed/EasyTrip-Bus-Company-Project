#pragma once
#include "Bus.h"
#include "MBus.h"
#include "WBus.h"
#include "Station.h"

class StationZero: public Station {
private:
    // Add checkup wbus and mbus ---> moved to company
    // add available m and w
    Queue<Bus*> MbusesInStation;
    Queue<Bus*> WbusesInStation;
public:
    StationZero(int NumberOfMBuses, int NumberOfWBuses, int MBusCapacity, int WBusCapacity);
    void addBusToStation(Bus* bus, char busType);
    void removeBusFromStation(char busType);
    Queue<Bus*> getMbusesInStation();
    Queue<Bus*> getWbusesInStation();
};
