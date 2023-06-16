#include "Player.h"
#include "Game.h"
Player::Player(Age* age1_, Age* age2_, sf::RenderWindow* window_, int side_)
{
    
    age1 = age1_;
    age2 = age2_;
    age_ptr = age1;
    window = window_;
    side = side_;
    this->side = side_;
    this->initVariables();
    
}

void Player::initVariables()
{
    //PLAYER RESOURCES
    if (this->side == 1)
    {
        this->hp = 500;
        this->gold_amount = 500;
        this->xp = 0;
    }
    //ENEMY RESOURCES
    if (this->side == -1)
    {
        this->hp = 500;
        this->gold_amount = 800;
        this->xp = 0;
    }

    isAlive = 1;
    baza = new Base(window, side);
    units.push_back(baza);
}

void Player::change_xp(int _xp)
{
    this->xp+=_xp;
}

void Player::change_hp(int _hp)
{
    this->hp = _hp;
}

void Player::change_money(int _mone)
{
    this->gold_amount += _mone;
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

void Player::push_arrow(std::unique_ptr<Arrow> arrow_) {
    arrows.push_back(arrow_.release());
}


void Player::push_unit(std::unique_ptr<Unit> unit_) {
    units.push_back(unit_.release());
}


void Player::update_arrows() {
    for (int i = 0; i < arrows.size(); i++) {
        arrows[i]->Animate();
    }
}

void Player::draw_units() {
    for (int i = 0; i < arrows.size(); i++) {
        window->draw(*arrows[i]);
    }
    for (int i = units.size() - 1; i >= 0; --i) {
        units[i]->draw(window);
    }  
}

void Player::checkDeads(Player *player_2) {
    for (int i = 0; i < units.size(); i++) {
        if (units[i]->die) { 

            player_2->change_money(units[i]->getValue());
            player_2->change_xp(3);
            units.erase(units.begin() + i);
            i--;
        }
    }
}

void Player::updatePlayerHp()
{
    hp = units[0]->return_hp();
}

