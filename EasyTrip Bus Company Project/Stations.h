#pragma once
#include "Station.h"
#include "Queue.h"
#include "Bus.h"
#include "Passenger.h"
#include "arrayList.h"
#include "Events.h"

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
    PriorityQueue<Passenger*> forwardSP;
    PriorityQueue<Passenger*> backwardSP;
    int capacity;


public:
    Stations(int number, int maxNumberOfBuses, int maxNumberOfPassengers);


    Queue<Bus*> getAvailableForwardBuses() const;
    Queue<Bus*> getAvailableBackwardBuses() const;

    void addPassengerToStation(Passenger* passenger);
    bool RemovePassengerFromStation(int id);
    void addRecentBus(Bus* bus);
    void unloadPassengers(Queue<Passenger*>*&FinishedPassengers, int numOfStations, int PassengerBoardingTime, int &BoardingTime);
    void loadPassengers(Queue<BusMoveEvent*>*& EventsList, int PassengerBoardingTime, int& BoardingTime, Time currentTime);
};
