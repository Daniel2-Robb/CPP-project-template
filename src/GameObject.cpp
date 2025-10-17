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
	sprite->setTexture(texture);
	//std::cout << "Texture loaded\n";

	return true;

}

sf::Sprite* GameObject::getSprite()
{
	return sprite;
}