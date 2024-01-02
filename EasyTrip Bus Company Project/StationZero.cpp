#include "Station.h"
#include "StationZero.h"

StationZero::StationZero(int number, int maxNumberOfBuses) : Station(number, maxNumberOfBuses), busesInStation(maxNumberOfBuses) {};

void StationZero::addBusToStation(Bus* bus) {
    busesInStation.enqueue(bus);
}

void StationZero::removeBusFromStation() {
    if (!busesInStation.isEmpty()) {
        Bus* busNode;
        busesInStation.dequeue(busNode);
        movedBuses.push(busNode);
        delete busNode;
    }
}

Queue<Bus*> StationZero::getBusesInStation() const {
    return busesInStation;
}
