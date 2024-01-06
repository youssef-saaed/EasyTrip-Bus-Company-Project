#include "Company.h"
using namespace std;

Company::Company(std::string InputDirectory, std::string OutputDirectory) {
	InputFileHandler.open(InputDirectory);
	ReadInputFile();
	BusesEvents = new Queue<BusMoveEvent*>(NumberOfMBuses + NumberOfWBuses);
	Time currentTime = Time(4, 0, 0);
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
	int timeCounter = 0;
	Bus* MB;
	Bus* WB;
	S02->removeBusFromStation('M', MB);
	S02->removeBusFromStation('W', WB);
	MB->setCurrent(1);
	WB->setCurrent(1);
	while (!PassengersEvents->isEmpty() && !BusesEvents->isEmpty()) {
		while (PassengersEvents->peek(PEvent) && PEvent->getEventTime() == currentTime) {
			PassengersEvents->dequeue(PEvent);
			PEvent->Execute(*StationsList, *FinishedPassengers);

		}
		/*while (BusesEvents->peek(BEvent) && BEvent->getEventTime() == currentTime) {
			BusesEvents->dequeue(BEvent);
			BEvent->Execute(*StationsList, *FinishedPassengers);
		}*/
		
		currentTime = currentTime + 1;
		timeCounter++;
		if (timeCounter == 15) {
			timeCounter = 0;
			S02->removeBusFromStation('M', MB);
			S02->removeBusFromStation('W', WB);
		}
	}
}