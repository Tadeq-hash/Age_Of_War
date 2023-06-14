#ifndef MAINMENU_H
#define MAINMENU_H
#include <SFML/Graphics.hpp>
#include <iostream>

#define max_buttons 4

class MainMenu {

private:
    sf::VideoMode video_mode_size;
    sf::RenderWindow* window;
    sf::Event event;

    bool Bot;
    int MainMenuSelected;

    /*
        MENU BUTTONS & FONT
    */
    sf::Font font;
    sf::Text M_M_Text[max_buttons];

    /*
        PRIVATE METHODS
    */
    void pollEvents();
    void initVariables();
    void initWindow();
    void loadButtons();
public:

    /*
        CONSTRUCTOR & DESTRUCTOR
    */
    MainMenu();
    ~MainMenu();

    
    /*
        MENU ACTIONS
    */
    void MoveUp();
    void MoveDown();
    int MainMenuPressed();


    /*
        GAME
    */
    void Game_run();
    
    /*
        OPTIONS
    */
    void Options_run();
    
    /*
        CREDITS
    */
    void Credits_run();
  
    /*
        MAIN MENU LOOP
    */
    bool getWindowIsOpen();
    void update();
    void render();
    void draw(sf::RenderWindow& window);
};

#endif // MAINMENU_H
