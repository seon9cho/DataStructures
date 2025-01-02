//
//  Arena.cpp
//  Lab 1 RPG
//
//  Created by Seong-Eun Cho on 5/9/16.
//  Copyright © 2016 Seong-Eun Cho. All rights reserved.
//

#include "Arena.h"
using namespace std;

bool Arena::addFighter(string info)
{
    bool A = true;
    
    int i = 0; while (isalpha(info[i])) i++;
    string name = info.substr(0, i);
    for (int i = 0; i < fighterList.size(); i++){
        if (fighterList[i]->getName() == name) A = false;
    }
    
    int j = i + 1; while (isalpha(info[j])) j++;
    string type = info.substr(i + 1, j - i - 1);
    if (type != "R" && type != "A" && type != "C") A = false;
    
    int k = j + 1; while (isdigit(info[k])) k++;
    string Hitpoint = info.substr(j + 1, k - j - 1);
    int hitpoint;
    if (Hitpoint == "") A = false;
    else hitpoint = atoi(Hitpoint.c_str());
    
    int l = k + 1; while (isdigit(info[l])) l++;
    string Strength = info.substr(k + 1, l - k - 1);
    int strength;
    if (Strength == "") A = false;
    else strength = atoi(Strength.c_str());
    
    int m = l + 1; while (isdigit(info[m])) m++;
    string Speed = info.substr(l + 1, m - l - 1);
    int speed;
    if (Speed == "") A = false;
    else speed = atoi(Speed.c_str());
    
    int n = m + 1; while (isdigit(info[n])) n++;
    string Magic = info.substr(m + 1, n - m - 1);
    int magic;
    if (Magic == "") A = false;
    else magic = atoi(Magic.c_str());
    
    if (A != false){
        FighterInterface* p;
        if (type == "R"){
            p = new Robot(name, hitpoint, strength, speed, magic);
            fighterList.push_back(p);
        }
        if (type == "A"){
            p = new Archer(name, hitpoint, strength, speed, magic);
            fighterList.push_back(p);
        }
        if (type == "C"){
            p = new Cleric(name, hitpoint, strength, speed, magic);
            fighterList.push_back(p);
        }
    }
    
    return A;
}
bool Arena::removeFighter(string name)
{
    bool A = false;
    for (int i = 0; i < fighterList.size(); i++){
        if (fighterList[i]->getName() == name){
            fighterList.erase(fighterList.begin()+i);
            A = true;
        }
    }
    
    return A;
}
FighterInterface* Arena::getFighter(string name)
{
    FighterInterface* p;
    bool A = false;
    for (int i = 0; i < fighterList.size(); i++){
        if (fighterList[i]->getName() == name){
            p = fighterList[i];
            A = true;
        }
    }
    if (A == false){
        return NULL;
    }
    else{
        return p;
    }
}
int Arena::getSize()
{
    int count = 0;
    for (int i = 0; i < fighterList.size(); i++){count++;}
    return count;
}