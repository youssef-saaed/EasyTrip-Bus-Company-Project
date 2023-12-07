#pragma once
#include "Bus.h"
#include "Queue.h"
class Passenger {

};
class WBus : public Bus
{
private:
	Queue <Passenger*> *passengers;
public:
	WBus();
	bool GetOn(Passenger*);
	bool GetOff();
};

