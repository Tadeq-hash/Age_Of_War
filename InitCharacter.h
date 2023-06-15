#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Ages.h"
#include "Player.h"

class InitCharacter
{
private:

	Player* player;
	sf::Clock clock;
	sf::RenderWindow* _window;

	/*
		CHARACTER
	*/
	sf::Sprite character_sprite;
	std::string character;
	Unit_type unit_type;
	
	/*
		BAR
	*/
	float cooldown;
	sf::Sprite cooldown_bar;
	sf::Sprite cooldown_animation;
	sf::Texture bar_texture;

	//actuall size of vector (vector of objects in queue)
	int vec_size;

	/*
		BUTTONS SETTINGS
	*/
	void sprite_setup();
	void setupButtons(std::vector<InitCharacter*>& vec, int size);

	/*
		BUTTON DEFAULT POSITIONS
	*/
	void setposition_0();
	void setposition_1();
	void setposition_2();

	/*
		BAR
	*/
	void bar_setup();
	void bar_animation();

	/*
		OTHERS
	*/
	void stringToEnumClass();
	bool isSpaceForRespawn();
	void InitVariables();
public:

	/*
		CONSTRUCTOR & DESTRUCTOR
	*/
	InitCharacter(std::string _character, sf::Sprite _character_sprite, sf::RenderWindow* window, int size, sf::Texture _tex, Player* player_);
	~InitCharacter();

	/*
		INIT COOLDOWN BAR
	*/
	void bar_init();
	
	/*
		DRAW
	*/

	/*
		UPDATE
	*/
	void drawButton();
	void update(std::vector<InitCharacter*>& vec, int size);


};