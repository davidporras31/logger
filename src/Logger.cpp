//********************************************************
// author David PORRAS
// date : 19/05/2021
// file: Logger.cpp
// class for log
//********************************************************
#include "../include/Logger.h"

Logger Logger::masterLogger;

Logger::~Logger()
{
	this->dump();
}

void Logger::dump()
{
	if (this->dumpToFile)
	{
		ofstream file(this->pathToFile, ios::app);
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

void Logger::log(loggerGravity gravity, string message)
{
	string strLog = "[" + loggerGravityToString(gravity) + "]" + message + "\n";
	#ifndef _DEBUG
	if(gravity != loggerGravity::DEBUG)
	{
	#endif
		if (gravity >= this->minToLog)
		{
			this->buffer.push_back(strLog);
			if (this->buffer.size() >= this->sizeToAutoDump)
			{
				if (this->autoDump)
				{
					dump();
				}
			}
		}
		if (gravity >= this->minToPrint)
		{
			cout << strLog;
		}
	#ifndef _DEBUG
	}
	#endif
}

bool Logger::getDumpToFile()
{
	return this->dumpToFile;
}

bool Logger::getAutoDump()
{
	return this->autoDump;
}

string Logger::getPathToFile()
{
	return this->pathToFile;
}

size_t Logger::getSizeToAutoDump()
{
	return this->sizeToAutoDump;
}

loggerGravity Logger::getMinToPrint()
{
	return this->minToPrint;
}

loggerGravity Logger::getMinToLog()
{
	return this->minToLog;
}

void Logger::setDumpToFile(bool dumpToFile)
{
	this->dumpToFile = dumpToFile;
}

void Logger::setAutoDump(bool autoDump)
{
	this->autoDump = autoDump;
}

void Logger::setPathToFile(string pathToFile)
{
	this->pathToFile = pathToFile;
}

void Logger::setSizeToAutoDump(size_t sizeToAutoDump)
{
	this->sizeToAutoDump = sizeToAutoDump;
}

void Logger::setMinToPrint(loggerGravity minToPrint)
{
	this->minToPrint = minToPrint;
}

void Logger::setMinToLog(loggerGravity minToLog)
{
	this->minToLog = minToLog;
}

Logger * Logger::getMasterLogger()
{
	return &masterLogger;
}

string Logger::loggerGravityToString(loggerGravity gravity)
{
	string ret;
	switch (gravity)
	{
	case loggerGravity::DEBUG:
		ret = "DEBUG";
		break;
	case loggerGravity::INFO:
		ret = "INFO";
		break;
	case loggerGravity::ERROR:
		ret = "ERROR";
		break;
	case loggerGravity::FATAL:
		ret = "FATAL";
		break;
	}
	return ret;
}
