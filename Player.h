#ifndef PLAYER_H
#define PLAYER_H

#include <vector>
#include "Ages.h"

#define const_xp 43
#define const_hp 50
class Player
{
private:
    //GOLD & HP & XP
    int gold_amount;
    int hp;
    int xp;

    //Zegar
    sf::Clock clock;

    //Wskaünik na aktualnπ Ere
 
    sf::RenderWindow* window;

    Base* baza;
    void initVariables();
public:
    Age* age1;
    Age* age2;
    int side;
    Age* age_ptr;

    //CONSTRUCTOR
    Player(Age* age1, Age* age2, sf::RenderWindow* window_,int side_);

    //Wektor wskaünikÛw posiadanych jednostek
    std::vector<Unit*> units;
    std::vector<Arrow*> arrows;

    //CHANGING RESOURCES IN PLAYER CLASS
    void change_xp(int _xp);
    void change_hp(int _hp);
    void change_money(int _mone);

    //RETURNS ACTUAL RESOURCES
    int current_gold();
    int current_xp();
    int current_hp();
    Age* current_age();

    void update_arrows(); 
    void push_arrow(std::unique_ptr<Arrow> arrow_);
    void push_unit(std::unique_ptr<Unit> unit_);
    //void update_units();
    void draw_units();
    void checkDeads();
};

#endif // PLAYER_H
