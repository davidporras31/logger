
//********************************************************
// author David PORRAS
// date : 05/08/2022
// file: SubLogger.h
// class for log
//********************************************************
#ifndef SUBLOGGER_H
#define SUBLOGGER_H
#include "Logger.h"
/**
 class use for split log
 */
class SubLogger :
    public Logger
{
public:
	/**
	 * Constructor that link SubLogger to one Logger
	 * 
	 * \param	master, the connected Logger to the SubLogger
	 * 
	 * \param	name, the name of the SubLogger used when log
	*/
	SubLogger(Logger* master, std::string name);
	void dump() override;
	void log(Gravity gravity, std::string message) override;
private:
    Logger* logger;
	std::string name;
};


#endif // SUBLOGGER_H