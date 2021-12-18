#include <iostream>
#include <windows.h>
#include <SFML/Graphics.hpp>
#include <ctime>

using namespace std;

const int size = 42;

void mapMaker(int map[size][size]) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			map[i][j] = rand() % 2;
		}
	}
	
//	map[1][2] = 1;
//	map[2][3] = 1;
//	map[3][1] = 1;
//	map[3][2] = 1;
//	map[3][3] = 1;
//	map[4][7] = 1;
//	map[5][8] = 1;
//	map[6][6] = 1;
//	map[6][7] = 1;
//	map[6][8] = 1;
//	map[6][2] = 1;
//	map[7][3] = 1;
//	map[8][1] = 1;
//	map[8][2] = 1;
//	map[8][3] = 1;

}

/*
План:
- берется две карты, первая и вторая
- вторая доска генерируется из первой данной прошлым ходом по правилам
- размеры доски одинаковы, задаются константой size
Правила:
- если данная клетка жива и имеет 2 или 3 живых соседей, то она остается жить
- если данная клетка мертва и имеет ровно 3 живых соседей, она оживает
- в остальных случаях клетка умирает или остается мертвой
- 0 - мертвая, 1 - живая клетка
*/

void printMap(int map[size][size], sf::RenderWindow &window) {
	system("cls");
	sf::RectangleShape rectangle;
	rectangle.setSize(sf::Vector2f(18, 18));
	for (int i = 0, x = 0; i < size; i++, x += 18) {
		for (int j = 0, y = 0; j < size; j++, y += 18) {
			rectangle.setPosition(x, y);
			if (map[i][j] == 0) {
				//cout << " " << " ";
				// печать белой
				rectangle.setFillColor(sf::Color::White);
			}
			else {
				//cout << map[i][j] << " ";
				// печать черной
				rectangle.setFillColor(sf::Color::Black);
			}
			window.draw(rectangle);
		}
	}
	Sleep(200);
}

void process(int map1[size][size], int map2[size][size]) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if ((i == 0) or (j == 0) or (i == size - 1) or (j == size - 1)) {
				map2[i][j] = 0;
			}
			else {
				int counter = 0;
				for (int x = -1; x <= 1; x++) {
					for (int y = -1; y <= 1; y++) {
						if (map1[i + x][j + y] == 1) {
							counter++;
						}
					}
				}
				int a = map1[i][j];
				counter -= a;
				if ((a == 1) and ((counter == 2) or (counter == 3))) {
					map2[i][j] = 1;
				}
				else if ((a == 0) and (counter == 3)) {
					map2[i][j] = 1;
				}
				else {
					map2[i][j] = 0;
				}
			}
		}
	}
}

void equating(int map1[size][size], int map2[size][size]) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			map1[i][j] = map2[i][j];
		}
	}
}
/*
int main() {
	int startMap[size][size];
	mapMaker(startMap);
	int lastMap[size][size];
	printMap(startMap);
	while (true) {
		process(startMap, lastMap);
		//printMap(lastMap);
		equating(startMap, lastMap);
	}
	
}*/