#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "InitCharacter.h"

class UserInterface 
{
private:

    sf::Clock clock_money_per_second;
    
    sf::RenderWindow* window;
    sf::Event* event;
    sf::Texture gui;
    sf::Font font;
    sf::Vector2f mouse_position;

    Age* age1;
    Age* age2;
    
    sf::Texture *cosmic_era_tex;
    sf::Sprite *background_sprite;
    

    /*
        BUTTONS
    */

    //Map of buttons
    std::map<std::string, sf::Sprite> buttons;
    std::map<std::string, sf::IntRect> buttons_animation_rects;

    //BUTTONS SETUP
    void initButtons();          //creating buttons
    void init_animation_rects(); //rects from texture

    void animate_concave_butt(std::string map_butt, std::string concave_map); //concave animation of button
    void animate_convex_butt(std::string map_butt, std::string convex_map);    //convex animation of button

    void button_blocked_animation(); //switching button animation to blocked
    bool canAfford(int price_); //checking if you have enough money to click button
    bool canUpgrade(int xp_);  //checking if you have enough xp to click button

    /*
        INTERFACE BACKGROUND *ONLY SPRITE*
    */
    sf::Sprite user_info;
    void init_user_info();

    /*
        GAME BACKGROUND
    */
    void changeAgeBackground();
    
    /*
        #MONEY
    */

    //Setting prices 
    int warrior_price = 70;
    int archer_price = 100;
    int boss_price = 200;

    //Prices in shop
    sf::Text gold;
    sf::Sprite coins[3];
    std::map<std::string, sf::Text> prices_in_shop;

    void init_prices();


    /*
        PLAYER RESOURCES
    */

    sf::Text current_gold;
    int curr_gold; 
    int curr_xp;   
    int curr_hp;   
    bool second_life; 
    int side;

    //xp_bar
    sf::Sprite xp_sprite;

    //hp_double_bar
    sf::Sprite hp_sprite_red;
    sf::Sprite hp_sprite_orange;

    //xp & hp_rects
    sf::IntRect xp_rect;
    sf::IntRect hp_rect_red;
    sf::IntRect hp_rect_orange;

    //Class player initation
    void initPlayer();

    //Uploading hp,xp,gold 
    void init_gold_amount();
    void init_xp_bar();
    void init_hp_bar();
    void initResources();

    //updating hp,xp from class Player
    void update_xp_bar();
    void update_hp_bar();
    void update_gold_per_second();
    void updateResources();

    //update background


    /*
        INIT CHARACTER QUEUE
    */
    const int max_of_queue = 3;
    std::vector<InitCharacter*> num_of_char_queue;
    int size_of_vec;
    void INIT_Character(std::map<std::string, sf::Sprite> buttons, std::string);

    //UPDATING LOADING QUEUE, REMOVING CHARACTER, CLEAN IT , CHAOS IN CODE
    void update_all_char();

public:
    Player* player;
    //constructor & destructor
    UserInterface(sf::Texture* texture, sf::RenderWindow* window_, sf::Event* event_, sf::Font* font_, Age* age1_, Age* age2_, int side_, sf::Sprite *sprite, sf::Texture *tex);
    ~UserInterface();

    void drawInterface();
    void pollEvents();
    //Poll events
    void update();

};

#endif // USERINTERFACE_H
