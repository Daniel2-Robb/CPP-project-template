#include "GameOver.h"

GameOver::GameOver()
{

}

GameOver::~GameOver()
{

}

void GameOver::init(sf::RenderWindow& window)
{
	if (!font1.loadFromFile("../Data/Fonts/OldLondon.ttf"))
	{
		std::cout << "GameOvercould not load first font\n";
	}

	if (!font2.loadFromFile("../Data/Fonts/JudasPriest.ttf"))
	{
		std::cout << "GameOver could not load second font\n";
	}

	final_score.setFont(font2);
	final_score.setCharacterSize(80);
	final_score.setFillColor(sf::Color(255, 255, 255, 255));

	return_message.setString("To return to the main menu, press any key");
	return_message.setFont(font1);
	return_message.setCharacterSize(40);
	return_message.setFillColor(sf::Color(255, 255, 255, 255));
	return_message.setPosition(window.getSize().x / 2 - return_message.getGlobalBounds().width / 2, 400);
}

void GameOver::render(sf::RenderWindow& window)
{

	final_score.setPosition(window.getSize().x / 2 - final_score.getGlobalBounds().width / 2, 100);
	window.draw(final_score);
	window.draw(return_message);

}