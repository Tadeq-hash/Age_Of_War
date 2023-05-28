#pragma once
#include <iostream>

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
