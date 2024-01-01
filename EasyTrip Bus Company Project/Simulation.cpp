#include "Company.h"
using namespace std;

Company::Company(std::string InputDirectory, std::string OutputDirectory) {
	InputFileHandler.open(InputDirectory);
	ReadInputFile();
	BusesEvents = new Queue<BusMoveEvent*>(NumberOfMBuses + NumberOfWBuses);
	Time currentTime = Time(4, 0, 0);
	FinishedPassengers = new Queue<Passenger*>(NumOfEvents);
	StationsList = new arrayList<Station*>(NumberOfStation + 1);
	StationsList->push(new StationZero(0, 100));
	for (int i = 0; i < NumberOfStation; i++)
	{
		StationsList->push(new Stations(i + 1, 100, 100));
	}
	/*OutputFileHandler.open(OutputDirectory);*/
}


Company::~Company() {
	InputFileHandler.close();
	/*OutputFileHandler.close();*/
}
void Company::Simulate() {
	Event* item;
	Events->Peak(item);
	while (!Events->IsEmpty()) {
		while (Events->Peak(item) && item->getEventTime() == currentTime) {
			int priority;
			item->Execute(*StationsList, *FinishedPassengers);
			Events->Dequeue(item, priority);
		}
		currentTime = currentTime + 1;

	}
}