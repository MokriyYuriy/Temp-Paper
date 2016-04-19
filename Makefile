CC=g++
CFLAGS=--std=c++11 -g -c -Wall
LDFLAGS=
SOURCES = \
		shiftstrategy.cpp\
		dsu.cpp\
		oracul.cpp\
		randomoracul.cpp\
		player.cpp\
		response.cpp\
		bruteforce.cpp\
		test.cpp\
		simpleplayer.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
