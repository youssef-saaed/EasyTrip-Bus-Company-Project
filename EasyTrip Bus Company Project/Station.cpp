#include "Station.h"


Station::Station(int number, int numberOfBusesAvailable, int numberOfMovedBuses) : stationNumber(number) , numberOfBusesAvailable(numberOfBusesAvailable), numberOfMovedBuses(numberOfMovedBuses), busesInStation(numberOfBusesAvailable) , movedBuses(numberOfMovedBuses) {};

void Station::addBusToStation(Bus* bus) {
    numberOfBusesAvailable++ ;
    busesInStation.enqueue(bus);
}

void Station::removeBusFromStation() {
    if (!busesInStation.isEmpty()) {
        Node<Bus*>* busNode = busesInStation.dequeue();
        numberOfBusesAvailable--;
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

void Station::SetNumberOfAvailableBuses(int numberOfBusesAvailable) {
    this->numberOfBusesAvailable = numberOfBusesAvailable;
}

int Station::GetNumberOfAvailableBuses() {
    return numberOfBusesAvailable;
}

void Station::SetNumberOfMovedBuses(int numberOfMovedBuses) {
    this->numberOfMovedBuses = numberOfMovedBuses;
}

int Station::GetNumberOfMovedBuses() {
    return numberOfMovedBuses;
}
