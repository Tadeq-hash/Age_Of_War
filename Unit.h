#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

//  - klasa wyliczeniowa - 
	/*Do przycisków*/
enum class Unit_type
{
	Warrior,
	Archer,
	Boss
};



//	-- klasa abstraktyjna --

class Unit
{
	sf::RenderWindow* window;
	sf::Texture* texture;
	int max_hp;
	float hp;
	int range;
	int dmg;
	int speed;
	float dmg_reduction;
	float dmg_delay = 1;

	//ANIMATIONS
	std::vector<sf::IntRect> idle_rects;
	std::vector<sf::IntRect> move_rects;
	std::vector<sf::IntRect> attack_rects;
	std::vector<sf::IntRect> die_rects;
	int current_frame_move = 0;
	int current_frame_idle = 0;
	int current_frame_attack = 0;
	int current_frame_die = 0;



public:

	sf::Clock clockAttack;
	sf::Clock clockMove;
	sf::Clock clockDie;
	float side;
	bool attacking = 0;
	bool moving = 0;
	bool die = 0;
	sf::Sprite sprite;
	Unit_type unit_type;
	//	KONSTRUKTOR
	Unit(sf::Texture* texture_, int &max_hp_, int &hp_, int &range_, int &dmg_, int &speed_, float &dmg_reduction_, int side_, sf::RenderWindow* window_, std::vector<sf::IntRect>& rects_idle, std::vector<sf::IntRect>& rects_move, std::vector<sf::IntRect>& rects_attack, std::vector<sf::IntRect>& rects_die);
	// DESTRUKTOR
	~Unit();
	virtual void attack(sf::Clock* clock_);
	void move(sf::Clock* clock_);

	//ANIMATIONS

	sf::Clock clock_move_animation;
	void Animate(int hp);
	void AnimateAtack();
	void AnimateMove();
	void AnimateIdle();
	void AnimateDie();


	//void update();
	void draw(sf::RenderWindow* window_);
	int return_hp();
	int getSpeed();
	int getRange();
	int getDmg();
	int getDmgRed();
	float getDmgDelay();
	void sufferDmg(int sufferDmg_);
	
};

//	-----KLASA WOJOWNIKA-----

class Warrior : public Unit
{

public:
	// KONSTRUKTOR
	using Unit::Unit;

	Unit_type unit_type = Unit_type::Warrior;

};

//	-----KLASA £UCZNIKA-----

class Archer : public Unit
{

public:
	// KONSTRUKTOR
	using Unit::Unit;

	Unit_type unit_type = Unit_type::Archer;

};

//	-----KLASA BOSS-----

class Boss : public Unit
{

public:
	// KONSTRUKTOR
	using Unit::Unit;

	Unit_type unit_type = Unit_type::Boss;

};
