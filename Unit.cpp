#include "Unit.h"

//   -- KLASA UNIT --

//4 wektory animacji



//	KONSTRUKTOR
Unit::Unit(sf::Texture* texture_, int &max_hp_, int &hp_, int &range_, int &dmg_, int &speed_, float &dmg_reduction_, int side_, sf::RenderWindow* window_, std::vector<sf::IntRect>& rects_idle, std::vector<sf::IntRect>& rects_move, std::vector<sf::IntRect>& rects_attack, std::vector<sf::IntRect>& rects_die, float scale) {
	window = window_;
	side = side_;
	texture = texture_;
	max_hp = max_hp_;
	hp = hp_;
	range = range_;
	dmg = dmg_;
	speed = speed_;
	//std::cout << "speed: " << speed<<"\n";
	//std::cout << "health: " << hp<<"\n";
	dmg_reduction = dmg_reduction_;
	this->idle_rects = rects_idle;
	this->move_rects = rects_move;
	this->attack_rects = rects_attack;
	this->die_rects = rects_die;
	sprite.setOrigin(0,sprite.getGlobalBounds().height);
	sprite.setTexture(*texture);
	sprite.setScale(side*scale, scale);
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

void Unit::Animate(int hp)
{
	
		if (hp >5)
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
		else
		{
			AnimateDie();
		}
	
	

}

void Unit::AnimateAtack()
{
	if (this->clock_move_animation.getElapsedTime().asSeconds() > 0.15)
	{
		this->sprite.setTextureRect(this->attack_rects[this->current_frame_attack]);
		//std::cout << current_frame_attack << "\n";
		if (this->current_frame_attack < this->attack_rects.size() - 1)
		{
			this->current_frame_attack += 1;
		}
		else {
			this->current_frame_attack = 0;
		}
		this->clock_move_animation.restart();
	}
}

void Unit::AnimateMove()
{
	
	if (this->clock_move_animation.getElapsedTime().asSeconds()>0.15)
	{
		this->sprite.setTextureRect(this->move_rects[this->current_frame_move]);
		//std::cout << current_frame_move << "\n";
		if (this->current_frame_move < this->move_rects.size()-1)
		{
			this->current_frame_move +=1;
		}
		else {
			this->current_frame_move = 0;	
		}
		this->clock_move_animation.restart();
	}
}

void Unit::AnimateIdle()
{
	if (this->clock_move_animation.getElapsedTime().asSeconds() > 0.15)
	{
		this->sprite.setTextureRect(this->idle_rects[this->current_frame_idle]);
		//std::cout << current_frame_idle << "\n";
		if (this->current_frame_idle < this->idle_rects.size() - 1)
		{
			this->current_frame_idle += 1;
		}
		else {
			this->current_frame_idle = 0;
		}
		this->clock_move_animation.restart();
	}
}

void Unit::AnimateDie()
{
	//std::cout << "DIEDIEDIE\n";
	if (this->clock_move_animation.getElapsedTime().asSeconds() > 0.1)
	{
		this->sprite.setTextureRect(this->die_rects[this->current_frame_die]);
		//std::cout << current_frame_die << "\n";
		if (this->current_frame_die < this->die_rects.size() - 1)
		{
			this->current_frame_die += 1;
		}
		else {
			this->current_frame_die = 0;
			this->die = true;
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
	
}



Arrow::Arrow(sf::Texture* tex_, int side_, std::vector<sf::IntRect>& frames_)
{
	side = side_;
	frames = frames_;
	texture = tex_;
	setTexture(*texture);
	setTextureRect(frames[0]);
}

void Arrow::Animate() {
	if (this->clock.getElapsedTime().asSeconds() > 0.15)
	{
		setTextureRect(frames[current_frame]);
		//std::cout << current_frame_move << "\n";
		if (this->current_frame < this->frames.size() - 1)
		{
			this->current_frame += 1;
		}
		else {
			this->current_frame = 0;
		}
		this->clock.restart();
	}
}

std::unique_ptr<Arrow> Unit::MakeArrow()
{
	Arrow arr = *arrow;
	arr.side = Unit::side;
	arr.setPosition(sprite.getGlobalBounds().left + ((side + 1) / (2))*(-55) + 95, sprite.getGlobalBounds().top + 70);
	arr.setScale(2 * side, 2);
	return std::make_unique<Arrow>(arr);
}
