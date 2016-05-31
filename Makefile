CC=g++
CFLAGS=--std=c++14 -O2 -c -Wall
LDFLAGS=
SOURCES = \
		shiftstrategy.cpp\
		dsu.cpp\
		oracle.cpp\
		randomoracle.cpp\
		player.cpp\
		response.cpp\
		bruteforce.cpp\
		test.cpp\
		simpleplayer.cpp\
		larmouth.cpp\
		equivalence.cpp\
		simpletools.cpp\
		crushstrategy.cpp\
		choosepossible.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
