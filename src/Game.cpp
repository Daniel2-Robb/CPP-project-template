
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
	state = MENU;

	menu.init(window);

			
	//initialise background
	background.initialiseSprite(background_texture, "../Data/WhackaMole Worksheet/background.png");
	//std::cout << "background texture loaded\n";

	//initialise actors
	character.initialiseSprite(character_texture, "../Data/WhackaMole Worksheet/Mouse_Right.png");
	//std::cout << "mole texture loaded\n";
	character.getSprite()->setScale(0.75f, 0.75f);

  return true;
}

void Game::update(float dt)
{
	switch (state)
	{
	case MENU:
		menu.update();
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
		menu.render(window);
		break;

	case GAMEPLAY:
		window.draw(*background.getSprite());
		window.draw(*character.getSprite());

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

	  menu.render(window);

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

		if (event.key.code == sf::Keyboard::Up || event.key.code == sf::Keyboard::Down)
		{
			menu.option_select(event);
			std::cout << "Choice changed \n";
			
		}
		else
		{
			if (menu.choice == Menu::START)
			{
				state = GAMEPLAY;
			}
			else if (menu.choice == Menu::OPTIONS)
			{
				state = OPTIONS;
			}
			else if (menu.choice == Menu::EXIT)
			{
				window.close();
			}
		}

		break;

	case GAMEPLAY:

		break;

	case GAMEEND:

		break;
	}
}


