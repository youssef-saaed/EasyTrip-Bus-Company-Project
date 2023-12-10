#include "Station.h"
#include "StationZero.h"

StationZero::StationZero(int number, int numberOfBusesAvailable, int numberOfMovedBuses) : Station(number, numberOfBusesAvailable, numberOfMovedBuses) {};

void StationZero::addBusToStation(Bus* bus) {
    this->getBusesInStation().enqueue(bus);
}

void StationZero::removeBusFromStation() {
    if (!this->getBusesInStation().isEmpty()) {
        Node<Bus*>* busNode = this->getBusesInStation().dequeue();
        this->getMovedBuses().push(busNode->data);
        delete busNode;
    }
}

arrayList<Bus*> StationZero::getMovedBuses() const {
    return this->getMovedBuses();
}

Queue<Bus*> StationZero::getBusesInStation() const {
    return this->getBusesInStation();
}