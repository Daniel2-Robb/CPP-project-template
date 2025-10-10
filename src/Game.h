
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "Flavour/Menu.h"

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event);
  void keyPressed(sf::Event event);

 private:
  sf::RenderWindow& window;
  sf::Sprite ball;
  sf::Texture ball_texture;

  enum GameState
  {
	  MENU,
	  OPTIONS,
	  GAMEPLAY,
	  GAMEEND
  }; 
  GameState state = MENU;

  GameObject background;
  sf::Texture background_texture;
  GameObject character;
  sf::Texture* characters = new sf::Texture[3];
  GameObject passport;
  sf::Texture* passports = new sf::Texture[3];

  Menu menu;

};

#endif // PLATFORMER_GAME_H
