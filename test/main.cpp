#include "../Logger.h"
#include "../OutputLogger.h"
#include "../SubLogger.h"

void test_logger()
{
    // Create a logger instance
    OutputLogger logger;

    // Configure the logger
    logger.setDumpToFile(true);
    logger.setAutoDump(true);
    logger.setPathToFile("log.txt");
    logger.setSizeToAutoDump(1024);
    logger.setMinToPrint(Logger::Gravity::INFO);
    logger.setMinToLog(Logger::Gravity::DEBUG);

    // Log some messages
    logger.log(Logger::Gravity::DEBUG, "This is a debug message.");
    logger.log(Logger::Gravity::INFO, "This is an info message.");
    logger.log(Logger::Gravity::ERROR, "This is an error message.");
    logger.log(Logger::Gravity::FATAL, "This is a fatal message.");

    // Dump the log buffer to file
    logger.dump();
}
void test_sub_logger()
{
    // Create a logger instance
    OutputLogger logger;

    // Configure the logger
    logger.setDumpToFile(true);
    logger.setAutoDump(true);
    logger.setPathToFile("log.txt");
    logger.setSizeToAutoDump(1024);
    logger.setMinToPrint(Logger::Gravity::INFO);
    logger.setMinToLog(Logger::Gravity::DEBUG);
    // Create a SubLogger instance
    SubLogger subLogger(&logger,"SubLogger");

    // Log some messages
    subLogger.log(Logger::Gravity::DEBUG, "This is a debug message from SubLogger.");
    subLogger.log(Logger::Gravity::INFO, "This is an info message from SubLogger.");
    subLogger.log(Logger::Gravity::ERROR, "This is an error message from SubLogger.");
    subLogger.log(Logger::Gravity::FATAL, "This is a fatal message from SubLogger.");

    // Dump the log buffer to file
    subLogger.dump();
}

int main()
{
    // Test the Logger
    test_logger();

    // Test the SubLogger
    test_sub_logger();

    return 0;
}