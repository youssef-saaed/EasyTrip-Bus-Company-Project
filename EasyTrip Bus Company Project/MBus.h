#pragma once
#include "Bus.h"
#include "PriorityQueue.h"
class Passenger {

};
class MBus : public Bus
{
private:
	PriorityQueue <Passenger*> * passengers;
public:
	MBus();
	bool GetOn(Passenger*);
	bool GetOff(Passenger*);
};

