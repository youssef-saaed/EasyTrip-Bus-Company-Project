#pragma once

#include "Time.h"
#include "PriorityQueue.h"
#include "Queue.h"
#include "PriorityQueue2D.h"
using namespace std; 

class Passenger {
    private:
    int passengerID;
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
    Passenger(int passengerID, int currentStation, int endStation, int priority, string busType, string passengerType, string direction, Time StationArrivalTime, Time GetOffBusTime=0, Time GetOnBusTime=0);
    void setGetOnBusTime(Time getOnBusTime);
    void setGetOffBusTime(Time getOnBusTime);
    void setFinishTime(Time finishTime);
    void setTripTime(Time tripTime);
    void setWaitTime(Time waitTime);
    void changePriority(int priority);
    int getPassengerID();
    int getCurrentStation();
    int getEndStation();
    string getBusType();
    string getPassengerType();
    string getDirection();
    Time getStationArrivalTime();
    Time getOnBusTime();
    Time getOffBusTime();
    Time getFinishTime();
    Time getTripTime();
    Time getWaitTime();
    int getPriority();
    void BoardMBus(PriorityQueue2D<Passenger>& MBusQ);
    void BoardWBus(Queue<Passenger>& WBusQ);
    void leaveMBus(PriorityQueue2D<Passenger>& MBusQ, Queue<Passenger> &FinishedPassengers);
    void leaveWBus(Queue<Passenger>& WBusQ, Queue<Passenger> &FinishedPassengers);
    void calcFinishTime(Queue<Passenger> FinishedPassengersCopy, Time busArrivalTime);
    void calcTripTime(Time busMoveTime);
    int calcWT(Time busMoveTime, Time now, int agedPriority, int maxW);
    void changeStatus(string status);
};
