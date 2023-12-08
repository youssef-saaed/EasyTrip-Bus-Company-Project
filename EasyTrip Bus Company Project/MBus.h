#pragma once
#include "Bus.h"
#include "PriorityQueue.h"
#include <string>
class MBus : public Bus
{
private:
	PriorityQueue<Passenger*> *passengers;
	string direction;
	int currentStation;
	int destination;
public:
	MBus(int capacity);
	bool GetOn(Passenger*);
	bool GetOff(Passenger*);
	void change_direction();
	void setCurrent(int currentStation);
	void setDestination(int destination);
};

