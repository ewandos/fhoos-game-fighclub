//
//  main.cpp
//  fightclub
//
//  Created by Philip Ewert on 2019-05-09.
//  Copyright © 2019 ewandos. All rights reserved.
//
// TODO: Validation for Character Name Length before construction

#include <iostream>
#include "Club.h"

int main()
{
    Club *Fightclub = new Club();

    // TODO: Choose Fighters by just referring the pointers to blank objects
    Fighter *f1 = Fightclub->Fighters[0];
    Fighter *f2 = Fightclub->Fighters[1];

    Fightclub->GrandPrix(f1, f2, 100);

    return 0;
}