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
	variants.reserve(8);
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
	characters.emplace_back();
	characters[5].loadFromFile("../Data/Images/Custom sprites/halford.jpg");
	/*characters.emplace_back();
	characters[6].loadFromFile("../Data/Images/Custom sprites/");*/

	//initialise variants
	variants.emplace_back();
	variants[0].loadFromFile("../Data/Images/Critter Crossing Customs/elephant.png");
	variants.emplace_back();
	variants[1].loadFromFile("../Data/Images/Critter Crossing Customs/moose.png");
	variants.emplace_back();
	variants[2].loadFromFile("../Data/Images/Critter Crossing Customs/penguin.png");
	variants.emplace_back();
	variants[3].loadFromFile("../Data/Images/Custom sprites/kane.png");
	variants.emplace_back();
	variants[4].loadFromFile("../Data/Images/Custom sprites/cillian.png");
	variants.emplace_back();
	variants[5].loadFromFile("../Data/Images/Custom sprites/halford.jpg");
	/*variants.emplace_back();
	variants[6].loadFromFile("../Data/Images/Custom sprites/");*/

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
	passports.emplace_back();
	passports[5].loadFromFile("../Data/Images/Custom sprites/halford passport.png");
	/*passports.emplace_back();
	passports[6].loadFromFile("../Data/Images/Custom sprites/");*/
}
