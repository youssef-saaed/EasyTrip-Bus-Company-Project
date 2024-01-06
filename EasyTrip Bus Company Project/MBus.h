#pragma once
#include "Bus.h"
#include "PriorityQueue.h"
#include <string>

class MBus : public Bus
{
public:
	MBus(int capacity, int currentStation, int destination=0);

};

