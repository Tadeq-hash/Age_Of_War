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
    Age* age1;
    Age* age2;
    sf::RenderWindow* window;


    void initVariables();
public:
    Age* age_ptr;

    //CONSTRUCTOR
    Player();
    Player(Age* age1, Age* age2, sf::RenderWindow* window_);

    //Wektor wskaünikÛw posiadanych jednostek
    std::vector<Unit*> units;

    //CHANGING RESOURCES IN PLAYER CLASS
    void change_xp(int _xp);
    void change_hp(int _hp);

    //RETURNS ACTUAL RESOURCES
    int current_gold();
    int current_xp();
    int current_hp();
    Age* current_age();

    void push_unit(std::unique_ptr<Unit> unit_);
    void update_units();
    void draw_units();
};

#endif // PLAYER_H
