#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

//  - klasa wyliczeniowa - 
	/*Do przycisk�w*/
enum class Unit_type
{
	Warrior,
	Archer,
	Boss
};

//	-- klasa abstraktyjna --

class Unit
{
	sf::RenderWindow* window;
	sf::Texture* texture;
	int max_hp;
	float hp;
	int range;
	int dmg;
	int speed;
	float dmg_reduction;
	float dmg_delay = 0.5;
public:
	float side;
	bool attacking = 0;
	bool moving = 0;
	sf::Sprite sprite;
	Unit_type unit_type;
	//	KONSTRUKTOR
	Unit(sf::Texture* texture_, int* max_hp_, int hp_, int* range_, int* dmg_, int* speed_, float* dmg_reduction_, int side_, sf::RenderWindow* window_);
	// DESTRUKTOR
	~Unit();
	virtual void attack(sf::Clock* clock_);
	void move(sf::Clock* clock_);
	//void update();
	void draw(sf::RenderWindow* window_);
	int return_hp();
	int getSpeed();
	int getRange();
	int getDmg();
	int getDmgRed();
	void sufferDmg(int sufferDmg_);
	
};

//	-----KLASA WOJOWNIKA-----

class Warrior : public Unit
{

public:
	// KONSTRUKTOR
	using Unit::Unit;

	Unit_type unit_type = Unit_type::Warrior;

	void attack();
};

//	-----KLASA �UCZNIKA-----

class Archer : public Unit
{

public:
	// KONSTRUKTOR
	using Unit::Unit;

	Unit_type unit_type = Unit_type::Archer;

	void attack();
};

//	-----KLASA BOSS-----

class Boss : public Unit
{

public:
	// KONSTRUKTOR
	using Unit::Unit;

	Unit_type unit_type = Unit_type::Boss;

	void attack();
};
