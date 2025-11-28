#include "NewDay.h"

NewDay::NewDay()
{

}

NewDay::~NewDay()
{

}

void NewDay::init(sf::RenderWindow& window)
{
	if (!font.loadFromFile("../Data/Fonts/OldLondon.ttf"))
	{
		std::cout << "could not load first font\n";
	}

	day_text.setFont(font);
	day_text.setCharacterSize(60);
	day_text.setFillColor(sf::Color(255, 255, 255, 255));
	day_text.setPosition((window.getSize().x / 2) - (day_text.getGlobalBounds().width / 2), (window.getSize().y / 2) - (day_text.getGlobalBounds().height / 2));

	day_end_text.setFont(font);
	day_end_text.setCharacterSize(60);
	day_end_text.setFillColor(sf::Color(255, 255, 255, 255));
	
}

void NewDay::dayStart(sf::RenderWindow& window, int day)
{
	day_text.setString("Day " + std::to_string(day));
	day_text.setPosition((window.getSize().x / 2) - (day_text.getGlobalBounds().width / 2), (window.getSize().y / 2) - (day_text.getGlobalBounds().height / 2) - 100);

	window.clear(sf::Color(100, 0, 255, 255));
	window.draw(day_text);
}

void NewDay::dayEnd(sf::RenderWindow& window, int day)
{
	day_end_text.setString("Congratulations! You beat day " + std::to_string(day));
	day_end_text.setPosition((window.getSize().x / 2) - (day_end_text.getGlobalBounds().width / 2), (window.getSize().y / 2) - (day_end_text.getGlobalBounds().height / 2) - 100);

	window.clear(sf::Color(100, 0, 255, 255));
	window.draw(day_end_text);
}