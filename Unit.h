#pragma once
#include <iostream>
//using namespace std;

//	-- klasa abstraktyjna --

class Unit
{

public:
	//Konstruktor 
	Unit() {};

};

//	-----KLASA WOJOWNIKA-----

class Warrior : public Unit
{

public:
	Warrior() { std::cout << "Tworze wojownika" << std::endl; }

};

//	-----KLASA £UCZNIKA-----

class Archer : public Unit
{
	Archer() { std::cout << "Tworze lucznika" << std::endl; }

};
