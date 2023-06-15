#include "BotAlgorythm.h"


BotAlgorythm::BotAlgorythm(UserInterface* PlayerInterface_, UserInterface* BotInterface_) {
	srand(time(NULL));
	PlayerInterface = PlayerInterface_;
	BotInterface = BotInterface_;
	player = PlayerInterface->player;
	bot = BotInterface->player;
	
	

}

void BotAlgorythm::update()
{
	
	checkXp();
	makeUnits();
	
	//std::cout << "Bot: Gold: " << bot->current_gold() << "\n";
	//std::cout << "Bot: Xp: " << bot->current_xp() << "\n";
}



void BotAlgorythm::checkXp()
{
	if (bot->current_xp() >= 43) {
		if (bot->age_ptr == bot->age1) {
			bot->age_ptr = bot->age2;
			bot->units[0]->sprite.setTexture(bot->age_ptr->base_texture);
			bot->units[0]->sprite.setScale(9.5 * -1, 8.5);
			bot->units[0]->sprite.setTextureRect(sf::IntRect(0, 0, 23, 40));
			bot->units[0]->sprite.setPosition(-10 + ((1 +1) / 2) * 1940, 648);
			std::cout << bot->units[0]->sprite.getPosition().x << " " << bot->units[0]->sprite.getPosition().y << "\n";
			BotInterface->changeAgeBackground();
		}
	}

}

void BotAlgorythm::makeUnits()
{
	Unit_type unit_type;
	if (clockFunits.getElapsedTime().asSeconds() >= 3) {
		int rd = rand() % 3;
		rd++;
		switch (rd)
		{
		case 1:

			unit_type = Unit_type::Warrior;
			break;
		case 2:

			unit_type = Unit_type::Archer;
			break;
		case 3:

			unit_type = Unit_type::Boss;
			break;
		}
		if (isSpaceForRespawn(unit_type) && EnoughtGold(unit_type)) {
			switch (unit_type)
			{
			case Unit_type::Warrior:
				bot->push_unit(move(bot->current_age()->MakeWarrior(bot->side)));
				break;
			case Unit_type::Archer:
				bot->push_unit(move(bot->current_age()->MakeArcher(bot->side)));
				break;
			case Unit_type::Boss:
				bot->push_unit(move(bot->current_age()->MakeBoss(bot->side)));
				break;
			}
			TakeGold(unit_type);
		}
		clockFunits.restart();
	}

}

bool BotAlgorythm::isSpaceForRespawn(Unit_type unit_type) {
	sf::Rect<float> rect_;
	switch (unit_type)
	{
	case Unit_type::Warrior:
		rect_ = bot->age_ptr->MakeWarrior(bot->side)->sprite.getGlobalBounds();
		break;
	case Unit_type::Archer:
		rect_ = bot->age_ptr->MakeArcher(bot->side)->sprite.getGlobalBounds();
		break;
	case Unit_type::Boss:
		rect_ = bot->age_ptr->MakeBoss(bot->side)->sprite.getGlobalBounds();
		break;
	}
	for (int i = 0; i < bot->units.size(); i++) {
		if (bot->units[i]->sprite.getGlobalBounds().intersects(rect_) && bot->units[i]->unit_type != Unit_type::Base) {
			return false;
		}
	}
	return true;
}

bool BotAlgorythm::EnoughtGold(Unit_type unit_type)
{
	switch (unit_type)
	{
	case Unit_type::Warrior:
		if (bot->current_gold() >= 70) {
			return true;
		}
		break;
	case Unit_type::Archer:
		if (bot->current_gold() >= 100) {
			return true;
		}
		break;
	case Unit_type::Boss:
		if (bot->current_gold() >= 200) {
			return true;
		}
		break;
	}
}

void BotAlgorythm::TakeGold(Unit_type unit_type)
{
	switch (unit_type)
	{
	case Unit_type::Warrior:
		bot->change_money(-70);
		break;
	case Unit_type::Archer:
		bot->change_money(-100);
		break;
	case Unit_type::Boss:
		bot->change_money(-200);
		break;
	}
}


