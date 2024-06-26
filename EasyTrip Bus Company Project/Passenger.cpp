#include "Passenger.h"
using namespace std;

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

string Passenger::getPassengerType() {
    return this->passengerType;
}

string Passenger::getDirection() {
    return this->direction;
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

void Passenger::BoardMBus(PriorityQueue2D<Passenger>& MBusQ) {
    MBusQ.Enqueue2D(*this, currentStation , priority);
}

void Passenger::BoardWBus(Queue<Passenger>& WBusQ) {
    WBusQ.enqueue(*this);
}

void Passenger::leaveMBus(PriorityQueue2D<Passenger>& MBusQ, Queue<Passenger> &FinishedPassengers) {
    MBusQ.Dequeue2D(*this, endStation , priority);
    FinishedPassengers.enqueue(*this);
}

void Passenger::leaveWBus(Queue<Passenger>& WBusQ, Queue<Passenger> &FinishedPassengers) {
    WBusQ.dequeueSpecificElement(*this);
    FinishedPassengers.enqueue(*this);
}

void Passenger::calcFinishTime(Queue<Passenger> FinishedPassengersCopy, Time busArrivalTime) {
    Time gettingOffAllPassengersTime;
    while (!(FinishedPassengersCopy.size() == 1)) {
        gettingOffAllPassengersTime = gettingOffAllPassengersTime + FinishedPassengersCopy.dequeue()->data.getOffBusTime();
    }
    Time getOff = FinishedPassengersCopy.peek().GetOffBusTime;
    Time totalFT = gettingOffAllPassengersTime + busArrivalTime + getOff;
    setFinishTime(totalFT);
    FinishedPassengersCopy.dequeue();
}

void Passenger::calcTripTime(Time busMoveTime) {
    Time TT = getFinishTime() - busMoveTime;
    setTripTime(TT);
}

int Passenger::calcWT(PriorityQueue2D<Passenger>& WaitingPassengers, Time busMoveTime, Time now, int agedPriority, int maxW) {
    if (status == "moved") {
        Time WT = busMoveTime - getStationArrivalTime();
        int WTMin = (WT.getHour() * 60) + WT.getMinute() + (WT.getSecond() / 60);
        setWaitTime(WT);
        return WTMin;
    }
    else if (status == "waiting") {
        Time WT = now - getStationArrivalTime();
        int WTMin = (WT.getHour() * 60) + WT.getMinute() + (WT.getSecond() / 60);
        if ((WTMin >= maxW) && getPassengerType() == "NP") changePriority(agedPriority);
        setWaitTime(WT);
        WaitingPassengers.Dequeue2D(*this, endStation, priority);
        WaitingPassengers.Enqueue2D(*this, currentStation, priority);
        return WTMin;
    }
}

void Passenger::changeStatus(string status) {
    this->status = status;
}

void Passenger::setWaitTime(Time waitTime) {
    this->WaitTime = waitTime;
}

Time Passenger::getWaitTime() {
    return this->WaitTime;
}