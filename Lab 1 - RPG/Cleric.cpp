//
//  Cleric.cpp
//  Lab 1 RPG
//
//  Created by Seong-Eun Cho on 5/9/16.
//  Copyright © 2016 Seong-Eun Cho. All rights reserved.
//

#include "Cleric.hpp"
using namespace std;

Cleric::Cleric (string name, int hitpoint, int strength, int speed, int magic) : Fighter (name, hitpoint, strength, speed, magic)
{
    mana = magic * 5;
    damage = magic;
    currentM = mana;
}
int Cleric::getDamage()
{
    return damage;
}
void Cleric::reset()
{
    current_hp = hitpoint;
    currentM = mana;
}
void Cleric::regenerate()
{
    int regen;
    regen = strength / 6;
    if (regen < 1) regen = 1;
    if (current_hp < hitpoint){
        int dif = hitpoint - current_hp;
        if (dif < regen) current_hp = hitpoint;
        else current_hp += regen;
    }
    int m_regen;
    m_regen = magic / 5;
    if (m_regen < 1) regen = 1;
    if (currentM < mana){
        int dif = mana - currentM;
        if (dif < m_regen) currentM = mana;
        else currentM += m_regen;
    }
}
bool Cleric::useAbility()
{
    /*	Cleric: Healing Light
    *	Increases the Cleric's current hit points by an amount equal to one third of its magic.
    *	Can only be used if the Cleric has at least [CLERIC_ABILITY_COST] mana.
        *	Will be used even if the Cleric's current HP is equal to their maximum HP.
            *	Decreases the Cleric's current mana by [CLERIC_ABILITY_COST] when used.
            *	Cleric Note:
            *	This ability, when successful, must increase the Cleric's current hit points
            *	by at least one, unless doing so would given the Cleric more hit points than its maximum hit points.
            *	Do not allow the current hit points to exceed the maximum hit points.*/
    if (currentM >= CLERIC_ABILITY_COST){
        int heal = magic / 3;
        if (heal < 1) heal = 1;
        if (current_hp < hitpoint){
            int dif = hitpoint - current_hp;
            if (dif < heal) current_hp = hitpoint;
            else current_hp += heal;
        }
        currentM -= CLERIC_ABILITY_COST;
        return true;
    }
    else return false;
}