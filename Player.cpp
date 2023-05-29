#include "Player.h"

//CONSTRUCTORS
Player::Player()
{
    this->initVariables();
    std::cout << "Tworze player" << std::endl;
    //age_ptr = 
}

//Player::Player(Age* age1, Age* age2)
//{
//    this->initVariables();
//    age_ptr = age1;
//}

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



