#pragma once
#include "Bus.h"
#include "PriorityQueue.h"
#include <string>
#include "PriorityQueue2D.h"

class MBus : public Bus
{
private:
	PriorityQueue2D<Passenger> *passengers;
	Queue<Passenger>* Finishedpassengers;
	string direction;
	int currentStation;
	int destination;
public:
	MBus(int capacity, int currentStation, int destination, int maxStations);
	void GetOn(Passenger*p);
	void GetOff(Passenger*p);
	void change_direction(int capacity, int maxStations);
	void setCurrent(int currentStation);
	void setDestination(int destination);
	string get_direction();
	int get_destination();
};

