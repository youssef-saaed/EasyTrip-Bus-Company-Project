#include "StationZero.h"
#include <typeinfo>

 StationZero::StationZero(int NumberOfMBuses, int NumberOfWBuses, int MBusCapacity, int WBusCapacity) : MbusesInStation(NumberOfMBuses), WbusesInStation(NumberOfWBuses), Station(0, NumberOfMBuses + NumberOfWBuses){       
    
    Bus* bus = nullptr;
    WBusCheckup = new Queue<Pair<Bus*, Time>>(NumberOfWBuses);
    MBusCheckup = new Queue<Pair<Bus*, Time>>(NumberOfMBuses);
    for (int i = 0; i < NumberOfMBuses; i++)
    {
        bus = new MBus(MBusCapacity, 0); 
        MbusesInStation.enqueue(bus);
    }

    for (int i = 0; i < NumberOfWBuses; i++)
    {
        bus = new WBus(WBusCapacity, 0); 
        WbusesInStation.enqueue(bus);
    }
};

void StationZero::addBusToStation(Bus* bus, char busType) {
    if (busType == 'M') MbusesInStation.enqueue(bus);
    else if (busType == 'W') WbusesInStation.enqueue(bus);
}

void StationZero::removeBusFromStation(char busType, Bus*& b) {
    if (busType == 'M' && MbusesInStation.dequeue(b))
    {
        MovedMBus->enqueue(b);
        
    }
    else if (busType == 'W'&& WbusesInStation.dequeue(b)) {
        MovedWBus->enqueue(b);
    }
}

void StationZero::AddToCheckup(Bus*& b, Time current)
{
    Pair<Bus*, Time> p;
    p.A = b;
    p.B = current;
    if (typeid(*b).name() == "MBus")
    {
        MBusCheckup->enqueue(p);
    }
    else
    {
        WBusCheckup->enqueue(p);
    }
}

Queue<Pair<Bus*, Time>>* StationZero::getWBusCheckup()
{
    return WBusCheckup;
}

Queue<Pair<Bus*, Time>>* StationZero::getMBusCheckup()
{
    return MBusCheckup;
}

Queue<Bus*> StationZero::getMbusesInStation() {
    return this->MbusesInStation;
}

Queue<Bus*> StationZero::getWbusesInStation() {
    return this->WbusesInStation;
}