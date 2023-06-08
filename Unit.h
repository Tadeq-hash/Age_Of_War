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
	sf::Texture* texture;
	int max_hp;
	int hp;
	int range;
	int dmg;
	int speed;
	float dmg_reduction;
public:
	sf::Sprite sprite;
	Unit_type unit_type;
	//	KONSTRUKTOR
	Unit(sf::Texture* texture_, int* max_hp_, int hp_, int* range_, int* dmg_, int* speed_, float* dmg_reduction_);
	// DESTRUKTOR
	~Unit();
	virtual void attack(sf::Clock* clock_);
	void move(sf::Clock* clock_);
	void update();
	void draw(sf::RenderWindow* window_);
	int return_hp();
	int getSpeed();
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
