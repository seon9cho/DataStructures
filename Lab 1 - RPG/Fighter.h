//
//  Fighter.h
//  Lab 1 RPG
//
//  Created by Seong-Eun Cho on 5/9/16.
//  Copyright © 2016 Seong-Eun Cho. All rights reserved.
//

#ifndef Fighter_h
#define Fighter_h

#include "ArenaInterface.h"
#include <cmath>
using namespace std;

class Fighter : public FighterInterface
{
protected:
    string name;
    int hitpoint;
    int current_hp;
    int strength;
    int speed;
    int magic;
    
public:
    Fighter(string name, int hitpoint, int strength, int speed, int magic);
    ~Fighter(){}

    string getName();
    
    int getMaximumHP();
    
    int getCurrentHP();
    
    int getStrength();

    int getSpeed();

    int getMagic();

    void takeDamage(int damage);

};

#endif /* Fighter_h */
