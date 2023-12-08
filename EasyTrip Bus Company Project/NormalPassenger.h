#pragma once

#include "Passenger.h"
using namespace std;

class NormalPassenger : public Passenger 
{
private:
    int maxW;
    Time waitTime;
    string status = "waiting";
    public:
    NormalPassenger(long int passengerID, int currentStation, int endStation, int priority, string busType, string passengerType, Time StationArrivalTime, Time GetOffBusTime, Time GetOnBusTime);
    void setwaitTime(Time waitTime); 
    void changeStatus(string status);
    int calcWT(Time busMoveTime, int agedPriority, int maxW);
};
