#pragma once

#include <fstream>
#include "Queue.h"
#include "Passenger.h"
#include "arrayList.h"
#include "Station.h"
#include "PriorityQueue.h"
#include "Event.h"
#include "Events.h"

class Company
{
private:
	std::ifstream InputFileHandler;
	std::ofstream OutputFileHandler;
	Queue<Passenger*> FinishedPassengers;
	arrayList<Station*> Stations;
	PriorityQueue<Event*> Events;
	int NumberOfStation, NumberOfWBuses, NumberOfMBuses, TimeBetweenEachStation, WBusCapacity, MBusCapacity, NumOfTripsBeforeCheckup, WBusCheckupDur, MBusCheckupDur, MaxNormalPassengerWaiting, GetOnOffDur, NumOfEvents;
public:
	Company(std::string InputDirectory = "input.txt", std::string OutputDirectory = "output.txt");
	void ReadInputFile();
	void ProduceOutputFile();
	void Simulate();
	~Company();	
};

Company::Company(std::string InputDirectory = "input.txt", std::string OutputDirectory = "output.txt") {
	InputFileHandler.open(InputDirectory);
	OutputFileHandler.open(OutputDirectory);
}


Company::~Company() {
	InputFileHandler.close();
	OutputFileHandler.close();
}