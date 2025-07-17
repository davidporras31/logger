#include "Logger.h"


#include <fstream>
#include <iostream>

class OutputLogger : public Logger
{
private:
	bool dumpToFile;
	bool autoDump;
	std::string pathToFile;
	size_t sizeToAutoDump;
	Gravity minToPrint;
	Gravity minToLog;
	std::vector<std::string> buffer;
public:
    OutputLogger();
    ~OutputLogger();

    void dump() override;
    void log(Gravity gravity, std::string message) override;

	/**
	 * This set if the Logger dump to file 
	 *
	 * \param	dumpToFile the new value
	*/
	void setDumpToFile(bool dumpToFile);
	/**
	 * This is a function for configure if the Logger auto dump the buffer
	 *
	 * \param	autoDump the new value
	*/
	void setAutoDump(bool autoDump);
	/**
	 * This is a function for configure where the Logger dump
	 *
	 * \param	pathToFile the path for log file
	*/
	void setPathToFile(std::string pathToFile);
	/**
	 * This is a function for configure the size of buffer to auto dump
	 *
	 * \param	sizeToAutoDump the minimal size of buffer before auto dump
	*/
	void setSizeToAutoDump(size_t sizeToAutoDump);
	/**
	 * This is a function for changing the minimal gravity of log to write in console
	 *
	 * \param	minToPrint the minimal gravity of log to write in console
	*/
	void setMinToPrint(Gravity minToPrint);
	/**
	 * This is a function for changing the minimal gravity of log to write in log file
	 *
	 * \param	minToLog the minimal gravity of log to write in log file
	*/
	void setMinToLog(Gravity minToLog);
};