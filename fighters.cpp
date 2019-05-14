// Created by Philip Ewert on 2019-05-09.
// Copyright (c) 2019 ewandos. All rights reserved.
//

#include "fighters.h"

/*
 * =====================
 *  F I G H T E R
 * =====================
 */

Fighter::Fighter()
{
    srand(static_cast<unsigned int>(time(0)));  // seed random number
}

Fighter::~Fighter()
{

}

void Fighter::IntroduceYourself()
{
    std::cout << "The " << this->name << std::endl << this->description << std::endl;
    std::cout << "HP:  " << this->healthPoints << "  |  ";
    std::cout << "ATK: " << this->offensePoints << "  |  ";
    std::cout << "DEF: " << this->defensePoints << std::endl;
}

void Fighter::giveName(std::string &name)
{
    this->name = name;
}

bool Fighter::CanFight()
{
    return this->healthPoints > 0 && this->offensePoints > 0;
}

void Fighter::Fights(Fighter *Enemy)
{
    if (this->CanFight())
        this->SpecialAttack(Enemy);

    if (Enemy->CanFight())
        Enemy->SpecialDefense(this);
}

void Fighter::ReceiveDamage(int damage)
{
    this->healthPoints -= damage;
}

void Fighter::SpecialAttack(Fighter *Enemy)
{
    int damage = this->OffensiveDamage();
    Enemy->ReceiveDamage(damage);
}

void Fighter::SpecialDefense(Fighter *Enemy)
{
    int damage = this->DefensiveDamage();
    Enemy->ReceiveDamage(damage);
}

int Fighter::OffensiveDamage()
{
    if (this->offensePoints != 0)
        return this->offensePoints + rand() % this->offensePoints;
    else
        return 0;
}

int Fighter::DefensiveDamage()
{
    if (this->defensePoints != 0)
        return this->defensePoints + rand() % this->defensePoints;
    else
        return 0;
}

void Fighter::ResetStats()
{
    this->healthPoints = this->maxHealthPoints;
    this->offensePoints = this->maxOffensePoints;
    this->defensePoints = this->maxDefensePoints;
}

void Fighter::attack(Fighter &Enemy)    // FOR TESTS
{
    if (!this->dead && !Enemy.dead)
    {
        int damage = (rand() % this->offensePoints) * (int)this->specialAttack() * (int)Enemy.specialDefense();
        Enemy.healthPoints -= damage;
        if (this->healthPoints <= 0)
            this->dead = true;
        if (Enemy.healthPoints <= 0)
            this->dead = true;
    }
}

double Fighter::specialAttack() // FOR TESTS
{
    return 1;
}

double Fighter::specialDefense()    // FOR TESTS
{
    return 1;
}

void fight(Fighter** Fighter, int i1, int i2)   // FOR TESTS
{
    while (!Fighter[i1]->dead && !Fighter[i2]->dead)
    {
        Fighter[i1]->attack(*Fighter[i2]);
        Fighter[i2]->attack(*Fighter[i1]);
    }

    if (Fighter[i1]->dead)
    {
        Fighter[i2]->healthPoints = 1;
        delete Fighter[i1];
        Fighter[i1] = nullptr;
    }

    if (Fighter[i2]->dead)
    {
        Fighter[i1]->healthPoints = 1;
        delete Fighter[i2];
        Fighter[i2] = nullptr;
    }
}

void lastManStanding(Fighter** Fighters)    // FOR TESTS
{
    /*
    int number = sizeof(Fighters) / sizeof(Fighters);
    std::cout << "GROESSE DES ARRAYS: " << number;
    for (int i = 1; i < number; i++)
    {
        delete Fighters[i];
        Fighters[i] = nullptr;
    }
     */

    delete Fighters[0];
    Fighters[0] = nullptr;
}

/*
 * =====================
 *  W A R R I O R
 * =====================
 */

Warrior::Warrior()
{
    this->name = "Warrior";
    this->description = "Strikes hard, sometimes even harder.";

    this->maxHealthPoints = 100;
    this->maxOffensePoints = 13;
    this->maxDefensePoints = 13;

    this->healthPoints = this->maxHealthPoints;
    this->offensePoints = this->maxOffensePoints;
    this->defensePoints = this->maxDefensePoints;

}

Warrior::~Warrior()
{
    //std::cout << this->name << " is dead." << std::endl;
}

int Warrior::OffensiveDamage()
{
    int damage = this->offensePoints + rand() % this->offensePoints;
    if (rand()%6 == 0)
        return damage * 2;
    else
        return damage;
}

Warrior::Warrior(std::string name) // FOR TESTS
{
    this->name = name;
    this->description = "You will regret trying to hit him.";

    this->maxHealthPoints = 100;
    this->maxOffensePoints = 25;
    this->maxDefensePoints = 25;

    this->healthPoints = this->maxHealthPoints;
    this->offensePoints = this->maxOffensePoints;
    this->defensePoints = this->maxDefensePoints;
}

/*
 * =====================
 *  N I N J A
 * =====================
 */

Ninja::Ninja()
{
    this->name = "Ninja";
    this->description = "You will regret trying to hit him.";

    this->maxHealthPoints = 100;
    this->maxOffensePoints = 18;
    this->maxDefensePoints = 5;

    this->healthPoints = this->maxHealthPoints;
    this->offensePoints = this->maxOffensePoints;
    this->defensePoints = this->maxDefensePoints;
}

Ninja::Ninja(std::string name)  // FOR TESTS
{
    this->name = name;
    this->description = "You will regret trying to hit him.";

    this->maxHealthPoints = 100;
    this->maxOffensePoints = 25;
    this->maxDefensePoints = 25;

    this->healthPoints = this->maxHealthPoints;
    this->offensePoints = this->maxOffensePoints;
    this->defensePoints = this->maxDefensePoints;
}

Ninja::~Ninja()
{
    //std::cout << this->name << " is dead." << std::endl;
}

void Ninja::ReceiveDamage(int damage)
{
    if (rand() % 6)
        this->healthPoints -= damage;
}


/*
 * =====================
 *  P A C I F I S T
 * =====================


Pacifist::Pacifist()
{
    this->name = "Pacifist";
    this->description = "Talks to enemy until he/she gives up.";

    this->maxHealthPoints = 100;
    this->maxOffensePoints = 3;
    this->maxDefensePoints = 0;

    this->healthPoints = this->maxHealthPoints;
    this->offensePoints = this->maxOffensePoints;
    this->defensePoints = this->maxDefensePoints;
}

Pacifist::~Pacifist()
{
    std::cout << this->name << " is dead." << std::endl;
}

void Pacifist::SpecialAttack(Fighter *Enemy)
{
    int damage = this->OffensiveDamage();
    Enemy->offensePoints -= damage;
}

 */

/*
 * =====================
 *  C U R S E D
 * =====================


Cursed::Cursed()
{
    this->name = "Cursed";
    this->description = "You always meet twice.";

    this->maxHealthPoints = 100;
    this->maxOffensePoints = 25;
    this->maxDefensePoints = 5;

    this->healthPoints = this->maxHealthPoints;
    this->offensePoints = this->maxOffensePoints;
    this->defensePoints = this->maxDefensePoints;

    this->isZombie = false;
}

Cursed::~Cursed()
{
    std::cout << this->name << " is dead." << std::endl;
}

void Cursed::ReceiveDamage(int damage)
{
    this->healthPoints -= damage;
    if (this->healthPoints <= 0 && !this->isZombie)
    {
        this->name = "Zombie";
        this->isZombie = true;
        this->healthPoints = maxHealthPoints / 2;
    }
}
 */
