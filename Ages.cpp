#include "Ages.h"


//	-----AGE OF KNIGHTS-----

// KONSTRUKTOR
AgeOfKnights::AgeOfKnights() 
{ 
	std::cout << "Tworze ere Rycerzy" << std::endl; 
	boss_texture.loadFromFile("textures/Boss_Age_Of_Knights.png");
};

// -> TWORZENIE JEDNOSTEK

//Wojownik
std::unique_ptr<Unit> AgeOfKnights::MakeWarrior() {
	sf::Texture texture;
	int max_hp = 50;
	int hp = max_hp;
	int range = 10;
	int dmg = 7;
	int speed = 5;
	float dmg_reduction = 0.9;
	std::cout << "Wywoluje wojownika ze statami z ery Rycerzy" << std::endl;
	//Warrior warrior(&texture, &max_hp, hp, &range, &dmg, &speed, &dmg_reduction);
	return std::make_unique<Unit>(Warrior(&texture, &max_hp, hp, &range, &dmg, &speed, &dmg_reduction));
};

//£uznik
std::unique_ptr<Unit> AgeOfKnights::MakeArcher() {
	sf::Texture texture;
	int max_hp = 35;
	int hp = max_hp;
	int range = 50;
	int dmg = 5;
	int speed = 5;
	float dmg_reduction = 1;
	std::cout << "Wywoluje Lucznika ze statami z ery Rycerzy" << std::endl;
	//Archer archer(&texture, &max_hp, hp, &range, &dmg, &speed, &dmg_reduction);
	return std::make_unique<Unit>(Archer(&texture, &max_hp, hp, &range, &dmg, &speed, &dmg_reduction));
}

//Boss
std::unique_ptr<Unit> AgeOfKnights::MakeBoss() {
	sf::Texture texture;
	if (!texture.loadFromFile("textures/Boss_Age_Of_Knights.png")) {
		std::cout<<"Nie udalo sie zaladowac tekstury Bossa\n";
	}
	int max_hp = 200;
	int hp = max_hp;
	int range = 12;
	int dmg = 15;
	int speed = 10;
	float dmg_reduction = 0.7;
	Boss boss(&boss_texture, &max_hp, hp, &range, &dmg, &speed, &dmg_reduction);
	std::cout << "Wywoluje Bossa ze statami z ery Rycerzy" << std::endl;
	//Boss boss(&texture, &max_hp, hp, &range, &dmg, &speed, &dmg_reduction);
	std::unique_ptr<Unit> unit = move(std::make_unique<Unit>(boss));
	std::cout << "stworzony uinique_ptr, teraz zwracam\n";
	return move(unit);
}



//	-----AGE OF GUNPOWDER-----

// KONSTRUKTOR
AgeOfGunpowder::AgeOfGunpowder(){ std::cout << "Tworze ere Prochu" << std::endl; }

// -> TWORZENIE JEDNOSTEK

//Wojownik
std::unique_ptr<Unit> AgeOfGunpowder::MakeWarrior() {
	sf::Texture texture;
	int max_hp = 80;
	int hp = max_hp;
	int range = 10;
	int dmg = 9;
	int speed = 6;
	float dmg_reduction = 1;
	std::cout << "Wywoluje wojownika ze statami z ery Prochu" << std::endl;
	//Warrior warrior(&texture, &max_hp, hp, &range, &dmg, &speed, &dmg_reduction);
	return move(std::make_unique<Unit>(Warrior(&texture, &max_hp, hp, &range, &dmg, &speed, &dmg_reduction)));
};

//£uznik
std::unique_ptr<Unit> AgeOfGunpowder::MakeArcher() {
	sf::Texture texture;
	int max_hp = 45;
	int hp = max_hp;
	int range = 75;
	int dmg = 8;
	int speed = 5;
	float dmg_reduction = 1;
	std::cout << "Wywoluje Lucznika ze statami z ery Prochu" << std::endl;
	//Archer archer(&texture, &max_hp, hp, &range, &dmg, &speed, &dmg_reduction);
	return std::make_unique<Unit>(Archer(&texture, &max_hp, hp, &range, &dmg, &speed, &dmg_reduction));
}

//Boss
std::unique_ptr<Unit> AgeOfGunpowder::MakeBoss() {
	sf::Texture texture;
	int max_hp = 200;
	int hp = max_hp;
	int range = 60;
	int dmg = 20;
	int speed = 5;
	float dmg_reduction = 1;
	std::cout << "Wywoluje Bossa ze statami z ery Prochu" << std::endl;
	//Boss boss(&texture, &max_hp, hp, &range, &dmg, &speed, &dmg_reduction);
	return std::make_unique<Unit>(Boss(&texture, &max_hp, hp, &range, &dmg, &speed, &dmg_reduction));
}


