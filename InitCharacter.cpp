#include "InitCharacter.h"

void InitCharacter::InitVariables()
{

	this->clock.restart();
	
}

void InitCharacter::drawButton()
{

	this->character_sprite.setPosition(100, 100);
	this->character_sprite.setColor(sf::Color::Red);
	this->character_sprite.setScale(2, 2);

	this->_window->draw(this->character_sprite);
}

InitCharacter::InitCharacter(std::string _character, sf::Sprite _character_sprite, sf::RenderWindow* window)
{
	this->_window = window;
	this->character = _character;
	this->character_sprite=_character_sprite;
	this->InitVariables();
	
}

InitCharacter::~InitCharacter()
{
	std::cout << "OBIEKT WYJEBANY Z WEKTORA, TERAZ TWORZE POSTAÆ :)";
}

void InitCharacter::update(std::vector<InitCharacter*>& vec)
{
	vector_of_charactes = vec;
	
	 
	if (clock.getElapsedTime().asSeconds() > 2)
	{
		std::cout << "Niszcze \n";
		vec.erase(vec.begin());
		delete this;		
		
		
	}
}


