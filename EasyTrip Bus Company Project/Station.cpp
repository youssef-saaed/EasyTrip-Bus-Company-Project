#include "Station.h"


Station::Station(int number, int numberOfBusesAvailable, int numberOfMovedBuses) : stationNumber(number) , numberOfBusesAvailable(numberOfBusesAvailable), numberOfMovedBuses(numberOfMovedBuses), busesInStation(numberOfBusesAvailable) , movedBuses(numberOfMovedBuses) {};

void Station::addBusToStation(Bus* bus) {
    busesInStation.enqueue(bus);
}

void Station::removeBusFromStation() {
    if (!busesInStation.isEmpty()) {
        Node<Bus*>* busNode = busesInStation.dequeue();
        movedBuses.push(busNode->data);
        delete busNode;
    }
}

arrayList<Bus*> Station::getMovedBuses() const {
    return movedBuses;
}

Queue<Bus*> Station::getBusesInStation() const {
    return busesInStation;
}