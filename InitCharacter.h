#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ages.h"
/*
	#LOADING ANIMATION, COOLDOWN BAR, QUEUE
*/

class InitCharacter
{
private:
	//timer to load cooldown of creating character
	sf::Clock clock;
	sf::RenderWindow* _window;


	float cooldown;
	//setting variables from constructor
	void InitVariables();
	sf::Sprite character_sprite;
	std::string character;
	Unit_type unit_type;

	sf::Sprite cooldown_bar;
	sf::Sprite cooldown_animation;
	sf::Texture bar_texture;
	//actuall size of vector (vector of objects in queue)
	int vec_size;
		
	//BUTTON SETTING
	void sprite_setup();
	void setupButtons(std::vector<InitCharacter*>& vec, int size);
	//BUTTON QUEUE POSITIONS
	void setposition_0();
	void setposition_1();
	void setposition_2();

	//BAR
	void bar_setup();
	void bar_animation();



	//zamiana stringa w enum class
	void stringToEnumClass();

public:

	//constructor
	InitCharacter(std::string _character, sf::Sprite _character_sprite, sf::RenderWindow* window, int size, sf::Texture _tex);
	void bar_init();
	//destructor
	~InitCharacter();
	void drawButton();
	void update(std::vector<InitCharacter*>& vec, int size);

	
};