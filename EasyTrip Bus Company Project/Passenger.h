#pragma once

#include "Time.h"
#include "PriorityQueue.h"
#include "Queue.h"
using namespace std; 

class Passenger {
    private:
    long int passengerID;
    int currentStation;
    int endStation;
    int priority;
    string busType;
    string passengerType;
    Time StationArrivalTime;
    Time GetOnBusTime;
    Time GetOffBusTime;
    Time FinishTime;
    Time TripTime;
    public:
    Passenger(long int passengerID, int currentStation, int endStation, int priority, string busType, string passengerType, Time StationArrivalTime, Time GetOffBusTime=0, Time GetOnBusTime=0);
    void setGetOnBusTime(Time getOnBusTime);
    void setGetOffBusTime(Time getOnBusTime);
    void setFinishTime(Time finishTime);
    void setTripTime(Time tripTime);
    void changePriority(int priority);
    int getCurrentStation();
    int getEndStation();
    string getBusType();
    string getPassengerType();
    Time getStationArrivalTime();
    Time getOnBusTime();
    Time getOffBusTime();
    Time getFinishTime();
    Time getTripTime();
    int getPriority();
    void passengerBoarding(PriorityQueue<Passenger>& q);
    /*void leavingBus(PriorityQueue<Passenger>& q, Queue<Passenger> &FinishedPassengers);*/
    void calcFinishTime(Queue<Passenger> FinishedPassengersCopy, Time busArrivalTime);
    void calcTripTime(Time busMoveTime);
};
