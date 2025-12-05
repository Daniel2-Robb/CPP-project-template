#include "SpriteVectors.h"

SpriteVectors::SpriteVectors()
{
}

SpriteVectors::~SpriteVectors()
{
}

void SpriteVectors::init()
{
	characters.reserve(8);
	passports.reserve(8);

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
}
