#include "Ages.h"


//	-----AGE OF KNIGHTS-----

// KONSTRUKTOR
AgeOfKnights::AgeOfKnights() { std::cout << "Tworze ere Rycerzy" << std::endl; };

// -> TWORZENIE JEDNOSTEK

//Wojownik
Unit* AgeOfKnights::MakeWarrior() {
	std::cout << "Wywoluje wojownika ze statami z ery Rycerzy" << std::endl;
	Warrior warrior;
	Unit* unit = &warrior;
	return unit;
};

//£uznik
Unit* AgeOfKnights::MakeArcher() {
	std::cout << "Wywoluje £ucznika ze statami z ery Rycerzy" << std::endl;
	Archer archer;
	Unit* unit = &archer;
	return unit;
}



//	-----AGE OF GUNPOWDER-----

// KONSTRUKTOR
AgeOfGunpowder::AgeOfGunpowder(){ std::cout << "Tworze ere Prochu" << std::endl; }

// -> TWORZENIE JEDNOSTEK

//Wojownik
Unit* AgeOfGunpowder::MakeWarrior() {
	std::cout << "Wywoluje wojownika ze statami z ery Prochu" << std::endl;
	Warrior warrior;
	Unit* unit = &warrior;
	return unit;
};

//£uznik
Unit* AgeOfGunpowder::MakeArcher() {
	std::cout << "Wywoluje £ucznika ze statami z ery Prochu" << std::endl;
	Archer archer;
	Unit* unit = &archer;
	return unit;
}