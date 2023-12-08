#include "MBus.h"
#include "PriorityQueue.h"


MBus::MBus(int capacity)
{
	passengers = new PriorityQueue<Passenger*>(capacity);
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
