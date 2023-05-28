#pragma once
#include <iostream>

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
public:
	virtual void attack()=0;
	void move();
};

//	-----KLASA WOJOWNIKA-----

class Warrior : public Unit
{

public:
	// KONSTRUKTOR
	Warrior();

	void attack();
};

//	-----KLASA £UCZNIKA-----

class Archer : public Unit
{

public:
	// KONSTRUKTOR
	Archer();

	void attack() ;
};
