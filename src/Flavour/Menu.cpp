#include "Menu.h"

Menu::Menu()
{

}

Menu::~Menu()
{

}

void Menu::init(sf::RenderWindow& window)
{
	if (!font1.loadFromFile("../Data/Fonts/OpenSans-Bold.ttf"))
	{
		std::cout << "could not load first font\n";
	}

	/*if (!font1.loadFromFile("../Data/Fonts/motorhead.ttf"))
	{
		std::cout << "could not load second font\n";
	}*/

	menu_text.setString("Welcome to Critter Crossing");
	menu_text.setFont(font1);
	menu_text.setCharacterSize(30);
	menu_text.setFillColor(sf::Color(255, 255, 255, 255));
	menu_text.setPosition(window.getSize().x / 2 - menu_text.getGlobalBounds().width / 2, 100);

	start_text.setString(">Start<");
	start_text.setFont(font1);
	start_text.setCharacterSize(30);
	start_text.setFillColor(sf::Color(255, 255, 255, 255));
	start_text.setPosition(window.getSize().x / 2 - menu_text.getGlobalBounds().width / 2, 300);

	options_text.setString("Options");
	options_text.setFont(font1);
	options_text.setCharacterSize(30);
	options_text.setFillColor(sf::Color(255, 255, 255, 255));
	options_text.setPosition(window.getSize().x / 2 - menu_text.getGlobalBounds().width / 2, 350);

	exit_text.setString("Exit");
	exit_text.setFont(font1);
	exit_text.setCharacterSize(30);
	exit_text.setFillColor(sf::Color(255, 255, 255, 255));
	exit_text.setPosition(window.getSize().x / 2 - menu_text.getGlobalBounds().width / 2, 400);

}

void Menu::update()
{
	
	switch (choice)
	{
	case (START):
		start_text.setString(">Start<");
		options_text.setString("Options");
		exit_text.setString("Exit");
		break;

	case (OPTIONS):
		start_text.setString("Start");
		options_text.setString(">Options<");
		exit_text.setString("Exit");
		break;

	case (EXIT):
		start_text.setString("Start");
		options_text.setString("Options");
		exit_text.setString(">Exit<");
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
		case(OPTIONS):
			choice = START;
			break;
		case(EXIT):
			choice = OPTIONS;
			break;
		}

	}
	else if (event.key.code == sf::Keyboard::Down)
	{
		switch (choice)
		{
		case(START):
			choice = OPTIONS;
			break;
		case(OPTIONS):
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
	window.draw(options_text);
	window.draw(exit_text);
}