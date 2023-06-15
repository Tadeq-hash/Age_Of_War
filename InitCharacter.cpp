#include "InitCharacter.h"

void InitCharacter::InitVariables() {
    clock.restart();
    cooldown = 2.5f;
}

// DRAWING
void InitCharacter::drawButton() {
    _window->draw(character_sprite);
}

// CONSTRUCTOR
InitCharacter::InitCharacter(std::string character, sf::Sprite character_sprite, sf::RenderWindow* window, int size, sf::Texture tex, Player* player_) {
    bar_texture = tex;
    vec_size = size;
    _window = window;
    this->character = character;
    this->character_sprite = character_sprite;
    player = player_;
    InitVariables();
    sprite_setup();
    bar_setup();
    stringToEnumClass();
}

// DESTRUCTOR
InitCharacter::~InitCharacter() {
    Unit* unit = nullptr;

    switch (unit_type) {
    case Unit_type::Warrior:
        player->push_unit(std::move(player->current_age()->MakeWarrior(player->side)));
        break;
    case Unit_type::Archer:
        player->push_unit(std::move(player->current_age()->MakeArcher(player->side)));
        break;
    case Unit_type::Boss:
        player->push_unit(std::move(player->current_age()->MakeBoss(player->side)));
        break;
    }
}

void InitCharacter::sprite_setup() {
    character_sprite.setScale(2, 2);
    character_sprite.setColor(sf::Color::Green);
}

// BUTTON SETUPS
void InitCharacter::setupButtons(std::vector<InitCharacter*>& vec, int size) {
    if (size == 1) {
        vec[0]->setposition_0();
    }
    if (size == 2) {
        vec[0]->setposition_0();
        vec[1]->setposition_1();
    }
    if (size == 3) {
        vec[0]->setposition_0();
        vec[1]->setposition_1();
        vec[2]->setposition_2();
    }
}

void InitCharacter::setposition_0() {
    character_sprite.setPosition(375, 5);
}

void InitCharacter::setposition_1() {
    character_sprite.setPosition(375, 35);
    clock.restart();
}

void InitCharacter::setposition_2() {
    character_sprite.setPosition(375, 65);
    clock.restart();
}

void InitCharacter::bar_setup() {
    cooldown_bar.setTexture(bar_texture);
    cooldown_bar.setTextureRect(sf::IntRect(184, 50, 3, 250));
    cooldown_bar.setScale(5, 0.45);
    cooldown_bar.setPosition(355, 0);
}

void InitCharacter::bar_animation() {
    cooldown_animation.setTexture(bar_texture);
    if (clock.getElapsedTime().asMilliseconds() < 2505) {
        cooldown_animation.setTextureRect(sf::IntRect(190, 51, 1, clock.getElapsedTime().asMilliseconds() / 11));
    }
    cooldown_animation.setPosition(360, 5);
    cooldown_animation.setScale(5, 0.45);
}

void InitCharacter::bar_init() {
    _window->draw(cooldown_bar);
    _window->draw(cooldown_animation);
}

// REMOVING OBJECT AFTER TIME
void InitCharacter::update(std::vector<InitCharacter*>& vec, int size) {
    setupButtons(vec, size);
    bar_animation();
    if (clock.getElapsedTime().asMilliseconds() > cooldown * 1000 && isSpaceForRespawn()) {
        vec.erase(vec.begin());
        vec_size--;
        delete this;
    }
}

// Zamiana stringa w enum class
void InitCharacter::stringToEnumClass() {
    if (character == "warrior") {
        unit_type = Unit_type::Warrior;
    }
    else if (character == "archer") {
        unit_type = Unit_type::Archer;
    }
    else if (character == "boss") {
        unit_type = Unit_type::Boss;
    }
}

// Definiowanie miejsca dla spawnu
bool InitCharacter::isSpaceForRespawn() {
    sf::Rect<float> rect_;
    switch (unit_type) {
    case Unit_type::Warrior:
        rect_ = player->age_ptr->MakeWarrior(player->side)->sprite.getGlobalBounds();
        break;
    case Unit_type::Archer:
        rect_ = player->age_ptr->MakeArcher(player->side)->sprite.getGlobalBounds();
        break;
    case Unit_type::Boss:
        rect_ = player->age_ptr->MakeBoss(player->side)->sprite.getGlobalBounds();
        break;
    }
    for (int i = 0; i < player->units.size(); i++) {
        if (player->units[i]->sprite.getGlobalBounds().intersects(rect_) && player->units[i]->unit_type != Unit_type::Base) {
            return false;
        }
    }
    return true;
}
