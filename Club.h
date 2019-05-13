// Created by Philip Ewert on 2019-05-11.
// Copyright (c) 2019 ewandos. All rights reserved.
//

#ifndef FIGHTCLUB_CLUB_H
#define FIGHTCLUB_CLUB_H

#include "Fighter.h"
#define MAX_CUSTOM_FIGHTERS 20

class Club
{
public:
    Club();
    ~Club();
    Fighter* FighterTypes[FIGHTER_TYPES_COUNT] = FIGHTER_TYPES_ARR;
    Fighter* CustomFighters[MAX_CUSTOM_FIGHTERS];
    void StartFight(Fighter**);
    void CreateFighter();
private:
    int customFighterCount;

    void IntroduceFighters();
    void Standoff(Fighter *, Fighter *, int);
};


#endif //FIGHTCLUB_CLUB_H
