#pragma once

#include "Time.h"
#include "PriorityQueue.h"
#include "Queue.h"
using namespace std; 

class Passenger {
private:
    int passengerID;
    int busID;
    int currentStation;
    int endStation;
    int priority;
    string busType;
    string passengerType;
    string direction;
    Time StationArrivalTime;
    Time GetOnBusTime;
    Time GetOffBusTime;
    Time FinishTime;
    Time TripTime;
    Time WaitTime;
    string status = "waiting";
public:
    Passenger();
    Passenger(int passengerID, int currentStation, int endStation, int priority, string busType, string passengerType, string direction, Time StationArrivalTime, Time GetOffBusTime=0, Time GetOnBusTime=0);
    void setBusID(int busID);
    void setGetOnBusTime(Time getOnBusTime);
    void setGetOffBusTime(Time getOnBusTime);
    void setFinishTime(Time finishTime);
    void setTripTime(Time tripTime);
    void setWaitTime(Time waitTime);
    void changePriority(int priority);
    int getPassengerID();
    int getBusID();
    int getCurrentStation();
    int getEndStation();
    string getBusType();
    string getPassengerType() const;
    string getDirection();
    Time getStationArrivalTime() const;
    Time getOnBusTime();
    Time getOffBusTime();
    Time getFinishTime();
    Time getTripTime();
    Time getWaitTime() const;
    int getPriority();
    /*void calcFinishTime(Queue<Passenger> FinishedPassengersCopy, Time busArrivalTime);*/
    void calcTripTime(Time busMoveTime);
    /*int calcWT(PriorityQueue<Passenger>& WaitingPassengers, Time busMoveTime, Time now, int agedPriority, int maxW);*/
    string getStatus() const;

    void changeStatus(string status);
};
