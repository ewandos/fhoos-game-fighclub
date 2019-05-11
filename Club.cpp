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

void Club::GrandPrix(Fighter *f1, Fighter *f2, int)
{
    int f1Wins = 0;
    int f2Wins = 0;

    for (int i = 0; i < 100; i++)
    {
        while (f1->isAlive() && f2->isAlive())
        {
            f1->Fights(f2);
            f2->Fights(f1);
        }

        f1Wins += f1->isAlive();
        f2Wins += f2->isAlive();

        f1->healthPoints = 100;
        f2->healthPoints = 100;
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
