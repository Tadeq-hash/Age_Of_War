#pragma once
#include "Unit.h"


//Klasa abstrakcyjna do tworzenia wskaŸników na ere

//Przechowuje statystyki ka¿dego typu jednostki oraz tekstury wyj¹tkowe dla ery
class Age
{


protected:
	/*
		MEDIEVAL ERA
	*/
	std::vector<sf::IntRect> warrior_idle_rects;
	std::vector<sf::IntRect> warrior_move_rects;
	std::vector<sf::IntRect> warrior_attack_rects;
	std::vector<sf::IntRect> warrior_die_rects;

	std::vector<sf::IntRect> archer_idle_rects;
	std::vector<sf::IntRect> archer_move_rects;
	std::vector<sf::IntRect> archer_attack_rects;
	std::vector<sf::IntRect> archer_die_rects;

	std::vector<sf::IntRect> boss_idle_rects;
	std::vector<sf::IntRect> boss_move_rects;
	std::vector<sf::IntRect> boss_attack_rects;
	std::vector<sf::IntRect> boss_die_rects;

	std::vector<sf::IntRect> arrow_rects;

	/*
		COSMIC ERA
	*/

	std::vector<sf::IntRect> warrior_idle_rects_cosmic;
	std::vector<sf::IntRect> warrior_move_rects_cosmic;
	std::vector<sf::IntRect> warrior_attack_rects_cosmic;
	std::vector<sf::IntRect> warrior_die_rects_cosmic;

	std::vector<sf::IntRect> archer_idle_rects_cosmic;
	std::vector<sf::IntRect> archer_move_rects_cosmic;
	std::vector<sf::IntRect> archer_attack_rects_cosmic;
	std::vector<sf::IntRect> archer_die_rects_cosmic;

	std::vector<sf::IntRect> boss_idle_rects_cosmic;
	std::vector<sf::IntRect> boss_move_rects_cosmic;
	std::vector<sf::IntRect> boss_attack_rects_cosmic;
	std::vector<sf::IntRect> boss_die_rects_cosmic;

	std::vector<sf::IntRect> fireball_rects;


	void initAnimationsRects_Medieval();
	void initAnimationsRects_Gunpowder();
	virtual void InitArr() = 0;



protected:
	Arrow* arr;
	sf::Texture arrow_texture;
	sf::Texture warrior_texture;
	sf::Texture archer_texture;
	sf::Texture boss_texture;
	sf::RenderWindow* window;
public:
	// -> TWORZENIE SZABLONU STRZA£Y


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

	virtual void InitArr();

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
	virtual void InitArr();
	AgeOfGunpowder(sf::RenderWindow* window_);

	virtual std::unique_ptr<Unit> MakeWarrior(int side_);
	virtual std::unique_ptr<Unit> MakeArcher(int side_);
	virtual std::unique_ptr<Unit> MakeBoss(int side_);
};
