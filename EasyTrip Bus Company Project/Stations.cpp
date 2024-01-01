#include "Station.h"
#include "Stations.h"

Stations::Stations(int number, int maxNumberOfBuses, int maxNumberOfPassengers) : Station(number, maxNumberOfBuses), availableForwardBuses(maxNumberOfBuses), availableBackwardBuses(maxNumberOfBuses), recentBuses(maxNumberOfBuses), forwardNP(maxNumberOfPassengers), backwardNP(maxNumberOfPassengers), forwardWP(maxNumberOfPassengers), backwardWP(maxNumberOfPassengers),forwardSP(maxNumberOfPassengers), backwardSP(maxNumberOfPassengers)
{
};

Queue<Bus*> Stations::getAvailableForwardBuses() const {
    return availableForwardBuses;
}

Queue<Bus*> Stations::getAvailableBackwardBuses() const {
    return availableBackwardBuses;
}

void Stations::addPassengerToStation(Passenger* passenger) {
    if (passenger->getPassengerType() == "POD")
    {
        if (passenger->getDirection() == "FWD")
        {
            forwardSP.enqueue(passenger);
        }
        else
        {
            backwardSP.enqueue(passenger);
        }
    }
    else if (passenger->getPassengerType() == "aged")
    {
        if (passenger->getDirection() == "FWD")
        {
            forwardSP.enqueue(passenger);
        }
        else
        {
            backwardSP.enqueue(passenger);
        }
    }
    else if (passenger->getPassengerType() == "Pregnant")
    {
        if (passenger->getDirection() == "FWD")
        {
            forwardSP.enqueue(passenger);
        }
        else
        {
            backwardSP.enqueue(passenger);
        }
    }
    else if (passenger->getPassengerType() == "NP")
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
}

bool Stations::RemovePassengerFromStation(int id)
{
    bool flag = false; 
    Queue<Passenger*> temp(forwardNP.getMaxCapacity());
    Passenger* p;
    forwardNP.dequeue(p);
    while (p)
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

    temp.dequeue(p);
    while (p)
    {
        forwardNP.enqueue(p);
    }
    return flag;
}

void Stations::addRecentBus(Bus* bus) {
    recentBuses.enqueue(bus);
}
