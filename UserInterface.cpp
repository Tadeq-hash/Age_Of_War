#include "UserInterface.h"
#include <iostream>
#include <string>



//--CONSTRUCTOR & DESTRUCTOR--//

UserInterface::UserInterface(sf::Texture* texture, sf::RenderWindow* window_, sf::Event* event_, sf::Font* font_, Age* age1_, Age* age2_,int side_, sf::Sprite* sprite, sf::Texture* tex)
{
    this->side = side_;
    this->gui = *texture;
    this->window = window_;
    this->font = *font_;
    this->event = event_;
    this->age1 = age1_;
    this->age2 = age2_;
    this->background_sprite = sprite;
    this->cosmic_era_tex = tex;

    initPlayer();
    initResources();
    init_animation_rects();
    initButtons();
    init_user_info(0);
    init_prices();
}

UserInterface::~UserInterface()
{
    delete this->player;
}

//---------------------------//

/*
    #FROM CLASS PLAYER
*/
void UserInterface::initPlayer()
{
    this->player = new Player(age1, age2, window, side);
    this->curr_gold = player->current_gold();
    this->curr_xp = player->current_xp();
    this->curr_hp = player->current_hp();
}

/*
    #INITS ANIMATION RECTS
*/

void UserInterface::init_animation_rects()
{
    this->last_era = 0;

    //convex (default)
    this->buttons_animation_rects["exit_convex"] = sf::IntRect(1, 81, 14, 14);
    this->buttons_animation_rects["warrior_convex"] = sf::IntRect(71, 178, 14, 14);
    this->buttons_animation_rects["archer_convex"] = sf::IntRect(88, 178, 14, 14);
    this->buttons_animation_rects["boss_convex"] = sf::IntRect(105, 178, 14, 14);
    this->buttons_animation_rects["upgrade_convex"] = sf::IntRect(121, 178, 14, 14);

    //concave
    this->buttons_animation_rects["exit_conc"] = sf::IntRect(48, 209, 14, 13);
    this->buttons_animation_rects["warrior_conc"] = sf::IntRect(71, 194, 14, 13);
    this->buttons_animation_rects["archer_conc"] = sf::IntRect(88, 194, 14, 13);
    this->buttons_animation_rects["boss_conc"] = sf::IntRect(106, 194, 14, 13);
    this->buttons_animation_rects["upgrade_conc"] = sf::IntRect(121, 194, 14, 13);

    //blocked
    this->buttons_animation_rects["warrior_blocked"] = sf::IntRect(71, 208, 14, 14);
    this->buttons_animation_rects["archer_blocked"] = sf::IntRect(88, 208, 14, 14);
    this->buttons_animation_rects["boss_blocked"] = sf::IntRect(106, 208, 14, 14);
    this->buttons_animation_rects["upgrade_blocked"] = sf::IntRect(122, 208, 14, 14);


}

