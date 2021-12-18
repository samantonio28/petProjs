CC=g++
CFLAGS=-c -Wall
LDFLAGS=
SRC=main.cpp
SOURCES=$(addprefix src/, $(SRC))
OBJECTS=$(SOURCES:.cpp=.o)
EXECUTABLE=main.exe 
all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(OBJECTS) -o bin/$@ -DSFML_STATIC \
	-Iinclude -Llib -lsfml-graphics -lsfml-system -lsfml-window -lopengl32 -lwinmm -lgdi32 -lfreetype -lstdc++

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@ -DSFML_STATIC \
	-Iinclude -Llib -lsfml-graphics -lsfml-system -lsfml-window -lopengl32 -lwinmm -lgdi32 -lfreetype -lstdc++

clear:
	rm -f src/*.o $(EXECUTABLE)
