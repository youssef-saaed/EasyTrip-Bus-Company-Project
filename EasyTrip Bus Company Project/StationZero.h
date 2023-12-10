#pragma once
#include "Station.h"

class StationZero : public Station {
public:
    StationZero(int number, int numberOfBusesAvailable, int numberOfMovedBuses);

    void addBusToStation(Bus* bus) override;

    void removeBusFromStation() override;

    arrayList<Bus*> getMovedBuses() const override;

    Queue<Bus*> getBusesInStation() const override;
};
