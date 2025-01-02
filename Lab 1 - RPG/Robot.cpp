//
//  Robot.cpp
//  Lab 1 RPG
//
//  Created by Seong-Eun Cho on 5/9/16.
//  Copyright © 2016 Seong-Eun Cho. All rights reserved.
//

#include "Robot.hpp"
using namespace std;

Robot::Robot (string name, int hitpoint, int strength, int speed, int magic) : Fighter (name, hitpoint, strength, speed, magic)
{
    energy = magic * 2;
    damage = strength;
    currentE = energy;
}
int Robot::getDamage()
{
    return damage;
}
void Robot::reset()
{
    current_hp = hitpoint;
    currentE = energy;
}
void Robot::regenerate()
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
bool Robot::useAbility()
{
    /*	Robot: Shockwave Punch
    *	Adds bonus damage to the Robot's next attack (and only its next attack) equal to (strength  * ((current_energy/maximum_energy)^4)).
    *	Can only be used if the Robot has at least [ROBOT_ABILITY_COST] energy.
        *	Decreases the Robot's current energy by [ROBOT_ABILITY_COST] (after calculating the additional damage) when used.
        *		Examples:
        *		strength=20, current_energy=20, maximum_energy=20		=> bonus_damage=20
        *		strength=20, current_energy=15, maximum_energy=20		=> bonus_damage=6
        *		strength=20, current_energy=10, maximum_energy=20		=> bonus_damage=1
        *		strength=20, current_energy=5,  maximum_energy=20		=> bonus_damage=0
        *	Robot Note:
        *	The bonus damage formula should be computed using double arithmetic, and only
        *	the final result should be cast into an integer.
     */
    if (currentE >= ROBOT_ABILITY_COST){
        double bonus = strength * pow((currentE / energy), 4);
        bonus_damage = bonus;
        currentE -= ROBOT_ABILITY_COST;
        return true;
    }
    else{
        return false;
    }
}