#include "InitCharacter.h"

void InitCharacter::InitVariables()
{
	this->clock.restart();
	this->cooldown = 2.5f;
}

//DRAWING
void InitCharacter::drawButton()
{
	this->_window->draw(this->character_sprite);
}

//CONSTRUCTOR
InitCharacter::InitCharacter(std::string _character, sf::Sprite _character_sprite, sf::RenderWindow* window, int size, sf::Texture _tex)
{
	this->bar_texture = _tex;
	this->vec_size = size;
	this->_window = window;
	this->character = _character;
	this->character_sprite=_character_sprite;
	this->InitVariables();
	this->sprite_setup();
	this->bar_setup();
}
//DESTRUCTOR
InitCharacter::~InitCharacter()
{
	std::cout << "OBIEKT WYJEBANY Z WEKTORA, TERAZ TWORZE POSTA� :)";
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
	clock.restart();
}

void InitCharacter::setposition_2()
{
	this->character_sprite.setPosition(375, 65);
	clock.restart();
}

void InitCharacter::bar_setup()
{
	this->cooldown_bar.setTexture(this->bar_texture);
	this->cooldown_bar.setTextureRect(sf::IntRect(184,50,3,250));
	this->cooldown_bar.setScale(5, 0.45);
	this->cooldown_bar.setPosition(355, 0);

}
													 
void InitCharacter::bar_animation()
{
	this->cooldown_animation.setTexture(this->bar_texture);
	this->cooldown_animation.setTextureRect(sf::IntRect(190, 51, 1, this->clock.getElapsedTime().asMilliseconds()/11));
	this->cooldown_animation.setPosition(360, 5);
	this->cooldown_animation.setScale(5, 0.45);
	

}

void InitCharacter::bar_init()
{
	this->_window->draw(this->cooldown_bar);
	this->_window->draw(this->cooldown_animation);
}

//REMOVING OBJECT AFTER TIME
void InitCharacter::update(std::vector<InitCharacter*>& vec, int size)
{

	this->setupButtons(vec, size);
	this->bar_animation();
	std::cout<<clock.getElapsedTime().asMilliseconds()<<"\n";
	if (clock.getElapsedTime().asMilliseconds() > cooldown*1000)
	{	
		std::cout << "Niszcze \n";
		vec.erase(vec.begin());
		this->vec_size--;
		delete this;			
	}
}

