#include "Player.h"

Player::Player(Age* age1_, Age* age2_, sf::RenderWindow* window_, int side_)
{
    this->initVariables();
    age1 = age1_;
    age2 = age2_;
    age_ptr = age1;
    window = window_;
    side = side_;
    this->side = side_;
    baza = new Base(window,side);
    units.push_back(baza);
}

void Player::initVariables()
{
    this->hp = const_hp; // it's 100, because second life of orange bar
    this->gold_amount = 1000;
    this->xp = 20;
}

void Player::change_xp(int _xp)
{
    this->xp = _xp;
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
    std::cout << "Odbieram strzale\n";
    arrows.push_back(arrow_.release());
    std::cout << "Ilosc strzal w wektorze gracza wynosi: " << arrows.size() << std::endl;
}


void Player::push_unit(std::unique_ptr<Unit> unit_) {
    std::cout << "Odbieram jednostke\n";
    units.push_back(unit_.release());
    std::cout << "Ilosc jednostek w wektorze gracza wynosi: " << units.size() << std::endl;
}


//void Player::update_units() {
//    for (int i = 0; i < units.size(); ++i) {
//        units[i]->move(&clock);
//        //Unit* unitptr = units[i].get();
//    }
//    for (int i = 0; i < units.size(); ++i) {
//        units[i]->attack(&clock);
//    }
//    for (int i = 0; i < units.size(); ++i) {
//        //units[i]->update();
//    }
//    clock.restart();
//}

void Player::update_arrows() {
    for (int i = 0; i < arrows.size(); i++) {
        arrows[i]->Animate();
    }
}

void Player::draw_units() {
    //std::cout << "Rysuje jednostki...\n";
    //
    //if (units.size() > 0) {
    //    std::cout << "Jednostka na 1 miejscu ma hp: " << units[0]->return_hp() << std::endl;
    //}
    for (int i = 0; i < arrows.size(); i++) {
        window->draw(*arrows[i]);
    }
    for (int i = units.size()-1; i >= 0 ; --i) {
        units[i]->draw(window);
    }
}

void Player::checkDeads() {
    for (int i = 0; i < units.size(); i++) {
        if (units[i]->die == true) {
            units.erase(units.begin() + i);
            i--;
        }
        else if (units[i]->unit_type == Unit_type::Base) {
            if (units[i]->return_hp() <= 0) {
                units.erase(units.begin() + i);
                i--;
            }
        }
    }
}

void Player::updatePlayerHp()
{
    hp = units[0]->return_hp();
}

