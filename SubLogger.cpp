
//********************************************************
// author David PORRAS
// date : 05/08/2022
// file: SubLogger.h
// class for log
//********************************************************
#include "SubLogger.h"

SubLogger::SubLogger(Logger* master, std::string name)
{
	this->logger = master;
	this->name = name;
}
void SubLogger::dump()
{
	this->logger->dump();
}

void SubLogger::log(Gravity gravity, std::string message)
{
	this->logger->log(gravity, "[" + this->name + "] " + message);
}