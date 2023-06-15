#ifndef GAME_H
#define GAME_H
#include "MainMenu.h"
#include "UserInterface.h"
#include "BotAlgorythm.h"
#include <SFML/Graphics.hpp>


class Game
{
private:

    /*
      ENTRY PRIVATE GAME SETUP
    */
    sf::RenderWindow* window;
    sf::Event* event;
    sf::VideoMode video_size;
    sf::Clock clock;
    
    void InitVariables();
    void LoadTextures();
    void LoadFonts();
    void InitWindow();
    void PollEvents();

private:

    /*
       BACKGROUND 
    */
    sf::Texture *medieval_background_tex;
    sf::Texture *cosmic_background_tex;
    sf::Sprite *background_sprite;

    void InitBackground();

private:

    /*
      AGE TEXTURES
    */

    AgeOfKnights* age_of_knights;
    AgeOfGunpowder* age_of_gunpowder;

private:

    /*
        USER INTERFACE 
    */

    
   


    sf::Texture* interface_tex;
    sf::Font* digitals;
    sf::Font EndFont;
    sf::Text EndText;

    UserInterface* interface;
    UserInterface* secondInterface;

    void initButtons();
    void drawInterface();
    void initBot();
    void initAges();

    /*
        TEMP
    */

    bool Bot = true;
    bool Game_End = false;
    BotAlgorythm* Bot_Algorythm;
public:

   


    /*
        CONSTRUCTOR & DESTRUCTOR
    */
    Game(bool bot_);
    ~Game();


    /*
        GAME LOOP
    */
    void update();
    void render();
    bool getWindowIsOpen();
    void CheckGameConditions();
    void GameWon();
    void GameLost();

  

    /*
        UNITS
    */
    void update_units(std::vector<Unit*> units, std::vector<Unit*> enemies, sf::Clock* clock_);
    void move(std::vector<Unit*> units,std::vector<Unit*> enemies, sf::Clock* clock_);
    bool attack(Unit* atacker, Unit* victim);
    void update_arrows();
    void move_arrows();
    void colision_arrows();
    
    //BOT TESTING   
    void testOnelyMakeBotWarrior();
    void testOnelyMakeBotArcher();
    void testOnelyMakeBotBoss();

};

#endif // GAME_H
