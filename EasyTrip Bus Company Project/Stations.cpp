#include "Station.h"
#include "Stations.h"

Stations::Stations(int number, int maxNumberOfBuses, int maxNumberOfPassengers) : Station(number, maxNumberOfBuses), availableForwardBuses(maxNumberOfBuses), availableBackwardBuses(maxNumberOfBuses), recentBuses(maxNumberOfBuses), forwardNP(maxNumberOfPassengers), backwardNP(maxNumberOfPassengers), forwardWP(maxNumberOfPassengers), backwardWP(maxNumberOfPassengers), forwardPOD(maxNumberOfPassengers), backwardPOD(maxNumberOfPassengers), forwardAged(maxNumberOfPassengers), backwardAged(maxNumberOfPassengers), forwardPregnant(maxNumberOfPassengers), backwardPregnant(maxNumberOfPassengers)
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
    Node<Passenger*> *p = forwardNP.dequeue();
    while (p)
    {
        if (p->data->getPassengerID() == id)
        {
            delete p->data;
            delete p;
            flag = true;
        }
        else 
        {
            temp.enqueue(p->data);
        }
    }
    p = temp.dequeue();
    while (p)
    {
        forwardNP.enqueue(p->data);
    }
    return flag;
}

void Stations::addRecentBus(Bus* bus) {
    recentBuses.enqueue(bus);
}
