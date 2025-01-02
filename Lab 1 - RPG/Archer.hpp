//
//  Archer.hpp
//  Lab 1 RPG
//
//  Created by Seong-Eun Cho on 5/9/16.
//  Copyright © 2016 Seong-Eun Cho. All rights reserved.
//

#ifndef Archer_hpp
#define Archer_hpp

#include <stdio.h>
#include "Fighter.h"
using namespace std;

class Archer : public Fighter
{
private:
    int damage;
    int currentS;
    
public:
    Archer(string name, int hitpoint, int strength, int speed, int magic);
    ~Archer(){}
    int getDamage();
    void reset();
    void regenerate();
    bool useAbility();
};

#endif /* Archer_hpp */
