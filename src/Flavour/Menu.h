#ifndef PLATFORMER_MENU_H
#define PLATFORMER_MENU_H

#include <SFML/Graphics.hpp>
#include <iostream>

class Menu
{
public:
	Menu();
	~Menu();
	void init(sf::RenderWindow& window);
	void update();
	void option_select(sf::Event event);
	void render(sf::RenderWindow& window);

	sf::Font font1;
	sf::Font font2;
	sf::Text menu_text;
	sf::Text start_text;
	sf::Text options_text;
	sf::Text exit_text;

	enum MenuSelection
	{
		START,
		OPTIONS,
		EXIT
	};
	MenuSelection choice = START;

};


#endif // PLATFORMER_MENU_H