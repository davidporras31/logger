#include "Logger.h"

int main()
{
	Logger::getMasterLogger()->setAutoDump(true);
	Logger::getMasterLogger()->setDumpToFile(true);
	Logger::getMasterLogger()->setPathToFile("log.log");
	Logger::getMasterLogger()->setSizeToAutoDump(2);
	Logger::getMasterLogger()->setMinToPrint(loggerGravity::INFO);
	Logger::getMasterLogger()->setMinToLog(loggerGravity::ERROR);
	Logger::getMasterLogger()->log(loggerGravity::DEBUG, "hello");
	Logger::getMasterLogger()->log(loggerGravity::INFO, "salut");
	Logger::getMasterLogger()->log(loggerGravity::ERROR, "je suis une erreur");
	Logger::getMasterLogger()->log(loggerGravity::FATAL, "je suis mort");
	Logger::getMasterLogger()->log(loggerGravity::FATAL, "je suis tres mort");
}