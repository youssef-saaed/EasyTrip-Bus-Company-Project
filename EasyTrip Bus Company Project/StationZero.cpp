#include "StationZero.h"
 StationZero::StationZero(int NumberOfMBuses, int NumberOfWBuses, int MBusCapacity, int WBusCapacity) : Station(number, maxNumberOfBuses), MbusesInStation(NumberOfMBuses), WbusesInStation(NumberOfWBuses), MovedMBus(MBusCapacity), MovedWBus(WBusCapacity){   
};
    
    
    Bus* bus = nullptr;

    for (int i = 0; i < NumberOfMBuses; i++)
    {
        bus = new MBus(MBusCapacity, 0); 
        MbusesInStation.enqueue(bus);
    }

    for (int i = 0; i < NumberOfMBuses; i++)
    {
        bus = new WBus(WBusCapacity, 0); 
        MbusesInStation.enqueue(bus);
    }
};

void StationZero::addBusToStation(Bus* bus, char busType) {
    if (busType == 'M') MbusesInStation.enqueue(bus);
    else if (busType == 'W') WbusesInStation.enqueue(bus);
}

void StationZero::removeBusFromStation(char busType) {
    if (busType == 'M') {
        Bus* bus = nullptr;
        if (MbusesInStation.dequeue(bus)) {
            MovedMBus.enqueue(bus);
        }
        else {
            delete bus;
        }
    }
    else if (busType == 'W') {
        Bus* bus = nullptr;
        if (WbusesInStation.dequeue(bus)) {
            MovedWBus.enqueue(bus);
        }
        else {
            delete bus;
        }
    }
}

Queue<Bus*> StationZero::getMbusesInStation() {
    return this->MbusesInStation;
}

Queue<Bus*> StationZero::getWbusesInStation() {
    return this->WbusesInStation;
}

Queue<Bus*> StationZero::getMovedMBus() {
    return this->MovedMBus;
}

Queue<Bus*> StationZero::getMovedWBus() {
    return this->MovedWBus;
}
