#pragma once

#include "Passenger.h"
using namespace std;

class NormalPassenger : public Passenger 
{
    private:
    string status = "waiting";
    public:
    NormalPassenger(long int passengerID, int currentStation, int endStation, int priority, string busType, string passengerType, Time StationArrivalTime, Time GetOffBusTime, Time GetOnBusTime);
    void changeStatus(string status);
    int calcWT(Time busMoveTime, Time now, int agedPriority, int maxW);
};
