#ifndef PLATFORMER_GAMEOBJECT_H
#define PLATFORMER_GAMEOBJECT_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <deque>

class GameObject
{
public:
	GameObject();
	~GameObject();
	void init();
	bool initialiseSprite(sf::Texture& texture);
	void replaceWaypoints(sf::Vector2f waypoint);
	void move(float dt);

	sf::Sprite* getSprite();

	std::deque<sf::Vector2f> waypoints;

private:

	sf::Sprite* sprite = nullptr;
	float velocity = 300;

};

#endif // PLATFORMER_GAMEOBJECT_H