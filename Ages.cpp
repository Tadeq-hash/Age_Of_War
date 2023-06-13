#include "Ages.h"


//	-----AGE OF KNIGHTS-----

// KONSTRUKTOR
AgeOfKnights::AgeOfKnights(sf::RenderWindow* window_){
	std::cout << "Tworze ere Rycerzy" << std::endl;
	window = window_;
	warrior_texture.loadFromFile("textures/Warrior_Medieval.png");
	archer_texture.loadFromFile("textures/archer_medieval.png");
	boss_texture.loadFromFile("textures/boss_medieval.png");
	this->initAnimationsRects_Medieval();
	
	

};

// -> TWORZENIE JEDNOSTEK

//Wojownik
std::unique_ptr<Unit> AgeOfKnights::MakeWarrior(int side_) {
	int max_hp = 50;
	int hp = max_hp;
	int range = 5;
	int dmg = 7;
	int speed = 20;
	float dmg_reduction = 0.9;
	
	//std::cout << "Wywoluje wojownika ze statami z ery Rycerzy" << std::endl;
	std::cout << this->warrior_move_rects.size() << "\n";
	Warrior warrior(&warrior_texture, max_hp, hp, range, dmg, speed, dmg_reduction, side_, window, warrior_idle_rects, warrior_move_rects, warrior_attack_rects, warrior_die_rects);
	return std::make_unique<Unit>(warrior);
};

//£uznik
std::unique_ptr<Unit> AgeOfKnights::MakeArcher(int side_) {
	int max_hp = 35;
	int hp = max_hp;
	int range = 300;
	int dmg = 5;
	int speed = 8;
	float dmg_reduction = 1;
	//std::cout << "Wywoluje Lucznika ze statami z ery Rycerzy" << std::endl;
	//Archer archer(&texture, &max_hp, hp, &range, &dmg, &speed, &dmg_reduction);
	return std::make_unique<Unit>(Archer(&archer_texture, max_hp, hp, range, dmg, speed, dmg_reduction, side_, window, archer_idle_rects, archer_move_rects, archer_attack_rects, archer_die_rects));
}

//Boss
std::unique_ptr<Unit> AgeOfKnights::MakeBoss(int side_) {
	int max_hp = 200;
	int hp = max_hp;
	int range = 12;
	int dmg = 15;
	int speed = 20;
	float dmg_reduction = 0.7;
	Boss boss(&boss_texture, max_hp, hp, range, dmg, speed, dmg_reduction, side_, window, boss_idle_rects, boss_move_rects, boss_attack_rects, boss_die_rects);
	std::cout << "Wywoluje Bossa ze statami z ery Rycerzy" << std::endl;
	//Boss boss(&texture, &max_hp, hp, &range, &dmg, &speed, &dmg_reduction);
	std::unique_ptr<Unit> unit = move(std::make_unique<Unit>(boss));
	std::cout << "stworzony uinique_ptr, teraz zwracam\n";
	return move(unit);
}



//	-----AGE OF GUNPOWDER-----


// KONSTRUKTOR
AgeOfGunpowder::AgeOfGunpowder(sf::RenderWindow* window_) {
	std::cout << "Tworze ere Prochu" << std::endl;
	window = window_;
	warrior_texture.loadFromFile("textures/Warrior_Medieval.png");
	archer_texture.loadFromFile("textures/Archer_Age_Of_Gunpowder.png");
	boss_texture.loadFromFile("textures/Boss_Age_Of_Gunpowder.png");
	this->initAnimationsRects_Medieval();
}

// -> TWORZENIE JEDNOSTEK

//Wojownik
std::unique_ptr<Unit> AgeOfGunpowder::MakeWarrior(int side_) {
	int max_hp = 80;
	int hp = max_hp;
	int range = 10;
	int dmg = 150;
	int speed = 300;
	float dmg_reduction = 1;
	//std::cout << "Wywoluje wojownika ze statami z ery Prochu" << std::endl;
	//Warrior warrior(&texture, &max_hp, hp, &range, &dmg, &speed, &dmg_reduction);
	return move(std::make_unique<Unit>(Warrior(&warrior_texture, max_hp, hp, range, dmg, speed, dmg_reduction, side_, window, warrior_idle_rects, warrior_move_rects, warrior_attack_rects, warrior_die_rects)));
};

