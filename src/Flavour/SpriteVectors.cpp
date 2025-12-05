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
	characters[5].loadFromFile("../Data/Images/Custom sprites/halford.png");
	characters.emplace_back();
	characters[6].loadFromFile("../data/images/custom sprites/eddie.png");

	//initialise variants
	variants.emplace_back();
	variants[0].loadFromFile("../Data/Images/Custom sprites/elephantVariant.png");
	variants.emplace_back();
	variants[1].loadFromFile("../Data/Images/Custom sprites/mooseVariant.png");
	variants.emplace_back();
	variants[2].loadFromFile("../Data/Images/Custom sprites/penguinVariant.png");
	variants.emplace_back();
	variants[3].loadFromFile("../Data/Images/Custom sprites/kaneVariant.png");
	variants.emplace_back();
	variants[4].loadFromFile("../Data/Images/Custom sprites/cillianVariant.png");
	variants.emplace_back();
	variants[5].loadFromFile("../Data/Images/Custom sprites/halford.png");
	variants.emplace_back();
	variants[6].loadFromFile("../Data/Images/Custom sprites/eddieVariant.png");

	//initialise passports
	passports.emplace_back();
	passports[0].loadFromFile("../Data/Images/Critter Crossing Customs/elephantPassport.png");
	passports.emplace_back();
	passports[1].loadFromFile("../Data/Images/Critter Crossing Customs/moosePassport.png");
	passports.emplace_back();
	passports[2].loadFromFile("../Data/Images/Critter Crossing Customs/penguinPassport.png");
	passports.emplace_back();
	passports[3].loadFromFile("../Data/Images/Custom sprites/kanePassport.png");
	passports.emplace_back();
	passports[4].loadFromFile("../Data/Images/Custom sprites/cillianPassport.png");
	passports.emplace_back();
	passports[5].loadFromFile("../Data/Images/Custom sprites/halfordPassport.png");
	passports.emplace_back();
	passports[6].loadFromFile("../Data/Images/Custom sprites/eddiePassport.png");
}
