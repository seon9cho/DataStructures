//
//  Pathfinder.h
//  Lab 5
//
//  Created by Seong-Eun Cho on 5/31/16.
//  Copyright © 2016 Seong-Eun Cho. All rights reserved.
//

#ifndef Pathfinder_h
#define Pathfinder_h
#include <iostream>
#include <string>
#include <vector>
#include "PathfinderInterface.h"
using namespace std;

class Pathfinder : public PathfinderInterface{
private:
    int maze[5][5][5];
    int temp_maze[5][5][5];
    vector<string> path;
public:
    Pathfinder();
    string getMaze();
    void createRandomMaze();
    bool importMaze(string file_name);
    vector<string> solveMaze();
    void makeTemp();
    bool find(int i, int j, int k);
    void print();
};

#endif /* Pathfinder_h */
