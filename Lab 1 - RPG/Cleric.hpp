//
//  Cleric.hpp
//  Lab 1 RPG
//
//  Created by Seong-Eun Cho on 5/9/16.
//  Copyright © 2016 Seong-Eun Cho. All rights reserved.
//

#ifndef Cleric_hpp
#define Cleric_hpp

#include <stdio.h>
#include "Fighter.h"
using namespace std;

class Cleric : public Fighter
{
private:
    int damage;
    int mana;
    int currentM;
    
public:
    Cleric (string name, int hitpoint, int strength, int speed, int magic);
    ~Cleric(){}
    int getDamage();
    void reset();
    void regenerate();
    bool useAbility();
};

#endif /* Cleric_hpp */
