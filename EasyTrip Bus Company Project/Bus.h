#pragma once

#include "Passenger.h"


class Bus
{
protected:
	string direction;
public:

	virtual void GetOn(Passenger* p) = 0;
	virtual void GetOff(Passenger* p) = 0;
	void change_direction();
	virtual void setCurrent(int station) = 0;
	virtual void setDestination(int station) = 0;
};

