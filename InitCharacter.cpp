#include "InitCharacter.h"

void InitCharacter::InitVariables()
{
	this->clock.restart();

}

//DRAWING
void InitCharacter::drawButton()
{
	this->_window->draw(this->character_sprite);
}

//CONSTRUCTOR
InitCharacter::InitCharacter(std::string _character, sf::Sprite _character_sprite, sf::RenderWindow* window, int size)
{
	this->vec_size = size;
	this->_window = window;
	this->character = _character;
	this->character_sprite=_character_sprite;
	this->InitVariables();
	this->sprite_setup();
}
//DESTRUCTOR
InitCharacter::~InitCharacter()
{
	std::cout << "OBIEKT WYJEBANY Z WEKTORA, TERAZ TWORZE POSTAÆ :)";
}


void InitCharacter::sprite_setup()
{
	this->character_sprite.setScale(2,2);
	this->character_sprite.setColor(sf::Color::Green);
}

//BUTTON SETUPS
void InitCharacter::setupButtons(std::vector<InitCharacter*>& vec, int size)
{
	if (size == 1)
	{
		vec[0]->setposition_0();
	}
	if (size == 2)
	{
		vec[0]->setposition_0();
		vec[1]->setposition_1();
	}
	if (size == 3)
	{
		vec[0]->setposition_0();
		vec[1]->setposition_1();
		vec[2]->setposition_2();
	}
}

void InitCharacter::setposition_0()
{
	this->character_sprite.setPosition(375, 5);
}

void InitCharacter::setposition_1()
{
	this->character_sprite.setPosition(375, 35);
}

void InitCharacter::setposition_2()
{
	this->character_sprite.setPosition(375, 65);
}

//REMOVING OBJECT AFTER TIME
void InitCharacter::update(std::vector<InitCharacter*>& vec, int size)
{
	this->setupButtons(vec, size);

	if (clock.getElapsedTime().asSeconds() > 3)
	{	
		std::cout << "Niszcze \n";
		vec.erase(vec.begin());
		this->vec_size--;
		delete this;			
	}
}


