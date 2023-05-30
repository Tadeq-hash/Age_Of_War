#include "Player.h"

//CONSTRUCTORS
Player::Player()
{
    this->initVariables();
}

Player::Player(Age* age1, Age* age2)
{
    this->initVariables();
    age_ptr = age1;
}

void Player::initVariables()
{
    this->hp=const_hp; // it's 100, because second life of orange bar
    this->gold_amount=200;
    this->xp=20;
}

void Player::change_xp(int _xp)
{
    this->xp=_xp;
}

void Player::change_hp(int _hp)
{
    this->hp=_hp;
}

int Player::current_gold()
{
    return this->gold_amount;
}

int Player::current_xp()
{
    return this->xp;
}

int Player::current_hp()
{
    return this->hp;
}

Age* Player::current_age() 
{
    return this->age_ptr;
}


void Player::push_unit(Unit* unit_) {
    units.push_back(unit_);
    std::cout << "Ilosc jednostek w wektorze gracza wynosi: " << units.size() << std::endl;
    std::cout << "Na miejscu pierwszym: " << units[0]->return_hp() << std::endl;
    current_age()->MakeWarrior();
}


void Player::update_units() {
    for (int i = 0; i < units.size(); ++i) {
        units[i]->move();
    }
    for (int i = 0; i < units.size(); ++i) {
        units[i]->attack();
    }
    for (int i = 0; i < units.size(); ++i) {
        units[i]->update();
    }
}
