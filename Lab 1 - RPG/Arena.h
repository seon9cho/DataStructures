//
//  Arena.h
//  Lab 1 RPG
//
//  Created by Seong-Eun Cho on 5/9/16.
//  Copyright © 2016 Seong-Eun Cho. All rights reserved.
//

#ifndef Arena_h
#define Arena_h

#include "ArenaInterface.h"
#include "Archer.hpp"
#include "Robot.hpp"
#include "Cleric.hpp"
using namespace std;

class Arena : public ArenaInterface
{
private:
    vector<FighterInterface*> fighterList;
    
public:
    Arena(){}
    ~Arena(){}
    
    bool addFighter(string info);
    bool removeFighter(string name);
    FighterInterface* getFighter(string name);
    int getSize();
    void print();
    
};

#endif /* Arena_h */
