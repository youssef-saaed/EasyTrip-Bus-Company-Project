#pragma once
#include "Bus.h"
#include "MBus.h"
#include "WBus.h"
#include "Station.h"
#include "Pair.h"

class StationZero: public Station {
private:
    // Add checkup wbus and mbus ---> moved to company
    // add available m and w
    Queue<Bus*> MbusesInStation;
    Queue<Bus*> WbusesInStation;
    Queue<Pair<Bus*, Time>>* WBusCheckup;
    Queue<Pair<Bus*, Time>>* MBusCheckup;
public:
    StationZero(int NumberOfMBuses, int NumberOfWBuses, int MBusCapacity, int WBusCapacity);
    void addBusToStation(Bus* bus, char busType);
    void removeBusFromStation(char busType, Bus*& b);
    void AddToCheckup(Bus*& b, Time current);
    Queue<Pair<Bus*, Time>>* getWBusCheckup();
    Queue<Pair<Bus*, Time>>* getMBusCheckup();
    Queue<Bus*> getMbusesInStation();
    Queue<Bus*> getWbusesInStation();
};
