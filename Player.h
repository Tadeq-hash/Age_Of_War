#ifndef PLAYER_H
#define PLAYER_H

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

    //Wskaünik na aktualnπ Ere
    Age* age_ptr;

    void initVariables();
public:

    //CONSTRUCTOR
    Player();
    Player(Age* age1, Age* age2);

    //CHANGING RESOURCES IN PLAYER CLASS
    void change_xp(int _xp);
    void change_hp(int _hp);

    //RETURNS ACTUAL RESOURCES
    int current_gold();
    int current_xp();
    int current_hp();
    Age* current_age();

};

#endif // PLAYER_H
