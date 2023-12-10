#include "MBus.h"
#include "PriorityQueue.h"



MBus::MBus(int capacity,int currentStation , int destination ,int maxStations)
{
	passengers = new PriorityQueue2D<Passenger>(capacity, maxStations);
	direction = "FWD";
	this->currentStation = currentStation;
	this->destination = destination;
}

void MBus::GetOn(Passenger* p)
{
	if (p->getCurrentStation() == currentStation) {
		p->BoardMBus(*passengers);
	}
}

void MBus::GetOff(Passenger*p, Queue<Passenger>& FinishedPassengers)
{
	if (p->getEndStation() == currentStation)
	{
		p->leaveMBus(*passengers,FinishedPassengers);
	}
}

void MBus::change_direction(int capacity ,int maxStations)
{
	direction = "BCW";
	passengers = new PriorityQueue2D<Passenger>(capacity, maxStations, true);
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



