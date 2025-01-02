//
//  Robot.hpp
//  Lab 1 RPG
//
//  Created by Seong-Eun Cho on 5/9/16.
//  Copyright © 2016 Seong-Eun Cho. All rights reserved.
//

#ifndef Robot_hpp
#define Robot_hpp

#include <stdio.h>
#include "Fighter.h"
using namespace std;

class Robot : public Fighter
{
private:
    int damage;
    int energy;
    int currentE;
    int bonus_damage;
    
public:
    Robot(string name, int hitpoint, int strength, int speed, int magic);
    ~Robot(){}
    int getDamage();
    void reset();
    void regenerate();
    bool useAbility();
};

#endif /* Robot_hpp */
