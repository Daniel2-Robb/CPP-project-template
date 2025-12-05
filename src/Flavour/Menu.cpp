#include "Menu.h"

Menu::Menu()
{

}

Menu::~Menu()
{

}

void Menu::init(sf::RenderWindow& window)
{
	if (!font1.loadFromFile("../Data/Fonts/OldLondon.ttf"))
	{
		std::cout << "could not load first font\n";
	}

	if (!font2.loadFromFile("../Data/Fonts/JudasPriest.ttf"))
	{
		std::cout << "could not load second font\n";
	}

	menu_text.setString("The Last in Line");
	menu_text.setFont(font1);
	menu_text.setCharacterSize(80);
	menu_text.setFillColor(sf::Color(255, 255, 255, 255));
	menu_text.setPosition(window.getSize().x / 2 - menu_text.getGlobalBounds().width / 2, 100);

	start_text.setString("> Start");
	start_text.setFont(font2);
	start_text.setCharacterSize(40);
	start_text.setFillColor(sf::Color(255, 255, 255, 255));
	start_text.setPosition(window.getSize().x / 2 - menu_text.getGlobalBounds().width / 2, 300);

	hard_text.setString("Hard Mode");
	hard_text.setFont(font2);
	hard_text.setCharacterSize(40);
	hard_text.setFillColor(sf::Color(255, 0, 0, 255));
	hard_text.setPosition(window.getSize().x / 2 - menu_text.getGlobalBounds().width / 2, 400);

	exit_text.setString("Exit");
	exit_text.setFont(font2);
	exit_text.setCharacterSize(40);
	exit_text.setFillColor(sf::Color(255, 255, 255, 255));
	exit_text.setPosition(window.getSize().x / 2 - menu_text.getGlobalBounds().width / 2, 500);

}

void Menu::update()
{
	
	switch (choice)
	{
	case (START):
		start_text.setString("> Start");
		hard_text.setString("Hard Mode");
		exit_text.setString("Exit");
		break;

	case (HARD):
		start_text.setString("Start");
		hard_text.setString("> Hard Mode");
		exit_text.setString("Exit");
		break;

	case (EXIT):
		start_text.setString("Start");
		hard_text.setString("Hard Mode");
		exit_text.setString("> Exit");
		break;
	}
}

void Menu::option_select(sf::Event event)
{
	if (event.key.code == sf::Keyboard::Up)
	{
		switch (choice)
		{
		case(START):
			choice = EXIT;
			break;

		case (HARD):
			choice = START;
			break;

		case(EXIT):
			choice = HARD;
			break;
		}

	}
	else if (event.key.code == sf::Keyboard::Down)
	{
		switch (choice)
		{
		case(START):
			choice = HARD;
			break;

		case(HARD):
			choice = EXIT;
			break;

		case(EXIT):
			choice = START;
			break;
		}
	}
}

void Menu::render(sf::RenderWindow & window)
{
	window.clear(sf::Color(100, 0, 255, 255));
	window.draw(menu_text);
	window.draw(start_text);
	window.draw(hard_text);
	window.draw(exit_text);
}

sf::String Menu::mouseReleased(sf::RenderWindow& window, sf::Event event)
{
	click = sf::Mouse::getPosition(window);
	clickf = static_cast<sf::Vector2f>(click);

	if (start_text.getGlobalBounds().contains(clickf))
	{
		return "start";
	}
	else if (hard_text.getGlobalBounds().contains(clickf))
	{		
		return "hard";
	}
	else if (exit_text.getGlobalBounds().contains(clickf))
	{
		return "quit";
	}
	else
	{
		return "null";
	}
}