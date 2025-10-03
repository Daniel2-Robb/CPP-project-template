#ifndef PLATFORMER_MENU_H
#define PLATFORMER_MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Menu
{
public:
	Menu();
	~Menu();
	void init();
	void render(sf::RenderWindow& window);

	sf::Font font;
	sf::Text menu_text;

};


#endif // PLATFORMER_MENU_H