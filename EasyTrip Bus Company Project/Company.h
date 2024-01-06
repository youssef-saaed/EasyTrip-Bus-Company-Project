#pragma once

#include <fstream>
#include "Queue.h"
#include "Passenger.h"
#include "arrayList.h"
#include "Station.h"
#include "PriorityQueue.h"
#include "Event.h"
#include "Events.h"
#include "Time.h"
#include "Bus.h"
#include "MBus.h"
#include "WBus.h"

class Company
{
private:
	std::ifstream InputFileHandler;
	std::ofstream OutputFileHandler;
	Queue<Passenger*> *FinishedPassengers;
	arrayList<Station*> *StationsList;
	Queue<PassengerEvent*> *PassengersEvents;
	Queue<BusMoveEvent*> *BusesEvents;
	Queue<Bus*> *WBusCheckup;
	Queue<Bus*> *MBusCheckup;
	Queue<Bus*> *WBusMoving;
	Queue<Bus*> *MBusMoving;
	Time currentTime;
	int NumberOfStation, NumberOfWBuses, NumberOfMBuses, TimeBetweenEachStation, WBusCapacity, MBusCapacity, NumOfTripsBeforeCheckup, WBusCheckupDur, MBusCheckupDur, MaxNormalPassengerWaiting, GetOnOffDur, NumOfEvents;
	void PassengerBoarding();
public:
	Company(std::string InputDirectory = "input.txt", std::string OutputDirectory = "output.txt");
	void ReadInputFile();
	void initialize();
	void calcFinishTime(Time busArrivalTime, Passenger* p);
	void calcTripTime(Time busMoveTime, Passenger* p);
	int calcWT(Time busMoveTime, Time now, int agedPriority, int maxW, const Passenger p);
	void ProduceOutputFile();
	void Simulate();
	~Company();	
};
