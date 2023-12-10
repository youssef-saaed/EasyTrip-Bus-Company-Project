#include "Station.h"
#include "Stations.h"

Stations::Stations(int number, int numberOfBusesAvailable, int numberOfMovedBuses, int numOfAvailableForwardBuses, int numOfAvailableBackwardBuses, int numOfRecentBuses, int NumOfWaitingPassengers) : Station(number, numberOfBusesAvailable, numberOfMovedBuses), NumOfAvailableForwardBuses(numOfAvailableForwardBuses), NumOfAvailableBackwardBuses(numOfAvailableBackwardBuses), NumOfRecentBuses(numOfRecentBuses) , NumOfWaitingPassengers(NumOfWaitingPassengers) , availableForwardBuses(NumOfAvailableForwardBuses), availableBackwardBuses(NumOfAvailableBackwardBuses), recentBuses(NumOfRecentBuses), waitingPassengers(NumOfWaitingPassengers){};

Queue<Bus*> Stations::getAvailableForwardBuses() const {
    return availableForwardBuses;
}

Queue<Bus*> Stations::getAvailableBackwardBuses() const {
    return availableBackwardBuses;
}


arrayList<Bus*> Stations::getMovedBuses() const {
    return this->Station::getMovedBuses();
}

void Stations::addPassengerToStation(Passenger* passenger) {
    waitingPassengers.Enqueue(passenger, passenger->getPriority());
}

void Stations::addRecentBus(Bus* bus) {
    recentBuses.enqueue(bus);
}