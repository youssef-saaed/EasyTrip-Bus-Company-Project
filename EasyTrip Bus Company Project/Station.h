#pragma once
#include "Bus.h"
#include "Queue.h"
#include "arrayList.h"

template<typename T>
class Station {
private:
    int stationNumber;
    Queue<T*> busesInStation;
    ArrayList<T*> movedBuses;

public:
    Station(int number);

    virtual void addBusToStation(T* bus);

    virtual void removeBusFromStation();

    virtual arrayList<T*> getMovedBuses() const;

    virtual Queue<T*> getBusesInStation() const;
};