#pragma once

#include "Passenger.h"
using namespace std;

<<<<<<< HEAD
class NormalPassenger : public Passenger {
    private:
=======
class NormalPassenger : public Passenger 
{
private:
    int maxW;
>>>>>>> 9dfdb5fa042d3f3e60acd68bd632b4365bf020e6
    Time waitTime;
    string status = "waiting";
    public:
    NormalPassenger(long int passengerID, int currentStation, int endStation, int priority, string busType, string passengerType, Time StationArrivalTime, Time GetOffBusTime, Time GetOnBusTime);
    void setwaitTime(Time waitTime); 
    void changeStatus(string status);
    int calcWT(Time busMoveTime, int agedPriority, int maxW);
};
