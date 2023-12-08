#include "Passenger.h"
using namespace std;

Passenger::Passenger(long int passengerID, int currentStation, int endStation, int priority, string busType, string passengerType, Time StationArrivalTime, Time GetOffBusTime, Time GetOnBusTime) {
    this->passengerID = passengerID;
    this->currentStation = currentStation;
    this->endStation = endStation;
    this->priority = priority;
    this->busType = busType;
    this->passengerType = passengerType;
    this->StationArrivalTime = StationArrivalTime;
}

void Passenger::setGetOnBusTime(Time getOnBusTime) {
    this->GetOnBusTime = getOnBusTime;
}

void Passenger::setGetOffBusTime(Time getOffBusTime) {
    this->GetOffBusTime = getOffBusTime;
}

void Passenger::setFinishTime(Time finishTime) {
    this->FinishTime = finishTime;
}

void Passenger::setTripTime(Time tripTime) {
    this->TripTime = tripTime;
}

void Passenger::changePriority(int priority) {
    this->priority = priority;
}

int Passenger::getCurrentStation() {
    return this->currentStation;
}

int Passenger::getEndStation() {
    return this->endStation;
}

string Passenger::getBusType() {
    return this->busType;
}

string Passenger::getPassengerType() {
    return this->passengerType;
}

Time Passenger::getStationArrivalTime() {
    return this->StationArrivalTime;
}

Time Passenger::getOnBusTime() {
    return this->GetOnBusTime;
}

Time Passenger::getOffBusTime() {
    return this->GetOffBusTime;
}

Time Passenger::getFinishTime() {
    return this->FinishTime;
}

Time Passenger::getTripTime() {
    return this->TripTime;
}

int Passenger::getPriority() {
    return this->priority;
}

void Passenger::passengerBoarding(PriorityQueue<Passenger>& q) {
    q.Enqueue(*this, priority);
}

//void Passenger::leavingBus(PriorityQueue<Passenger>& q, Queue<Passenger> &FinishedPassengers) {
//    q.Dequeue(*this, priority);
//    FinishedPassengers.enqueue(*this);
//}
//
void Passenger::calcFinishTime(Queue<Passenger> FinishedPassengersCopy, Time busArrivalTime) {
    Time gettingOffAllPassengersTime;
    while (!(FinishedPassengersCopy.size() == 1)) {
        gettingOffAllPassengersTime = gettingOffAllPassengersTime + FinishedPassengersCopy.dequeue()->data.getOffBusTime();
    }
    Time getOff = FinishedPassengersCopy.peek().GetOffBusTime;
    Time totalFT = gettingOffAllPassengersTime + busArrivalTime + getOff;
    FinishedPassengersCopy.dequeue()->data.setFinishTime(totalFT);
}

void Passenger::calcTripTime(Time busMoveTime) {
    Time TT = getFinishTime() - busMoveTime;
    setTripTime(TT);
}
