#pragma once
#include "Station.h"
#include "Queue.h"
#include "Bus.h"
#include "Passenger.h"
#include "arrayList.h"

#include "PriorityQueue.h"


class Stations : public Station {
private:
    int stationNumber;
    int NumOfAvailableForwardBuses;
    int NumOfAvailableBackwardBuses;
    int NumOfRecentBuses;
    int NumOfWaitingPassengers;
    Queue<Bus*> availableForwardBuses;
    Queue<Bus*> availableBackwardBuses;
    Queue<Bus*> recentBuses;
    PriorityQueue<Passenger*> waitingPassengers;

public:
    Stations(int number, int numberOfBusesAvailable, int numberOfMovedBuses, int numOfAvailableForwardBuses, int numOfAvailableBackwardBuses, int numOfRecentBuses, int NumOfWaitingPassengers);

    Queue<Bus*> getAvailableForwardBuses() const;
    Queue<Bus*> getAvailableBackwardBuses() const;

   
    arrayList<Bus*> getMovedBuses() const override;

    void addPassengerToStation(Passenger* passenger);
    void addRecentBus(Bus* bus);
};
