
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{

}

bool Game::init()
{
	player.init();
	if (!player_texture.loadFromFile("../Data/Images/kenney_animalpackredux/PNG/Round/frog.png"))
	{
		std::cout << "Could not load texture";
	}
	else
	{
		player.initialiseSprite(player_texture);
	}

	player.getSprite()->setScale(0.75f, 0.75f);
	player.getSprite()->setPosition((window.getSize().x / 2) - player.getSprite()->getGlobalBounds().width /2, (window.getSize().y / 2) - player.getSprite()->getGlobalBounds().height/2);

  return true;
}

void Game::update(float dt)
{
	switch (state)
	{
	case MENU:

		break;

	case GAMEPLAY:
		player.move(dt);
		break;

	case GAMEEND:

		break;
	}


}

void Game::render()
{

	switch (state)
	{
	case MENU:

		break;

	case GAMEPLAY:

		window.draw(*player.getSprite());
		break;

	case GAMEEND:

		break;
	}


}

void Game::mouseClicked(sf::Event event, sf::Vector2f cursor_location)
{
  
  switch (state)
  {
  case MENU:

	  break;

  case GAMEPLAY:

	  if (event.mouseButton.button == sf::Mouse::Left)
	  {
		  player.replaceWaypoints(cursor_location);
	  }

	  break;

  case GAMEEND:

	  break;
  }


}

void Game::keyPressed(sf::Event event)
{
	if (event.key.code == sf::Keyboard::Escape)
	{
		window.close();
	}

	switch (state)
	{
	case MENU:

		break;

	case GAMEPLAY:

		break;

	case GAMEEND:

		break;
	}
}


