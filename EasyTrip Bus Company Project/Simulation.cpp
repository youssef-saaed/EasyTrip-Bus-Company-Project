#include "Company.h"
using namespace std;
#include <iostream>

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
	while (Events!=nullptr){
		currentTime = currentTime + 1 ;
		Event* item;
		Events->Peak(item);
		
		if (item->getEventTime() == currentTime) {
			int priority;
			item->Execute(*Stations);
			if (item->getType() == 'A') {
				

			}
			if (item->getType() == 'L') {

			}
			Events->Dequeue(item, priority);
		}
	}
	
}