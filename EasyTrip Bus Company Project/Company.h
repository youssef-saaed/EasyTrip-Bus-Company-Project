#pragma once

#include <fstream>
#include "Queue.h"
#include "Passenger.h"
#include "arrayList.h"
#include "Station.h"

class Company
{
private:
	std::ifstream* InputFileHandler;
	std::ofstream* OutputFileHandler;
	Queue<Passenger*> FinishedPassengers;
	arrayList<Station*> Stations;
};

