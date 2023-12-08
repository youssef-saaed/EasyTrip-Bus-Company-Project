#include "MBus.h"
#include "PriorityQueue.h"



MBus::MBus(int capacity)
{
	passengers = new PriorityQueue<Passenger*>(capacity);
	direction = "FWD";
	currentStation = 0;
	destination = 1;
}

bool MBus::GetOn(Passenger* p)
{
	if (passengers->Enqueue(p, p->getPriority())) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

bool MBus::GetOff(Passenger*p)
{
	int priority;
	if (!passengers->IsEmpty()) {
		passengers->Dequeue(p , priority);
		return true;
	}
	else {
		return false;
	}
}

void MBus::setCurrent(int currentStation)
{
	this->currentStation = currentStation;
}

void MBus::setDestination(int destination)
{
	this->destination = destination;
}



void WBus::change_direction()
{
	direction = "BCW";
}