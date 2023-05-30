#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

//  - klasa wyliczeniowa - 
	/*Do przycisków*/
enum class Unit_type
{
	Warrior,
	Archer,	
	Boss
};

//	-- klasa abstraktyjna --

class Unit
{
	sf::Texture* texture;
	int* max_hp;
	int hp;
	int* range;
	int* dmg;
	int* speed;
	float* dmg_reduction;

	sf::Sprite sprite;
public:
	Unit(sf::Texture* texture_,int* max_hp_,int hp_, int* range_, int* dmg_, int* speed_ , float* dmg_reduction_);
	virtual void attack()=0;
	void move();
};

//	-----KLASA WOJOWNIKA-----

class Warrior : public Unit
{

public:
	// KONSTRUKTOR
	using Unit::Unit;

	void attack();
};

//	-----KLASA £UCZNIKA-----

class Archer : public Unit
{

public:
	// KONSTRUKTOR
	using Unit::Unit;

	void attack() ;
};

//	-----KLASA BOSS-----

class Boss : public Unit
{

public:
	// KONSTRUKTOR
	using Unit::Unit;

	void attack();
};
