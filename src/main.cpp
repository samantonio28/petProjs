//#include <SFML/Graphics.hpp>
#include "Header/GOL.h"

/*
int main() {
	int startMap[size][size];   
	mapMaker(startMap);               // начало уровня
	int lastMap[size][size];
	printMap(startMap);               // печать карты
	while (true) {
		process(startMap, lastMap);   // логика карты
		printMap(lastMap);            // печать после логики
		equating(startMap, lastMap);  // обновление карт
			
}
*/

int main()
{
    sf::RenderWindow window(sf::VideoMode(810, 810), "Game of Life");
    int startMap[size][size];
    mapMaker(startMap);
    int lastMap[size][size];
    
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);
	//sf::RectangleShape rectangle;
	//sf::RectangleShape rectangleBlack;
	//rectangleWhite.setSize(sf::Vector2f(9, 9));
	//rectangleBlack.setSize(sf::Vector2f(9, 9));
	//rectangleWhite.setOutlineColor(sf::Color::White);
	//rectangleBlack.setOutlineColor(sf::Color::Black);
	//rectangle.setOutlineThickness(5);
	//rectangle.setPosition(10, 20)
	
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        printMap(startMap, window);
        process(startMap, lastMap);
        equating(startMap, lastMap);
        window.display();
    }

    return 0;
}