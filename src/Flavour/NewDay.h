#ifndef PLATFORMER_NEWDAY_H
#define PLATFORMER_NEWDAY_H

#include <SFML/Graphics.hpp>
#include <iostream>

class NewDay
{
public:
	NewDay();
	~NewDay();
	void init(sf::RenderWindow& window);
	void dayStart(sf::RenderWindow& window, int day);
	void dayEnd(sf::RenderWindow& window, int day);

private:
	sf::Font font;
	sf::Text day_text;
	sf::Text day_end_text;

};

#endif // PLATFORMER_NEWDAY_H