//
//  main.cpp
//  Lab 4
//
//  Created by Seong-Eun Cho on 5/23/16.
//  Copyright © 2016 Seong-Eun Cho. All rights reserved.
//

#include <iostream>
#include "StationInterface.h"
#include "Station.h"
using namespace std;

int main()
{
    int i = 0;
    StationInterfaceExtra* station = new Station();
    while (i == 0){
        cout << "1. Add a car to the station\n"
        << "2. Remove a car from the station\n"
        << "3. Add a car from the station to a storage facility\n"
        << "4. Remove a car from a storage facility and add it to the station\n"
        << "5. Display the cars currently accessible in the station and storage facilities.\n"
        << "6. Quit." << endl;
        int option;
        cin >> option;
        
        if (cin.fail()){
            cin.clear();
            cin.ignore(100, '\n');
        }
        if (option == 1){
            if (station->showCurrentCar() == -1){
                int ID;
                cout << "Enter the car number: ";
                cin >> ID;
                if (cin.fail()){
                    cin.clear();
                    cin.ignore(100,'\n');
                    cout << "CAR COULD NOT BE ADDED!\n" << endl;
                }
                else{
                    if (station->addToStation(ID)){
                        cout << "CAR ADDED!\n" << endl;
                    }
                    else cout << "CAR COULD NOT BE ADDED!\n" << endl;
                }
            }
            else cout << "STATION IS FULL!\n" << endl;
        }
        
        if (option == 2){
            if (station->removeFromStation()){
                cout << "CAR REMOVED!\n" << endl;
            }
            else cout << "STATION IS EMPTY!\n" << endl;
            
        }
        
        if (option == 3){
            if (station->showCurrentCar() != -1){
                cout << "1. Add a car to stack\n"
                << "2. Add a car to queue\n"
                << "3. Add a car to deque\n"
                << "4. Add a car to intput restricted deque\n"
                << "5. Add a car to output restricted deque\n";
                int add;
                cin >> add;
                
                if (cin.fail()){
                    cin.clear();
                    cin.ignore(100, '\n');
                }
                
                if (add == 1) {
                    if (station->addToStack()){
                        cout << "CAR ADDED TO STACK!\n" << endl;
                    }
                    else cout << "CAR COULD NOT BE ADDED TO STACK!\n" << endl;
                }
                
                if (add == 2) {
                    if (station->addToQueue()){
                        cout << "CAR ADDED TO QUEUE!\n" << endl;
                    }
                    else cout << "CAR COULD NOT BE ADDED TO QUEUE!\n" << endl;
                }
                if (add == 3) {
                    cout << "1. Add a car to left deque\n"
                    << "2. Add a car to right deque\n";
                    int dOption;
                    cin >> dOption;
                    if (cin.fail()){
                        cin.clear();
                        cin.ignore(100, '\n');
                    }
                    if (dOption == 1){
                        if (station->addToDequeLeft()){
                            cout << "CAR ADDED TO LEFT DEQUE!\n" << endl;
                        }
                        else cout << "CAR COULD NOT BE ADDED TO LEFT DEQUE!\n" << endl;
                    }
                    if (dOption == 2){
                        if (station->addToDequeRight()) {
                            cout << "CAR ADDED TO RIGHT DEQUE!\n" << endl;
                        }
                        else cout << "CAR COULD NOT BE ADDED TO RIGHT DEQUE!\n" << endl;
                    }
                }
                if (add == 4) {
                    if (station->addToIRDequeLeft()){
                        cout << "CAR ADDED TO INPUT RESTRICTED DEQUE!\n" << endl;
                    }
                    else cout << "CAR COULD NOT BE ADDED TO INTPUT RESTRICTED DEQUE!\n" << endl;
                }
                if (add == 5) {
                    cout << "1. Add a car to left deque\n"
                    << "2. Add a car to right deque\n";
                    int dOption;
                    cin >> dOption;
                    if (cin.fail()){
                        cin.clear();
                        cin.ignore(100, '\n');
                    }
                    if (dOption == 1){
                        if (station->addToORDequeLeft()){
                            cout << "CAR ADDED TO LEFT OUTPUT RESTRICTED DEQUE!\n" << endl;
                        }
                        else cout << "CAR COULD NOT BE ADDED TO LEFT OUTPUT RESTRICTED DEQUE!\n" << endl;
                    }
                    if (dOption == 2){
                        if (station->addToORDequeRight()) {
                            cout << "CAR ADDED TO RIGHT OUTPUT RESTRICTED DEQUE!\n" << endl;
                        }
                        else cout << "CAR COULD NOT BE ADDED TO RIGHT OUTPUT RESTRICTED DEQUE!\n" << endl;
                    }
                }
            }
            else cout << "STATION IS EMPTY!\n" << endl;
        }
        
        if (option == 4){
            if (station->showCurrentCar() == -1){
                int ID;
                cout << "Enter the car number: ";
                cin >> ID;
                if (cin.fail()){
                    cin.clear();
                    cin.ignore(100, '\n');
                }
                if (station->showTopOfQueue() == ID || station->showTopOfStack() == ID || station->showTopOfDequeLeft() == ID || station->showTopOfDequeRight() == ID || station->showTopOfIRDequeRight() || station->showTopOfIRDequeLeft() || station->showTopOfORDequeLeft()){
                    if (station->showTopOfQueue() == ID){
                        station->removeFromQueue();
                        cout << "Car #" << ID << " removed from queue!\n" << endl;
                    }
                    if (station->showTopOfStack() == ID){
                        station->removeFromStack();
                        cout << "Car #" << ID << " removed from stack!\n" << endl;
                    }
                    if (station->showTopOfDequeLeft() == ID){
                        station->removeFromDequeLeft();
                        cout << "Car #" << ID << " removed from left deque!\n" << endl;
                    }
                    if (station->showTopOfDequeRight() == ID){
                        station->removeFromDequeRight();
                        cout << "Car #" << ID << " removed from right deque!\n" << endl;
                    }
                    if (station->showTopOfIRDequeLeft() == ID){
                        station->removeFromIRDequeLeft();
                        cout << "Car #" << ID << " removed from left input restricted deque!\n" << endl;
                    }
                    if (station->showTopOfIRDequeRight() == ID){
                        station->removeFromIRDequeRight();
                        cout << "Car #" << ID << " removed from right input restricted deque!\n" << endl;
                    }
                    if (station->showTopOfORDequeLeft() == ID){
                        station->removeFromORDequeLeft();
                        cout << "Car #" << ID << " removed from left output restricted deque!\n" << endl;
                    }
                }
                else cout << "CAR CANNOT BE ACCESSED!\n" << endl;
            }
            else cout << "STATION IS FULL!\n" << endl;
        }
        
        if (option == 5){
            cout << "Stack: ";
            if (station->showSizeOfStack() == 0){
                cout << "empty" << endl;
            }
            else cout << station->showTopOfStack() << endl;
            
            cout << "Deque: ";
            if (station->showSizeOfDeque() == 0){
                cout << "empty" << endl;
            }
            else cout << station->showTopOfDequeRight() << ", " << station->showTopOfDequeLeft() << endl;
            
            cout << "Input Restricted Deque: ";
            if (station->showSizeOfIRDeque() == 0){
                cout << "empty" << endl;
            }
            else cout << station->showTopOfIRDequeRight() << ", " << station->showTopOfIRDequeLeft() << endl;
            
            cout << "Output Restricted Deque: ";
            if (station->showSizeOfORDeque() == 0){
                cout << "empty" << endl;
            }
            else cout << station->showTopOfORDequeLeft() << endl;
            
            cout << "Queue: ";
            if (station->showSizeOfQueue() == 0){
                cout << "empty" << endl;
            }
            else cout << station->showTopOfQueue() << endl;
            
            cout << "Station: ";
            if (station->showCurrentCar() == -1){
                cout << "empty" << endl;
            }
            else cout << station->showCurrentCar() << endl;
        }
        
        if (option == 6){
            cout << "Choo choo ciao!!" << endl;
            i++;
        }
    }
    
    return 0;
}
