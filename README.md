# logger
add logger class for make log to console and log to file

# use
basic log:
```
Logger logger();
logger.log(LoggerGravity::INFO,"this is an info");	//output:[INFO]this is an info
```
configurating:
```
Logger logger();
logger.setPathToFile("test.log");		//set the Logger output file
logger.setDumpToFile(true);			//activate the Logger output to file
logger.setAutoDump(true);			//activate the Logger dump to file when log
logger.setSizeToAutoDump(10);			//the Logger auto dump the buffered log to file when the buffer size is bigger then 10
logger.setMinToPrint(LoggerGravity::INFO);	//change the ninimal log gravity to print in console
logger.setMinToLog(LoggerGravity::INFO);	//change the ninimal log gravity to add in buffer
```
# using SubLogger
basic log:
```
Logger logger();
SubLogger subLogger(&logger,"new SubLogger");
subLogger.log(LoggerGravity::INFO,"this is an info");	//output:[INFO][new SubLogger] this is an info
```