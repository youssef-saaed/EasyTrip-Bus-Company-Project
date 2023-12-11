#include "Company.h"

Company::Company(std::string InputDirectory, std::string OutputDirectory) {
	InputFileHandler.open(InputDirectory);
	OutputFileHandler.open(OutputDirectory);
}


Company::~Company() {
	InputFileHandler.close();
	OutputFileHandler.close();
}