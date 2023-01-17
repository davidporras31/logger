
//********************************************************
// author David PORRAS
// date : 19/05/2021
// file: Logger.cpp
// class for log
//********************************************************
#include "Logger.h"

Logger::Logger()
{
	this->dumpToFile = false;
	this->autoDump = false;
	this->pathToFile = "";
	this->sizeToAutoDump = 0u;
	this->minToPrint = LoggerGravity::DEBUG;
	this->minToLog = LoggerGravity::DEBUG;
}

Logger::~Logger()
{
	this->dump();
}

void Logger::dump()
{
	if (this->dumpToFile)
	{
		std::ofstream file(this->pathToFile, std::ios::app);
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

void Logger::log(LoggerGravity gravity, std::string message)
{
	#ifndef _DEBUG
		if (gravity != loggerGravity::DEBUG)
		{
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
			if (gravity == LoggerGravity::ERROR)
				std::cerr << strLog;
			else
				std::cout << strLog;
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

std::string Logger::getPathToFile()
{
	return this->pathToFile;
}

size_t Logger::getSizeToAutoDump()
{
	return this->sizeToAutoDump;
}

LoggerGravity Logger::getMinToPrint()
{
	return this->minToPrint;
}

LoggerGravity Logger::getMinToLog()
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

void Logger::setPathToFile(std::string pathToFile)
{
	this->pathToFile = pathToFile;
}

void Logger::setSizeToAutoDump(size_t sizeToAutoDump)
{
	this->sizeToAutoDump = sizeToAutoDump;
}

void Logger::setMinToPrint(LoggerGravity minToPrint)
{
	this->minToPrint = minToPrint;
}

void Logger::setMinToLog(LoggerGravity minToLog)
{
	this->minToLog = minToLog;
}

std::string Logger::loggerGravityToString(LoggerGravity gravity)
{
	std::string ret;
	switch (gravity)
	{
	case LoggerGravity::DEBUG:
		ret = "DEBUG";
		break;
	case LoggerGravity::INFO:
		ret = "INFO";
		break;
	case LoggerGravity::ERROR:
		ret = "ERROR";
		break;
	case LoggerGravity::FATAL:
		ret = "FATAL";
		break;
	}
	return ret;
}