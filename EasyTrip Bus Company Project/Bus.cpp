#include "Bus.h"

void Bus::change_direction()
{
	if (direction == "FWD") {
		direction = "BCW";
	}
	else {
		direction = "FWD";
	}
}

Bus::Bus(int capacity, int currentStation, int destination)
{
	passengers = new PriorityQueue<Passenger*>(capacity);
	direction = "FWD";
	this->currentStation = currentStation;
	this->destination = destination;
}

void Bus::GetOn(Passenger* p)
{
	if (p->getCurrentStation() == currentStation) {
		if (direction == "FWD")
		{
			passengers->Enqueue(p, 1000 - p->getEndStation());
		}
		else
		{
			passengers->Enqueue(p, p->getEndStation());
		}
	}
}

void Bus::GetOff(Passenger *&p)
{
	if (passengers->Peak(p) && p->getEndStation() == currentStation)
	{
		int _;
		passengers->Dequeue(p, _);
	}
}


void Bus::setCurrent(int currentStation)
{
	if (direction == "FWD") {
		currentStation++;
	}
	else {
		currentStation--;
	}
}

void Bus::setDestination(int destination)
{
	this->destination = destination;
}

void Bus::setBusId(int busID)
{
	this->busID = busID;
}

string Bus::get_direction()
{
	return direction;
}

int Bus::get_destination()
{
	return destination;
}

int Bus::get_current()
{
	return currentStation;
}

int Bus::getBusID()
{
	return busID;
}