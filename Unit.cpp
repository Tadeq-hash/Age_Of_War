#include "Unit.h"

//   -- KLASA UNIT --

Unit::Unit(sf::Texture* texture_, int* max_hp_, int hp_, int* range_, int* dmg_, int* speed_ , float* dmg_reduction_) {
	texture = texture_;
	sprite.setTexture(*texture);
	max_hp = max_hp_;
	hp = hp_;
	range = range_;
	dmg = dmg_;
	speed = speed_;
	dmg_reduction = dmg_reduction_;
}


//	-----KLASA WOJOWNIKA-----

// KONSTRUKTOR
//Warrior::Warrior() { std::cout << "Tworze wojownika" << std::endl; };

// METODY	
void Warrior::attack() {};


//	-----KLASA £UCZNIKA-----

// KONSTRUKTOR
//Archer::Archer() { std::cout << "Tworze lucznika" << std::endl; };

// METODY	
void Archer::attack() {};


//	-----KLASA BOSS-----


// KONSTRUKTOR
//Boss::Boss() { std::cout << "Tworze Bossa"<<std::endl; };

// METODY
void Boss::attack() {};
