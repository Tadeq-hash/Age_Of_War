#include "Ages.h"


//	-----AGE OF KNIGHTS-----

// KONSTRUKTOR
AgeOfKnights::AgeOfKnights() { std::cout << "Tworze ere Rycerzy" << std::endl; };

// -> TWORZENIE JEDNOSTEK

//Wojownik
Unit* AgeOfKnights::MakeWarrior() {
	sf::Texture texture;
	int max_hp = 50;
	int hp = max_hp;
	int range = 10;
	int dmg = 7;
	int speed = 5;
	float dmg_reduction = 0.9;
	std::cout << "Wywoluje wojownika ze statami z ery Rycerzy" << std::endl;
	Warrior warrior(&texture,&max_hp, hp,&range,&dmg,&speed,&dmg_reduction);
	Unit* unit = &warrior;
	return unit;
};

//£uznik
Unit* AgeOfKnights::MakeArcher() {
	sf::Texture texture;
	int max_hp = 35;
	int hp = max_hp;
	int range = 50;
	int dmg = 5;
	int speed = 5;
	float dmg_reduction = 1;
	std::cout << "Wywoluje Lucznika ze statami z ery Rycerzy" << std::endl;
	Archer archer(&texture, &max_hp, hp, &range, &dmg, &speed, &dmg_reduction);
	Unit* unit = &archer;
	return unit;
}

//Boss
Unit* AgeOfKnights::MakeBoss() {
	sf::Texture texture;
	int max_hp = 200;
	int hp = max_hp;
	int range = 12;
	int dmg = 15;
	int speed = 10;
	float dmg_reduction = 0.7;
	std::cout << "Wywoluje Bossa ze statami z ery Rycerzy" << std::endl;
	Boss boss(&texture, &max_hp, hp, &range, &dmg, &speed, &dmg_reduction);
	Unit* unit = &boss;
	return unit;
}



//	-----AGE OF GUNPOWDER-----

// KONSTRUKTOR
AgeOfGunpowder::AgeOfGunpowder(){ std::cout << "Tworze ere Prochu" << std::endl; }

// -> TWORZENIE JEDNOSTEK

//Wojownik
Unit* AgeOfGunpowder::MakeWarrior() {
	sf::Texture texture;
	int max_hp = 80;
	int hp = max_hp;
	int range = 10;
	int dmg = 9;
	int speed = 6;
	float dmg_reduction = 1;
	std::cout << "Wywoluje wojownika ze statami z ery Prochu" << std::endl;
	Warrior warrior(&texture, &max_hp, hp, &range, &dmg, &speed, &dmg_reduction);
	Unit* unit = &warrior;
	return unit;
};

//£uznik
Unit* AgeOfGunpowder::MakeArcher() {
	sf::Texture texture;
	int max_hp = 45;
	int hp = max_hp;
	int range = 75;
	int dmg = 8;
	int speed = 5;
	float dmg_reduction = 1;
	std::cout << "Wywoluje Lucznika ze statami z ery Prochu" << std::endl;
	Archer archer(&texture, &max_hp, hp, &range, &dmg, &speed, &dmg_reduction);
	Unit* unit = &archer;
	return unit;
}

//Boss
Unit* AgeOfGunpowder::MakeBoss() {
	sf::Texture texture;
	int max_hp = 200;
	int hp = max_hp;
	int range = 60;
	int dmg = 20;
	int speed = 5;
	float dmg_reduction = 1;
	std::cout << "Wywoluje Bossa ze statami z ery Prochu" << std::endl;
	Boss boss(&texture, &max_hp, hp, &range, &dmg, &speed, &dmg_reduction);
	Unit* unit = &boss;
	return unit;
}


