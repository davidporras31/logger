
//********************************************************
// author David PORRAS
// date : 19/05/2021
// file: Logger.cpp
// class for log
//********************************************************
#include "Logger.h"


std::string Logger::gravityToString(Gravity gravity)
{
	const std::string gravityNames[4] = {"DEBUG", "INFO", "ERROR", "FATAL"};
	return gravityNames[gravity];
}