#pragma once

#include <iostream>
#include "Passenger.h"
using namespace std;

class NormalPassenger : public Passenger {
    private:
    int maxW;
    Time waitTime;
    int waitTimeMin;
    string status = "waiting";
    public:
    NormalPassenger(int maxW, int currentStation, int endStation, int priority, string busType, string passengerType, Time StationArrivalTime, Time GetOffBusTime=0, Time GetOnBusTime=0);
    void setwaitTime(Time waitTime);
    Time getWaitTime(); 
    int getMaxW();
    void changeStatus(string status);
    void calcWT(Time busMoveTime, int agedPriority);
};