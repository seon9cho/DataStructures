//
//  main.cpp
//  Quicksort
//
//  Created by Seong-Eun Cho on 6/7/16.
//  Copyright © 2016 Seong-Eun Cho. All rights reserved.
//

#include <iostream>
#include "QS.h"
using namespace std;

int main() {
    QS array;
    int i = 0;
    while (i == 0){
        int option;
        cin >> option;
        if (option == 1){
            int capacity;
            cin >> capacity;
            if (array.createArray(capacity)){
                cout << "yes" << endl;
            }
            else cout << "no" << endl;
        }
        if (option == 2){
            int value;
            cin >> value;
            array.addToArray(value);
        }
        if (option == 3){
            cout << array.getSize() << endl;
        }
        if (option == 4){
            cout << array.getArray() << endl;
        }
        if (option == 5){
            array.clear();
        }
        if (option == 6){
            int left, right;
            cin >> left >> right;
            cout << array.partition(left, right, array.medianOfThree(left, right)) << endl;
        }
        if (option == 7){
            array.sortAll();
        }
    }
    return 0;
}
