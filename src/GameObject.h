#ifndef PLATFORMER_GAMEOBJECT_H
#define PLATFORMER_GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <iostream>

class GameObject
{
public:
	GameObject();
	~GameObject();
	void init();
	bool initialiseSprite(sf::Texture& texture);
	sf::Sprite* getSprite();
	sf::Sprite* sprite = nullptr;

private:
	

};

#endif // PLATFORMER_GAMEOBJECT_H