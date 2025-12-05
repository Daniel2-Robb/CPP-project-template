
#ifndef PLATFORMER_GAME_H
#define PLATFORMER_GAME_H

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>
#include "GameObject.h"
#include "Flavour/Menu.h"
#include "Flavour/SpriteVectors.h"
#include "Flavour/GameOver.h"
#include "Flavour/NewDay.h"

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
  void dragSprite(std::unique_ptr<sf::Sprite>& sprite);
  void returnPassport();
  void freshDay();

 private:
  sf::RenderWindow& window;

  enum GameState
  {
	  MENU,
	  DAYSTART,
	  DAYEND,
	  GAMEPLAY,
	  GAMEEND
  }; 
  GameState state = MENU;

  GameObject background;
  sf::Texture background_texture;

  GameObject accept_button;
  sf::Texture accept_button_texture;

  GameObject accept_stamp;
  sf::Texture accept_stamp_texture;

  GameObject reject_button;
  sf::Texture reject_button_texture;

  GameObject reject_stamp;
  sf::Texture reject_stamp_texture;

  GameObject character;
  GameObject passport;

  std::unique_ptr<sf::Sprite> dragged = std::make_unique<sf::Sprite>();

  sf::Vector2i click;
  sf::Vector2f clickf;

  sf::Vector2i mouse_position;
  sf::Vector2f mouse_positionf;
  sf::Vector2f drag_position;

  sf::Font font;

  Menu menu;
  SpriteVectors sprite_vectors;
  GameOver game_over;
  NewDay new_day;

  bool evil = false;
  bool divine = false;
  bool casting_judgement = false;
  bool judgement_cast = false;
  bool passport_moveable = true;
  bool accepted = false;
  bool rejected = false;

  int max_characters = 0;
  int character_index = 0;
  int passport_index = 0;
  int last_character = 0;
  int score = 0;
  int total_score = 0;
  int quota = 0;
  int day = 3;
  int variant = 0;

  sf::Music intro;
  bool music_playing = false;

  sf::Clock timer;
  int time_remaining = 30;
  int default_timer = 30;
  sf::Text timer_text;

  sf::Text quota_text;

};

#endif // PLATFORMER_GAME_H