//£uznik
std::unique_ptr<Unit> AgeOfGunpowder::MakeArcher(int side_) {
	int max_hp = 45;
	int hp = max_hp;
	int range = 75;
	int dmg = 8;
	int speed = 10;
	float dmg_reduction = 1;
	//std::cout << "Wywoluje Lucznika ze statami z ery Prochu" << std::endl;
	//Archer archer(&texture, &max_hp, hp, &range, &dmg, &speed, &dmg_reduction);
	return std::make_unique<Unit>(Archer(&archer_texture, max_hp, hp, range, dmg, speed, dmg_reduction, side_, window, archer_idle_rects, archer_move_rects, archer_attack_rects, archer_die_rects));
}

//Boss
std::unique_ptr<Unit> AgeOfGunpowder::MakeBoss(int side_) {
	int max_hp = 200;
	int hp = max_hp;
	int range = 60;
	int dmg = 20;
	int speed = 10;
	float dmg_reduction = 1;
	std::cout << "Wywoluje Bossa ze statami z ery Prochu" << std::endl;
	//Boss boss(&texture, &max_hp, hp, &range, &dmg, &speed, &dmg_reduction);
	return std::make_unique<Unit>(Boss(&boss_texture, max_hp, hp, range, dmg, speed, dmg_reduction,side_, window, boss_idle_rects, boss_move_rects, boss_attack_rects, boss_die_rects));
}

