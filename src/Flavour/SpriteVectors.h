#ifndef PLATFORMER_SPRITEVECTORS_H
#define PLATFORMER_SPRITEVECTORS_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include "../GameObject.h"

class SpriteVectors
{
public:
	SpriteVectors();
	~SpriteVectors();
	void init();

	

	std::vector<sf::Texture> characters;
	std::vector<sf::Texture> passports;
};

#endif // PLATFORMER_SPRITEVECTORS_H