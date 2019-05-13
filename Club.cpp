// Created by Philip Ewert on 2019-05-11.
// Copyright (c) 2019 ewandos. All rights reserved.
//

#include "Club.h"

Club::Club()
{
    this->customFighterCount = 0;

    for (int i = 0; i < MAX_CUSTOM_FIGHTERS; i++)
    {
        this->CustomFighters[i] = nullptr;
    }
}

Club::~Club()
{
    for (int i = 0; i < FIGHTER_TYPES_COUNT; i++)
    {
        delete this->FighterTypes[i];
    }

    for (int i = 0; i < MAX_CUSTOM_FIGHTERS; i++)
    {
        if (this->CustomFighters[i] != nullptr)
            delete this->CustomFighters[i];
    }
}

void Club::CreateFighter()
{
    std::cout << "---- CREATE FIGHTER ----" << std::endl;

    for (int i = 0; i < FIGHTER_TYPES_COUNT; i++)
    {
        std::cout << "[" << i << "] " << this->FighterTypes[i]->name << std::endl;
    }

    int input = -1;
    while (1602)
    {
        if (input >= 0 && input < FIGHTER_TYPES_COUNT)
        {
            std::string name = "";
            std::cout << "Enter a nickname: ";
            std::cin >> name;

            Fighter f = *this->FighterTypes[input];
            f.giveName(name);
            Fighter *pointer = &f;

            this->CustomFighters[customFighterCount] = pointer;
            this->customFighterCount++;
            break;
        }
    }

    std::cout << "Pick a type:" << std::endl;
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

void Club::IntroduceFighters()
{
    for (int i = 0; i < FIGHTER_TYPES_COUNT; i++)
    {   std::cout << std::endl << "NUMBER " << i+1 << " ================" << std::endl;
        FighterTypes[i]->IntroduceYourself();
    }
    std::cout << std::endl;
}

void Club::StartFight(Fighter** Fighters)
{
    // TODO: Need to implement function to name chosen fighters!

    this->IntroduceFighters();
    int firstInput = 0;
    while (1602)
    {
        std::cout << "Choose your first Fighter: ";
        std::cin >> firstInput;
        if (firstInput <= FIGHTER_TYPES_COUNT && firstInput > 0)
        {
            Fighters[0] = this->FighterTypes[firstInput - 1];
            break;
        }
    }

    int secondInput = 0;
    while (1602)
    {
        std::cout << "Choose your second Fighter: ";
        std::cin >> secondInput;
        if (secondInput <= FIGHTER_TYPES_COUNT && secondInput > 0 && secondInput != firstInput)
        {
            Fighters[1] = this->FighterTypes[secondInput - 1];
            break;
        }
    }

    std::cout << "You've chosen your fighters!" << std::endl << "Let the battle begin!" << std::endl;
    this->Standoff(Fighters[0], Fighters[1], 1);
}
