//
//  main.cpp
//  Lab 5
//
//  Created by Seong-Eun Cho on 5/31/16.
//  Copyright © 2016 Seong-Eun Cho. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <fstream>
#include "Pathfinder.h"
using namespace std;

const int SIZE = 5;

void constructMaze(int maze[5][5][5]){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            for (int k = 0; k < 5; k++){
                maze[i][j][k] = 1;
            }
        }
    }
}

string getMaze(int maze[5][5][5]){
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

void createRandomMaze(int maze[5][5][5]){
    for (int i = 0; i < 5; i++){
        for (int j = 0; j < 5; j++){
            for (int k = 0; k < 5; k++){
                maze[k][j][i] = rand() % 2;
            }
        }
    }
    maze[0][0][0] = 1;
    maze[4][4][4] = 1;
}

bool importMaze(string file_name, int maze[5][5][5]){
    int count = 0;
    string smaze[5][5][5];
    ifstream in_file(file_name);
    if (in_file.fail()){
        cout << "invalid file!" << endl;
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

void random(int a[6]){
    a[0] = 1;
    a[1] = 2;
    a[2] = 3;
    a[3] = 4;
    a[4] = 5;
    a[5] = 6;
    
    for (int i = 0; i < 6; i++){
        int b = rand() % 6;
        int c = a[i];
        a[i] = a[b];
        a[b] = c;
    }
    
}

void find(int maze[SIZE][SIZE][SIZE], int r, int c, int d, int precedence, int order, int check, int final, int count){
    
    if (count >= 1000){
        cout << "unsolvable" << endl;
        return;
    }
    if (r == SIZE - 1 && c == SIZE - 1 && d == SIZE - 1){
        cout << "(" << r << ", " << c << ", " << d << ")" << endl;
    }
    
    else{
        if (maze[r+1][c][d] == 0 || r + 1 >= SIZE || precedence == 4 || order == 4 || check == 4 || final == 4){
            if (maze[r][c+1][d] == 0 || c + 1 >= SIZE || precedence == 5 || order == 5 || check == 5 || final == 5){
                if (maze[r][c][d+1] == 0 || d + 1 >= SIZE || precedence == 6 || order == 6 || check == 6 || final == 6){
                    if (maze[r-1][c][d] == 0 || r - 1 < 0 || precedence == 1 || order == 1 || check == 1 || final == 1){
                        if (maze[r][c-1][d] == 0 || c - 1 < 0 || precedence == 2 || order == 2 || check == 2 || final == 2){
                            if (maze[r][c][d-1] == 0 || d - 1 < 0 || precedence == 3 || order == 3 || check == 3 || final == 3){
                                final = check;
                                check = order;
                                order = precedence;
                                find(maze, r, c, d, 0, 0, check, final, count);
                            }
                            else{
                                cout << "(" << r << ", " << c << ", " << d << ")" << endl;
                                count++;
                                final = check;
                                check = order;
                                order = precedence;
                                find(maze, r, c, d - 1, 6, order, check, final, count);
                            }
                        }
                        else{
                            cout << "(" << r << ", " << c << ", " << d << ")" << endl;
                            count++;
                            final = check;
                            check = order;
                            order = precedence;
                            find(maze, r, c - 1, d, 5, order, check, final, count);
                        }
                    }
                    else{
                        cout << "(" << r << ", " << c << ", " << d << ")" << endl;
                        count++;
                        final = check;
                        check = order;
                        order = precedence;
                        find(maze, r - 1, c, d, 4, order, check, final, count);
                    }
                }
                else{
                    cout << "(" << r << ", " << c << ", " << d << ")" << endl;
                    count++;
                    final = check;
                    check = order;
                    order = precedence;
                    find(maze, r, c, d + 1, 3, order, check, final, count);
                }
            }
            else{
                cout << "(" << r << ", " << c << ", " << d << ")" << endl;
                count++;
                final = check;
                check = order;
                order = precedence;
                find(maze, r, c + 1, d, 2, order, check, final, count);
            }
        }
        else{
            cout << "(" << r << ", " << c << ", " << d << ")" << endl;
            count++;
            final = check;
            check = order;
            order = precedence;
            find(maze, r + 1, c, d, 1, order, check, final, count);
        }
    }
}

int main() {
    /*int maze[5][5][5];
    string name;
    cin >> name;
    importMaze(name, maze);
    cout << getMaze(maze);
    find(maze, 0, 0, 0, 0, 0, 0, 0, 0);
    */
    Pathfinder q;
    string name;
    cin >> name;
    if (q.importMaze(name)){
        cout << q.getMaze();
    }
    else cout << "fail" << endl;
    q.solveMaze();
    q.print();

    return 0;
}
