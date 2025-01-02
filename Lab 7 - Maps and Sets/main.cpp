//
//  main.cpp
//  Lab 7
//
//  Created by Seong-Eun Cho on 6/13/16.
//  Copyright © 2016 Seong-Eun Cho. All rights reserved.
//

#include <iostream>
#include "GPAInterface.h"
#include "GPA.h"


// studentListMap_Small.txt studentListSet_Small.txt
int main() {
    GPA a;
    int i = 0;
    while (i == 0){
        int option;
        cin >> option;
        if (option == 1){
            string filenameS, filenameM;
            cin >> filenameM >> filenameS;
            if (a.importStudents(filenameM, filenameS)){
                cout << "yes" << endl;
            }
            else cout << "no" << endl;
            
        }
        if (option == 5){
            cout << a.getSet().size() << " " << a.getMap().size() << endl;
        }
        if (option == 6){
            unsigned long long int ID;
            cin >> ID;
            cout << a.getMap()[ID]->getName() << endl;
        }
    }
    
    return 0;
}
