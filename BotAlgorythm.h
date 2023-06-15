#pragma once
#include "UserInterface.h"

class BotAlgorythm
{
	UserInterface* PlayerInterface;
	UserInterface* BotInterface;
	Player* player;
	Player* bot;
	sf::Clock clockFunits;
public:
	BotAlgorythm(UserInterface* PlayerInterface_,UserInterface* BotInterface_);
	void update();
	void checkXp();
	void makeUnits();
	bool isSpaceForRespawn(Unit_type unit_type);
	bool EnoughtGold(Unit_type unit_type);
	void TakeGold(Unit_type unit_type);
};

