#pragma once
#include "Bus.h"
#include "Queue.h"
#include <string>

class WBus : public Bus
{
private:
	Queue <Passenger> *passengers;
	string direction;
	int currentStation;
	int destination;
public:
	WBus(int capacity, int currentStation, int destination);
	void GetOn(Passenger*p);
	void GetOff(Passenger* p, Queue<Passenger>& FinishedPassengers);
	void change_direction();
	void setCurrent(int currentStation);
	void setDestination(int destination);
	string get_direction();
	int get_destination();
};

