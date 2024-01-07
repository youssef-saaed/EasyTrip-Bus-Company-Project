#pragma once

#include "Passenger.h"
#include "DirPriorityQueue.h"

class Bus
{
protected:
	static int count;
	string direction;
	DirPriorityQueue <Passenger*>* passengers;
	int tripCount;
	int currentStation;
	int destination;
	int busID;
	int totalNumberOfPassengers;
public:
	Bus(int capacity, int currentStation, int destination);
	bool IsEmpty();
	void AddOneTrip();
	int getTripCount();
	void change_direction();
	void GetOn(Passenger* p);
	bool GetOff(Passenger *&p);
	void setCurrent();
	void setDestination(int destination);
	void setBusId(int busID);
	string get_direction();
	int get_destination();
	int get_current();
	int getBusID();
};