/*
    #INIT PRICES IN SHOP INTERFACE
*/
void UserInterface::init_prices()
{


    sf::Text warrior_price;
    warrior_price.setFont(this->font);
    warrior_price.setCharacterSize(7);
    warrior_price.setOutlineColor(sf::Color::Yellow);
    warrior_price.setOutlineThickness(0.3);
    warrior_price.setFillColor(sf::Color::Yellow);
    warrior_price.setString(std::to_string(this->warrior_price));
    warrior_price.setPosition(this->buttons["warrior"].getPosition().x + 7, this->buttons["warrior"].getPosition().y + this->buttons["warrior"].getGlobalBounds().height + 12);
    this->prices_in_shop["warrior_price"] = warrior_price;

    sf::Text archer_price;
    archer_price.setFont(this->font);
    archer_price.setCharacterSize(7);
    archer_price.setOutlineColor(sf::Color::Yellow);
    archer_price.setOutlineThickness(0.3);
    archer_price.setFillColor(sf::Color::Yellow);
    archer_price.setString(std::to_string(this->archer_price));
    archer_price.setPosition(this->buttons["archer"].getPosition().x + 6, this->buttons["archer"].getPosition().y + this->buttons["archer"].getGlobalBounds().height + 12);
    this->prices_in_shop["archer_price"] = archer_price;

    sf::Text boss_price;
    boss_price.setFont(this->font);
    boss_price.setCharacterSize(7);
    boss_price.setFillColor(sf::Color::Yellow);
    boss_price.setOutlineColor(sf::Color::Yellow);
    boss_price.setOutlineThickness(0.3);
    boss_price.setString(std::to_string(this->boss_price));
    boss_price.setPosition(this->buttons["boss"].getPosition().x + 6, this->buttons["boss"].getPosition().y + this->buttons["boss"].getGlobalBounds().height + 12);
    this->prices_in_shop["boss_price"] = boss_price;



    coins[0].setTexture(this->gui);
    coins[1].setTexture(this->gui);
    coins[2].setTexture(this->gui);

    coins[0].setTextureRect(sf::IntRect(137, 22, 5, 6));
    coins[0].setScale(2, 2);
    coins[0].setPosition(this->prices_in_shop["warrior_price"].getPosition().x + this->prices_in_shop["warrior_price"].getGlobalBounds().width + 6, this->prices_in_shop["warrior_price"].getGlobalBounds().top);

    coins[1].setTextureRect(sf::IntRect(137, 22, 5, 6));
    coins[1].setScale(2, 2);
    coins[1].setPosition(this->prices_in_shop["archer_price"].getPosition().x + this->prices_in_shop["archer_price"].getGlobalBounds().width + 6, this->prices_in_shop["archer_price"].getGlobalBounds().top);

    coins[2].setTextureRect(sf::IntRect(137, 22, 5, 6));
    coins[2].setScale(2, 2);
    coins[2].setPosition(this->prices_in_shop["boss_price"].getPosition().x + this->prices_in_shop["boss_price"].getGlobalBounds().width + 6, this->prices_in_shop["boss_price"].getGlobalBounds().top);

}

void UserInterface::changeAgeBackground()
{
    this->background_sprite->setTexture(*this->cosmic_era_tex);
}

/*
    #INITS RESOURCES XP & GOLD & HP
*/
void UserInterface::initResources()
{
    this->init_gold_amount();
    this->init_xp_bar();
    this->init_hp_bar();
}

void UserInterface::init_gold_amount()
{

    this->gold.setCharacterSize(15);
    this->gold.setFont(this->font);
    this->gold.setFillColor(sf::Color::White);
    if (this->side==1)
    {
        this->gold.setPosition(162, 78);
    }
    if(this->side==-1)
    {
        this->gold.setPosition(1920 - 225, 78);
    }
    
    this->gold.setString(std::to_string(this->curr_gold));
}

void UserInterface::init_xp_bar()
{
    this->xp_rect = sf::IntRect(72, 6, this->curr_xp, 3);
    this->xp_sprite.setTexture(this->gui);
    this->xp_sprite.setTextureRect(this->xp_rect);
    
    if (this->side == 1)
    {
        this->xp_sprite.setPosition(117, 36);
        this->xp_sprite.setScale(4.5, 4.7);
    }
    
    if (this->side == -1)
    {
        this->xp_sprite.setPosition(1803, 36);
        this->xp_sprite.setScale(-4.5, 4.7);
    }
    
    
}

void UserInterface::init_hp_bar()
{
    this->hp_rect_red = sf::IntRect(72, 22, 49, 3); // red bar
    this->hp_sprite_red.setTexture(this->gui);
    this->hp_sprite_red.setTextureRect(this->hp_rect_red);

    if (this->side == 1)
    {
        this->hp_sprite_red.setScale(4.5, 4.7);
        this->hp_sprite_red.setPosition(117, 9); // Player's hp_bar position
    }
    else if (this->side == -1)
    {

        this->hp_sprite_red.setScale(-4.5, 4.7);
        this->hp_sprite_red.setPosition(1803, 9); // Enemy's hp_bar position
    }
}


