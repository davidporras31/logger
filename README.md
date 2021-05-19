# logger
add logger class
for make log and log file

# use
Logger::getMasterLogger()->
log(loggerGravity::DEBUG, "hello");

# min conf
setAutoDump(true);
setDumpToFile(true);
setPathToFile("log.log");
setSizeToAutoDump(2);
setMinToPrint(loggerGravity::INFO);
setMinToLog(loggerGravity::ERROR);