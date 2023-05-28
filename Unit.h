#pragma once
#include <iostream>

//	-- klasa abstraktyjna --

class Unit
{

public:
	//Konstruktor 
	Unit() {};
	virtual void attack() {};
	virtual void move() {};
};

//	-----KLASA WOJOWNIKA-----

class Warrior : public Unit
{

public:
	Warrior() { std::cout << "Tworze wojownika" << std::endl; }
	void attack() {};
};

//	-----KLASA £UCZNIKA-----

class Archer : public Unit
{
	Archer() { std::cout << "Tworze lucznika" << std::endl; }
	void attack() {};
};
