#include "Unit.h"

//   -- KLASA UNIT --

//	KONSTRUKTOR
Unit::Unit(sf::Texture* texture_, int* max_hp_, int hp_, int* range_, int* dmg_, int* speed_ , float* dmg_reduction_) {
	texture = texture_;
	sprite.setTexture(*texture);
	max_hp = max_hp_;
	hp = hp_;
	range = range_;
	dmg = dmg_;
	speed = speed_;
	dmg_reduction = dmg_reduction_;

	sprite.setTexture(*texture);
	sprite.setPosition(sf::Vector2f(50, 200));
}

// DESTRUKTOR
Unit::~Unit() {
	std::cout << "Umieram\n";
}

void Unit::update() {
	if (hp <= 0) {
		std::cout << "Zabijam jednostke\n";
		delete this;
	}
}

void Unit::move() {
	std::cout << "Ruszam sie" << std::endl;
}

int Unit::return_hp() {
	return hp;
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
