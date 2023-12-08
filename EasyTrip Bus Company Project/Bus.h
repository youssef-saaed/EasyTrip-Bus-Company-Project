#pragma once

#include "Passenger.h"

class Bus
{
public:
	virtual bool GetOn(Passenger* p) = 0;
	virtual bool GetOff(Passenger* p) = 0;
};

