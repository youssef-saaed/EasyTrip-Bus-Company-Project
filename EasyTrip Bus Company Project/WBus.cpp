#include "WBus.h"
#include "Queue.h"


WBus::WBus(int capacity)
{
	passengers = new Queue<Passenger*>(capacity);
	direction = "FWD";
	currentStation = 0;
	destination = 1;
}

bool WBus::GetOn(Passenger* p)
{

	if (!passengers->isFull()) {
		passengers->enqueue(p);
		return true;
	}
	else {
		return false;
	}
}

bool WBus::GetOff()
{
	if (!passengers->isEmpty()) {
		passengers->dequeue();
		return true;
	}
	else {
		return false;
	}
}

void WBus::setCurrent(int currentStation)
{
	this->currentStation = currentStation;
}

void WBus::setDestination(int destination)
{
	this->destination = destination;
}

void WBus::change_direction()
{
	direction = "BCW";
}


