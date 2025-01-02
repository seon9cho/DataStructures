//
//  Station.cpp
//  Lab 4
//
//  Created by Seong-Eun Cho on 5/24/16.
//  Copyright © 2016 Seong-Eun Cho. All rights reserved.
//

#include <stdio.h>
#include "Station.h"
using namespace std;

Station::Station() : stack(), queue(), deque(), irDeque(), orDeque(), CurrentCar(-1) {}

bool Station::addToStation(int car){
    if (CurrentCar != -1 || stack.find(car) || queue.find(car) || deque.find(car) || car < 0){
        return false;
    }
    else{
        CurrentCar = car;
        return true;
    }
}

int Station::showCurrentCar(){
    return CurrentCar;
}

bool Station::removeFromStation(){
    if (CurrentCar != -1){
        CurrentCar = -1;
        return true;
    }
    else return false;
}

bool Station::addToStack(){
    if (CurrentCar != -1){
            if (stack.size() < 5){
            stack.push(CurrentCar);
            CurrentCar = -1;
            return true;
        }
        else return false;
    }
    else return false;
}

bool Station::removeFromStack(){
    if (CurrentCar == -1 && !stack.empty()){
        CurrentCar = stack.top();
        stack.pop();
        return true;
    }
    else return false;
}

int Station::showTopOfStack(){
    if (stack.empty()){
        return -1;
    }
    else return stack.top();
}

int Station::showSizeOfStack(){
    return stack.size();
}

bool Station::addToQueue(){
    if (CurrentCar != -1){
        if (queue.size() < 5){
            queue.push(CurrentCar);
            CurrentCar = -1;
            return true;
        }
        else return false;
    }
    else return false;
}

bool Station::removeFromQueue(){
    if (CurrentCar == -1 && !queue.empty()){
        CurrentCar = queue.front();
        queue.pop();
        return true;
    }
    else return false;
}

int Station::showTopOfQueue(){
    if (queue.empty()){
        return -1;
    }
    else return queue.front();
}

int Station::showSizeOfQueue(){
    return queue.size();
}

bool Station::addToDequeLeft(){
    if (CurrentCar != -1){
        deque.push_left(CurrentCar);
        CurrentCar = -1;
        return true;
    }
    else return false;
}

bool Station::addToDequeRight(){
    if (CurrentCar != -1){
        deque.push_right(CurrentCar);
        CurrentCar = -1;
        return true;
    }
    else return false;
}

bool Station::removeFromDequeLeft(){
    if (CurrentCar == -1 && !deque.empty()){
        CurrentCar = deque.left();
        deque.pop_left();
        return true;
    }
    else return false;
}

bool Station::removeFromDequeRight(){
    if (CurrentCar == -1 && !deque.empty()){
        CurrentCar = deque.right();
        deque.pop_right();
        return true;
    }
    else return false;
}

int Station::showTopOfDequeLeft(){
    if (deque.empty()){
        return -1;
    }
    else return deque.left();
}

int Station::showTopOfDequeRight(){
    if (deque.empty()){
        return -1;
    }
    else return deque.right();
}

int Station::showSizeOfDeque(){
    return deque.size();
}

bool Station::addToIRDequeLeft(){
    if (CurrentCar != -1){
        irDeque.push(CurrentCar);
        CurrentCar = -1;
        return true;
    }
    else return false;
}

bool Station::removeFromIRDequeLeft(){
    if (CurrentCar == -1 && !irDeque.empty()){
        CurrentCar = irDeque.left();
        irDeque.pop_left();
        return true;
    }
    else return false;
}

bool Station::removeFromIRDequeRight(){
    if (CurrentCar == -1 && !irDeque.empty()){
        CurrentCar = irDeque.right();
        irDeque.pop_right();
        return true;
    }
    else return false;
}

int Station::showTopOfIRDequeLeft(){
    if (irDeque.empty()){
        return -1;
    }
    else return irDeque.left();
}

int Station::showTopOfIRDequeRight(){
    if (irDeque.empty()){
        return -1;
    }
    else return irDeque.right();
}

int Station::showSizeOfIRDeque(){
    return irDeque.size();
}

bool Station::addToORDequeLeft(){
    if (CurrentCar != -1){
        orDeque.push_left(CurrentCar);
        CurrentCar = -1;
        return true;
    }
    else return false;
}

bool Station::addToORDequeRight(){
    if (CurrentCar != -1){
        orDeque.push_right(CurrentCar);
        CurrentCar = -1;
        return true;
    }
    else return false;
}

bool Station::removeFromORDequeLeft(){
    if (CurrentCar == -1 && !orDeque.empty()){
        CurrentCar = orDeque.left();
        orDeque.pop();
        return true;
    }
    else return false;
}

int Station::showTopOfORDequeLeft(){
    if (orDeque.empty()){
        return -1;
    }
    else return orDeque.left();
}

int Station::showSizeOfORDeque(){
    return orDeque.size();
}