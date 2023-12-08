#include "Passenger.h"
#include "NormalPassenger.h"
using namespace std;

NormalPassenger::NormalPassenger(long int passengerID, int currentStation, int endStation, int priority, string busType, string passengerType, Time StationArrivalTime, Time GetOffBusTime, Time GetOnBusTime)
    : Passenger(passengerID, currentStation, endStation, priority, busType, passengerType, StationArrivalTime, GetOffBusTime, GetOnBusTime)
{}

int NormalPassenger::calcWT(Time busMoveTime, int agedPriority, int maxW) {
    Time WT = busMoveTime - getStationArrivalTime();
    int WTMin = (WT.getHour() * 60) + WT.getMinute() + (WT.getSecond() / 60);
    if (WTMin == maxW) changePriority(agedPriority);
    return WTMin;

}

void NormalPassenger::changeStatus(string status) {
    this->status = status;
}