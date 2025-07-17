#include "OutputLogger.h"

OutputLogger::OutputLogger()
        : dumpToFile(true), autoDump(true), pathToFile("log.txt"), sizeToAutoDump(1024),
          minToPrint(Gravity::DEBUG), minToLog(Gravity::DEBUG) 
{
    this->buffer.reserve(1024);
}

OutputLogger::~OutputLogger()
{
    this->dump();
}

void OutputLogger::dump()
{
	if (this->dumpToFile)
	{
		std::ofstream file(this->pathToFile, std::ofstream::out | std::ofstream::app);
        if (!file.is_open())
        {
            throw std::runtime_error("Could not open log file: " + this->pathToFile);
        }
		while (this->buffer.size() != 0)
		{
			file << this->buffer.front();
			this->buffer.erase(this->buffer.begin());
		}
		file.close();
	}
	else
	{
		this->buffer.clear();
	}
}

void OutputLogger::log(Gravity gravity, std::string message)
{
	#ifndef _DEBUG
		if (gravity <= Gravity::DEBUG)
		{
            return;
        }
	#endif
    std::string strLog = "[" + loggerGravityToString(gravity) + "]" + message + "\n";
    if (gravity >= this->minToLog)
    {
        this->buffer.push_back(strLog);
        if (this->autoDump)
        {
            if (this->buffer.size() >= this->sizeToAutoDump)
            {
                dump();
            }
        }
    }
    if (gravity >= this->minToPrint)
    {
        if (gravity == Gravity::ERROR)
            std::cerr << strLog;
        else
            std::cout << strLog;
    }
}

void OutputLogger::setDumpToFile(bool dumpToFile)
{
	this->dumpToFile = dumpToFile;
}

void OutputLogger::setAutoDump(bool autoDump)
{
	this->autoDump = autoDump;
}

void OutputLogger::setPathToFile(std::string pathToFile)
{
	this->pathToFile = pathToFile;
}

void OutputLogger::setSizeToAutoDump(size_t sizeToAutoDump)
{
	this->sizeToAutoDump = sizeToAutoDump;
    this->buffer.reserve(sizeToAutoDump);
}

void OutputLogger::setMinToPrint(Gravity minToPrint)
{
	this->minToPrint = minToPrint;
}

void OutputLogger::setMinToLog(Gravity minToLog)
{
	this->minToLog = minToLog;
}
