//
//  Pathfinder.cpp
//  Lab 5
//
//  Created by Seong-Eun Cho on 6/1/16.
//  Copyright © 2016 Seong-Eun Cho. All rights reserved.
//

#include <stdio.h>
#include "Pathfinder.h"
#include <sstream>
#include <fstream>
using namespace std;

Pathfinder::Pathfinder(){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            for (int k = 0; k < 5; k++){
                maze[i][j][k] = 1;
            }
        }
    }
}

string Pathfinder::getMaze(){
    stringstream ss;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            for (int k = 0; k < 5; k++){
                if (k < 4){
                    ss << maze[k][j][i] << " ";
                }
                else ss << maze[k][j][i];
            }
            ss << endl;
        }
        if (i < 4){
            ss << endl;
        }
    }
    return ss.str();
}

void Pathfinder::createRandomMaze(){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            for (int k = 0; k < 5; k++){
                maze[k][j][i] = rand() % 2;
            }
        }
    }
}

bool Pathfinder::importMaze(string file_name){
    int count = 0;
    string smaze[5][5][5];
    ifstream in_file(file_name);
    if (in_file.fail()){
        return false;
    }
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            for (int k = 0; k < 5; k++){
                
                if (in_file >> smaze[k][j][i]) count++;
                if (smaze[k][j][i] != "1" && smaze[k][j][i] != "0") return false;
            }
        }
    }
    if (count != 125) return false;
    string dummy;
    if (in_file >> dummy) return false;
    if (smaze[0][0][0] != "1" || smaze[4][4][4] != "1") return false;
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            for (int k = 0; k < 5; k++){
                
                maze[k][j][i] = stoi(smaze[k][j][i]);
            }
        }
    }
    return true;
}

vector<string> Pathfinder::solveMaze(){
    path.clear();
    makeTemp();
    if(!find(0, 0, 0)){
        path.clear();
    }
    return path;
}

void Pathfinder::makeTemp(){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            for (int k = 0; k < 5; k++){
                temp_maze[i][j][k] = maze[i][j][k];
            }
        }
    }
}

bool Pathfinder::find(int i, int j, int k){
    stringstream ss;
    if (i == 4 && j == 4 && k == 4){
        ss << "(" << i << ", " << j << ", " << k << ")";
        path.push_back(ss.str());
        return true;
    }
    else if ((i >= 5 || i < 0 || j >= 5 || j < 0 || k >= 5 || k < 0) || temp_maze[i][j][k] != 1){
        return false;
    }
    else{
        temp_maze[i][j][k] = 2;
        ss << "(" << i << ", " << j << ", " << k << ")";
        path.push_back(ss.str());
        if (find(i + 1, j, k) || find(i, j + 1, k) ||
            find(i, j, k + 1) || find(i, j, k - 1) ||
            find(i, j - 1, k) || find(i - 1, j, k)){
            return true;
        }
        else return false;
        
    }
}

void Pathfinder::print(){
    for (int i = 0; i < path.size(); i++){
        cout << path[i] << endl;
    }
}