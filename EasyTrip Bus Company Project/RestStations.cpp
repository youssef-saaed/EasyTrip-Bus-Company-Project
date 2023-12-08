#include "basestation.h"
#include "RestStations.h"

template<typename T>
Stations<T>::Stations(int number) : Station<T>(number) {}

template<typename T>
Queue<Bus*> Stations<T>::getAvailableForwardBuses() const {
    return availableForwardBuses;
}

template<typename T>
Queue<Bus*> Stations<T>::getAvailableBackwardBuses() const {
    return availableBackwardBuses;
}


template<typename T>
arrayList<T*> Stations<T>::getMovedBuses() const {
    return this->Station<T>::getMovedBuses();
}

template<typename T>
void Stations<T>::addPassengerToStation(Passenger* passenger) {
    waitingPassengers.enqueue(passenger, passenger->getPriority());
}

template<typename T>
void Stations<T>::addRecentBus(Bus* bus) {
    recentBuses.enqueue(bus);
}