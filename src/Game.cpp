
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
	game_over.init(window);
	new_day.init(window);

	characters.reserve(8);
	passports.reserve(8);
			
	//initialise background
	background_texture.loadFromFile("../Data/WhackaMole Worksheet/background.png");
	background.initialiseSprite(background_texture);

	//initialise characters
	characters.emplace_back();
	characters[0].loadFromFile("../Data/Images/Critter Crossing Customs/elephant.png");
	characters.emplace_back();
	characters[1].loadFromFile("../Data/Images/Critter Crossing Customs/moose.png");
	characters.emplace_back();
	characters[2].loadFromFile("../Data/Images/Critter Crossing Customs/penguin.png");
	characters.emplace_back();
	characters[3].loadFromFile("../Data/Images/Custom sprites/kane.png");
	characters.emplace_back();
	characters[4].loadFromFile("../Data/Images/Custom sprites/cillian.png");
	/*characters.emplace_back();
	characters[5].loadFromFile("../Data/Images/Custom sprites/");
	characters.emplace_back();
	characters[6].loadFromFile("../Data/Images/Custom sprites/");*/


	//initialise passports
	passports.emplace_back();
	passports[0].loadFromFile("../Data/Images/Critter Crossing Customs/elephant passport.png");
	passports.emplace_back();
	passports[1].loadFromFile("../Data/Images/Critter Crossing Customs/moose passport.png");
	passports.emplace_back();
	passports[2].loadFromFile("../Data/Images/Critter Crossing Customs/penguin passport.png");
	passports.emplace_back();
	passports[3].loadFromFile("../Data/Images/Custom sprites/kane passport.png");
	passports.emplace_back();
	passports[4].loadFromFile("../Data/Images/Custom sprites/cillian passport.png");
	/*passports.emplace_back();
	passports[5].loadFromFile("../Data/Images/Custom sprites/");
	passports.emplace_back();
	passports[6].loadFromFile("../Data/Images/Custom sprites/");*/

	//initialise judgements
	accept_button_texture.loadFromFile("../Data/Images/Custom sprites/divine button.png");
	accept_button.initialiseSprite(accept_button_texture);

	reject_button_texture.loadFromFile("../Data/Images/Custom sprites/evil button.png");
	reject_button.initialiseSprite(reject_button_texture);

	accept_stamp_texture.loadFromFile("../Data/Images/Custom sprites/divine.png");
	accept_stamp.initialiseSprite(accept_stamp_texture);

	reject_stamp_texture.loadFromFile("../Data/Images/Custom sprites/evil.png");
	reject_stamp.initialiseSprite(reject_stamp_texture);

	//initialise font
	font.loadFromFile("../Data/Fonts/JudasPriest.ttf");

	//initialise music
	if (!intro.openFromFile("../Data/Audio/Last in Line (Intro).mp3"))
	{
		std::cout << "could not load music\n";
	}

	//initialise timer
	timer.restart();

	//initialise timer text
	timer_text.setString(std::to_string(time_remaining));
	timer_text.setFont(font);
	timer_text.setCharacterSize(50);
	timer_text.setFillColor(sf::Color(255, 38, 79, 255));
	timer_text.setPosition((window.getSize().x / 2) - timer_text.getGlobalBounds().width / 2, 50);

	//initialise quota text
	quota_text.setFont(font);
	quota_text.setCharacterSize(50);
	quota_text.setFillColor(sf::Color(255, 255, 255, 255));
	quota_text.setPosition(5 * (window.getSize().x / 6) - quota_text.getGlobalBounds().width / 2, 50);

		

  return true;
}

