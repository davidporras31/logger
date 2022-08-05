
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
 enum containing all gravity for log
 */
enum LoggerGravity
{
	DEBUG,
	INFO,
	ERROR,
	FATAL
};
/**
 class use for log to the console and to file
 */
class Logger
{
public:
	Logger();
	~Logger();
	/**
	 * This is a function for dump log buffer in file if the Logger is configured to allow this
	*/
	void dump();
	/** 
	 * This is a function for add log in buffer, write in console and dump the buffer if the Logger is configured to allow this
	 *
	 * \param	gravity, the gravity of message
	 *
	 * \param	message, the message of log
	*/
	void log(LoggerGravity gravity, std::string message);

	/**
	 * This is a function for get the if the Logger dump its buffer log in a file
	 *
	 * \return	if the Logger dump to file
	*/
	bool getDumpToFile();
	/**
	 * This is a function for get the if the Logger automatically dump its buffer log
	 *
	 * \return	if the Logger automatically dump
	*/
	bool getAutoDump();
	/** 
	 * This is a function for get the current configured file path where the Logger dump its buffer
	 * 
	 * \return	the current file path where the Logger dump its buffer
	*/
	std::string getPathToFile();
	/** 
	 * This is a function for get the current configured size of the buffer before auto dump the log
	 *
	 * \return	the current configured size of the buffer before auto dump
	*/
	size_t getSizeToAutoDump();
	/**
	 * This is a function for get the current configured minimal gravity of log that will be written in the console
	 *
	 * \return	the current configue of the minimal gravity of log write in console
	*/
	LoggerGravity getMinToPrint();
	/**
	 * This is a function for get the current configured minimal gravity of log that will be written in file
	 *
	 * \return	the current configue of the minimal gravity of log write in file
	*/
	LoggerGravity getMinToLog();

	/**
	 * This is a function for configure if the Logger dump the buffer in file
	 *
	 * \param	dumpToFile, the new value
	*/
	void setDumpToFile(bool dumpToFile);
	/**
	 * This is a function for configure if the Logger auto dump the buffer
	 *
	 * \param	autoDump, the new value
	*/
	void setAutoDump(bool autoDump);
	/**
	 * This is a function for configure where the Logger dump
	 *
	 * \param	pathToFile, the path for log file
	*/
	void setPathToFile(std::string pathToFile);
	/**
	 * This is a function for configure the size of buffer to auto dump
	 *
	 * \param	sizeToAutoDump, the minimal size of buffer before auto dump
	*/
	void setSizeToAutoDump(size_t sizeToAutoDump);
	/**
	 * This is a function for changing the minimal gravity of log to write in console
	 *
	 * \param	minToPrint, the minimal gravity of log to write in console
	*/
	void setMinToPrint(LoggerGravity minToPrint);
	/**
	 * This is a function for changing the minimal gravity of log to write in log file
	 *
	 * \param	minToLog, the minimal gravity of log to write in log file
	*/
	void setMinToLog(LoggerGravity minToLog);

	/**
	 * This is a function for converting loggerGravity in string
	 *
	 * \return	the name in string of loggerGravity
	*/
	static std::string loggerGravityToString(LoggerGravity gravity);

private:
	bool dumpToFile;
	bool autoDump;
	std::string pathToFile;
	size_t sizeToAutoDump;
	LoggerGravity minToPrint;
	LoggerGravity minToLog;
	std::vector<std::string> buffer;
};

#endif // LOGGER_H