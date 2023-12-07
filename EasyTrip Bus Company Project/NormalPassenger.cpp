#include "Passenger.h"
#include "NormalPassenger.h"
using namespace std;

NormalPassenger::NormalPassenger(int maxW, int currentStation, int endStation, int priority, string busType, string passengerType, Time StationArrivalTime, Time GetOffBusTime, Time GetOnBusTime)
    : Passenger(currentStation, endStation, priority, busType, passengerType, StationArrivalTime, GetOffBusTime, GetOnBusTime)
{
    this->maxW = maxW;
}

void NormalPassenger::setwaitTime(Time waitTime) {
    this->waitTime = waitTime;
}

Time NormalPassenger::getWaitTime() {
    return this->waitTime;
}

int NormalPassenger::getMaxW() {
    return this->maxW;
}

void NormalPassenger::calcWT(Time busMoveTime, int agedPriority) {
    Time WT = busMoveTime - getStationArrivalTime();
    setwaitTime(WT);
    int WTMin = (WT.getHour() * 60) + WT.getMinute() + (WT.getSecond() / 60);
    if (WTMin == getMaxW()) changePriority(agedPriority);
}

void NormalPassenger::changeStatus(string status) {
    this->status = status;
}