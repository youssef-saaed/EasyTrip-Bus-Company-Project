#include "Company.h"
#include <iostream>
using namespace std;

Company::Company(std::string InputDirectory, std::string OutputDirectory) {
	InputFileHandler.open(InputDirectory);
	ReadInputFile();
	BusesEvents = new Queue<BusMoveEvent*>(NumberOfMBuses + NumberOfWBuses);
	currentTime = Time(4, 0, 0);
	initialize();
	/*OutputFileHandler.open(OutputDirectory);*/
}


Company::~Company() {
	InputFileHandler.close();
	/*OutputFileHandler.close();*/
}
void Company::Simulate() {
	//std::cout << currentTime.display() << "\n";
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
	((Stations*)StationsList->LookAt(1))->getAvailableForwardBuses().enqueue(MB);
	((Stations*)StationsList->LookAt(1))->getAvailableForwardBuses().enqueue(WB);
	while (!PassengersEvents->isEmpty() || !BusesEvents->isEmpty()) {
		std::cout << FinishedPassengers->size() << '\n';
		//std::cout << PEvent->getEventTime().display() << "\n";
		while (PassengersEvents->peek(PEvent) || PEvent->getEventTime() == currentTime) {
			PassengersEvents->dequeue(PEvent);
			//cout << "IN" << "\n";
			PEvent->Execute(*StationsList, *FinishedPassengers);
			//cout << "ex" << "\n";
		}
		//cout << BEvent->getEventTime().display() << "\n";
		Time BusEventTime = currentTime + BoardingTime;
		BEvent->setEventTime(BusEventTime);
		while (BusesEvents->peek(BEvent) && BEvent->getEventTime() == currentTime) {
			BusesEvents->dequeue(BEvent);
			BEvent->Execute(*StationsList, *FinishedPassengers);
			//cout << "ddd" << "\n";
		}
		currentTime = currentTime + 1;
		//std::cout << currentTime.display() << "\n";
		timeCounter++;
		if (timeCounter == 15) {
			timeCounter = 0;
			((StationZero*)StationsList->LookAt(0))->removeBusFromStation('M', MB);
			((StationZero*)StationsList->LookAt(0))->removeBusFromStation('W', WB);
			StationsList->LookAt(MB->get_current())->getRecentBuses()->enqueue(MB);
			StationsList->LookAt(WB->get_current())->getRecentBuses()->enqueue(WB);
		}
		//cout << "sss" << "\n";
		PassengerBoarding();
	}

}