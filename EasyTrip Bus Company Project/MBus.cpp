#include "MBus.h"
#include "PriorityQueue.h"


MBus::MBus()
{
	PriorityQueue<Passenger*>*passengers = new PriorityQueue<Passenger*>(60);
}

bool MBus::GetOn( Passenger* p)
{
	if (passengers->Enqueue(p, p->calculatePriority())) {
		return true;
	}
	else {
		return false;
	}
}

bool MBus::GetOff(Passenger*p)
{
	if (!passengers->IsEmpty()) {
		passengers->Dequeue( p , p->calculatePriority());
		return true;
	}
	else {
		return false;
	}
}
