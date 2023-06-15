#include "Game.h"
#include "UserInterface.h"

/*
    INIT VARIABLES
*/
void Game::InitVariables()
{
    //DEFAULT POINTERS SETUP
    this->age_of_knights = nullptr;
    this->age_of_gunpowder = nullptr;
    this->event = nullptr;
    this->interface_tex = nullptr;
    this->secondInterface = nullptr;
    this->window = nullptr;
    this->digitals = nullptr;
    this->Bot_Algorythm = nullptr;

    //INIT POINTERS
    this->background_sprite = new sf::Sprite();
    this->cosmic_background_tex = new sf::Texture();
    this->medieval_background_tex = new sf::Texture();
    this->interface_tex = new sf::Texture();

    //INIT VARIABLES
    this->video_size = this->video_size.getDesktopMode();
}

/*
    LOAD TEXTURES
*/
void Game::LoadTextures()
{
    //BACKGROUNDS 
    if (!medieval_background_tex->loadFromFile("textures/background_medieval.png"))
    {
        std::cout << "Couldn't load texture 'background'\n";
    }

    if (!cosmic_background_tex->loadFromFile("textures/cosmic_background.png"))
    {
        std::cout << "Couldn't load texture 'background'\n";
    }

    //USER INTERFACE
    if (!interface_tex->loadFromFile("textures/GUI.png"))
    {
        std::cout << "Coulnd't load texture 'GUI'\n";
    }
}

/*
    LOAD FONTS
*/
void Game::LoadFonts()
{
    this->digitals = new sf::Font();
    if (!this->digitals->loadFromFile("fonts/PixelFJVerdana12pt.ttf"))
    {
        std::cout << "couldn't load font\n";
    }
}

/*
    INIT WINDOW
*/
void Game::InitWindow()
{

    this->window = new sf::RenderWindow(this->video_size, "Age_Of_War", sf::Style::Fullscreen);
    this->event = new sf::Event();
    this->window->setFramerateLimit(120);
}

/*
    EVENTS
*/
void Game::PollEvents()
{
    while (this->window->pollEvent(*event))
    {
        if (event->type == sf::Event::Closed)
        {
            this->window->close();
        }

        //User interface actions
        this->interface->pollEvents();

        //Key pressed
        if (this->event->type == sf::Event::KeyPressed)
        {
            if (this->event->key.code == sf::Keyboard::Escape)
            {
                this->window->close();
            }
        }
    }
}

/*
    CONSTRUCTOR & DESTRUCTOR
*/
Game::Game(bool bot_)
{
    //this->Bot = bot_;
    this->InitVariables();
    this->LoadTextures();
    this->InitBackground();
    this->InitWindow();
    this->initAges();
    this->LoadFonts();
    this->initButtons();
    this->initBot();
}

Game::~Game()
{
    delete this->interface_tex;    
    delete this->age_of_gunpowder;
    delete this->age_of_knights;
    delete this->medieval_background_tex;
    delete this->cosmic_background_tex;
    delete this->digitals;
    delete this->background_sprite;
    delete this->interface;
    delete this->secondInterface;
    delete this->event;
    delete this->window;
}

bool Game::getWindowIsOpen()
{
    return this->window->isOpen();
}

void Game::CheckGameConditions()
{
    if (interface->player->units[0]->return_hp() <= 0) {
        GameLost();
    }
    if (secondInterface->player->units[0]->return_hp() <= 0) {
        GameWon();
    }
}

void Game::GameWon()
{
    EndFont.loadFromFile("fonts/Pixelmania.ttf");
    EndText.setFont(EndFont);
    EndText.setFillColor(sf::Color(102, 203, 108));
    EndText.setCharacterSize(100);
    EndText.setOutlineThickness(2);
    EndText.setOutlineColor(sf::Color::Red);
    EndText.setString("GAME WON");
    EndText.setPosition(window->getSize().x / 2 - EndText.getGlobalBounds().width / 2, window->getSize().y / 2 - EndText.getGlobalBounds().height / 2);
    window->draw(EndText);
    window->display();
    Game_End = true;
}

void Game::GameLost()
{
    EndFont.loadFromFile("fonts/Pixelmania.ttf");
    EndText.setFont(EndFont);
    EndText.setFillColor(sf::Color(203, 102, 102));
    EndText.setCharacterSize(100);
    EndText.setOutlineThickness(2);
    EndText.setOutlineColor(sf::Color::Red);
    EndText.setString("GAME LOST");
    EndText.setPosition(window->getSize().x / 2 - EndText.getGlobalBounds().width / 2, window->getSize().y / 2 - EndText.getGlobalBounds().height / 2);
    window->draw(EndText);
    window->display();
    Game_End = true;
}

