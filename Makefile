CC=g++
CFLAGS=--std=c++14 -g -c -Wall
LDFLAGS=
SOURCES = \
		shiftstrategy.cpp\
		dsu.cpp\
		oracle.cpp\
		randomoracle.cpp\
		player.cpp\
		response.cpp\
		choosepossible.cpp\
		bruteforce.cpp\
		test.cpp\
		simpleplayer.cpp\
		simpletools.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
