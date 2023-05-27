#pragma once
#include <SFML/Graphics.hpp>
/*
	#LOADING ANIMATION, COOLDOWN BAR, QUEUE
*/


class InitCharacter
{
private:
	//timer to load cooldown of creating character
	sf::Clock clock;



public:
	InitCharacter(std::string _character,sf::Sprite _character_sprite);

};