#pragma once
#include "Bus.h"
#include "Queue.h"
#include "arrayList.h"

class Station {
private:
    int stationNumber;
    int numberOfBusesAvailable;
    int numberOfMovedBuses;
    Queue<Bus*> busesInStation;
    arrayList<Bus*> movedBuses;

public:
    Station(int number, int numberOfBusesAvailable, int numberOfMovedBuses);

    void addBusToStation(Bus* bus);

    void removeBusFromStation();

    arrayList<Bus*> getMovedBuses() const;

    Queue<Bus*> getBusesInStation() const;
    void SetNumberOfAvailableBuses(int numberOfBusesAvailable);
    int GetNumberOfAvailableBuses();

    void SetNumberOfMovedBuses(int numberOfMovedBuses);
    int GetNumberOfMovedBuses();
};
