//
//  main.cpp
//  Lab 2- Linked List
//
//  Created by Seong-Eun Cho on 5/17/16.
//  Copyright © 2016 Seong-Eun Cho. All rights reserved.
//

#include <iostream>
#include "LinkedList.h"

int main() {
    LinkedList<int> a;
    
    a.insertHead(5);
    a.insertHead(6);
    a.insertHead(7);
    a.insertTail(8);
    a.insertTail(9);
    a.insertHead(4);
    a.insertAfter(2, 6);
    a.insertTail(5);
    a.insertHead(8);
    a.insertAfter(10, 4);
    
    a.remove(7);
    a.show();
    
    cout << "size is " << a.size();
    
    try{
        a.at(9);
    }
    catch (out_of_range)
    {
        cout << "cool";
    }
    
    return 0;
}
