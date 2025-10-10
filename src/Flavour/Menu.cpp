#include "Menu.h"

Menu::Menu()
{

}

Menu::~Menu()
{

}

void Menu::init()
{
	if (!font.loadFromFile("../Data/Fonts/OpenSans-Bold.ttf"))
	{
		std::cout << "could not load font\n";
	}
}

void Menu::render(sf::RenderWindow& window)
{

}