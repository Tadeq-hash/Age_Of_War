#include "Ages.h"


//	-----AGE OF KNIGHTS-----

// KONSTRUKTOR
AgeOfKnights::AgeOfKnights(sf::RenderWindow* window_){
	std::cout << "Tworze ere Rycerzy" << std::endl;
	window = window_;
	warrior_texture.loadFromFile("textures/Warrior_Age_Of_Knights.png");
	archer_texture.loadFromFile("textures/Archer_Age_Of_Knights.png");
	boss_texture.loadFromFile("textures/Boss_Age_Of_Knights.png");
};

// -> TWORZENIE JEDNOSTEK

//Wojownik
std::unique_ptr<Unit> AgeOfKnights::MakeWarrior(int side_) {
	int max_hp = 50;
	int hp = max_hp;
	int range = 10;
	int dmg = 7;
	int speed = 10;
	float dmg_reduction = 0.9;
	//std::cout << "Wywoluje wojownika ze statami z ery Rycerzy" << std::endl;
	//Warrior warrior(&texture, &max_hp, hp, &range, &dmg, &speed, &dmg_reduction);
	return std::make_unique<Unit>(Warrior(&warrior_texture, &max_hp, hp, &range, &dmg, &speed, &dmg_reduction, side_, window));
};

//£uznik
std::unique_ptr<Unit> AgeOfKnights::MakeArcher(int side_) {
	int max_hp = 35;
	int hp = max_hp;
	int range = 50;
	int dmg = 5;
	int speed = 8;
	float dmg_reduction = 1;
	//std::cout << "Wywoluje Lucznika ze statami z ery Rycerzy" << std::endl;
	//Archer archer(&texture, &max_hp, hp, &range, &dmg, &speed, &dmg_reduction);
	return std::make_unique<Unit>(Archer(&archer_texture, &max_hp, hp, &range, &dmg, &speed, &dmg_reduction, side_, window));
}

//Boss
std::unique_ptr<Unit> AgeOfKnights::MakeBoss(int side_) {
	int max_hp = 200;
	int hp = max_hp;
	int range = 12;
	int dmg = 15;
	int speed = 20;
	float dmg_reduction = 0.7;
	Boss boss(&boss_texture, &max_hp, hp, &range, &dmg, &speed, &dmg_reduction, side_, window);
	//std::cout << "Wywoluje Bossa ze statami z ery Rycerzy" << std::endl;
	//Boss boss(&texture, &max_hp, hp, &range, &dmg, &speed, &dmg_reduction);
	std::unique_ptr<Unit> unit = move(std::make_unique<Unit>(boss));
	//std::cout << "stworzony uinique_ptr, teraz zwracam\n";
	return move(unit);
}



//	-----AGE OF GUNPOWDER-----


// KONSTRUKTOR
AgeOfGunpowder::AgeOfGunpowder(sf::RenderWindow* window_) {
	std::cout << "Tworze ere Prochu" << std::endl;
	window = window_;
	warrior_texture.loadFromFile("textures/Warrior_Age_Of_Gunpowder.png");
	archer_texture.loadFromFile("textures/Archer_Age_Of_Gunpowder.png");
	boss_texture.loadFromFile("textures/Boss_Age_Of_Gunpowder.png");
}

// -> TWORZENIE JEDNOSTEK

//Wojownik
std::unique_ptr<Unit> AgeOfGunpowder::MakeWarrior(int side_) {
	int max_hp = 80;
	int hp = max_hp;
	int range = 10;
	int dmg = 9;
	int speed = 12;
	float dmg_reduction = 1;
	//std::cout << "Wywoluje wojownika ze statami z ery Prochu" << std::endl;
	//Warrior warrior(&texture, &max_hp, hp, &range, &dmg, &speed, &dmg_reduction);
	return move(std::make_unique<Unit>(Warrior(&warrior_texture, &max_hp, hp, &range, &dmg, &speed, &dmg_reduction, side_, window)));
};

//£uznik
std::unique_ptr<Unit> AgeOfGunpowder::MakeArcher(int side_) {
	int max_hp = 45;
	int hp = max_hp;
	int range = 75;
	int dmg = 8;
	int speed = 10;
	float dmg_reduction = 1;
	//std::cout << "Wywoluje Lucznika ze statami z ery Prochu" << std::endl;
	//Archer archer(&texture, &max_hp, hp, &range, &dmg, &speed, &dmg_reduction);
	return std::make_unique<Unit>(Archer(&archer_texture, &max_hp, hp, &range, &dmg, &speed, &dmg_reduction, side_, window));
}

//Boss
std::unique_ptr<Unit> AgeOfGunpowder::MakeBoss(int side_) {
	int max_hp = 200;
	int hp = max_hp;
	int range = 60;
	int dmg = 20;
	int speed = 10;
	float dmg_reduction = 1;
	//std::cout << "Wywoluje Bossa ze statami z ery Prochu" << std::endl;
	//Boss boss(&texture, &max_hp, hp, &range, &dmg, &speed, &dmg_reduction);
	return std::make_unique<Unit>(Boss(&boss_texture, &max_hp, hp, &range, &dmg, &speed, &dmg_reduction,side_, window));
}