/*
    #INIT BUTTONS (SETTINGS, DEFAULTS)
*/
void UserInterface::initButtons()
{
    sf::Sprite background_of_ui;
    background_of_ui.setTexture(this->gui);
    background_of_ui.setTextureRect(sf::IntRect(2, 34, 74, 44));
    background_of_ui.setScale(4.5, 2.6);
    background_of_ui.setPosition(405, -1);
    this->buttons["a_background_of_ui"] = background_of_ui;

    sf::Sprite exit_butt;
    exit_butt.setTexture(this->gui);
    exit_butt.setTextureRect(this->buttons_animation_rects["exit_convex"]);
    exit_butt.setPosition(450, 20);
    exit_butt.setScale(3, 3);
    this->buttons["exit"] = exit_butt;

    sf::Sprite warrior;
    warrior.setTexture(this->gui);
    warrior.setTextureRect(this->buttons_animation_rects["warrior_convex"]);
    warrior.setScale(3, 3);
    warrior.setPosition(500, 20);
    this->buttons["warrior"] = warrior;

    sf::Sprite archer;
    archer.setTexture(this->gui);
    archer.setTextureRect(this->buttons_animation_rects["archer_convex"]);
    archer.setScale(3, 3);
    archer.setPosition(550, 20);
    this->buttons["archer"] = archer;

    sf::Sprite boss;
    boss.setTexture(this->gui);
    boss.setTextureRect(this->buttons_animation_rects["boss_convex"]);
    boss.setScale(3, 3);
    boss.setPosition(600, 20);
    this->buttons["boss"] = boss;

    sf::Sprite upgrade_era;
    upgrade_era.setTexture(this->gui);
    upgrade_era.setTextureRect(this->buttons_animation_rects["upgrade_convex"]);
    upgrade_era.setScale(3, 3);
    upgrade_era.setPosition(650, 20);
    this->buttons["upgrade_era"] = upgrade_era;



}

/*
    #UPDATE RESOURCES XP & GOLD & HP FROM CLASS PLAYER
*/

void UserInterface::updateResources()
{
    this->curr_gold = this->player->current_gold();
    this->curr_xp = this->player->current_xp();
    this->curr_hp = this->player->current_hp();

    this->gold.setString(std::to_string(this->curr_gold));   //display money amount in interface

}

/*
    ANIMATIONS OF HEALTH & XP BAR
*/

void UserInterface::update_xp_bar()
{
    if (this->curr_xp >= 43)
    {
        this->xp_rect = sf::IntRect(8, 6, 43, 3);
        this->xp_sprite.setTextureRect(this->xp_rect);
    }
    else
    {
        this->xp_rect = sf::IntRect(72, 6, this->curr_xp, 3);
        this->xp_sprite.setTextureRect(this->xp_rect);
    }
}

void UserInterface::update_hp_bar()
{
    player->updatePlayerHp();
    curr_hp = player->current_hp();
    if (this->curr_hp > 0 )
    {
        anim_rect = sf::IntRect(72, 22, (this->curr_hp / 10) - 1, 3);
        this->hp_sprite_red.setTextureRect(anim_rect);

    }

}

void UserInterface::update_gold_per_second()
{
    this->player->change_money(1);
}

/*
    ANIMATIONS OF BUTTON 'BLOCKED', 'CONCAVE', 'CONVEX
*/

//BLOCKED
void UserInterface::button_blocked_animation()
{
    if (!this->canAfford(this->warrior_price))
    {
        this->buttons["warrior"].setTextureRect(this->buttons_animation_rects["warrior_blocked"]);
    }
    else
    {
        this->buttons["warrior"].setTextureRect(this->buttons_animation_rects["warrior_convex"]);
    }
    if (!this->canAfford(this->archer_price))
    {
        this->buttons["archer"].setTextureRect(this->buttons_animation_rects["archer_blocked"]);
    }
    else
    {
        this->buttons["archer"].setTextureRect(this->buttons_animation_rects["archer_convex"]);
    }
    if (!this->canAfford(this->boss_price))
    {
        this->buttons["boss"].setTextureRect(this->buttons_animation_rects["boss_blocked"]);
    }
    else
    {
        this->buttons["boss"].setTextureRect(this->buttons_animation_rects["boss_convex"]);
    }
    if (!this->canUpgrade(const_xp) || last_era)
    {
        this->buttons["upgrade_era"].setTextureRect(this->buttons_animation_rects["upgrade_blocked"]);
    }
    else
    {
        this->buttons["upgrade_era"].setTextureRect(this->buttons_animation_rects["upgrade_convex"]);
    }

}
//CONCAVE
void UserInterface::animate_concave_butt(std::string map_butt, std::string concave_map)
{
    this->buttons[map_butt].setTextureRect(this->buttons_animation_rects[concave_map]);
    this->buttons[map_butt].setPosition(this->buttons[map_butt].getPosition().x, this->buttons[map_butt].getPosition().y + 2);
}

