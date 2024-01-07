#include "Company.h"
#include <iostream>

Company::Company(std::string InputDirectory, std::string OutputDirectory) {
	InputFileHandler.open(InputDirectory);
	OutputFileHandler.open(OutputDirectory);
	ReadInputFile();
	BusesEvents = new Queue<BusMoveEvent*>(NumberOfMBuses + NumberOfWBuses);
	currentTime = Time(4, 0, 0);
	initialize();
}


Company::~Company() {
	InputFileHandler.close();
	ProduceOutputFile();
	OutputFileHandler.close();
}
void Company::Simulate() {
	
	BusMoveEvent *BEvent;
	PassengerEvent *PEvent;
	PassengersEvents->peek(PEvent);
	BusesEvents->peek(BEvent);
	int timeCounter = 0;
	Bus* MB;
	Bus* WB;
	((StationZero*)StationsList->LookAt(0))->removeBusFromStation('M', MB);
	((StationZero*)StationsList->LookAt(0))->removeBusFromStation('W', WB);
	StationsList->LookAt(1)->getRecentBuses()->enqueue(MB);
	StationsList->LookAt(1)->getRecentBuses()->enqueue(WB);
	StationsList->LookAt(1)->getRecentBuses()->enqueue(WB);
	((Stations*)StationsList->LookAt(1))->getAvailableForwardBuses()->enqueue(MB);
	((Stations*)StationsList->LookAt(1))->getAvailableForwardBuses()->enqueue(WB);
	while (!PassengersEvents->isEmpty() || !BusesEvents->isEmpty()) {
		for (int i = 1; i <= NumberOfStation; i++)
		{
			
			if (((Stations*)StationsList->LookAt(i))->getRecentBuses()->dequeue(MB))
			{
				WB = MB;
				if (MB->IsEmpty())
				{
					busyTime[MB->getBusID() - 1]++;
				}
				((Stations*)StationsList->LookAt(i))->getRecentBuses()->enqueue(MB);
				while (((Stations*)StationsList->LookAt(i))->getRecentBuses()->peek(MB) && MB != WB)
				{
					((Stations*)StationsList->LookAt(i))->getRecentBuses()->dequeue(MB);
					if (MB->IsEmpty())
					{
						busyTime[MB->getBusID() - 1]++;
					}
					((Stations*)StationsList->LookAt(i))->getRecentBuses()->enqueue(MB);

				}
			}

			auto fnpl = ((Stations*)StationsList->LookAt(i))->getForwardNP();
			auto fspl = ((Stations*)StationsList->LookAt(i))->getForwardSP();
			Passenger* p;
			while (fnpl->peek(p) && calcWT(Time(), currentTime, p) > MaxNormalPassengerWaiting)
			{
				fnpl->dequeue(p);
				p->changeStatus("moved");
				fspl->Enqueue(p, 4);
				NumberOfPromotedPassengers++;
			}
			auto bnpl = ((Stations*)StationsList->LookAt(i))->getBackwardNP();
			auto bspl = ((Stations*)StationsList->LookAt(i))->getBackwardSP();
			while (bnpl->peek(p) && calcWT(Time(), currentTime, p) > MaxNormalPassengerWaiting)
			{
				bnpl->dequeue(p);
				p->changeStatus("moved");
				bspl->Enqueue(p, 4);
				NumberOfPromotedPassengers++;
			}
		}
		PassengerBoarding();
		while (PassengersEvents->peek(PEvent) || PEvent->getEventTime() == currentTime) {
			PassengersEvents->dequeue(PEvent);
			PEvent->Execute(*StationsList, *FinishedPassengers);
		}
		Time BusEventTime = currentTime + BoardingTime;
		while (BusesEvents->peek(BEvent) && BEvent->getEventTime() == currentTime) {
			BusesEvents->dequeue(BEvent);
			BEvent->Execute(*StationsList, *FinishedPassengers, NumOfTripsBeforeCheckup, MBusCheckupDur, WBusCheckupDur);
		}
		Pair<Bus*, Time> p;
		while (((StationZero*)StationsList->LookAt(0))->getWBusCheckup()->peek(p) && p.B == currentTime)
		{
			((StationZero*)StationsList->LookAt(0))->getWBusCheckup()->dequeue(p);
			((StationZero*)StationsList->LookAt(0))->addBusToStation(p.A, 'W');
		}
		while (((StationZero*)StationsList->LookAt(0))->getMBusCheckup()->peek(p) && p.B == currentTime)
		{
			((StationZero*)StationsList->LookAt(0))->getMBusCheckup()->dequeue(p);
			((StationZero*)StationsList->LookAt(0))->addBusToStation(p.A, 'M');
		}
		currentTime = currentTime + 1;
		timeCounter++;
		if (timeCounter == 15) {
			timeCounter = 0;
			((StationZero*)StationsList->LookAt(0))->removeBusFromStation('M', MB);
			((StationZero*)StationsList->LookAt(0))->removeBusFromStation('W', WB);
			StationsList->LookAt(MB->get_current())->getRecentBuses()->enqueue(MB);
			StationsList->LookAt(WB->get_current())->getRecentBuses()->enqueue(WB);
		}		
	}

}