void Game::update(float dt)
{
	switch (state)
	{
	case MENU:
		menu.update();
		score = 0;

		if (!music_playing)
		{
			music_playing = true;
			intro.play();
		}

		break;

	case GAMEPLAY:

		if (dragged != nullptr)
		{
			dragSprite(dragged);
		}

		

		if (timer.getElapsedTime().asSeconds() >= 1)
		{
			time_remaining--;
			/*std::cout << std::to_string(timer.getElapsedTime().asSeconds()) << "\n";*/

			if (time_remaining <= 0)
			{
				state = GAMEEND;
			}
			else
			{
				timer.restart();
				timer_text.setString(std::to_string(time_remaining));
				window.draw(timer_text);
			}
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

	case DAYSTART:
		new_day.dayStart(window,day);
		break;
	case DAYEND:
		new_day.dayEnd(window,day);
		break;

	case GAMEPLAY:
		window.draw(*background.getSprite());
		window.draw(*character.getSprite());
		window.draw(*passport.getSprite());
		window.draw(timer_text);
		window.draw(quota_text);

		if (casting_judgement)
		{
			window.draw(*accept_button.getSprite());
			window.draw(*reject_button.getSprite());
		}
		else if (judgement_cast)
		{
			if (accepted)
			{
				window.draw(*accept_stamp.getSprite());
			}
			else if (rejected)
			{
				window.draw(*reject_stamp.getSprite());
			}
		}

		break;

	case GAMEEND:
		game_over.render(window, score);
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

		  if (passport_moveable)
		  {
			  click = sf::Mouse::getPosition(window);
			  clickf = static_cast<sf::Vector2f>(click);

			  if (passport.getSprite()->getGlobalBounds().contains(clickf))
			  {
				  dragged.reset(passport.getSprite());

			  }
		  }
		  else if (!passport_moveable)
		  {
			  if (accept_button.getSprite()->getGlobalBounds().contains(clickf))
			  {
				  accepted = true;
				  judgement_cast = true;
				  casting_judgement = false;
				  passport_moveable = true;
				  accept_stamp.getSprite()->setPosition(passport.getSprite()->getPosition().x + 25, passport.getSprite()->getPosition().y + 50);
			  }
			  else if (reject_button.getSprite()->getGlobalBounds().contains(clickf))
			  {
				  rejected = true;
				  judgement_cast = true;
				  casting_judgement = false;
				  passport_moveable = true;
				  reject_stamp.getSprite()->setPosition(passport.getSprite()->getPosition().x + 25, passport.getSprite()->getPosition().y + 50);
			  }
		  }
	  }
	  else if (event.mouseButton.button == sf::Mouse::Right)
	  {
		  if (!judgement_cast)
		  {
			  click = sf::Mouse::getPosition(window);
			  clickf = static_cast<sf::Vector2f>(click);

			  accept_button.getSprite()->setPosition(clickf.x, clickf.y);
			  reject_button.getSprite()->setPosition(clickf.x, clickf.y + accept_button.getSprite()->getGlobalBounds().height + 10);

			  casting_judgement = true;
			  passport_moveable = false;
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
	case MENU:
		if (menu.mouseReleased(window, event) == "start")
		{
			newAnimal();
			freshDay();
			quota_text.setString(std::to_string(score) + " / " + std::to_string(quota));
			state = DAYSTART;
		}
		else if (menu.mouseReleased(window, event) == "quit")
		{
			window.close();
		}

		break;

	case GAMEPLAY:

		if (dragged != nullptr)
		{
			returnPassport();
		}

		dragged.release();
		break;
	
	case DAYSTART:
		state = GAMEPLAY;
		break;

	case DAYEND:
		freshDay();
		quota_text.setString(std::to_string(score) + " / " + std::to_string(quota));
		state = DAYSTART;
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

	switch (state)
	{
	case MENU:
		if (menu.choice == Menu::START)
		{
			newAnimal();
			freshDay();
			quota_text.setString(std::to_string(score) + " / " + std::to_string(quota));
			state = DAYSTART;
			break;
		}
		else if (menu.choice == Menu::EXIT)
		{
			window.close();
		}
		break;

	case GAMEEND:
		state = MENU;
		break;
	case DAYSTART:
		state = GAMEPLAY;
		break;
	case DAYEND:
		freshDay();
		quota_text.setString(std::to_string(score) + " / " + std::to_string(quota));
		state = DAYSTART;
		break;
	}
}


void Game::newAnimal()
{
	evil = false;
	divine = false;
	judgement_cast = false;
	accepted = false;
	rejected = false;

	if (day == 1)
	{
		character_index = rand() % 3;
		passport_index = rand() % 3;
	}
	else if (day >= 2)
	{
		character_index = rand() % 5;
		passport_index = rand() % 5;
	}
	/*else
	{
		character_index = rand() % 7;
		passport_index = rand() % 7;
	}*/

	/*character_index = rand() % 3;
	passport_index = rand() % 3;*/

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
	//std::cout << "Character loaded\n";
	character.getSprite()->setScale(1.8, 1.8);
	character.getSprite()->setPosition(window.getSize().x / 12, window.getSize().y / 12);

	passport.initialiseSprite(passports[passport_index]);
	//std::cout << "Passport loaded\n";
	passport.getSprite()->setScale(0.6, 0.6);
	passport.getSprite()->setPosition(window.getSize().x / 2, window.getSize().y / 3);
}

void Game::dragSprite(std::unique_ptr<sf::Sprite>& sprite)
{
	if (sprite != nullptr)
	{
		mouse_position = sf::Mouse::getPosition(window);
		mouse_positionf = static_cast<sf::Vector2f>(mouse_position);

		drag_position = mouse_positionf;
		sprite->setPosition(drag_position.x, drag_position.y);

		accept_stamp.getSprite()->setPosition(drag_position.x + 25, drag_position.y + 50);
		reject_stamp.getSprite()->setPosition(drag_position.x + 25, drag_position.y + 50);

	}
}

void Game::returnPassport()
{

	mouse_position = sf::Mouse::getPosition(window);
	mouse_positionf = static_cast<sf::Vector2f>(mouse_position);


	if (judgement_cast)
	{
		if (character.getSprite()->getGlobalBounds().contains(mouse_positionf))
		{
			if ((accepted && divine) || (rejected && evil))
			{
				score++;

				quota_text.setString(std::to_string(score) + " / " + std::to_string(quota));

				if (score == quota)
				{
					state = DAYEND;
				}
			}
			else
			{
				time_remaining -= 3;
				timer_text.setString(std::to_string(time_remaining));
			}

			newAnimal();
		}
	}
}

void Game::freshDay()
{
	day++;
	score = 0;
	quota += 5;
	time_remaining = default_timer;

}