#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

/*
	ARROW FOR ARCHERS
*/
class Arrow : public sf::Sprite {

private:
	sf::Texture* texture;
	std::vector<sf::IntRect> frames;
	int current_frame = 0;

public:
	int side;
	int speed;
	int dmg;
	sf::Clock clock;
	Arrow() {};
	Arrow(sf::Texture* tex_, int side_, std::vector<sf::IntRect>& frames_);
	void Animate();
};

/*
	ENUM
*/
enum class Unit_type
{
	Warrior,
	Archer,
	Boss,
	Base
};

/*
	VIRTUAL CLASS
*/

class Unit :public Arrow
{
protected:

	sf::RenderWindow* window;
	sf::Texture* texture;

	int max_hp;
	float hp;
	int range;
	int dmg;
	int value;
	int speed;
	float dmg_reduction;
	float dmg_delay = 1;

	/*
		ANIMATIONS
	*/
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
	Arrow* arrow;

	/*
		CONSTRUCTORS & DESTRUCTOR
	*/
	Unit() {};
	Unit(sf::Texture* texture_, int &max_hp_, int &hp_, int &range_, int &dmg_, int &speed_, float &dmg_reduction_, int side_, sf::RenderWindow* window_, std::vector<sf::IntRect>& rects_idle, std::vector<sf::IntRect>& rects_move, std::vector<sf::IntRect>& rects_attack, std::vector<sf::IntRect>& rects_die, float scale, int value_);
	
	~Unit();

	/*
		ACTION METHODS
	*/
	virtual void attack(sf::Clock* clock_);
	void move(sf::Clock* clock_);
	std::unique_ptr<Arrow> MakeArrow();


	//ANIMATIONS
	sf::Clock clock_move_animation;
	void Animate(int hp);
	void AnimateAtack();
	void AnimateMove();
	void AnimateIdle();
	void AnimateDie();

	//SETTINGS
	int return_hp();
	int getSpeed();
	int getRange();
	int getDmg();
	int getDmgRed();
	int getValue();
	float getDmgDelay();
	void sufferDmg(int sufferDmg_);

	//DRAW
	void draw(sf::RenderWindow* window_);
	
};

/*
	WARRIOR
*/
class Warrior : public Unit
{
public:
	//CONSTRUCTOR
	using Unit::Unit;
};

/*
	ARCHER
*/
class Archer : public Unit
{
public:
	//CONSTRUCTOR
	using Unit::Unit;
};

/*
	BOSS
*/
class Boss : public Unit
{
public:
	//CONSTRUCTOR
	using Unit::Unit;
};

/*
	BASE
*/
class Base : public Unit 
{
private:
	sf::Texture First_era;
	sf::Texture Second_era;
public:
	Base(sf::RenderWindow* window_, float side_);

};