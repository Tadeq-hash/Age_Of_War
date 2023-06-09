#ifndef GAME_H
#define GAME_H
#include "MainMenu.h"
#include "UserInterface.h"
#include <SFML/Graphics.hpp>


class Game
{
private:

    /*
      #GAME SETUP
    */
    sf::RenderWindow* window;
    sf::Event* event;
    sf::VideoMode video_size;
    sf::Clock clock;

    void InitVariables();
    void InitWindow();
    void PollEvents();
    void LoadTextures();
    void LoadFonts();


    /*
      #TEXTURES
    */



    //background
private:
    sf::Texture medieval_back_tex;
    sf::Sprite medieval_back_sprite;

    void InitBackground();

    /*
        #CLASS USER_INTERFACE INCLUDING BUTTONS
    */
    UserInterface* secondInterface;


    UserInterface* interface;
    sf::Texture* interface_tex;
    sf::Font* digitals;

    void initButtons();
    void drawInterface();
    void initBot();
    void initAges();

    /*
        #VARIABULES
    */

    bool Bot = true;
public:

    //Constructor / Destructor
    Game(bool bot_);
    ~Game();


    //  ! ! ! !  //
    // GAME LOOP //
    void update();
    void render();
    bool getWindowIsOpen();
    //  ! ! ! !  //


    ////Age Textures
    AgeOfKnights* age_of_knights;
    AgeOfGunpowder* age_of_gunpowder;

    //Funkcje do obs³ugi jednostek
    void update_units(std::vector<Unit*> units, std::vector<Unit*> enemies, sf::Clock* clock_);
    void move(std::vector<Unit*> units, sf::Clock* clock_);
    bool attack(Unit* atacker, Unit* victim);
    void testOnelyMakeBotWarrior();

};

#endif // GAME_H
