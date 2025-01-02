//
//  main.cpp
//  Lab 6
//
//  Created by Seong-Eun Cho on 6/3/16.
//  Copyright © 2016 Seong-Eun Cho. All rights reserved.
//

#include <iostream>
#include "BSTInterface.h"
#include "BST.h"

int main(int argc, const char * argv[]) {
    BST tree;
    int i = 0;
    while (i == 0){
        int option;
        cin >> option;
        if (option == 1){
            int a;
            cin >> a;
            tree.add(a);
        }
        else if (option == 2){
            int a;
            cin >> a;
            tree.remove(a);
        }
        else if (option == 3){
            cout << tree.getRoot() << endl;
        }
        else if (option == 4){
            tree.print();
        }
        else if (option == 5){
            tree.clear();
        }
    }
    
    return 0;
}
