#include "Station.h"
#include "StationZero.h"

StationZero::StationZero(int number, int maxNumberOfBuses) : Station(number, maxNumberOfBuses), busesInStation(maxNumberOfBuses) {};

void StationZero::addBusToStation(Bus* bus) {
    busesInStation.enqueue(bus);
}

void StationZero::removeBusFromStation() {
    if (!busesInStation.isEmpty()) {
        Node<Bus*>* busNode = busesInStation.dequeue();
        movedBuses.push(busNode->data);
        delete busNode->data;
        delete busNode;
    }
}

Queue<Bus*> StationZero::getBusesInStation() const {
    return busesInStation;
}
