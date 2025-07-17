
//********************************************************
// author David PORRAS
// date : 19/05/2021
// file: Logger.h
// class for log
//********************************************************
#ifndef LOGGER_H
#define LOGGER_H

#include <vector>
#include <string>
#include <fstream>
#include <iostream>

/**
 class use for log to the console and to file
 */
class Logger
{
public:
	/**
	 enum containing all gravity for logging
	*/
	enum Gravity
	{
		DEBUG,
		INFO,
		ERROR,
		FATAL
	};
	/**
	 * This is a function for dump log buffer in file if the Logger is configured to allow this
	*/
	virtual void dump() = 0;
	/** 
	 * This is a function for add log in buffer, write in console and dump the buffer if the Logger is configured to allow this
	 *
	 * \param	gravity, the gravity of message
	 *
	 * \param	message, the message of log
	*/
	virtual void log(Gravity gravity, std::string message) = 0;

	/**
	 * This is a function for converting loggerGravity in string
	 *
	 * \return	the name in string of loggerGravity
	*/
	static std::string loggerGravityToString(Gravity gravity);

private:

};

#endif // LOGGER_H