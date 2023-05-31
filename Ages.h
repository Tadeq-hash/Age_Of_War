#pragma once
#include "Unit.h"


//Klasa abstrakcyjna do tworzenia wskaŸników na ere

//Przechowuje statystyki ka¿dego typu jednostki oraz tekstury wyj¹tkowe dla ery
class Age
{
protected:
	sf::Texture boss_texture;
public:

	// -> TWORZENIE JEDNOSTEK
	/*funkcje tworza jednostki z danymi texturami i statystykami dla odpowiedniej ery i zwracaja wskaznik na nie
	aby zaoszczêdziæ pamiêci */ 
	virtual std::unique_ptr<Unit> MakeWarrior()=0;
	virtual std::unique_ptr<Unit> MakeArcher()=0;
	virtual std::unique_ptr<Unit> MakeBoss()=0;
	~Age(){std::cout<<"Niszcze Ere\n";}
};

//	-----AGE OF KNIGHTS-----

class AgeOfKnights :public Age
{
public:
	// KONSTRUKTOR
	AgeOfKnights();

	// -> TWORZENIE JEDNOSTEK

	virtual std::unique_ptr<Unit> MakeWarrior();
	virtual std::unique_ptr<Unit> MakeArcher();
	virtual std::unique_ptr<Unit> MakeBoss();
};

//	-----AGE OF GUNPOWDER-----

class AgeOfGunpowder :public Age
{

public:
	// KONSTRUKTOR
	AgeOfGunpowder();

	virtual std::unique_ptr<Unit> MakeWarrior();
	virtual std::unique_ptr<Unit> MakeArcher();
	virtual std::unique_ptr<Unit> MakeBoss();
};
