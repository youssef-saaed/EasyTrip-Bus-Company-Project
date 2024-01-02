#pragma once
#include "Bus.h"
#include "PriorityQueue.h"
#include <string>

class MBus : public Bus
{
private:
	PriorityQueue<Passenger> *passengers;
	string direction;
	int currentStation;
	int destination;
public:
	MBus(int capacity, int currentStation, int destination=0);
	void GetOn(Passenger*p);
	void GetOff(Passenger*p );
	void setCurrent(int currentStation);
	void setDestination(int destination);
	string get_direction();
	int get_destination();
	int get_current();
};

