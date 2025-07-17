COMPYLE_ARGS := -g -Wall

all: config test

config:
	mkdir -p bin
	mkdir -p obj

logger:
	g++ ${COMPYLE_ARGS}  -o obj/Logger.o -c Logger.cpp
outputlogger:
	g++ ${COMPYLE_ARGS}  -o obj/OutputLogger.o -c OutputLogger.cpp
sublogger:
	g++ ${COMPYLE_ARGS}  -o obj/SubLogger.o -c SubLogger.cpp
clean:
	rm -rf bin/*
	rm -rf obj/*
	rmdir bin
	rmdir obj

test: logger sublogger outputlogger
	g++ ${COMPYLE_ARGS}  -o bin/test.exe test/main.cpp obj/Logger.o obj/SubLogger.o obj/OutputLogger.o