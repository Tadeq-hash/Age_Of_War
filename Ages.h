#pragma once
#include "Unit.h"


//Klasa abstrakcyjna do tworzenia wskaŸników na ere

//Przechowuje statystyki ka¿dego typu jednostki oraz tekstury wyj¹tkowe dla ery
class Age
{
public:
	virtual void MakeWarrior() {};
	virtual void MakeArcher() {};
};

//	-----AGE OF KNIGHTS-----

class AgeOfKnights :public Age
{
public:
	AgeOfKnights() { std::cout << "Tworze ere Rycerzy" << std::endl; }
};

//	-----AGE OF GUNPOWDER-----

class AgeOfGunpowder :public Age
{

public:
	AgeOfGunpowder() { std::cout << "Tworze ere Prochu" << std::endl; }

};