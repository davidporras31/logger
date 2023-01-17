
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

void SubLogger::log(LoggerGravity gravity, std::string message)
{
	this->logger->log(gravity, "[" + this->name + "] " + message);
}

bool SubLogger::getDumpToFile()
{
	return this->logger->getDumpToFile();
}

bool SubLogger::getAutoDump()
{
	return this->logger->getAutoDump();
}

std::string SubLogger::getPathToFile()
{
	return this->logger->getPathToFile();
}

size_t SubLogger::getSizeToAutoDump()
{
	return this->logger->getSizeToAutoDump();
}

LoggerGravity SubLogger::getMinToPrint()
{
	return this->logger->getMinToPrint();
}

LoggerGravity SubLogger::getMinToLog()
{
	return this->logger->getMinToLog();
}

void SubLogger::setDumpToFile(bool dumpToFile)
{
	this->logger->setDumpToFile(dumpToFile);
}

void SubLogger::setAutoDump(bool autoDump)
{
	this->logger->setAutoDump(autoDump);
}

void SubLogger::setPathToFile(std::string pathToFile)
{
	this->logger->setPathToFile(pathToFile);
}

void SubLogger::setSizeToAutoDump(size_t sizeToAutoDump)
{
	this->logger->setSizeToAutoDump(sizeToAutoDump);
}

void SubLogger::setMinToPrint(LoggerGravity minToPrint)
{
	this->logger->setMinToPrint(minToPrint);
}

void SubLogger::setMinToLog(LoggerGravity minToLog)
{
	this->logger->setMinToLog(minToLog);
}
