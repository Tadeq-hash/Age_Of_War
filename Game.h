#ifndef GAME_H
#define GAME_H

#include "MainMenu.h"
#include "UserInterface.h"
#include "BotAlgorythm.h"
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

class Game
{
private:
    sf::RenderWindow* window;
    sf::Event* event;
    sf::VideoMode video_size;
    sf::Clock clock;

    void InitVariables();
    void LoadTextures();
    void LoadSounds();
    void LoadFonts();
    void InitWindow();
    void PollEvents();

private:
    sf::Texture* medieval_background_tex;
    sf::Texture* cosmic_background_tex;
    sf::Sprite* background_sprite;

    void InitBackground();

private:
    AgeOfKnights* age_of_knights;
    AgeOfGunpowder* age_of_gunpowder;

private:
    sf::Texture* interface_tex;
    sf::Font* digitals;
    sf::Font EndFont;
    sf::Text EndText;
    sf::Music music;

    UserInterface* interface;
    UserInterface* secondInterface;

    void initButtons();
    void drawInterface();
    void initBot();
    void initAges();

    bool Bot = true;
    bool Game_End = false;
    BotAlgorythm* Bot_Algorythm;

public:
    Game(bool bot_);
    ~Game();

    void playMusic();
    void update();
    void render();
    bool getWindowIsOpen();
    void CheckGameConditions();
    void GameWon();
    void GameLost();

    void update_units(std::vector<Unit*> units, std::vector<Unit*> enemies, sf::Clock* clock_);
    void move(std::vector<Unit*> units, std::vector<Unit*> enemies, sf::Clock* clock_);
    bool attack(Unit* atacker, Unit* victim);
    void update_arrows();
    void move_arrows();
    void colision_arrows();

};

#endif // GAME_H
