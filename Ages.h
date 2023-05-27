#pragma once
#include "Unit.h"


//Klasa abstrakcyjna do tworzenia wskaŸników na ere

//Przechowuje statystyki ka¿dego typu jednostki oraz tekstury wyj¹tkowe dla ery
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