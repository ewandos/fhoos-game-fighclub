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
    Fighter *Fighters[2];
    Fightclub->StartFight(Fighters);
    delete Fightclub;
    return 0;
}