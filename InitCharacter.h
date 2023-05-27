#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
/*
	#LOADING ANIMATION, COOLDOWN BAR, QUEUE
*/


class InitCharacter
{
private:
	//timer to load cooldown of creating character
	sf::Clock clock;

	sf::RenderWindow *_window;
	//setting variables from constructor
	std::string character;
	sf::Sprite character_sprite;
	std::vector<InitCharacter*> vector_of_charactes;
	void InitVariables();

	
	//deleting object


public:
	//constructor
	InitCharacter(std::string _character,sf::Sprite _character_sprite, sf::RenderWindow *window);
	

	//destructor
	~InitCharacter();
	void drawButton();
	void update(std::vector<InitCharacter*>& vec);

	
};