void Age::initAnimationsRects_Medieval()
{
		/*
			WARRIOR
		*/

		//Stay
		sf::IntRect stay1 = sf::IntRect(12, 165, 65, 65);
		sf::IntRect stay2 = sf::IntRect(162, 165, 65, 65);
		sf::IntRect stay3 = sf::IntRect(312, 165, 65, 65);
		sf::IntRect stay4 = sf::IntRect(462, 165, 65, 65);
		sf::IntRect stay5 = sf::IntRect(612, 165, 65, 65);
		sf::IntRect stay6 = sf::IntRect(762, 165, 65, 65);

		this->warrior_idle_rects.emplace_back(stay1);
		this->warrior_idle_rects.emplace_back(stay2);
		this->warrior_idle_rects.emplace_back(stay3);
		this->warrior_idle_rects.emplace_back(stay4);
		this->warrior_idle_rects.emplace_back(stay5);
		this->warrior_idle_rects.emplace_back(stay6);


		//Run
		sf::IntRect run1 = sf::IntRect(6, 296, 65, 65);
		sf::IntRect run2 = sf::IntRect(160, 296, 65, 65);
		sf::IntRect run3 = sf::IntRect(314, 296, 65, 65);
		sf::IntRect run4 = sf::IntRect(458, 296, 65, 65);
		sf::IntRect run5 = sf::IntRect(606, 296, 65, 65);
		sf::IntRect run6 = sf::IntRect(759, 296, 65, 65);

		this->warrior_move_rects.emplace_back(run1);
		this->warrior_move_rects.emplace_back(run2);
		this->warrior_move_rects.emplace_back(run3);
		this->warrior_move_rects.emplace_back(run4);
		this->warrior_move_rects.emplace_back(run5);
		this->warrior_move_rects.emplace_back(run6);



		//Attack
		sf::IntRect atk1 = sf::IntRect(99, 70, 65, 65);
		sf::IntRect atk2 = sf::IntRect(252, 70, 65, 65);
		sf::IntRect atk3 = sf::IntRect(430, 70, 65, 65);
		sf::IntRect atk4 = sf::IntRect(580, 70, 65, 65);

		this->warrior_attack_rects.emplace_back(atk1);
		this->warrior_attack_rects.emplace_back(atk2);
		this->warrior_attack_rects.emplace_back(atk3);
		this->warrior_attack_rects.emplace_back(atk4);

		//Death
		sf::IntRect dead1 = sf::IntRect(12, 420, 65, 65);
		sf::IntRect dead2 = sf::IntRect(157, 420, 65, 65);
		sf::IntRect dead3 = sf::IntRect(305, 420, 65, 65);
		sf::IntRect dead4 = sf::IntRect(440, 420, 65, 65);
		sf::IntRect dead5 = sf::IntRect(588, 420, 65, 65);
		sf::IntRect dead6 = sf::IntRect(734, 420, 65, 65);

		this->warrior_die_rects.emplace_back(dead1);
		this->warrior_die_rects.emplace_back(dead2);
		this->warrior_die_rects.emplace_back(dead3);
		this->warrior_die_rects.emplace_back(dead4);
		this->warrior_die_rects.emplace_back(dead5);
		this->warrior_die_rects.emplace_back(dead6);
		
		/*
			ARCHER
		*/

		//IDLE
		sf::IntRect idle1_a = sf::IntRect(35, 28, 65, 65);
		sf::IntRect idle2_a = sf::IntRect(135, 28, 65, 65);
		sf::IntRect idle3_a = sf::IntRect(235, 28, 65, 65);
		sf::IntRect idle4_a = sf::IntRect(335, 28, 65, 65);
		sf::IntRect idle5_a = sf::IntRect(435, 28, 65, 65);
		sf::IntRect idle6_a = sf::IntRect(535, 28, 65, 65);
		sf::IntRect idle7_a = sf::IntRect(635, 28, 65, 65);
		sf::IntRect idle8_a = sf::IntRect(735, 28, 65, 65);
		sf::IntRect idle9_a = sf::IntRect(835, 28, 65, 65);
		sf::IntRect idle10_a = sf::IntRect(935, 28, 65, 65);

		this->archer_idle_rects.emplace_back(idle1_a);
		this->archer_idle_rects.emplace_back(idle2_a);
		this->archer_idle_rects.emplace_back(idle3_a);
		this->archer_idle_rects.emplace_back(idle4_a);
		this->archer_idle_rects.emplace_back(idle5_a);
		this->archer_idle_rects.emplace_back(idle6_a);
		this->archer_idle_rects.emplace_back(idle7_a);
		this->archer_idle_rects.emplace_back(idle8_a);
		this->archer_idle_rects.emplace_back(idle9_a);
		this->archer_idle_rects.emplace_back(idle10_a);
		
		//RUN
		sf::IntRect run1_a = sf::IntRect(35, 160, 65, 65);
		sf::IntRect run2_a = sf::IntRect(133, 160, 65, 65);
		sf::IntRect run3_a = sf::IntRect(239, 160, 65, 65);
		sf::IntRect run4_a = sf::IntRect(342, 160, 65, 65);
		sf::IntRect run5_a = sf::IntRect(438, 160, 65, 65);
		sf::IntRect run6_a = sf::IntRect(533, 160, 65, 65);
		sf::IntRect run7_a = sf::IntRect(639, 160, 65, 65);
		sf::IntRect run8_a = sf::IntRect(743, 160, 65, 65);

		this->archer_move_rects.emplace_back(run1_a);
		this->archer_move_rects.emplace_back(run2_a);
		this->archer_move_rects.emplace_back(run3_a);
		this->archer_move_rects.emplace_back(run4_a);
		this->archer_move_rects.emplace_back(run5_a);
		this->archer_move_rects.emplace_back(run6_a);
		this->archer_move_rects.emplace_back(run7_a);
		this->archer_move_rects.emplace_back(run8_a);

		//ATTACK
		sf::IntRect atk1_a = sf::IntRect(41, 307, 65, 65);
		sf::IntRect atk2_a = sf::IntRect(141, 307, 65, 65);
		sf::IntRect atk3_a = sf::IntRect(241, 307, 65, 65);
		sf::IntRect atk4_a = sf::IntRect(340, 307, 65, 65);
		sf::IntRect atk5_a = sf::IntRect(436, 307, 65, 65);
		sf::IntRect atk6_a = sf::IntRect(536, 307, 65, 65);

		this->archer_attack_rects.emplace_back(atk1_a);
		this->archer_attack_rects.emplace_back(atk2_a);
		this->archer_attack_rects.emplace_back(atk3_a);
		this->archer_attack_rects.emplace_back(atk4_a);
		this->archer_attack_rects.emplace_back(atk5_a);
		this->archer_attack_rects.emplace_back(atk6_a);

		//DEAD
		sf::IntRect dead1_a = sf::IntRect(36, 454, 65, 65);
		sf::IntRect dead2_a = sf::IntRect(136, 454, 65, 65);
		sf::IntRect dead3_a = sf::IntRect(316, 454, 65, 65);
		sf::IntRect dead4_a = sf::IntRect(460, 454, 65, 65);
		sf::IntRect dead5_a = sf::IntRect(638, 454, 65, 65);
		sf::IntRect dead6_a = sf::IntRect(774, 454, 65, 65);
		sf::IntRect dead7_a = sf::IntRect(945, 454, 65, 65);
		sf::IntRect dead8_a = sf::IntRect(1073, 454, 65, 65);
		sf::IntRect dead9_a = sf::IntRect(1205, 454, 65, 65);
		sf::IntRect dead10_a = sf::IntRect(1361, 454, 65, 65);

		this->archer_die_rects.emplace_back(dead1_a);
		this->archer_die_rects.emplace_back(dead2_a);
		this->archer_die_rects.emplace_back(dead3_a);
		this->archer_die_rects.emplace_back(dead4_a);
		this->archer_die_rects.emplace_back(dead5_a);
		this->archer_die_rects.emplace_back(dead6_a);
		this->archer_die_rects.emplace_back(dead7_a);
		this->archer_die_rects.emplace_back(dead8_a);
		this->archer_die_rects.emplace_back(dead9_a);
		this->archer_die_rects.emplace_back(dead10_a);


		/*
			BOSS
		*/
		
		//IDLE
		sf::IntRect idle1 = sf::IntRect(63, 192, 65, 65);
		sf::IntRect idle2 = sf::IntRect(203, 192, 65, 65);
		sf::IntRect idle3 = sf::IntRect(343, 192, 65, 65);
		sf::IntRect idle4 = sf::IntRect(483, 192, 65, 65);
		sf::IntRect idle5 = sf::IntRect(623, 192, 65, 65);
		sf::IntRect idle6 = sf::IntRect(763, 192, 65, 65);
		sf::IntRect idle7 = sf::IntRect(903, 192, 65, 65);
		sf::IntRect idle8 = sf::IntRect(1043, 192, 65, 65);

		this->boss_idle_rects.emplace_back(idle1);
		this->boss_idle_rects.emplace_back(idle2);
		this->boss_idle_rects.emplace_back(idle3);
		this->boss_idle_rects.emplace_back(idle4);
		this->boss_idle_rects.emplace_back(idle5);
		this->boss_idle_rects.emplace_back(idle6);
		this->boss_idle_rects.emplace_back(idle7);
		this->boss_idle_rects.emplace_back(idle8);


		//MOVE
		sf::IntRect move1_b = sf::IntRect(63, 26, 65, 65);
		sf::IntRect move2_b = sf::IntRect(198, 26, 65, 65);
		sf::IntRect move3_b = sf::IntRect(343, 26, 65, 65);
		sf::IntRect move4_b = sf::IntRect(486, 26, 65, 65);
		sf::IntRect move5_b = sf::IntRect(620, 26, 65, 65);
		sf::IntRect move6_b = sf::IntRect(758, 26, 65, 65);
		sf::IntRect move7_b = sf::IntRect(905, 26, 65, 65);
		sf::IntRect move8_b = sf::IntRect(1048, 26, 65, 65);

		this->boss_move_rects.emplace_back(move1_b);
		this->boss_move_rects.emplace_back(move2_b);
		this->boss_move_rects.emplace_back(move3_b);
		this->boss_move_rects.emplace_back(move4_b);
		this->boss_move_rects.emplace_back(move5_b);
		this->boss_move_rects.emplace_back(move6_b);
		this->boss_move_rects.emplace_back(move7_b);
		this->boss_move_rects.emplace_back(move8_b);


		//ATTACK

		sf::IntRect atk1_b = sf::IntRect(63, 371, 86, 65);
		sf::IntRect atk2_b = sf::IntRect(201, 371, 86, 65);
		sf::IntRect atk3_b = sf::IntRect(336, 371, 86, 65);
		sf::IntRect atk4_b = sf::IntRect(477, 371, 86, 65);
		sf::IntRect atk5_b = sf::IntRect(598, 371, 86, 65);
		sf::IntRect atk6_b = sf::IntRect(779, 371, 86, 65);

		this->boss_attack_rects.emplace_back(atk1_b);
		this->boss_attack_rects.emplace_back(atk2_b);
		this->boss_attack_rects.emplace_back(atk3_b);
		this->boss_attack_rects.emplace_back(atk4_b);
		this->boss_attack_rects.emplace_back(atk5_b);
		this->boss_attack_rects.emplace_back(atk6_b);

		//DEAD
		sf::IntRect dead1_b = sf::IntRect(54, 533, 65, 65);
		sf::IntRect dead2_b = sf::IntRect(192, 533, 65, 65);
		sf::IntRect dead3_b = sf::IntRect(332, 533, 65, 65);
		sf::IntRect dead4_b = sf::IntRect(476, 533, 65, 65);

		this->boss_die_rects.emplace_back(dead1_b);
		this->boss_die_rects.emplace_back(dead2_b);
		this->boss_die_rects.emplace_back(dead3_b);
		this->boss_die_rects.emplace_back(dead4_b);


}

void Age::initAnimationsRects_Gunpowder()
{
}


