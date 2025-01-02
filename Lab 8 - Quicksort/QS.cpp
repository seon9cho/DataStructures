//
//  QS.cpp
//  Quicksort
//
//  Created by Seong-Eun Cho on 6/8/16.
//  Copyright © 2016 Seong-Eun Cho. All rights reserved.
//

#include <stdio.h>
#include "QS.h"
#include <sstream>
#include <algorithm>
using namespace std;

QS::QS() : array(NULL), size(0){}

void QS::sortAll(){
    quicksort(0, size - 1);
}
void QS::quicksort(int left, int right){
    if (right - left > 1) {  // There is data to be sorted.
        // Partition the table.
        int pivot = partition(left, right, medianOfThree(left, right));
        
        // Sort the left half.
        quicksort(left, pivot);
        
        // Sort the right half.
        quicksort(pivot + 1, right);
    }
}

int QS::medianOfThree(int left, int right){
    if (!(size == 0 || left >= right || left >= size || right >= size)){
        int median = (left + right) / 2;
        if (array[left] > array[median]) swap(left, median);
        if (array[median] > array [right]) swap(median, right);
        if (array[left] > array[median]) swap(left, median);
        return median;
    }
    else return -1;
}

int QS::partition(int left, int right, int pivotIndex){
    if (!(size == 0 || left >= right || left >= size || right >= size || pivotIndex < left || pivotIndex > right)){
        swap(left, pivotIndex);
        int up = left + 1;
        int down = right - 1;
        do {
            /* Invariant:
             All items in table[first] through table[up - 1] <= table[first]
             All items in table[down + 1] through table[last - 1] > table[first]
             */
            while ((up != right - 1) && !(array[left] < array[up])) {
                ++up; }
            // Assert: up equals last - 1 or table[up] > table[first].
            while (array[left] < array[down]) {
                --down; }
            // Assert: down equals first or table[down] <= table[first].
            if (up < down) {   // if up is to the left of down,
                // Exchange table[up] and table[down].
                swap(up, down);
            }
        } while (up < down);  // Repeat while up is left of down.
        // Exchange table[first] and table[down] thus putting the
        // pivot value where it belongs.
        // Return position of pivot.
        swap(left, down);
        return down;
    }
    else return -1;
}

string QS::getArray(){
    stringstream ss;
    for (int i = 0; i < size; i++){
        if (i != size - 1){
            ss << array[i] << ",";
        }
        else ss << array[i];
    }
    return ss.str();
}

int QS::getSize(){
    return size;
}

void QS::addToArray(int value){
    if (cap > size){
        array[size] = value;
        size++;
    }
    else return;
}

bool QS::createArray(int capacity){
    clear();
    if (capacity > 0){
        array = new int[capacity];
        cap = capacity;
        return true;
    }
    else return false;
}

void QS::clear(){
    delete[] array;
    size = 0;
    array = NULL;
}

void QS::swap(int first, int second){
    int holder = array[first];
    array[first] = array[second];
    array[second] = holder;
}