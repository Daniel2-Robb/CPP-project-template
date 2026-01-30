
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <SFML/Graphics.hpp>
#include "GameObject.h"

class Game
{
 public:
  Game(sf::RenderWindow& window);
  ~Game();
  bool init();
  void update(float dt);
  void render();
  void mouseClicked(sf::Event event, sf::Vector2f cursor_location);
  void keyPressed(sf::Event event);

 private:
  sf::RenderWindow& window;
  
  enum GameState
  {
	  MENU,
	  GAMEPLAY,
	  GAMEEND
  }; 
  GameState state = GAMEPLAY;

  GameObject player;
  sf::Texture player_texture;

};

#endif // PLATFORMER_GAME_H
