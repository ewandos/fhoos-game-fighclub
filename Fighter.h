// Created by Philip Ewert on 2019-05-09.
// Copyright (c) 2019 ewandos. All rights reserved.
//

#ifndef FIGHTCLUB_FIGHTER_H
#define FIGHTCLUB_FIGHTER_H

#include <iostream>
#include <cstdlib>  // for rand()

#define FIGHTER_COUNT 2
#define FIGHTER_ARR {new Warrior(), new Ninja()}

class Fighter   // base Class for all Fighters
{
public:
    Fighter();
    virtual ~Fighter();
    void IntroduceYourself();   // prints all you have to know about the fighter

    std::string name;
    std::string ability;
    int healthPoints; // is public for testing

    void giveName(std::string &name);
    void Fights(Fighter *Enemy);
    bool isAlive();
    virtual void ReceiveDamage(int damage); // how char deals with incoming damage?
protected:

    int offensePoints;
    int defensePoints;

    virtual void SpecialAttack(Fighter *Enemy); // specifies the Fights Move
    virtual void SpecialDefense(Fighter *Enemy);    // specifies the Defense Move
    virtual int OffensiveDamage();   // how char calc dealing attack damage?
    virtual int DefensiveDamage();    // how char calc dealing defense damage?
};

/*
 * ALL TYPES OF FIGHTERS
 */

class Warrior : public Fighter
{
public:
    Warrior();
    ~Warrior();

protected:
    int OffensiveDamage() override;
};

class Ninja : public Fighter
{
public:
    Ninja();
    ~Ninja();

protected:
    void ReceiveDamage(int damage) override;
};

#endif //FIGHTCLUB_FIGHTER_H
