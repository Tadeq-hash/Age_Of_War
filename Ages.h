#pragma once
#include "Unit.h"


//Klasa abstrakcyjna do tworzenia wska�nik�w na ere

//Przechowuje statystyki ka�dego typu jednostki oraz tekstury wyj�tkowe dla ery
class Age
{
public:
	void MakeWarrior() {};
	void MakeArcher() {};
};

//	-----AGE OF KNIGHTS-----

class AgeOfKnights :public Age
{



};

//	-----AGE OF GUNPOWDER-----

class AgeOfGunpowder :public Age
{



};