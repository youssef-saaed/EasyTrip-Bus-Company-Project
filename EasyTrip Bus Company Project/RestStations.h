#pragma once
#include "basestation.h"
#include "Queue.h"
#include "Bus.h"
#include "Passenger.h"
#include "arrayList.h"

#include "PriorityQueue.h"


template<typename T>
class Stations : public Station<T> {
private:
    int stationNumber;
    Queue<Bus*> availableForwardBuses;
    Queue<Bus*> availableBackwardBuses;
    Queue<Bus*> recentBuses;
    PriorityQueue<Passenger*> waitingPassengers;

public:
    Stations(int number);

    Queue<Bus*> getAvailableForwardBuses() const;
    Queue<Bus*> getAvailableBackwardBuses() const;

   
    arrayList<T*> getMovedBuses() const override;

    void addPassengerToStation(Passenger* passenger);
    void addRecentBus(Bus* bus);
};
