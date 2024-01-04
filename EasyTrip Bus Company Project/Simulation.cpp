#include "Company.h"
using namespace std;

Company::Company(std::string InputDirectory, std::string OutputDirectory) {
	InputFileHandler.open(InputDirectory);
	ReadInputFile();
	BusesEvents = new Queue<BusMoveEvent*>(NumberOfMBuses + NumberOfWBuses);
	Time currentTime = Time(4, 0, 0);

	// FinishedPassengers = new Queue<Passenger*>(NumOfEvents);
	// StationsList = new arrayList<Station*>(NumberOfStation + 1);
	// StationsList->push(new StationZero(0, 100));
	// for (int i = 0; i < NumberOfStation; i++)
	// {
	// 	StationsList->push(new Stations(i + 1, 100, 100));
	// }

	initialize();

	/*OutputFileHandler.open(OutputDirectory);*/
}


Company::~Company() {
	InputFileHandler.close();
	/*OutputFileHandler.close();*/
}
void Company::Simulate() {
	BusMoveEvent *BEvent;
	PassengerEvent *PEvent;
	PassengersEvents->peek(PEvent);
	BusesEvents->peek(BEvent);
	while (!PassengersEvents->isEmpty() && !BusesEvents->isEmpty()) {
		while (PassengersEvents->peek(PEvent) && PEvent->getEventTime() == currentTime) {
			PassengersEvents->dequeue(PEvent);
			PEvent->Execute(*StationsList, *FinishedPassengers);
		}
		while (BusesEvents->peek(BEvent) && BEvent->getEventTime() == currentTime) {
			BusesEvents->dequeue(BEvent);
			BEvent->Execute(*StationsList, *FinishedPassengers);
		}
		currentTime = currentTime + 1;

	}
}