/*
    INIT BACKGROUND
*/
void Game::InitBackground()
{
    this->background_sprite->setTexture(*medieval_background_tex);
}
/*
    INIT BUTTONS
*/
void Game::initButtons()
{
    this->interface = new UserInterface(this->interface_tex, this->window, this->event, this->digitals, age_of_knights, age_of_gunpowder, 1, this->background_sprite, this->cosmic_background_tex);
    this->secondInterface = new UserInterface(this->interface_tex, this->window, this->event, this->digitals, age_of_knights, age_of_gunpowder, -1, this->background_sprite, this->cosmic_background_tex);
    
}

/*
    INIT BOT (TEMP)
*/
void Game::initBot()
{
    Bot_Algorythm = new BotAlgorythm(interface, secondInterface);
}
/*
    INIT AGES
*/
void Game::initAges()
{
    //Ages
    age_of_knights = new AgeOfKnights(window);
    age_of_gunpowder = new AgeOfGunpowder(window);
}


/*
    GAME UPDATE
*/
void Game::update()
{
    this->PollEvents();
    this->interface->update();
    this->secondInterface->update();
    this->update_units(interface->player->units, secondInterface->player->units, &clock);

    this->update_arrows();
    this->Bot_Algorythm->update();
    clock.restart();
}

/*
    GAME RENDER
*/

void Game::render()
{
    if (!Game_End) {
        //clear
        this->window->clear(sf::Color::Cyan);

        /*
            Draw
        */

        //window
        this->window->draw(*this->background_sprite);

        //user interface
        this->drawInterface();
        

        //units
        this->interface->player->draw_units();
        this->secondInterface->player->draw_units();

        //display
        this->window->display();
    }
}

/*
    DRAW INTERFACE
*/

void Game::drawInterface()
{
    this->interface->drawInterface();
    this->secondInterface->drawInterface();
}

/*
    UNITS
*/

//Update units
void Game::update_units(std::vector<Unit*> units, std::vector<Unit*> enemies, sf::Clock* clock_) {
    
    for (int n = 0; n < units.size(); n++) {
        units[n]->attacking = false;
        for (int m = 0; m < enemies.size(); m++) {
            if (units[n]->unit_type == Unit_type::Archer) {
                if (!units[n]->moving) {
                    attack(units[n], enemies[m]);
                }
            }
            else {
                attack(units[n], enemies[m]);
            }
        }
        if(units[n]->attacking == false){ units[n]->clockAttack.restart(); }
    }
    for (int n = 0; n < enemies.size(); n++) {
        enemies[n]->attacking = false;
        for (int m = 0; m < units.size(); m++) {
            if (enemies[n]->unit_type == Unit_type::Archer) {
                if (!enemies[n]->moving) {
                    attack(enemies[n], units[m]);
                }
            }
            else {
                attack(enemies[n], units[m]);
            }
        }
        if (enemies[n]->attacking == false) { enemies[n]->clockAttack.restart(); }
    }
    this->move(units, enemies, clock_);
    this->move(enemies, units, clock_);

    interface->player->checkDeads(secondInterface->player);
    secondInterface->player->checkDeads(interface->player);
  

  
    

    for (int n = 0; n < units.size(); n++) {
        if (units[n]->unit_type != Unit_type::Base) {
            units[n]->Animate(units[n]->return_hp());
        }
    }
    for (int n = 0; n < enemies.size(); n++) {
        if (enemies[n]->unit_type != Unit_type::Base) {
            enemies[n]->Animate(enemies[n]->return_hp());
        }
    }


}

//Attack
bool Game::attack(Unit* attacker, Unit* victim) {
    sf::FloatRect rangeRec = attacker->sprite.getGlobalBounds();
    rangeRec.width += attacker->getRange()-30;
    if (attacker->side == -1) { rangeRec.left -= attacker->getRange()-30; }
    if (rangeRec.intersects(victim->sprite.getGlobalBounds())) {

        attacker->attacking = true;
        if (attacker->clockAttack.getElapsedTime().asSeconds() >= attacker->getDmgDelay()) {
            if (attacker->unit_type == Unit_type::Archer) {
                if (interface->player->side == attacker->side) {
                    interface->player->push_arrow(attacker->MakeArrow());
                }
                else if (secondInterface->player->side == attacker->side) {
                    secondInterface->player->push_arrow(attacker->MakeArrow());
                }
                attacker->clockAttack.restart();
            }else{
                 victim->sufferDmg(attacker->getDmg());
                 attacker->clockAttack.restart();
            }
        }
    }
    return 0;
}

