#include "Company.h"


Company::Company(std::string InputDirectory, std::string OutputDirectory) {
	InputFileHandler.open(InputDirectory);
	ReadInputFile();
	Time currentTime = Time(4, 0, 0);
	FinishedPassengers = new Queue<Passenger*>(500);
	Stations = new arrayList<Station*>(NumberOfStation);
	Events = new PriorityQueue<Event*>(NumOfEvents);
	OutputFileHandler.open(OutputDirectory);
	

}


Company::~Company() {
	InputFileHandler.close();
	OutputFileHandler.close();
}
void Company::Simulate() {
	for (int i = 0; i < 60; i++) {
		currentTime = currentTime + 1 ;
		if ()
	}
	
}