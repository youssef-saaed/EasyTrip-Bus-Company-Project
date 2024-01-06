#include "StationZero.h"
 StationZero::StationZero(int NumberOfMBuses, int NumberOfWBuses, int MBusCapacity, int WBusCapacity) : MbusesInStation(NumberOfMBuses), WbusesInStation(NumberOfWBuses), Station(0, NumberOfMBuses + NumberOfWBuses){       
    
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

void StationZero::removeBusFromStation(char busType, Bus*& b) {
    if (busType == 'M') {
        if (MbusesInStation.dequeue(b)) {
            MovedMBus->enqueue(b);
        }
        else {
            delete b;
        }
    }
    else if (busType == 'W') {
        if (WbusesInStation.dequeue(b)) {
            MovedWBus->enqueue(b);
        }
        else {
            delete b;
        }
    }
}

Queue<Bus*> StationZero::getMbusesInStation() {
    return this->MbusesInStation;
}

Queue<Bus*> StationZero::getWbusesInStation() {
    return this->WbusesInStation;
}