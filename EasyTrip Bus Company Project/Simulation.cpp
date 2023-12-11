#include "Company.h"
using namespace std;

Company::Company(std::string InputDirectory, std::string OutputDirectory) {
	InputFileHandler.open(InputDirectory);
	ReadInputFile();
	Time currentTime = Time(4, 0, 0);
	FinishedPassengers = new Queue<Passenger*>(NumOfEvents);
	Stations = new arrayList<Station*>(NumberOfStation);
	/*OutputFileHandler.open(OutputDirectory);*/
}


Company::~Company() {
	InputFileHandler.close();
	/*OutputFileHandler.close();*/
}
void Company::Simulate() {
	Event* item;
	Events->Peak(item);
	while (item) {
		if (Events->Peak(item) && item->getEventTime() == currentTime) {
			int priority;
			item->Execute(*Stations, *FinishedPassengers);
			Events->Dequeue(item, priority);
			continue;
		}
		currentTime = currentTime + 1;
	}
}