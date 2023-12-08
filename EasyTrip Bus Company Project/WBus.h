#pragma once
#include "Bus.h"
#include "Queue.h"

class WBus : public Bus
{
private:
	Queue <Passenger*> *passengers;
public:
	WBus(int capacity);
	bool GetOn(Passenger*);
	bool GetOff();
};

