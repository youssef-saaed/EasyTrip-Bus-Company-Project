#include "basestation.h"

template<typename T>
Station<T>::Station(int number) : stationNumber(number) {}

template<typename T>
void Station<T>::addBusToStation(T* bus) {
    busesInStation.enqueue(bus);
}

template<typename T>
void Station<T>::removeBusFromStation() {
    if (!busesInStation.isEmpty()) {
        Node<T*>* busNode = busesInStation.dequeue();
        movedBuses.add(busNode->data);
        delete busNode;
    }
}

template<typename T>
arrayList<T*> Station<T>::getMovedBuses() const {
    return movedBuses;
}

template<typename T>
Queue<T*> Station<T>::getBusesInStation() const {
    return busesInStation;
}