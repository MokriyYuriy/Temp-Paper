CC=g++
CFLAGS=--std=c++11 -c -Wall
LDFLAGS=
SOURCES=randomoracul.cpp oracul.cpp player.cpp response.cpp bruteforce.cpp test.cpp
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@
