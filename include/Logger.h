//********************************************************
// author David PORRAS
// date : 19/05/2021
// file: Logger.h
// class for log
//********************************************************
#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

enum loggerGravity
{
	DEBUG,
	INFO,
	ERROR,
	FATAL
};

class Logger
{
public:
	~Logger();
	/** \brief This is a function for dump log buffer in file
	 *
	 * This is a function for dump log buffer in file if configue allow this
	*/
	void dump();
	/** \brief This is a function for add log in buffer and write in console
	 *
	 * \param	gravity, the gravity of message
	 *
	 * \param	message, the message of log 
	 *
	 * This is a function for add log in buffer, write in console and dump the buffer if configue allow this
	*/
	void log(loggerGravity gravity, string message);
	/** \brief This is a function for add log in buffer and write in console, it's for log float value
	 *
	 * \param	gravity, the gravity of message
	 *
	 * \param	message, the message of log
	 *
	 * \param	value, the value of variable  
	 *
	 * This is a function for add log in buffer, write in console and dump the buffer if configue allow this, it's for log float value
	*/
	void log(loggerGravity gravity, string message, flaot value);

	/** \brief This is a function for get the current configue of the dump in file
	 *
	 * \return	the current configue of the auto dump in file
	 *
	 * This is a function for get the current configue of the auto dump in file
	*/
	bool getDumpToFile();
	/** \brief This is a function for get the current configue of the auto dump
	 *
	 * \return	the current configue of the auto dump
	 *
	 * This is a function for get the current configue of the auto dump
	*/
	bool getAutoDump();
	/** \brief This is a function for get the current path of the log file
	 *
	 * \return	the current path of the log file
	 *
	 * This is a function for get the current path of the log file
	*/
	string getPathToFile();
	/** \brief This is a function for get the current configue of the buffer size before auto dump
	 *
	 * \return	the current configue of the buffer size before auto dump
	 *
	 * This is a function for get the current configue of the buffer size before auto dump
	*/
	size_t getSizeToAutoDump();
	/** \brief This is a function for get the current configue of the minimal gravity of log write in console
	 *
	 * \return	the current configue of the minimal gravity of log write in console
	 *
	 * This is a function for get the current configue of the minimal gravity of log write in console
	*/
	loggerGravity getMinToPrint();
	/** \brief This is a function for get the current configue of the minimal gravity of log write in file
	 *
	 * \return	the current configue of the minimal gravity of log write in file
	 *
	 * This is a function for get the current configue of the minimal gravity of log write in file
	*/
	loggerGravity getMinToLog();

	/** \brief This is a function for configue the auto dump of buffer in file
	 *
	 * \param	dumpToFile, the new value
	 *
	 * This is a function for configue the auto dump of buffer in file
	*/
	void setDumpToFile(bool dumpToFile);
	/** \brief This is a function for configue the auto dump of buffer
	 *
	 * \param	autoDump, the new value
	 *
	 * This is a function for configue the auto dump of buffer
	*/
	void setAutoDump(bool autoDump);
	/** \brief This is a function for changing the path for log file
	 *
	 * \param	pathToFile, the path for log file
	 *
	 * This is a function for changing the path for log file
	*/
	void setPathToFile(string pathToFile);
	/** \brief This is a function for changing the minimal size of buffer before dump
	 *
	 * \param	sizeToAutoDump, the minimal size of buffer before dump
	 *
	 * This is a function for changing the minimal size of buffer before dump in log file
	*/
	void setSizeToAutoDump(size_t sizeToAutoDump);
	/** \brief This is a function for changing the minimal gravity of log to write in console
	 *
	 * \param	minToPrint, the minimal gravity of log to write in console
	 *
	 * This is a function for changing the minimal gravity of log to write in console
	*/
	void setMinToPrint(loggerGravity minToPrint);
	/** \brief This is a function for changing the minimal gravity of log to write in log file
	 *
	 * \param	minToLog, the minimal gravity of log to write in log file
	 *
	 * This is a function for changing the minimal gravity of log to write in log file
	*/
	void setMinToLog(loggerGravity minToLog);

	/** \brief This is a function for geting the master logger
	 *
	 * This is a function for geting the master logger
	*/
	static Logger * getMasterLogger();
	/** \brief This is a function for converting loggerGravity in string
	 *
	 * \return	the name in string of loggerGravity
	 *
	 * This is a function for converting loggerGravity in string
	*/
	static string loggerGravityToString(loggerGravity gravity);

private:

	bool dumpToFile;
	bool autoDump;
	string pathToFile;
	size_t sizeToAutoDump;
	loggerGravity minToPrint;
	loggerGravity minToLog;
	vector<string> buffer;
	static Logger masterLogger;
};
#endif // LOGGER_H