#include "Station.h"
#include "Stations.h"
#include <typeinfo>
#include "MBus.h"
#include "WBus.h"
#include "arrayList.h"

Stations::Stations(int number, int maxNumberOfBuses, int maxNumberOfPassengers) : Station(number, maxNumberOfBuses)
{
    availableForwardBuses = new Queue<Bus*>(maxNumberOfBuses);
    availableBackwardBuses = new Queue<Bus*>(maxNumberOfBuses);
    forwardNP = new Queue<Passenger*>(maxNumberOfPassengers);
    backwardNP = new Queue<Passenger*>(maxNumberOfPassengers);
    forwardWP = new Queue<Passenger*>(maxNumberOfPassengers);
    backwardWP = new Queue<Passenger*>(maxNumberOfPassengers);
    forwardSP = new PriorityQueue<Passenger*>(maxNumberOfPassengers);
    backwardSP = new PriorityQueue<Passenger*>(maxNumberOfPassengers);
};

Queue<Bus*> *Stations::getAvailableForwardBuses() const {
    return availableForwardBuses;
}

Queue<Bus*> *Stations::getAvailableBackwardBuses() const {
    return availableBackwardBuses;
}
Queue<Passenger*>* Stations::getForwardNP()
{
    return forwardNP;
}
Queue<Passenger*> *Stations::getBackwardNP()
{
    return backwardNP;
}
PriorityQueue<Passenger*>* Stations::getForwardSP()
{
    return forwardSP;
}
PriorityQueue<Passenger*>* Stations::getBackwardSP()
{
    return backwardSP;
}
void Stations::unloadPassengers(Queue<Passenger*>*& FinishedPassengers, int numOfStations, int PassengerBoardingTime, int &BoardingTime) {
    Bus* currentBus;
    while (!recentBuses->isEmpty()) {
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

                availableForwardBuses->enqueue(currentBus);
            }
            else if (currentBus->get_direction() == "BWD") {
                availableBackwardBuses->enqueue(currentBus);
            }
            currentBus->setCurrent();
            recentBuses->dequeue(currentBus);
        }
    }
}

void Stations::loadPassengers(Queue<BusMoveEvent*>*& EventsList, int PassengerBoardingTime, int &BoardingTime, Time currentTime, int MBusCapacity, int WBusCapacity) {
    Bus* currentBus;
    while (availableForwardBuses->peek(currentBus)) {

        if ((typeid(*currentBus).name() == "MBus")) {


            while (!forwardSP->IsEmpty() && BoardingTime < 60) {

                int _;
                Passenger* currentPassenger;
                forwardSP->Peak(currentPassenger);
                currentBus->GetOn(currentPassenger);
                forwardSP->Dequeue(currentPassenger, _);
                BoardingTime += PassengerBoardingTime;
            }

            while (!forwardNP->isEmpty() && BoardingTime < 60) {
                Passenger* currentPassenger;
                forwardNP->peek(currentPassenger);
                currentBus->GetOn(currentPassenger);
                forwardNP->dequeue(currentPassenger);
                BoardingTime += PassengerBoardingTime;
            }
            if (BoardingTime < 60 && currentBus)
            {
                availableForwardBuses->dequeue(currentBus);
                MovedWBus->enqueue(currentBus);
                EventsList->enqueue(new BusMoveEvent(currentTime + 1, stationNumber, currentBus->get_destination(), currentBus->getBusID()));
            }
        }

        else {
            while (!forwardWP->isEmpty() && BoardingTime < 60) {
                Passenger* currentPassenger;
                forwardWP->peek(currentPassenger);
                currentBus->GetOn(currentPassenger);
                forwardWP->dequeue(currentPassenger);
                BoardingTime += PassengerBoardingTime;
            }
            if (BoardingTime < 60 && currentBus)
            {
                availableForwardBuses->dequeue(currentBus);
                MovedWBus->enqueue(currentBus);
                EventsList->enqueue(new BusMoveEvent(currentTime + 2, stationNumber, currentBus->get_destination(), currentBus->getBusID()));
            }
        }
    }

   /* ////////////////////////////////availableBackwardBuses///////////////////////////////////////////////
    */
    while (availableBackwardBuses->peek(currentBus)) {

        

        if ((typeid(*currentBus).name() == "MBus")) {
                while (!forwardSP->IsEmpty()) {
                    int _;
                    Passenger* currentPassenger;
                    forwardSP->Peak(currentPassenger);
                    currentBus->GetOn(currentPassenger);
                    forwardSP->Dequeue(currentPassenger, _);
                }

            while (!forwardNP->isEmpty()) {
                Passenger* currentPassenger;
                forwardNP->peek(currentPassenger);
                currentBus->GetOn(currentPassenger);
                forwardNP->dequeue(currentPassenger);
            }
            if (BoardingTime < 60 && currentBus)
            {
                availableForwardBuses->dequeue(currentBus);
                MovedWBus->enqueue(currentBus);
                EventsList->enqueue(new BusMoveEvent(currentTime + 2, stationNumber, currentBus->get_destination(), currentBus->getBusID()));
            }
        }

        else {

            currentBus = new WBus(WBusCapacity, currentBus->get_current(), currentBus->get_destination());
            while (!forwardWP->isEmpty()) {
                Passenger* currentPassenger;
                forwardWP->peek(currentPassenger);
                currentBus->GetOn(currentPassenger);
                forwardWP->dequeue(currentPassenger);
            }
            if (BoardingTime < 60 && currentBus)
            {
                availableForwardBuses->dequeue(currentBus);
                MovedWBus->enqueue(currentBus);
                EventsList->enqueue(new BusMoveEvent(currentTime + 2, stationNumber, currentBus->get_destination(), currentBus->getBusID()));
            }
        }
    }
}

void Stations::addPassengerToStation(Passenger* passenger) {
    
    if (passenger->getPassengerType() == "NP")
    {
        if (passenger->getDirection() == "FWD")
        {
            forwardNP->enqueue(passenger);
        }
        else
        {
            backwardNP->enqueue(passenger);
        }
    }
    else if (passenger->getPassengerType() == "WP")
    {
        if (passenger->getDirection() == "FWD")
        {
            forwardWP->enqueue(passenger);
        }
        else
        {
            backwardWP->enqueue(passenger);
        }
    }
    else
    {
        if (passenger->getDirection() == "FWD")
        {
            forwardSP->Enqueue(passenger, passenger->getPriority());
        }
        else
        {
            backwardSP->Enqueue(passenger, passenger->getPriority());
        }
    }
}

bool Stations::RemovePassengerFromStation(int id)
{
    bool flag = false; 
    //Queue<Passenger*> temp(forwardNP.getMaxCapacity());
    Passenger* p, *firstP;
    if (!forwardNP->dequeue(p))
    {
        return true;
    }
    firstP = p;
    if (firstP->getPassengerID() == id)
    {
        delete firstP;
        return true;
    }
    forwardNP->enqueue(firstP);
    while (forwardNP->peek(p) && p != firstP)
    {
        if (p->getPassengerID() == id)
        {
            delete p;
            flag = true;
        }
        else 
        {
            forwardNP->enqueue(p);
        }
    }

    /*while (temp.dequeue(p))
    {
        forwardNP.enqueue(p);
    }*/
    return flag;
}
