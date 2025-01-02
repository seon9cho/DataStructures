//
//  Archer.cpp
//  Lab 1 RPG
//
//  Created by Seong-Eun Cho on 5/9/16.
//  Copyright © 2016 Seong-Eun Cho. All rights reserved.
//

#include "Archer.hpp"
using namespace std;

Archer::Archer (string name, int hitpoint, int strength, int speed, int magic) : Fighter (name, hitpoint, strength, speed, magic)
{
    currentS = speed;
    damage = currentS;
}
int Archer::getDamage()
{
    return damage;
}
void Archer::reset()
{
    current_hp = hitpoint;
    currentS = speed;
    damage = currentS;
}
void Archer::regenerate()
{
    int regen;
    regen = strength / 6;
    if (regen < 1) regen = 1;
    if (current_hp < hitpoint){
        int dif = hitpoint - current_hp;
        if (dif < regen) current_hp = hitpoint;
        else current_hp += regen;
    }
}
bool Archer::useAbility()
{
    /*	Archer: Quickstep
    *	Increases the Archer's speed by one point each time the ability is used.
    *	This bonus lasts until the reset() method is used.
    *	This ability always works; there is no maximum bonus speed.
     */
    currentS++;
    damage = currentS;
    return true;
}