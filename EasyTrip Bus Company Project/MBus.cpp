#include "MBus.h"
#include "PriorityQueue.h"



MBus::MBus(int capacity,int currentStation , int destination ,int maxStations)
{
	passengers = new PriorityQueue<Passenger>(capacity);
	direction = "FWD";
	this->currentStation = currentStation;
	this->destination = destination;
}

void MBus::GetOn(Passenger* p)
{
	if (p->getCurrentStation() == currentStation) {
		if (direction == "FWD")
		{
			passengers->Enqueue(*p, 1000-p->getEndStation());
		}
		else
		{
			passengers->Enqueue(*p, p->getEndStation());
		}
	}
}

void MBus::GetOff(Passenger*p, Queue<Passenger>& FinishedPassengers)
{
	if (p->getEndStation() == currentStation)
	{
		int _;
		passengers->Dequeue(*p, _);
		FinishedPassengers.enqueue(*p);
	}
}

void MBus::change_direction(int capacity ,int maxStations)
{
	direction = "BCW";
	passengers = new PriorityQueue<Passenger>(capacity);
}

void MBus::setCurrent(int currentStation)
{
	this->currentStation = currentStation;
}

void MBus::setDestination(int destination)
{
	this->destination = destination;
}

string MBus::get_direction()
{
	return direction;
}

int MBus::get_destination()
{
	return destination;
}



