// Created by Philip Ewert on 2019-05-09.
// Copyright (c) 2019 ewandos. All rights reserved.
//

#ifndef FIGHTCLUB_FIGHTER_H
#define FIGHTCLUB_FIGHTER_H

#include <iostream>
#include <cstdlib>  // for rand()

#define FIGHTER_COUNT 4
#define FIGHTER_ARR {new Warrior(), new Ninja(), new Pacifist(), new Cursed()}

class Fighter   // base Class for all Fighters
{
public:
    Fighter();
    virtual ~Fighter();
    void IntroduceYourself();   // prints all you have to know about the fighter

    std::string name;
    std::string ability;

    int healthPoints; //vvv is public for testing
    int maxHealthPoints;
    int offensePoints;
    int maxOffensePoints;
    int defensePoints;
    int maxDefensePoints; //^^^

    bool CanFight();

    void giveName(std::string &name);
    void Fights(Fighter *Enemy);
    void ResetStats();
    virtual void ReceiveDamage(int damage); // how char deals with incoming damage?
protected:

    virtual void SpecialAttack(Fighter *Enemy); // specifies the Fights Move
    virtual void SpecialDefense(Fighter *Enemy);    // specifies the Defense Move
    virtual int OffensiveDamage();   // how char calc dealing attack damage?
    virtual int DefensiveDamage();    // how char calc dealing defense damage?
};

/* W A R R I O R
 * The warrior is a brave fighter that sometimes can attack very strongly
 * (one by six chance of double hitpoints)
 */

class Warrior : public Fighter
{
public:
    Warrior();
    ~Warrior();

protected:
    int OffensiveDamage() override;
};

/* N I N J A
 * Ninjas move very fast, hence they can escape attacks sometimes
 * but still launch a counterattack
 * (one by six chance that an attack does not cause any damage)
 */

class Ninja : public Fighter
{
public:
    Ninja();
    ~Ninja();

protected:
    void ReceiveDamage(int damage) override;
};

/* P A C I F I S T
 * Talks to enemy until he/she gives up.
 * (doesn't deal damage, he just reduces Enemies offensePoints)
 */

class Pacifist : public Fighter
{
public:
    Pacifist();
    ~Pacifist();

protected:
    void SpecialAttack(Fighter *Enemy) override;
};

/* C U R S E D
 * Turns into zombie after death.
 */

class Cursed : public Fighter
{
public:
    Cursed();
    ~Cursed();

protected:
    bool isZombie;
    void ReceiveDamage(int damage) override;
};

#endif //FIGHTCLUB_FIGHTER_H
