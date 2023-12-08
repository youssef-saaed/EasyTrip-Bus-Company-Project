#include "basestation.h"
#include "zerostation.h"

template<typename T>
StationZero<T>::StationZero(int number) : Station<T>(number) {}

template<typename T>
void StationZero<T>::addBusToStation(T* bus) {
    this->busesInStation.enqueue(bus);
}

template<typename T>
void StationZero<T>::removeBusFromStation() {
    if (!this->busesInStation.isEmpty()) {
        Node<T*>* busNode = this->busesInStation.dequeue();
        this->movedBuses.add(busNode->data);
        delete busNode;
    }
}

template<typename T>
arrayList<T*> StationZero<T>::getMovedBuses() const {
    return this->movedBuses;
}

template<typename T>
Queue<T*> StationZero<T>::getBusesInStation() const {
    return this->busesInStation;
}