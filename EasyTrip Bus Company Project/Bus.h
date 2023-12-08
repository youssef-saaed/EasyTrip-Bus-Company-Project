#pragma once

#include "Passenger.h"


class Bus
{

public:

	virtual void GetOn(Passenger* p) = 0;
	virtual void GetOff(Passenger* p) = 0;
	virtual void change_direction() = 0;
	virtual void setCurrent(int station) = 0;
	virtual void setDestination(int station) = 0;
};

