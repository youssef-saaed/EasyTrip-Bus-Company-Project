#pragma once
#include "Bus.h"
#include "Queue.h"
#include <string>

class WBus : public Bus
{
public:
	WBus(int capacity, int currentStation, int destination=0);
};

