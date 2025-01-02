//
//  Fighter.cpp
//  Lab 1 RPG
//
//  Created by Seong-Eun Cho on 5/9/16.
//  Copyright © 2016 Seong-Eun Cho. All rights reserved.
//

#include <stdio.h>
#include "Fighter.h"
using namespace std;

Fighter::Fighter (string name, int hitpoint, int strength, int speed, int magic)
{
    this->name = name;
    this->hitpoint = hitpoint;
    this->strength = strength;
    this->speed = speed;
    this->magic = magic;
    current_hp = hitpoint;
}
string Fighter::getName()
{
    return name;
}
int Fighter::getMaximumHP()
{
    return hitpoint;
}
int Fighter::getCurrentHP()
{
    return current_hp;
}

int Fighter::getStrength()
{
    return strength;
}

int Fighter::getSpeed()
{
    return speed;
}

int Fighter::getMagic()
{
    return magic;
}
void Fighter::takeDamage(int damage)
{
    int damage_taken;
    damage_taken = damage - (speed / 4);
    if (damage_taken < 1){
        damage_taken = 1;
    }
    current_hp -= damage_taken;
}