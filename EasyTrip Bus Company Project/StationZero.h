#pragma once
#include "Station.h"

class StationZero : public Station {
private:
    // Add checkup and moving wbus and mbus
    // add available m and w
    Queue<Bus*> busesInStation;
public:
    StationZero(int number, int maxNumberOfBuses);
    void addBusToStation(Bus* bus);

    void removeBusFromStation();
    Queue<Bus*> getBusesInStation() const;

   
};
