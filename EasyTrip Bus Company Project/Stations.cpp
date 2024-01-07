#include "Station.h"
#include "Stations.h"
#include <typeinfo>
#include "MBus.h"
#include "WBus.h"
#include "arrayList.h"
//#include "Company.h"
#include <iostream>
Stations::Stations(int number, int maxNumberOfBuses, int maxNumberOfPassengers) : Station(number, maxNumberOfBuses), availableForwardBuses(maxNumberOfBuses), availableBackwardBuses(maxNumberOfBuses), forwardNP(maxNumberOfPassengers), backwardNP(maxNumberOfPassengers), forwardWP(maxNumberOfPassengers), backwardWP(maxNumberOfPassengers),forwardSP(maxNumberOfPassengers), backwardSP(maxNumberOfPassengers)
{
};

Queue<Bus*> Stations::getAvailableForwardBuses() const {
    return availableForwardBuses;
}

Queue<Bus*> Stations::getAvailableBackwardBuses() const {
    return availableBackwardBuses;
}
void Stations::unloadPassengers(Queue<Passenger*>*& FinishedPassengers, int numOfStations, int PassengerBoardingTime, int &BoardingTime) {
    
    while (!recentBuses->isEmpty()) {

        Bus* currentBus;
        if (recentBuses->peek(currentBus))
        {
            Passenger* p;

            while (currentBus->GetOff(p) && BoardingTime < 60)
            {
                FinishedPassengers->enqueue(p);
                BoardingTime += PassengerBoardingTime;
            }
        }

        if (BoardingTime < 60)
        {
            if (stationNumber == numOfStations) {
                currentBus->change_direction();
            }
            if (currentBus->get_direction() == "FWD") {

                availableForwardBuses.enqueue(currentBus);
            }
            if (currentBus->get_direction() == "BWD") {
                availableBackwardBuses.enqueue(currentBus);
            }
            currentBus->setCurrent();
            recentBuses->dequeue(currentBus);
        }
    }
}

void Stations::loadPassengers(Queue<BusMoveEvent*>*& EventsList, int PassengerBoardingTime, int &BoardingTime, Time currentTime, int MBusCapacity, int WBusCapacity) {

    while (!availableForwardBuses.isEmpty()) {

        Bus* currentBus;
        availableForwardBuses.peek(currentBus);

        if ((typeid(*currentBus).name() == "MBus")) {

            currentBus = new MBus(MBusCapacity, currentBus->get_current(), currentBus->get_destination());


            while (!forwardSP.IsEmpty() && BoardingTime < 60) {

                int _;
                Passenger* currentPassenger;
                forwardSP.Peak(currentPassenger);
                currentBus->GetOn(currentPassenger);
                forwardSP.Dequeue(currentPassenger, _);
                BoardingTime += PassengerBoardingTime;
            }

            while (!forwardNP.isEmpty() && BoardingTime < 60) {
                Passenger* currentPassenger;
                forwardNP.peek(currentPassenger);
                currentBus->GetOn(currentPassenger);
                forwardNP.dequeue(currentPassenger);
                BoardingTime += PassengerBoardingTime;
            }
            if (BoardingTime < 60)
            {
                MovedWBus->enqueue(currentBus);
                //EventsList->enqueue(new BusMoveEvent(currentTime, stationNumber, currentBus->get_destination(), currentBus->getBusID()));
            }
        }

        else {
            while (!forwardWP.isEmpty() && BoardingTime < 60) {
                Passenger* currentPassenger;
                forwardWP.peek(currentPassenger);
                currentBus->GetOn(currentPassenger);
                forwardWP.dequeue(currentPassenger);
                BoardingTime += PassengerBoardingTime;
            }
            if (BoardingTime < 60) 
            {
                MovedWBus->enqueue(currentBus);
                //EventsList->enqueue(new BusMoveEvent(currentTime, stationNumber, currentBus->get_destination(), currentBus->getBusID()));
            }
        }
    }

   /* ////////////////////////////////availableBackwardBuses///////////////////////////////////////////////
    */
    while (!availableBackwardBuses.isEmpty()) {

        Bus* currentBus; 
        availableBackwardBuses.peek(currentBus);

        if ((typeid(*currentBus).name() == "MBus")) {
            currentBus = new MBus(MBusCapacity, currentBus->get_current(), currentBus->get_destination());
                while (!forwardSP.IsEmpty()) {
                    int _;
                    Passenger* currentPassenger;
                    forwardSP.Peak(currentPassenger);
                    currentBus->GetOn(currentPassenger);
                    forwardSP.Dequeue(currentPassenger, _);
                }

            while (!forwardNP.isEmpty()) {
                Passenger* currentPassenger;
                forwardNP.peek(currentPassenger);
                currentBus->GetOn(currentPassenger);
                forwardNP.dequeue(currentPassenger);
            }
            MovedMBus->enqueue(currentBus);
        }

        else {

            currentBus = new WBus(WBusCapacity, currentBus->get_current(), currentBus->get_destination());
            while (!forwardWP.isEmpty()) {
                Passenger* currentPassenger;
                forwardWP.peek(currentPassenger);
                currentBus->GetOn(currentPassenger);
                forwardWP.dequeue(currentPassenger);
            }
            MovedWBus->enqueue(currentBus);
        }
    }
}

void Stations::addPassengerToStation(Passenger* passenger) {
    
    if (passenger->getPassengerType() == "NP")
    {
        if (passenger->getDirection() == "FWD")
        {
            forwardNP.enqueue(passenger);
        }
        else
        {
            backwardNP.enqueue(passenger);
        }
    }
    else if (passenger->getPassengerType() == "WP")
    {
        if (passenger->getDirection() == "FWD")
        {
            forwardWP.enqueue(passenger);
        }
        else
        {
            backwardWP.enqueue(passenger);
        }
    }
    else
    {
        if (passenger->getDirection() == "FWD")
        {
            forwardSP.Enqueue(passenger, passenger->getPriority());
        }
        else
        {
            backwardSP.Enqueue(passenger, passenger->getPriority());
        }
    }
}

bool Stations::RemovePassengerFromStation(int id)
{
    bool flag = false; 
    Queue<Passenger*> temp(forwardNP.getMaxCapacity());
    Passenger* p;
    while (forwardNP.dequeue(p))
    {
        if (p->getPassengerID() == id)
        {
            delete p;
            flag = true;
        }
        else 
        {
            temp.enqueue(p);
        }
    }

    while (temp.dequeue(p))
    {
        forwardNP.enqueue(p);
    }
    return flag;
}
