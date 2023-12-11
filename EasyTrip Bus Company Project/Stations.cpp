#include "Station.h"
#include "Stations.h"

Stations::Stations(int number, int numberOfBusesAvailable, int numberOfBuses, int numOfAvailableForwardBuses, int numOfAvailableBackwardBuses, int numOfRecentBuses, int NumOfWaitingPassengers) : Station(number, numberOfBusesAvailable, numberOfMovedBuses), NumOfAvailableForwardBuses(numOfAvailableForwardBuses), NumOfAvailableBackwardBuses(numOfAvailableBackwardBuses), NumOfRecentBuses(numOfRecentBuses) , NumOfWaitingPassengers(NumOfWaitingPassengers) , availableForwardBuses(NumOfAvailableForwardBuses), availableBackwardBuses(NumOfAvailableBackwardBuses), recentBuses(NumOfRecentBuses), forwardNP(NumOfWaitingPassengers), backwardNP(NumOfWaitingPassengers), forwardWP(NumOfWaitingPassengers), backwardWP(NumOfWaitingPassengers), forwardPOD(NumOfWaitingPassengers), backwardPOD(NumOfWaitingPassengers), forwardAged(NumOfWaitingPassengers), backwardAged(NumOfWaitingPassengers), forwardPregnant(NumOfWaitingPassengers), backwardPregnant(NumOfWaitingPassengers)
{
};

Queue<Bus*> Stations::getAvailableForwardBuses() const {
    return availableForwardBuses;
}

Queue<Bus*> Stations::getAvailableBackwardBuses() const {
    return availableBackwardBuses;
}

void Stations::addPassengerToStation(Passenger* passenger) {
    NumOfWaitingPassengers++;
    if(passenger->)
}

bool Stations::RemovePassengerFromStation(int id)
{
    
}

void Stations::addRecentBus(Bus* bus) {
    NumOfRecentBuses++ ;
    recentBuses.enqueue(bus);
}

void Stations::SetNumOfAvailableForwardBuses(int numOfAvailableForwardBuses) {
    NumOfAvailableForwardBuses = numOfAvailableForwardBuses;
}

void Stations::SetNumOfAvailableBackwardBuses(int numOfAvailableBackwardBuses) {
    NumOfAvailableBackwardBuses = numOfAvailableBackwardBuses;
}

void Stations::SetNumOfRecentBuses(int numOfRecentBuses) {
    NumOfRecentBuses = numOfRecentBuses;
}

void Stations::SetNumOfWaitingPassengers(int numOfWaitingPassengers) {
    NumOfWaitingPassengers = numOfWaitingPassengers;
}


int Stations::GetNumOfAvailableForwardBuses() const {
    return NumOfAvailableForwardBuses;
}

int Stations::GetNumOfAvailableBackwardBuses() const {
    return NumOfAvailableBackwardBuses;
}

int Stations::GetNumOfRecentBuses() const {
    return NumOfRecentBuses;
}

int Stations::GetNumOfWaitingPassengers() const {
    return NumOfWaitingPassengers;
}
