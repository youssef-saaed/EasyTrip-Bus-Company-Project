#include "Passenger.h"
using namespace std;

Passenger::Passenger()
{
    this->passengerID = 0;
    this->currentStation = 0;
    this->endStation = 0;
    this->priority = -1000;
    this->busType = "NA";
    this->direction = "NA";
    this->passengerType = "NA";
}

Passenger::Passenger(int passengerID, int currentStation, int endStation, int priority, string busType, string passengerType, string direction, Time StationArrivalTime, Time GetOffBusTime, Time GetOnBusTime) {
    this->passengerID = passengerID;
    this->currentStation = currentStation;
    this->endStation = endStation;
    this->priority = priority;
    this->busType = busType;
    this->direction = direction;
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

int Passenger::getPassengerID() {
    return this->passengerID;
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

string Passenger::getPassengerType() const{
    return this->passengerType;
}

string Passenger::getDirection() {
    return this->direction;
}

Time Passenger::getStationArrivalTime() const{
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

string Passenger::getStatus() const {
    return this->status;
}


void Passenger::changeStatus(string status) {
    this->status = status;
}

void Passenger::setWaitTime(Time waitTime) {
    this->WaitTime = waitTime;
}

Time Passenger::getWaitTime() const{
    return this->WaitTime;
}