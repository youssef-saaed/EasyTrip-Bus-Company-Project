#include "Bus.h"

void Bus::change_direction()
{
	if (direction == "FWD") {
		direction = "BCW";
	}
	else {
		direction = "FWD";
	}
}
