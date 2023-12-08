#include "MBus.h"
#include "PriorityQueue.h"



MBus::MBus(int capacity,int currentStation , int destination)
{
	passengers = new PriorityQueue<Passenger>(capacity);
	Finishedpassengers = new Queue<Passenger>(capacity);
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

void MBus::GetOff(Passenger*p)
{
	if (p->getEndStation() == currentStation)
	{
		p->leaveMBus(*passengers,*Finishedpassengers);
	}
}

void MBus::change_direction()
{
	direction = "BCW";
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



