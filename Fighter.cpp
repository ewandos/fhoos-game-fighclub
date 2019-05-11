// Created by Philip Ewert on 2019-05-09.
// Copyright (c) 2019 ewandos. All rights reserved.
//

#include "Fighter.h"

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
    std::cout << this->name << std::endl << std::endl << this->ability << std::endl;
    std::cout << "-----------------" << std::endl;
    std::cout << "HP:  " << this->healthPoints << std::endl;
    std::cout << "ATK: " << this->offensePoints << std::endl;
    std::cout << "DEF: " << this->defensePoints << std::endl;
    std::cout << "-----------------" << std::endl;
}

void Fighter::OutputStats()
{
    std::cout << this->name <<  " HP:  " << this->healthPoints << std::endl;
    std::cout << "-----------------" << std::endl;
}

bool Fighter::isAlive()
{
    return this->healthPoints > 0;
}

void Fighter::Fights(Fighter *Enemy)
{
    if (this->isAlive())
        this->SpecialAttack(Enemy);

    if (Enemy->isAlive())
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
    return this->offensePoints + rand() % (this->offensePoints / 2);
}

int Fighter::DefensiveDamage()
{
    return this->defensePoints + rand() % (this->defensePoints / 2);
}

/*
 * =====================
 *  W A R R I O R
 * =====================
 */

Warrior::Warrior(std::string &name)
{
    this->name = name;
    this->ability = "By a little chance, the warrior hits critically which deals doubled damage.";
    this->healthPoints = 130;
    this->offensePoints = 30;   // testing
    this->defensePoints = 10;   // testing
}

Warrior::~Warrior()
{
    std::cout << this->name << " is dead." << std::endl;
}

int Warrior::OffensiveDamage()
{
    int damage = this->offensePoints + rand() % (this->offensePoints / 2);
    if (rand()%6 == 0)
        return damage * 2;
    else
        return damage;
}

/*
 * =====================
 *  N I N J A
 * =====================
 */

Ninja::Ninja(std::string &name)
{
    this->name = name;
    this->ability = "By a little chance, the warrior hits critically which deals doubled damage.";
    this->healthPoints = 130;
    this->offensePoints = 30;   // testing
    this->defensePoints = 10;   // testing
}

Ninja::~Ninja()
{
    std::cout << this->name << " is dead." << std::endl;
}

void Ninja::ReceiveDamage(int damage)
{
    if (rand() % 6)
        this->healthPoints -= damage;
}



