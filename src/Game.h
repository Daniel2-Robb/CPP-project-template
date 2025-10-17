
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
  void mousePressed(sf::Event event);
  void mouseReleased(sf::Event event);
  void keyPressed(sf::Event event);
  void keyReleased(sf::Event event);
  void newAnimal();
  void dragSprite(sf::Sprite* sprite);

 private:
  sf::RenderWindow& window;

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
  GameObject passport;

  sf::Texture* characters = new sf::Texture[3];
  sf::Texture* passports = new sf::Texture[3];

  sf::Sprite* dragged = nullptr;

  sf::Vector2i click;
  sf::Vector2f clickf;

  sf::Vector2i mouse_position;
  sf::Vector2f mouse_positionf;
  sf::Vector2f drag_position;

  Menu menu;

  bool evil = false;
  bool divine = true;

  int character_index = 0;
  int passport_index = 0;

};

#endif // PLATFORMER_GAME_H
