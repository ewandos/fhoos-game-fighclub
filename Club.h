// Created by Philip Ewert on 2019-05-11.
// Copyright (c) 2019 ewandos. All rights reserved.
//

#ifndef FIGHTCLUB_CLUB_H
#define FIGHTCLUB_CLUB_H

#include "Fighter.h"

class Club
{
public:
    Club();
    ~Club();
    Fighter* ClubbedFighters[FIGHTER_COUNT] = FIGHTER_ARR;

    void StartFight(Fighter**);
    void Standoff(Fighter *, Fighter *, int);
private:
    void IntroduceFighters();

};


#endif //FIGHTCLUB_CLUB_H
