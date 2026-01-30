
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

  return true;
}

void Game::update(float dt)
{
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

void Game::render()
{

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

void Game::mouseClicked(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);

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


