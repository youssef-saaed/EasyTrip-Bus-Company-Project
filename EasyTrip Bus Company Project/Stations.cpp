#include "Station.h"
#include "Stations.h"
#include <typeinfo>
#include <MBus.h>
#include <WBus.h>
#include<arrayList.h>
Stations::Stations(int number, int maxNumberOfBuses, int maxNumberOfPassengers) : Station(number, maxNumberOfBuses), availableForwardBuses(maxNumberOfBuses), availableBackwardBuses(maxNumberOfBuses), recentBuses(maxNumberOfBuses), forwardNP(maxNumberOfPassengers), backwardNP(maxNumberOfPassengers), forwardWP(maxNumberOfPassengers), backwardWP(maxNumberOfPassengers),forwardSP(maxNumberOfPassengers), backwardSP(maxNumberOfPassengers)
{
};

Queue<Bus*> Stations::getAvailableForwardBuses() const {
    return availableForwardBuses;
}

Queue<Bus*> Stations::getAvailableBackwardBuses() const {
    return availableBackwardBuses;
}
void Stations::unloadPassengers() {

   
    while (!recentBuses.isEmpty()) {

        Bus* currentBus = recentBuses.peek();
        if (typeid(*currentBus).name() == "MBus") {

            currentBus = new MBus(int capacity, currentBus->get_current(), currentBus->get_destination());
            currentBus->GetOff(Passenger * p);
        }


        else {

            currentBus = new WBus(int capacity, currentBus->get_current(), currentBus->get_destination());

        }


        if (stationNumber == arrayList[stationNumber].size() - 1) {
            currentBus->change_direction();
        }
        if (currentBus->get_direction() == "FWD") {

            availableForwardBuses.enqueue(currentBus);


        }
        if (currentBus->get_direction() == "BWD") {
            availableBackwardBuses.enqueue(currentBus);
        }
        recentBuses.dequeue();


    }
}

void Stations::loadPassengers() {

    while (!availableForwardBuses.isEmpty()) {

        Bus* currentBus = availableForwardBuses.peek();

        if ((typeid(*currentBus).name() == "MBus")) {

            currentBus = new MBus(int capacity, currentBus->get_current(), currentBus->get_destination());


            while (!forwardSP.isEmpty()) {


                Passenger* currentPassenger = forwardSP.peek() ;
                currentBus->GetOn(currentPassenger);
                forwardSP.dequeue();




            }


            while (!forwardNP.isEmpty()) {


                Passenger* currentPassenger = forwardNP.peek();
                currentBus->GetOn(currentPassenger);
                forwardNP.dequeue();


            }



        }

        else {

            currentBus = new WBus(int capacity, currentBus->get_current(), currentBus->get_destination());

            while (!forwardWP.isEmpty()) {


                Passenger* currentPassenger = forwardWP.peek();
                currentBus->GetOn(currentPassenger);
                forwardWP.dequeue();

            }



        }



    }

   /* ////////////////////////////////availableBackwardBuses///////////////////////////////////////////////
    */
    while (!availableBackwardBuses.isEmpty()) {

        Bus* currentBus = availableBackwardBuses.peek();

        if ((typeid(*currentBus).name() == "MBus")) {

            currentBus = new MBus(int capacity, currentBus->get_current(), currentBus->get_destination());


                while (!forwardSP.isEmpty()) {


                    Passenger* currentPassenger = forwardSP.peek();
                        currentBus->GetOn(currentPassenger);
                        forwardSP.dequeue();




                }


            while (!forwardNP.isEmpty()) {


                Passenger* currentPassenger = forwardNP.peek();
                currentBus->GetOn(currentPassenger);
                forwardNP.dequeue();


            }



        }

        else {

            currentBus = new WBus(int capacity, currentBus->get_current(), currentBus->get_destination());

            while (!forwardWP.isEmpty()) {


                Passenger* currentPassenger = forwardWP.peek();
                currentBus->GetOn(currentPassenger);
                forwardWP.dequeue();

            }



        }



    }


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
