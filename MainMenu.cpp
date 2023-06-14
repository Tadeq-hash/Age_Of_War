#include "MainMenu.h"
#include "Game.h"

/*
    INIT VARIABLES
*/
void MainMenu::initVariables()
{
    //VARIABLES
    this->video_mode_size.width = 800;
    this->video_mode_size.height = 800;
    this->Bot = 0;
    this->MainMenuSelected = 0;

    //POINTERS
    this->window = nullptr;
}

/*
    INIT WINDOW
*/
void MainMenu::initWindow()
{
    this->window = new sf::RenderWindow(this->video_mode_size, "MainMenu");
}

/*
    BUTTONS SETUP
*/
void MainMenu::loadButtons()
{
    if (!this->font.loadFromFile("fonts/fontmenu.ttf"))
    {
        std::cout << "Couldn't load font \n";
    }

    //PLAY
    this->M_M_Text[0].setFont(this->font);
    this->M_M_Text[0].setFillColor(sf::Color::White);
    this->M_M_Text[0].setString("PLAY");
    this->M_M_Text[0].setCharacterSize(70);
    this->M_M_Text[0].setPosition(this->video_mode_size.width / 3, this->video_mode_size.height / 4);

    //OPTIONS
    this->M_M_Text[1].setFont(this->font);
    this->M_M_Text[1].setFillColor(sf::Color::White);
    this->M_M_Text[1].setString("OPTIONS");
    this->M_M_Text[1].setCharacterSize(70);
    this->M_M_Text[1].setPosition(this->video_mode_size.width / 3, (this->video_mode_size.height / 4 + 100));

    //ABOUT
    this->M_M_Text[2].setFont(this->font);
    this->M_M_Text[2].setFillColor(sf::Color::White);
    this->M_M_Text[2].setString("ABOUT");
    this->M_M_Text[2].setCharacterSize(70);
    this->M_M_Text[2].setPosition(this->video_mode_size.width / 3, (this->video_mode_size.height / 4 + 200));

    //EXIT
    this->M_M_Text[3].setFont(this->font);
    this->M_M_Text[3].setFillColor(sf::Color::White);
    this->M_M_Text[3].setString("EXIT");
    this->M_M_Text[3].setCharacterSize(70);
    this->M_M_Text[3].setPosition(this->video_mode_size.width / 3, (this->video_mode_size.height / 4 + 300));

  
    this->M_M_Text[this->MainMenuSelected].setFillColor(sf::Color::Red);

}

/*
    WINDOW STATUS
*/
bool MainMenu::getWindowIsOpen()
{
    return this->window->isOpen();
}


/*
    CONSTRUCTOR & DESTRUCTOR
*/
MainMenu::MainMenu()
{
    this->initVariables();
    this->initWindow();
    this->loadButtons();
}

MainMenu::~MainMenu()
{
    delete this->window;
}

/*
    EVENTS LOOP
*/
void MainMenu::pollEvents()
{
    while (this->window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
        {
            this->window->close();
        }
        if (event.type == sf::Event::KeyPressed)
        {
            //Moving in menu
            if (event.key.code == sf::Keyboard::Up)
            {
                MoveUp(); break;
            }
            if (event.key.code == sf::Keyboard::Down)
            {
                MoveDown(); break;
            }
            if (event.key.code == sf::Keyboard::Return)
            {
                int x = MainMenuPressed();
                
                /*
                    GAME LOOP
                */
                if (x == 0)
                {
                    this->Game_run();
                }
               
                /*
                    OPTIONS LOOP
                */
                if (x == 1)
                {
                    this->Options_run();
                }

                /*
                    ABOUT LOOP
                */
                if (x == 2)
                {
                    this->Credits_run();
                }

                /*
                    EXIT
                */
                if (x == 3)
                {
                    this->window->close();
                }
            }
        }
    }
}

/*
    MENU MOVING
*/
void MainMenu::MoveUp()
{
    if (this->MainMenuSelected >= -1)
    {
        this->M_M_Text[MainMenuSelected].setFillColor(sf::Color::White);
        MainMenuSelected--;

        if (MainMenuSelected == -1)
        {
            MainMenuSelected = 3;
        }
        this->M_M_Text[MainMenuSelected].setFillColor(sf::Color::Red);

    }
}

void MainMenu::MoveDown()
{
    if (MainMenuSelected <= max_buttons - 1)
    {
        this->M_M_Text[MainMenuSelected].setFillColor(sf::Color::White);
        MainMenuSelected++;

        if (MainMenuSelected == 4)
        {
            MainMenuSelected = 0;
        }
        this->M_M_Text[MainMenuSelected].setFillColor(sf::Color::Red);
    }
}

int MainMenu::MainMenuPressed()
{
    return MainMenuSelected;
}


/*
    MENU UPDATE LOOP
*/
void MainMenu::update()
{
    this->pollEvents();
}

/*
    MENU DRAW
*/
void MainMenu::draw(sf::RenderWindow& window)
{
    for (int i = 0; i < max_buttons; i++)
    {
        window.draw(this->M_M_Text[i]);
    }
}

/*
    MENU RENDER
*/
void MainMenu::render()
{
    this->window->clear();
    this->draw(*this->window);
    this->window->display();
}

/*
    GAME SELECTED
*/
void MainMenu::Game_run()
{
    Game game(Bot);
    this->window->setVisible(0);
    while (game.getWindowIsOpen())
    {
        //Update
        game.update();

        //Render
        game.render();
    }
    this->window->setVisible(1);
}

/*
    OPTIONS SELECTED
*/
void MainMenu::Options_run()
{
    sf::RenderWindow Options(sf::VideoMode(960, 720), "Options");
    this->window->setVisible(0);

    while (Options.isOpen())
    {
        sf::Event optionsEvent;
        while (Options.pollEvent(optionsEvent))
        {
            if (optionsEvent.type == sf::Event::Closed)
            {
                Options.close();
                this->window->setVisible(1);
            }
            //Keyboard
            if (optionsEvent.type == sf::Event::KeyPressed)
            {
                if (optionsEvent.key.code == sf::Keyboard::Escape)
                {
                    Options.close();
                    this->window->setVisible(1);
                }
            }
        }
        //Options render
        Options.clear();
        Options.display();
    }
}

/*
    CREDITS SELECTED
*/
void MainMenu::Credits_run()
{
    this->window->setVisible(0);
    sf::RenderWindow About(sf::VideoMode(960, 720), "About");
    while (About.isOpen())
    {
        sf::Event aboutEvent;
        while (About.pollEvent(aboutEvent))
        {
            if (aboutEvent.type == sf::Event::Closed)
            {
                About.close();
                this->window->setVisible(1);
            }
            //Keyboard
            if (aboutEvent.type == sf::Event::KeyPressed)
            {
                if (aboutEvent.key.code == sf::Keyboard::Escape)
                {
                    About.close();
                    this->window->setVisible(1);
                }
            }
        }
        //About render
        About.clear();
        About.display();
    }
}

