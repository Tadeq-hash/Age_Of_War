#include "Game.h"
#include "UserInterface.h"

//VARIABLES
void Game::InitVariables()
{
    this->age_of_knights = nullptr;
    this->age_of_gunpowder = nullptr;
    this->event = nullptr;
    this->interface_tex = nullptr;
    this->secondInterface = nullptr;
    this->medieval_background_tex = nullptr;
    this->cosmic_background_tex = nullptr;
    this->interface = nullptr;
    this->window = nullptr;
    this->digitals = nullptr;
    this->video_size = this->video_size.getDesktopMode();
    this->background_sprite = new sf::Sprite();
    this->cosmic_background_tex = new sf::Texture();
    this->medieval_background_tex = new sf::Texture();
}

//TEXTURES
void Game::LoadTextures()
{
    //background tex
    

    if (!medieval_background_tex->loadFromFile("textures/background_medieval.png"))
    {
        std::cout << "Couldn't load texture 'background'\n";
    }

    if (!cosmic_background_tex->loadFromFile("textures/cosmic_background.png"))
    {
        std::cout << "Couldn't load texture 'background'\n";
    }

    //user interface ui
    interface_tex = new sf::Texture;

    if (!interface_tex->loadFromFile("textures/GUI.png"))
    {
        std::cout << "Coulnd't load texture 'GUI'\n";
    }
}
//FONTS
void Game::LoadFonts()
{
    this->digitals = new sf::Font();
    if (!this->digitals->loadFromFile("fonts/PixelFJVerdana12pt.ttf"))
    {
        std::cout << "couldn't load font\n";
    }
}



//WINDOW
void Game::InitWindow()
{
    this->window = new sf::RenderWindow(this->video_size, "Age_Of_War");
    this->event = new sf::Event();
    this->window->setFramerateLimit(120);
}
//-----! CONSTRUCTOR !-----//
Game::Game(bool bot_)
{
    //this->Bot = bot_;
    this->InitVariables();
    this->LoadTextures();
    this->InitWindow();
    this->LoadFonts();

    this->initAges();
    this->InitBackground();
    this->initButtons();
    this->initBot();
}
//-----! DESTRUCTOR !-----//
Game::~Game()
{
    delete this->window;
    delete this->interface_tex;
    delete this->interface;
    delete this->event;
    delete this->digitals;
}


bool Game::getWindowIsOpen()
{
    return this->window->isOpen();
}

//BACKGROUND
void Game::InitBackground()
{
    this->background_sprite->setTexture(*medieval_background_tex);
}
//BUTTONS
void Game::initButtons()
{
    this->interface = new UserInterface(this->interface_tex, this->window, this->event, this->digitals, age_of_knights, age_of_gunpowder, 1, this->background_sprite, this->cosmic_background_tex);
}

void Game::drawInterface()
{

    this->interface->drawInterface();

}

void Game::initBot()
{
    if (Bot) {
        this->secondInterface = new UserInterface(this->interface_tex, this->window, this->event, this->digitals, age_of_knights, age_of_gunpowder, -1, this->background_sprite, this->cosmic_background_tex);
    }
}

void Game::initAges()
{
    //Ages
    age_of_knights = new AgeOfKnights(window);
    age_of_gunpowder = new AgeOfGunpowder(window);
}

//UPDATING GAME//
void Game::update()
{
    this->PollEvents();
    this->interface->update();
    this->update_units(interface->player->units, secondInterface->player->units, &clock);
    this->update_arrows();
    clock.restart();
}

void Game::PollEvents()
{
    while (this->window->pollEvent(*event))
    {


        if (event->type == sf::Event::Closed)
        {
            this->window->close();
        }


        //Button updates
        this->interface->pollEvents();

        //Pressed
        if (this->event->type == sf::Event::KeyPressed)
        {

            if (this->event->key.code == sf::Keyboard::Escape)
            {
                this->window->close();
            }


        }

        //Testing rest for Bot
        if (this->event->type == sf::Event::KeyPressed) {
            if (event->key.code == sf::Keyboard::W) {
                this->testOnelyMakeBotWarrior();
            }
            if (event->key.code == sf::Keyboard::A) {
                this->testOnelyMakeBotArcher();
            }
            if (event->key.code == sf::Keyboard::B) {
                this->testOnelyMakeBotBoss();
            }
        }


    }
}





//RENDERING GAME//