//CONVEX
void UserInterface::animate_convex_butt(std::string map_butt, std::string convex_map)
{
    this->buttons[map_butt].setTextureRect(this->buttons_animation_rects[convex_map]);
    this->buttons[map_butt].setPosition(this->buttons[map_butt].getPosition().x, this->buttons[map_butt].getPosition().y - 2);
}

/*
    #UPDATING ANIMATIONS (IF ENOUGH MONEY OR XP)
*/
bool UserInterface::canAfford(int price_)
{
    if (this->curr_gold >= price_)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool UserInterface::canUpgrade(int xp_)
{
    if (this->curr_xp >= xp_)
    {
        return true;
    }
    else
    {
        return false;
    }
}



/*
    #INITS ONLY BACKGROUND OF INTERFACE
*/
void UserInterface::init_user_info(bool bot_)
{
    
    this->user_info.setTexture(this->gui);
    this->user_info.setTextureRect(sf::IntRect(96, 36, 77, 24));
    if (this->side==1)
    {
        this->user_info.setScale(4.5, 4.5);
        this->user_info.setPosition(0, 0);
    }
    if(this->side==-1)
    {
        this->user_info.setScale(-4.5, 4.5);
        this->user_info.setPosition(1920, 0);
    }
    
   

}

/*
    #DRAWING
*/
void UserInterface::drawInterface()
{
    
        this->window->draw(this->user_info);
        this->window->draw(this->gold);
        this->window->draw(this->xp_sprite);
        this->window->draw(this->hp_sprite_red);

        if (this->side==1)
        {
            for (const auto& button : this->buttons)
            {
                this->window->draw(button.second);
            }

            for (const auto& price : this->prices_in_shop)
            {
                this->window->draw(price.second);
            }

            for (const auto& coin : coins)
            {
                this->window->draw(coin);
            }

            if (this->num_of_char_queue.size() >= 0)
            {
                for (const auto& charc : this->num_of_char_queue)
                {
                    charc->drawButton();
                    this->num_of_char_queue[0]->bar_init();
                }
            }
        }
}

/*
    #UPDATING
*/
void UserInterface::update()
{
    this->button_blocked_animation();
    this->updateResources();
    this->update_xp_bar();
    this->update_hp_bar();
    this->update_all_char();

    if (this->clock_money_per_second.getElapsedTime().asSeconds() > 0.25f)
    {
        this->update_gold_per_second();
        this->clock_money_per_second.restart();
    }
   
}


//INITING AND CHECKING IF QUEUE HAS ONLY 3 CHARACTERS
void UserInterface::INIT_Character(std::map<std::string, sf::Sprite> buttons, std::string charac)
{
    this->size_of_vec = this->num_of_char_queue.size() + 1;
    if (this->num_of_char_queue.size() < max_of_queue)
    {
        //std::cout << "Respawning" << charac << "\n";
        InitCharacter* character = new InitCharacter(charac, this->buttons[charac], this->window, this->num_of_char_queue.size(), this->gui, player);
        this->num_of_char_queue.emplace_back(character);
    }

}

//UPDATING CHARACTERS FROM VECTOR
void UserInterface::update_all_char()
{
    //std::cout << this->num_of_char_queue.size()<<"\n";

    for (const auto& character : num_of_char_queue)
    {
        character->update(num_of_char_queue, this->num_of_char_queue.size());
    }
}

//BUTTON EVENTS LOOP
void UserInterface::pollEvents()
{

    this->mouse_position = window->mapPixelToCoords(sf::Mouse::getPosition(*window));
    if (this->event->type == sf::Event::MouseButtonPressed)
    {

        if (this->event->mouseButton.button == sf::Mouse::Left)
        {
            if (this->buttons["exit"].getGlobalBounds().contains(mouse_position))
            {
                this->animate_concave_butt("exit", "exit_conc");
            }
            if (this->buttons["warrior"].getGlobalBounds().contains(mouse_position) && this->canAfford(this->warrior_price))
            {
                this->animate_concave_butt("warrior", "warrior_conc");
              

            }
            if (this->buttons["archer"].getGlobalBounds().contains(mouse_position) && this->canAfford(this->archer_price))
            {
                this->animate_concave_butt("archer", "archer_conc");
               
            }
            if (this->buttons["boss"].getGlobalBounds().contains(mouse_position) && this->canAfford(this->boss_price))
            {
                this->animate_concave_butt("boss", "boss_conc");
              
            }
            if (this->buttons["upgrade_era"].getGlobalBounds().contains(mouse_position) && this->canUpgrade(const_xp) && !last_era)
            {
                this->animate_concave_butt("upgrade_era", "upgrade_conc");
            }
        }
    }
    if (this->event->type == sf::Event::MouseButtonReleased)
    {

        //BUTTONS ACTIONS

        if (this->buttons["exit"].getGlobalBounds().contains(mouse_position))
        {   //EXIT
            this->animate_convex_butt("exit", "exit_convex");
            this->window->close();
        }
        if (this->buttons["warrior"].getGlobalBounds().contains(mouse_position) && this->canAfford(this->warrior_price))
        {   //WARRIOR
            this->animate_convex_butt("warrior", "warrior_convex");
            this->INIT_Character(this->buttons, "warrior");
            
            if (this->size_of_vec < 4)
            {
                this->player->change_money(-this->warrior_price);
            }
        }

        if (this->buttons["archer"].getGlobalBounds().contains(mouse_position) && this->canAfford(this->archer_price))
        {   //ARCHER
            this->animate_convex_butt("archer", "archer_convex");
            this->INIT_Character(this->buttons, "archer");
      
            if (this->size_of_vec < 4)
            {
                this->player->change_money(-this->archer_price);
            }

        }


        if (this->buttons["boss"].getGlobalBounds().contains(mouse_position) && this->canAfford(this->boss_price))
        {
            //BOSS
            this->animate_convex_butt("boss", "boss_convex");
            this->INIT_Character(this->buttons, "boss");
            
            if (this->size_of_vec < 4)
            {
                this->player->change_money(-this->boss_price);
            }

        }

        if (this->buttons["upgrade_era"].getGlobalBounds().contains(mouse_position) && this->canUpgrade(const_xp) && !last_era)
        {
            //UPGRADE
            this->animate_convex_butt("upgrade_era", "upgrade_convex");
            std::cout << "Welcome to the new era \n";
            last_era = 1;
            if (player->age_ptr == age1) {
                player->age_ptr = age2;
                player->units[0]->sprite.setTexture(player->age_ptr->base_texture);
                player->units[0]->sprite.setScale(9.5 , 8.5);
                player->units[0]->sprite.setTextureRect(sf::IntRect(0, 0, 23, 40));
                player->units[0]->sprite.setPosition(-10 + ((1 - side) / 2) * 1940, 648);
            }
            changeAgeBackground();
            this->buttons["upgrade_era"].setTextureRect(this->buttons_animation_rects["upgrade_blocked"]);
        }

    }

    //CHECKING {LINES TO REMOVE}
    if (this->event->type == sf::Event::KeyPressed)
    {

        if (this->event->key.code == sf::Keyboard::Left)
        {
            this->curr_xp--;
            this->player->change_xp(this->curr_xp);

        }

        if (this->event->key.code == sf::Keyboard::Right)
        {
            this->curr_xp++;
            this->player->change_xp(this->curr_xp);

        }

        if (this->event->key.code == sf::Keyboard::Up)
        {
            this->curr_hp++;
            this->player->change_hp(this->curr_hp);

        }

        if (this->event->key.code == sf::Keyboard::Down)
        {
            this->curr_hp--;
            this->player->change_hp(this->curr_hp);

        }
    }

}


