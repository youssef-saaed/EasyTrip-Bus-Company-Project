#include "WBus.h"
#include "Queue.h"


WBus::WBus()
{
	Queue<Passenger*>* passengers = new Queue<Passenger*>(60);
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