void Game::render()
{
    this->window->clear(sf::Color::Cyan);

    //--DRAWINGS--//

    //Background
    this->window->draw(*this->background_sprite);

    //Buttons
    this->drawInterface();

    //Units

    this->interface->player->draw_units();
    this->secondInterface->player->draw_units();
  

    //-----------//



    this->window->display();
}

//-------------//


void Game::update_arrows() {
    interface->player->update_arrows();
    secondInterface->player->update_arrows();
    colision_arrows();
    move_arrows();
}

void Game::move_arrows() {
    sf::Time time = clock.getElapsedTime();
    for (int i = 0; i < interface->player->arrows.size(); i++) {
        interface->player->arrows[i]->move(time.asSeconds() * (interface->player->arrows[i]->speed) * interface->player->side, 0);
    }
    for (int i = 0; i < secondInterface->player->arrows.size(); i++) {
        secondInterface->player->arrows[i]->move(time.asSeconds() * (secondInterface->player->arrows[i]->speed) * secondInterface->player->side, 0);
    }
}

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

//Funkcje do obs�ugi jednostek
void Game::update_units(std::vector<Unit*> units, std::vector<Unit*> enemies, sf::Clock* clock_) {
    for (int n = 0; n < units.size(); n++) {
        units[n]->attacking = false;
        for (int m = 0; m < enemies.size(); m++) {
            attack(units[n], enemies[m]);
        }
        if(units[n]->attacking == false){ units[n]->clockAttack.restart(); }
    }
    for (int n = 0; n < enemies.size(); n++) {
        enemies[n]->attacking = false;
        for (int m = 0; m < units.size(); m++) {
            attack(enemies[n], units[m]);
        }
        if (enemies[n]->attacking == false) { enemies[n]->clockAttack.restart(); }
    }
    this->move(units, clock_);
    this->move(enemies, clock_);
    interface->player->checkDeads();
    secondInterface->player->checkDeads();
    for (int n = 0; n < units.size(); n++) {
        units[n]->Animate(units[n]->return_hp());
    }
    for (int n = 0; n < enemies.size(); n++) {
        enemies[n]->Animate(enemies[n]->return_hp());
    }


}


bool Game::attack(Unit* attacker, Unit* victim) {
    sf::FloatRect rangeRec = attacker->sprite.getGlobalBounds();
    rangeRec.width += attacker->getRange();
    if (attacker->side == -1) { rangeRec.left -= attacker->getRange(); }
    if (rangeRec.intersects(victim->sprite.getGlobalBounds())) {
        //std::cout << "Mam cie w zasiegu!!!\n";
        attacker->attacking = true;
        //std::cout << "Clock: " << attacker->clockAttack.getElapsedTime().asSeconds()<<"\n";
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
                 std::cout << "Zadaje dmg\n";
                 attacker->clockAttack.restart();
            }
        }
    }
    return 0;
}


void Game::move(std::vector<Unit*> units, sf::Clock* clock_) {
    bool spaceForMove = 1;

    for (int i = 0; i < units.size(); ++i) {
        if (units[i]->attacking == false) {
            //Wspolczynnik szybkosci pozwalajacy szybciej przeprowadzac symulacje
            int wsp = 5;
            sf::Time time = clock_->getElapsedTime();
            if (false) {
                std::cout << time.asSeconds() << " speed: " << units[i]->getSpeed() << std::endl;
            }
            spaceForMove = 1;
            sf::FloatRect rec = units[i]->sprite.getGlobalBounds();
            rec.left += units[i]->getSpeed() * time.asSeconds() * wsp * units[i]->side;


            for (int j = 0; j < units.size(); ++j) {
                if (units[i] != units[j]) {
                    if (rec.intersects(units[j]->sprite.getGlobalBounds()) && units[j]->unit_type != Unit_type::Base) {
                        spaceForMove = 0;
                        //std::cout << j<< "\n";
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

void Game::testOnelyMakeBotWarrior() {
    secondInterface->player->push_unit(std::move(secondInterface->player->current_age()->MakeWarrior(secondInterface->player->side)));
}

void Game::testOnelyMakeBotArcher() {
    secondInterface->player->push_unit(std::move(secondInterface->player->current_age()->MakeArcher(secondInterface->player->side)));
}

void Game::testOnelyMakeBotBoss() {
    secondInterface->player->push_unit(std::move(secondInterface->player->current_age()->MakeBoss(secondInterface->player->side)));
}
