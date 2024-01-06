#pragma once

#include "Passenger.h"


class Bus
{
protected:
	static int count;
	string direction;
	PriorityQueue <Passenger*>* passengers;
	int currentStation;
	int destination;
	int busID;
public:
	Bus(int capacity, int currentStation, int destination);
	void change_direction();
	void GetOn(Passenger* p);
	void GetOff(Passenger *&p);
	void setCurrent(int currentStation);
	void setDestination(int destination);
	void setBusId(int busID);
	string get_direction();
	int get_destination();
	int get_current();
	int getBusID();
};

