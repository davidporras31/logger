
//********************************************************
// author David PORRAS
// date : 19/05/2021
// file: Logger.cpp
// class for log
//********************************************************
#include "Logger.h"


std::string Logger::loggerGravityToString(Gravity gravity)
{
	std::string ret;
	switch (gravity)
	{
	case Gravity::DEBUG:
		ret = "DEBUG";
		break;
	case Gravity::INFO:
		ret = "INFO";
		break;
	case Gravity::ERROR:
		ret = "ERROR";
		break;
	case Gravity::FATAL:
		ret = "FATAL";
		break;
	}
	return ret;
}