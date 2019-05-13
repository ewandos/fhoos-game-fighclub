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
    Fighter* f1 = new Cursed();
    Fighter* f2 = new Pacifist();

    Fightclub->Standoff(f1, f2, 1000);
    return 0;
}