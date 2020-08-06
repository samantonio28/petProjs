CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SRC=Client.cpp client_main.cpp Object.cpp Player.cpp Server.cpp
SOURCES=$(addprefix src/, $(SRC))
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=client

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o $@ -DSFML_STATIC \
	-Iinclude -Llib -pthread -lsfml-graphics -lsfml-system -lsfml-window -lsfml-network -lfreetype -lstdc++

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clear:
	rm -f src/*.o $(EXECUTABLE)
