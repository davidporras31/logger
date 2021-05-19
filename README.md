# logger
add logger class for make log and log file

# use
Logger::getMasterLogger()-><br>
log(loggerGravity::DEBUG, "hello");<br>

# min conf
use setPathToFile(); for configue the path to the log<br>

other settings :<br>
setAutoDump();<br>
setDumpToFile();<br>
setSizeToAutoDump();<br>
setMinToPrint();<br>
setMinToLog();<br>
