#include "Unit.h"

//   -- KLASA UNIT --

//	KONSTRUKTOR
Unit::Unit(sf::Texture* texture_, int* max_hp_, int hp_, int* range_, int* dmg_, int* speed_, float* dmg_reduction_) {
	texture = texture_;
	max_hp = *max_hp_;
	hp = hp_;
	range = *range_;
	dmg = *dmg_;
	speed = *speed_;
	dmg_reduction = *dmg_reduction_;

	sprite.setTexture(*texture);
	sprite.setPosition(sf::Vector2f(50, 987 - sprite.getGlobalBounds().height));
}

// DESTRUKTOR
Unit::~Unit() {
	//std::cout << "Umieram\n";
}

void Unit::update() {
	if (hp <= 0) {
		std::cout << "Zabijam jednostke\n";
		delete this;
	}
}

void Unit::move(sf::Clock* clock_) {
	//Wspolczynnik szybkosci pozwalajacy szybciej przeprowadzac symulacje
	int wsp = 5;
	sf::Time time = clock_->getElapsedTime();
	if (false) {
		std::cout << time.asSeconds() << " speed: " << speed << std::endl;
	}
	sprite.move(sf::Vector2f(time.asSeconds() * speed * wsp, 0));

}

int Unit::getSpeed() {
	return speed;
}

int Unit::return_hp() {
	return hp;
}


void Unit::attack(sf::Clock* clock_) {}

void Unit::draw(sf::RenderWindow* window_) {
	window_->draw(sprite);
	//std::cout << "Narysowalem\n";
	//std::cout << "Jestem na wspolrzendnych: x: " << sprite.getPosition().x << " y: " << sprite.getPosition().y << std::endl;
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
