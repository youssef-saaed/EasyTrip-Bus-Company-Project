#pragma once

#include "Passenger.h"


class Bus
{

public:

	virtual bool GetOn(Passenger* p) = 0;
	virtual bool GetOff(Passenger* p) = 0;
	virtual void change_direction() = 0;
	virtual void setCurrent(int station) = 0;
	virtual void setDestination(int station) = 0;
};

