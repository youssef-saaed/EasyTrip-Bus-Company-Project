#pragma once
#include "Bus.h"
#include "Queue.h"
#include <string>

class WBus : public Bus
{
private:
	Queue <Passenger*> *passengers;
	string direction;
	int currentStation;
	int destination;
public:
	WBus(int capacity);
	bool GetOn(Passenger*);
	bool GetOff();
	void change_direction();
	void setCurrent(int currentStation);
	void setDestination(int destination);
};

