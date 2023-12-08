#pragma once
#include "Bus.h"
#include "PriorityQueue.h"

class MBus : public Bus
{
private:
	PriorityQueue<Passenger*> *passengers;
public:
	MBus(int capacity);
	bool GetOn(Passenger*);
	bool GetOff(Passenger*);
};

