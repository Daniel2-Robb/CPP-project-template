#include "GameObject.h"

GameObject::GameObject()
{
	sprite = new sf::Sprite();
}

GameObject::~GameObject()
{
	if (sprite != nullptr)
	{
		delete sprite;
		sprite = nullptr;
	}
}

void GameObject::init()
{

}

bool GameObject::initialiseSprite(sf::Texture& texture)
{
	sprite->setTexture(texture, true);

	return true;

}

sf::Sprite* GameObject::getSprite()
{
	return sprite;
}

void GameObject::replaceWaypoints(sf::Vector2f waypoint)
{
	waypoints.clear();
	waypoints.push_back(waypoint);
}

void GameObject::move(float dt)
{
	if (!waypoints.empty()) // checks for waypoint
	{
		//calculate distance from character to waypoint
		sf::Vector2f direction = waypoints.front() - getSprite()->getPosition();
		float distance = sqrt((direction.x * direction.x) + (direction.y * direction.y));

		if (distance < 1) //player already at waypoint
		{
			waypoints.pop_front(); //removes first waypoint from the deque
		}
		else //not at waypoiny
		{
			//normalise direction vector
			direction.x = direction.x / distance;
			direction.y = direction.y / distance;

			//move sprite
			getSprite()->move(direction * velocity * dt);
		}
	}
}