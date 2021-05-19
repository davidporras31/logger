#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;
#pragma once

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

	void dump();
	void log(loggerGravity gravity, string message);

	bool getDumpToFile();
	bool getAutoDump();
	string getPathToFile();
	size_t getSizeToAutoDump();
	loggerGravity getMinToPrint();
	loggerGravity getMinToLog();

	void setDumpToFile(bool dumpToFile);
	void setAutoDump(bool autoDump);
	void setPathToFile(string pathToFile);
	void setSizeToAutoDump(size_t sizeToAutoDump);
	void setMinToPrint(loggerGravity minToPrint);
	void setMinToLog(loggerGravity minToLog);

	static Logger * getMasterLogger();
private:

	static string loggerGravityToString(loggerGravity gravity);

	bool dumpToFile;
	bool autoDump;
	string pathToFile;
	size_t sizeToAutoDump;
	loggerGravity minToPrint;
	loggerGravity minToLog;
	vector<string> buffer;
	static Logger masterLogger;
};