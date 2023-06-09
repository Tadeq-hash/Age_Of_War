#pragma once
#include "Unit.h"


//Klasa abstrakcyjna do tworzenia wskaŸników na ere

//Przechowuje statystyki ka¿dego typu jednostki oraz tekstury wyj¹tkowe dla ery
class Age
{
protected:
	sf::Texture warrior_texture;
	sf::Texture archer_texture;
	sf::Texture boss_texture;
	sf::RenderWindow* window;
public:

	// -> TWORZENIE JEDNOSTEK
	/*funkcje tworza jednostki z danymi texturami i statystykami dla odpowiedniej ery i zwracaja wskaznik na nie
	aby zaoszczêdziæ pamiêci */
	virtual std::unique_ptr<Unit> MakeWarrior(int side_) = 0;
	virtual std::unique_ptr<Unit> MakeArcher(int side_) = 0;
	virtual std::unique_ptr<Unit> MakeBoss(int side_) = 0;
	~Age() { std::cout << "Niszcze Ere\n"; }
};

//	-----AGE OF KNIGHTS-----

class AgeOfKnights :public Age
{
public:
	// KONSTRUKTOR
	AgeOfKnights(sf::RenderWindow* window_);

	// -> TWORZENIE JEDNOSTEK

	virtual std::unique_ptr<Unit> MakeWarrior(int side_);
	virtual std::unique_ptr<Unit> MakeArcher(int side_);
	virtual std::unique_ptr<Unit> MakeBoss(int side_);
};

//	-----AGE OF GUNPOWDER-----

class AgeOfGunpowder :public Age
{

public:
	// KONSTRUKTOR
	AgeOfGunpowder(sf::RenderWindow* window_);

	virtual std::unique_ptr<Unit> MakeWarrior(int side_);
	virtual std::unique_ptr<Unit> MakeArcher(int side_);
	virtual std::unique_ptr<Unit> MakeBoss(int side_);
};
