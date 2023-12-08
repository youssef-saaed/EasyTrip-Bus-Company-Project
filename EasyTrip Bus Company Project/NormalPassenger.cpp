#include "Passenger.h"
#include "NormalPassenger.h"
using namespace std;

NormalPassenger::NormalPassenger(long int passengerID, int currentStation, int endStation, int priority, string busType, string passengerType, string direction, Time StationArrivalTime, Time GetOffBusTime, Time GetOnBusTime)
    : Passenger(passengerID, currentStation, endStation, priority, busType, passengerType, direction, StationArrivalTime, GetOffBusTime, GetOnBusTime)
{}

int NormalPassenger::calcWT(Time busMoveTime, Time now, int agedPriority, int maxW) {
    if (status == "moved") {
        Time WT = busMoveTime - getStationArrivalTime();
        int WTMin = (WT.getHour() * 60) + WT.getMinute() + (WT.getSecond() / 60);
        return WTMin;
    }
    else if (status == "waiting") {
        Time WT = now - getStationArrivalTime();
        int WTMin = (WT.getHour() * 60) + WT.getMinute() + (WT.getSecond() / 60);
        if (WTMin == maxW) changePriority(agedPriority);
        return WTMin;
    }
}

void NormalPassenger::changeStatus(string status) {
    this->status = status;
}