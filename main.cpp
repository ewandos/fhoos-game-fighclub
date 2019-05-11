//
//  main.cpp
//  fightclub
//
//  Created by Philip Ewert on 2019-05-09.
//  Copyright © 2019 ewandos. All rights reserved.
//
// TODO: Validation for Character Name Length before construction

#include <iostream>
#include "Fighter.h"

int main()
{
    std::string name1 = "Hans";
    std::string name2 = "Yi Xao";
    Fighter *f1 = new Warrior(name1);
    Fighter *f2 = new Warrior(name2);

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

    std::cout << name1 << ":" << f1Wins << std::endl;
    std::cout << name2 << ":" << f2Wins << std::endl;

    return 0;
}