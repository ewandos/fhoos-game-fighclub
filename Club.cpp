// Created by Philip Ewert on 2019-05-11.
// Copyright (c) 2019 ewandos. All rights reserved.
//

#include "Club.h"

Club::Club()
{
}

Club::~Club()
{
    for (int i = 0; i < FIGHTER_COUNT; i++)
    {
        delete this->Fighters[i];
    }
}

void Club::Standoff(Fighter *f1, Fighter *f2, int rounds)
{
    int f1Wins = 0;
    int f2Wins = 0;

    for (int i = 0; i < rounds; i++)
    {
        while (f1->CanFight() && f2->CanFight())
        {
            f1->Fights(f2);
            f2->Fights(f1);
        }

        f1Wins += f1->CanFight();
        f2Wins += f2->CanFight();

        f1->ResetStats();
        f2->ResetStats();
    }

    std::cout << f1->name << ":" << f1Wins << std::endl;
    std::cout << f2->name << ":" << f2Wins << std::endl;
}

void Club::OutputFighter()
{
    for (int i = 0; i < FIGHTER_COUNT; i++)
    {
        Fighters[i]->IntroduceYourself();
    }
}
