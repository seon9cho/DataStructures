//
//  QS.h
//  Quicksort
//
//  Created by Seong-Eun Cho on 6/7/16.
//  Copyright © 2016 Seong-Eun Cho. All rights reserved.
//

#ifndef QS_h
#define QS_h
#include <iostream>
#include <string>
using namespace std;

class QS{
public:
    QS();
    void sortAll();
    int medianOfThree(int left, int right);
    int partition(int left, int right, int pivotIndex);
    string getArray();
    int getSize();
    void addToArray(int value);
    bool createArray(int capacity);
    void clear();
    void swap(int first, int second);
private:
    int* array;
    int size;
    int cap;
    void quicksort(int left, int right);
};

#endif /* QS_h */
