#include "Bus.h"

int Bus::count = 0;

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
	count++;
	tripCount = 0;
	totalNumberOfPassengers = 0;
	passengers = new DirPriorityQueue<Passenger*>(capacity, 10);
	direction = "FWD";
	this->currentStation = currentStation;
	this->destination = currentStation + 1;
	busID = count;
}

bool Bus::IsEmpty()
{
	return passengers->IsEmpty();
}

void Bus::AddOneTrip()
{
	tripCount++;
}

int Bus::getTripCount()
{
	return tripCount;
}

void Bus::GetOn(Passenger* p)
{
	if (p->getCurrentStation() == currentStation) {
		if (direction == "FWD")
		{
			passengers->Enqueue(p, p->getEndStation()) ? totalNumberOfPassengers++ : totalNumberOfPassengers;
		}
		else
		{
			passengers->Enqueue(p, p->getEndStation()) ? totalNumberOfPassengers++ : totalNumberOfPassengers;
		}
	}
}

bool Bus::GetOff(Passenger *&p)
{
	if (passengers->Peak(p) && p->getEndStation() == currentStation)
	{
		int _;
		passengers->Dequeue(p, _);
		return true;
	}
	return false;
}


void Bus::setCurrent()
{
	if (direction == "FWD") {
		this->currentStation++;
		this->destination = currentStation + 1;
	}
	else {
		this->currentStation--;
		this->destination = currentStation - 1;
		if (currentStation == 0)
		{
			tripCount++;
		}
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