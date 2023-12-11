#pragma once
#include "Station.h"
#include "Queue.h"
#include "Bus.h"
#include "Passenger.h"
#include "arrayList.h"

#include "PriorityQueue.h"


class Stations : public Station {
private:
    Queue<Bus*> availableForwardBuses;
    Queue<Bus*> availableBackwardBuses;
    Queue<Bus*> recentBuses;
    Queue<Passenger*> forwardNP;
    Queue<Passenger*> backwardNP;
    Queue<Passenger*> forwardWP;
    Queue<Passenger*> backwardWP;
    Queue<Passenger*> forwardPOD;
    Queue<Passenger*> backwardPOD;
    Queue<Passenger*> forwardAged;
    Queue<Passenger*> backwardAged;
    Queue<Passenger*> forwardPregnant;
    Queue<Passenger*> backwardPregnant;

public:
    Stations(int number, int maxNumberOfBuses, int maxNumberOfPassengers);


    Queue<Bus*> getAvailableForwardBuses() const;
    Queue<Bus*> getAvailableBackwardBuses() const;

    void addPassengerToStation(Passenger* passenger);
    bool RemovePassengerFromStation(int id);
    void addRecentBus(Bus* bus);
   
   
};
