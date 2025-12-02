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
	sf::String mouseReleased(sf::RenderWindow& window, sf::Event event);

	sf::Font font1;
	sf::Font font2;
	sf::Text menu_text;
	sf::Text start_text;
	sf::Text exit_text;

	enum MenuSelection
	{
		START,
		EXIT
	};
	MenuSelection choice = START;

private:
	sf::Vector2i click;
	sf::Vector2f clickf;

};


#endif // PLATFORMER_MENU_H