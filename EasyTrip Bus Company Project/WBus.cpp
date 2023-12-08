#include "WBus.h"
#include "Queue.h"


WBus::WBus(int capacity,int currentStation,int destination)
{
	passengers = new Queue<Passenger>(capacity);
	Finishedpassengers = new Queue<Passenger>(capacity);
	direction = "FWD";
	this->currentStation = currentStation;
	this->destination = destination;
}

void WBus::GetOn(Passenger* p)
{
	if (p->getCurrentStation() == currentStation) {
		p->BoardWBus(*passengers);
	}

}

void WBus::GetOff(Passenger* p)
{
	if (p->getEndStation() == currentStation) {
		p->leaveWBus(*passengers, *Finishedpassengers);
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

string WBus::get_direction()
{
	return direction;
}

int WBus::get_destination()
{
	return destination;
}

void WBus::change_direction()
{
	direction = "BCW";
}


