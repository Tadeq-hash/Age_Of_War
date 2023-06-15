#pragma once
#include "Unit.h"

class Age {
protected:
    std::vector<sf::IntRect> warrior_idle_rects;
    std::vector<sf::IntRect> warrior_move_rects;
    std::vector<sf::IntRect> warrior_attack_rects;
    std::vector<sf::IntRect> warrior_die_rects;

    std::vector<sf::IntRect> archer_idle_rects;
    std::vector<sf::IntRect> archer_move_rects;
    std::vector<sf::IntRect> archer_attack_rects;
    std::vector<sf::IntRect> archer_die_rects;

    std::vector<sf::IntRect> boss_idle_rects;
    std::vector<sf::IntRect> boss_move_rects;
    std::vector<sf::IntRect> boss_attack_rects;
    std::vector<sf::IntRect> boss_die_rects;

    std::vector<sf::IntRect> arrow_rects;

    std::vector<sf::IntRect> warrior_idle_rects_cosmic;
    std::vector<sf::IntRect> warrior_move_rects_cosmic;
    std::vector<sf::IntRect> warrior_attack_rects_cosmic;
    std::vector<sf::IntRect> warrior_die_rects_cosmic;

    std::vector<sf::IntRect> archer_idle_rects_cosmic;
    std::vector<sf::IntRect> archer_move_rects_cosmic;
    std::vector<sf::IntRect> archer_attack_rects_cosmic;
    std::vector<sf::IntRect> archer_die_rects_cosmic;

    std::vector<sf::IntRect> boss_idle_rects_cosmic;
    std::vector<sf::IntRect> boss_move_rects_cosmic;
    std::vector<sf::IntRect> boss_attack_rects_cosmic;
    std::vector<sf::IntRect> boss_die_rects_cosmic;

    std::vector<sf::IntRect> fireball_rects;

    void initAnimationsRects_Medieval();
    void initAnimationsRects_Gunpowder();

    virtual void InitArr() = 0;

protected:
    Arrow* arr;
    sf::Texture arrow_texture;
    sf::Texture warrior_texture;
    sf::Texture archer_texture;
    sf::Texture boss_texture;
    sf::RenderWindow* window;

public:
    sf::Texture base_texture;

    virtual std::unique_ptr<Unit> MakeWarrior(int side_) = 0;
    virtual std::unique_ptr<Unit> MakeArcher(int side_) = 0;
    virtual std::unique_ptr<Unit> MakeBoss(int side_) = 0;

    virtual ~Age() {};
};

class AgeOfKnights : public Age {
public:
    void InitArr() override;

    AgeOfKnights(sf::RenderWindow* window_);

    std::unique_ptr<Unit> MakeWarrior(int side_) override;
    std::unique_ptr<Unit> MakeArcher(int side_) override;
    std::unique_ptr<Unit> MakeBoss(int side_) override;
};

class AgeOfGunpowder : public Age {
public:
    void InitArr() override;

    AgeOfGunpowder(sf::RenderWindow* window_);

    std::unique_ptr<Unit> MakeWarrior(int side_) override;
    std::unique_ptr<Unit> MakeArcher(int side_) override;
    std::unique_ptr<Unit> MakeBoss(int side_) override;
};
