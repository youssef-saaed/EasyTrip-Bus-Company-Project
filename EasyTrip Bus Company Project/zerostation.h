#pragma once
#include "basestation.h"

template<typename T>
class StationZero : public Station<T> {
public:
    StationZero(int number);

    void addBusToStation(T* bus) override;

    void removeBusFromStation() override;

    arrayList<T*> getMovedBuses() const override;

    Queue<T*> getBusesInStation() const override;
};
