
gc:
	g++ project/main.cpp -o bin/main.exe -DSFML_STATIC \
	-Iinclude -Llib -lsfml-graphics -lsfml-system -lsfml-window -lopengl32 -lwinmm -lgdi32 -lfreetype -lstdc++
	
