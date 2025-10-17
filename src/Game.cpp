
#include "Game.h"
#include <iostream>

Game::Game(sf::RenderWindow& game_window)
  : window(game_window)
{
  srand(time(NULL));
}

Game::~Game()
{
	delete[] characters;
	delete[] passports;


}

bool Game::init()
{
	state = MENU;

	menu.init(window);

			
	//initialise background
	background_texture.loadFromFile("../Data/WhackaMole Worksheet/background.png");
	background.initialiseSprite(background_texture);
	//std::cout << "background texture loaded\n";

	//initialise characters

	if (!characters[0].loadFromFile("../Data/Images/Critter Crossing Customs/elephant.png"))
	{
		std::cout << "Could not load elephant texture";
	}
	else if (!characters[1].loadFromFile("../Data/Images/Critter Crossing Customs/moose.png"))
	{
		std::cout << "Could not load moose texture";
	}
	else if (!characters[2].loadFromFile("../Data/Images/Critter Crossing Customs/penguin.png"))
	{
		std::cout << "Could not load penguin texture";
	}

	
	//initialise passports
	if (!passports[0].loadFromFile("../Data/Images/Critter Crossing Customs/elephant passport.png"))
	{
		std::cout << "Could not load elephant passport";
	}
	else if (!passports[1].loadFromFile("../Data/Images/Critter Crossing Customs/moose passport.png"))
	{
		std::cout << "Could not load moose passport";
	}
	else if (!passports[2].loadFromFile("../Data/Images/Critter Crossing Customs/penguin passport.png"))
	{
		std::cout << "Could not load penguin passport";
	}

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

		if (dragged != nullptr)
		{
			dragSprite(dragged);
		}

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
		window.draw(*passport.getSprite());

		break;

	case GAMEEND:

		break;
	}


}

void Game::mousePressed(sf::Event event)
{
  //get the click position
  sf::Vector2i click = sf::Mouse::getPosition(window);

  switch (state)
  {
  case MENU:

	  break;

  case GAMEPLAY:

	  if (event.mouseButton.button == sf::Mouse::Left)
	  {
		  click = sf::Mouse::getPosition(window);
		  clickf = static_cast<sf::Vector2f>(click);

		  if (passport.getSprite()->getGlobalBounds().contains(clickf))
		  {
			  dragged = passport.getSprite();
			  
		  }
	  }

	  break;

  case GAMEEND:

	  break;
  }


}

void Game::mouseReleased(sf::Event event)
{

	switch (state)
	{
	case GAMEPLAY:
		dragged = nullptr;
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
				newAnimal();
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

void Game::keyReleased(sf::Event event)
{
	if (event.key.code == sf::Keyboard::Escape)
	{
		window.close();
	}
}


void Game::newAnimal()
{
	evil = false;
	divine = false;

	character_index = rand() % 3;
	passport_index = rand() % 3;

	if (character_index == passport_index)
	{
		divine = true;
		std::cout << "Divine \n";
	}
	else
	{
		evil = true;
		std::cout << "Evil \n";
	}

	character.initialiseSprite(characters[character_index]);
	std::cout << "Character loaded\n";
	character.getSprite()->setScale(1.8, 1.8);
	character.getSprite()->setPosition(window.getSize().x / 12, window.getSize().y / 12);

	passport.initialiseSprite(passports[passport_index]);
	std::cout << "Passport loaded\n";
	passport.getSprite()->setScale(0.6, 0.6);
	passport.getSprite()->setPosition(window.getSize().x / 2, window.getSize().y / 3);
}

void Game::dragSprite(sf::Sprite* sprite)
{
	if (sprite != nullptr)
	{
		mouse_position = sf::Mouse::getPosition(window);
		mouse_positionf = static_cast<sf::Vector2f>(mouse_position);

		drag_position = mouse_positionf;
		sprite->setPosition(drag_position.x, drag_position.y);
	}
}