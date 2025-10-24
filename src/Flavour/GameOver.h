#ifndef PLATFORMER_GAMEOVER_H
#define PLATFORMER_GAMEOVER_H

#include <SFML/Graphics.hpp>
#include <iostream>

class GameOver
{
public:
	GameOver();
	~GameOver();
	void init(sf::RenderWindow& window);
	void render(sf::RenderWindow& window);

	sf::Font font1;
	sf::Font font2;
	sf::Text final_score;
	sf::Text return_message;
};

#endif // PLATFORMER_GAMEOVER_H