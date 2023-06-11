#include "Unit.h"

//   -- KLASA UNIT --

//4 wektory animacji



//	KONSTRUKTOR
Unit::Unit(sf::Texture* texture_, int* max_hp_, int hp_, int* range_, int* dmg_, int* speed_, float* dmg_reduction_, int side_, sf::RenderWindow* window_, std::vector<sf::IntRect>& rects_idle, std::vector<sf::IntRect>& rects_move, std::vector<sf::IntRect>& rects_attack, std::vector<sf::IntRect>& rects_die) {
	window = window_;
	side = side_;
	texture = texture_;
	max_hp = *max_hp_;
	hp = hp_;
	range = *range_;
	dmg = *dmg_;
	speed = *speed_;
	dmg_reduction = *dmg_reduction_;
	this->idle_rects = rects_idle;
	this->move_rects = rects_move;
	this->attack_rects = rects_attack;
	this->die_rects = rects_die;

	sprite.setTexture(*texture);
	sprite.setScale(side*2, 2);
	sprite.setTextureRect(idle_rects[0]);
	sprite.setPosition(sf::Vector2f(((side - 1) / (-2))*(window->getSize().x  - 100) + 50, 987 - sprite.getGlobalBounds().height));
}

// DESTRUKTOR
Unit::~Unit() {
	//std::cout << "Umieram\n";
}

//void Unit::update() {
//	if (hp <= 0) {
//		std::cout << "Umieram \n";
//		
//	}
//}

void Unit::move(sf::Clock* clock_) {
	//Wspolczynnik szybkosci pozwalajacy szybciej przeprowadzac symulacje
	int wsp = 5;
	sf::Time time = clock_->getElapsedTime();
	if (false) {
		std::cout << time.asSeconds() << " speed: " << speed << std::endl;
	}
	sprite.move(sf::Vector2f(time.asSeconds() * speed * wsp, 0));

}

void Unit::Animate()
{
	if (attacking) {
		AnimateAtack();
	}
	else if (moving) {
		AnimateMove();
	}
	else {
		AnimateIdle();
	}
}

void Unit::AnimateAtack()
{
	std::cout << "Animuje Atak\n";
}

void Unit::AnimateMove()
{
	
	if (this->clock_move_animation.getElapsedTime().asSeconds()>0.2)
	{
		this->sprite.setTextureRect(this->move_rects[this->current_frame]);
		std::cout << current_frame << "\n";
		if (this->current_frame < this->move_rects.size()-1)
		{
			this->current_frame +=1;
		}
		else {
			this->current_frame = 0;	
		}
		this->clock_move_animation.restart();
	}
}

void Unit::AnimateIdle()
{
	if (this->clock_move_animation.getElapsedTime().asSeconds() > 0.2)
	{
		this->sprite.setTextureRect(this->idle_rects[this->current_frame]);
		std::cout << current_frame << "\n";
		if (this->current_frame < this->idle_rects.size() - 1)
		{
			this->current_frame += 1;
		}
		else {
			this->current_frame = 0;
		}
		this->clock_move_animation.restart();
	}
}

int Unit::getSpeed() {
	return speed;
}

int Unit::getDmg() { return dmg; }
int Unit::getDmgRed() { return dmg_reduction; }

float Unit::getDmgDelay()
{
	return dmg_delay;
}

void Unit::sufferDmg(int sufferDmg_)
{
	hp -= sufferDmg_;
}

int Unit::getRange() { return range; }

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
