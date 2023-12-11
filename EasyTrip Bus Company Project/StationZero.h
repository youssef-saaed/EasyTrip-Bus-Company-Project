#pragma once
#include "Station.h"

class StationZero : public Station {
private:
    Queue<Bus*> busesInStation;
public:
    StationZero(int number, int maxNumberOfBuses);
    void addBusToStation(Bus* bus);

    void removeBusFromStation();
    Queue<Bus*> getBusesInStation() const;

   
};
