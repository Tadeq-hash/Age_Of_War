#pragma once
#include "Unit.h"


//Klasa abstrakcyjna do tworzenia wskaŸników na ere

//Przechowuje statystyki ka¿dego typu jednostki oraz tekstury wyj¹tkowe dla ery
class Age
{
public:

	// -> TWORZENIE JEDNOSTEK
	/*funkcje tworza jednostki z danymi texturami i statystykami dla odpowiedniej ery i zwracaja wskaznik na nie
	aby zaoszczêdziæ pamiêci */ 
	virtual Unit* MakeWarrior()=0;
	virtual Unit* MakeArcher()=0;
	virtual Unit* MakeBoss() = 0;
};

//	-----AGE OF KNIGHTS-----

class AgeOfKnights :public Age
{
public:
	// KONSTRUKTOR
	AgeOfKnights();

	// -> TWORZENIE JEDNOSTEK

	virtual Unit* MakeWarrior();
	virtual Unit* MakeArcher();
	virtual Unit* MakeBoss();
};

//	-----AGE OF GUNPOWDER-----

class AgeOfGunpowder :public Age
{

public:
	// KONSTRUKTOR
	AgeOfGunpowder();

	virtual Unit* MakeWarrior();
	virtual Unit* MakeArcher();
	virtual Unit* MakeBoss();
};