//Move units
void Game::move(std::vector<Unit*> units, std::vector<Unit*> enemies, sf::Clock* clock_) {
    bool spaceForMove = 1;

    for (int i = 0; i < units.size(); ++i) {
        if (units[i]->unit_type == Unit_type::Archer) {
            //Wspolczynnik szybkosci pozwalajacy szybciej przeprowadzac symulacje
            int wsp = 5;
            sf::Time time = clock_->getElapsedTime();
  
            spaceForMove = 1;
            sf::FloatRect rec = units[i]->sprite.getGlobalBounds();
            rec.left += units[i]->getSpeed() * time.asSeconds() * wsp * units[i]->side;


            for (int j = 0; j < units.size(); ++j) {
                if (units[i] != units[j]) {
                    if (rec.intersects(units[j]->sprite.getGlobalBounds()) && units[j]->unit_type != Unit_type::Base) {
                        spaceForMove = 0;
                    }
                }
            }
            for (int j = 0; j < enemies.size(); ++j) {
                    if (rec.intersects(enemies[j]->sprite.getGlobalBounds())) {
                        spaceForMove = 0;
                    }
            }
            if (spaceForMove) {
                units[i]->sprite.move(sf::Vector2f(time.asSeconds() * units[i]->getSpeed() * wsp * units[i]->side, 0));
                units[i]->moving = true;
                units[i]->clockMove.restart();
            }
            else {
                if (units[i]->clockMove.getElapsedTime().asSeconds() >= 0.05) {
                    units[i]->moving = false;
                }
            }


        }
        else if (units[i]->attacking == false) {
            //Wspolczynnik szybkosci pozwalajacy szybciej przeprowadzac symulacje
            int wsp = 5;
            sf::Time time = clock_->getElapsedTime();
            spaceForMove = 1;
            sf::FloatRect rec = units[i]->sprite.getGlobalBounds();
            rec.left += units[i]->getSpeed() * time.asSeconds() * wsp * units[i]->side;


            for (int j = 0; j < units.size(); ++j) {
                if (units[i] != units[j]) {
                    if (rec.intersects(units[j]->sprite.getGlobalBounds()) && units[j]->unit_type != Unit_type::Base) {
                        spaceForMove = 0;
                    }
                }
            }
            if (spaceForMove) {
                units[i]->sprite.move(sf::Vector2f(time.asSeconds() * units[i]->getSpeed() * wsp * units[i]->side, 0));
                units[i]->moving = true;
                units[i]->clockMove.restart();
            }
            else {
                if (units[i]->clockMove.getElapsedTime().asSeconds() >= 0.05) {
                    units[i]->moving = false;
                }
            }
        }
    } 
}

/*
    ARROWS
*/

//Update arrows
void Game::update_arrows() {
    interface->player->update_arrows();
    secondInterface->player->update_arrows();
    colision_arrows();
    move_arrows();
}

//Move arrows
void Game::move_arrows() {
    sf::Time time = clock.getElapsedTime();
    for (int i = 0; i < interface->player->arrows.size(); i++) {
        interface->player->arrows[i]->move(time.asSeconds() * (interface->player->arrows[i]->speed) * interface->player->side, 0);
    }
    for (int i = 0; i < secondInterface->player->arrows.size(); i++) {
        secondInterface->player->arrows[i]->move(time.asSeconds() * (secondInterface->player->arrows[i]->speed) * secondInterface->player->side, 0);
    }
}

//Collision arrows
void Game::colision_arrows() {
    for (int i = 0; i < interface->player->arrows.size(); i++) {
        for (int j = 0; j < secondInterface->player->units.size(); j++) {
            if (interface->player->arrows[i]->getGlobalBounds().intersects(secondInterface->player->units[j]->sprite.getGlobalBounds())) {
                secondInterface->player->units[j]->sufferDmg(interface->player->arrows[i]->dmg);
                interface->player->arrows.erase(interface->player->arrows.begin() + i);
                i--;
                break;
            }
        }
    }
    for (int i = 0; i < secondInterface->player->arrows.size(); i++) {
        for (int j = 0; j < interface->player->units.size(); j++) {
            if (secondInterface->player->arrows[i]->getGlobalBounds().intersects(interface->player->units[j]->sprite.getGlobalBounds())) {
                interface->player->units[j]->sufferDmg(secondInterface->player->arrows[i]->dmg);
                secondInterface->player->arrows.erase(secondInterface->player->arrows.begin() + i);
                i--;
                break;
            }
        }
    }
}

