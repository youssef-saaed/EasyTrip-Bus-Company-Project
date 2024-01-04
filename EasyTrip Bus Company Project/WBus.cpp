#include "WBus.h"
#include "Queue.h"


WBus::WBus(int capacity,int currentStation,int destination=0)
{
	passengers = new PriorityQueue<Passenger>(capacity);
	direction = "FWD";
	this->currentStation = currentStation;
	this->destination = destination;
}


void WBus::GetOn(Passenger* p)
{
	if (p->getCurrentStation() == currentStation) {
		if (direction == "FWD")
		{
			passengers->Enqueue(*p, 1000 - p->getEndStation());
		}
		else
		{
			passengers->Enqueue(*p, p->getEndStation());
		}
	}
}

void WBus::GetOff(Passenger* p)
{
	if (p->getEndStation() == currentStation)
	{
		int _;
		passengers->Dequeue(*p, _);
	}
}

void WBus::setCurrent(int currentStation)
{
	if (direction == "FWD") {
		currentStation++;
	}
	else {
		currentStation--;
	}
}

void WBus::setDestination(int destination)
{
	this->destination = destination;
}

void WBus::setBusId(int busID)
{
	this->busID = busID;
}

string WBus::get_direction()
{
	return direction;
}

int WBus::get_destination()
{
	return destination;
}

int WBus::get_current()
{
	return currentStation;
}

int WBus::getBusID()
{
	return busID;
}


