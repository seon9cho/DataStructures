//
//  LinkedList.h
//  Lab 2- Linked List
//
//  Created by Seong-Eun Cho on 5/17/16.
//  Copyright © 2016 Seong-Eun Cho. All rights reserved.
//

#include <stdexcept>
#ifndef LinkedList_h
#define LinkedList_h
#include "LinkedListInterface.h"


using namespace std;

template<typename T>
class LinkedList : public LinkedListInterface<T>
{
private:
    struct Node
    {
        T data;
        Node* next;
        
    };
    Node* start;
    int range;
public:

    LinkedList()
    {
        range = 0;
        start = NULL;
        
    }
    
    bool find(T value)
    {
        bool x;
        Node* a = start;
        while (a != NULL && a->data != value)
        {
            a = a->next;
        }
        if (a != NULL){
            x = true;
        }
        else{
            x = false;
        }
        return x;
    }
    
    void insertHead(T value)
    {
        if (!find(value))
        {
            Node* a = new Node;
            a->data = value;
            a->next = start;
            start = a;
            
            range++;
        }
    }
    

    void insertTail(T value)
    {
        if (!find(value))
        {
            Node* a = new Node;
            a->data = value;
            Node* b = start;
            while (b->next != NULL)
            {
                b = b->next;
            }
            b->next = a;
            a->next = NULL;
            
            range++;
        }
    }
    

    void insertAfter(T value, T insertionNode)
    {
        if (!find(value) && find(insertionNode))
        {
            Node* a = new Node;
            a->data = value;
            Node* b = start;
            while (b->data != insertionNode)
            {
                b = b->next;
            }
            a->next = b->next;
            b->next = a;
            
            range++;
        }
    }
    

    void remove(T value)
    {
        if (start != NULL){
            Node* b = start;
            if (b->data == value){
                start = start->next;
                delete b;
                range--;
            }
            else{
                while (!(b->next == NULL || b->next->data == value))
                {
                    b = b->next;
                }
                Node* a = b->next;
                if (a != NULL){
                    b->next = a->next;
                    delete a;
                    
                    range--;
                }
            }
        }
    }
    

    void clear()
    {
        Node* b;
        while (start != NULL)
        {
            b = start;
            start = start->next;
            delete b;
        }
        range = 0;
    }

    T at(int index)
    {
        if (index >= range){
            throw out_of_range("Index out of range!");
        }
        else{
            Node* a = start;
            for (int i = 0; i < index; i++)
            {
                a = a->next;
            }
            
            return a->data;
        }
    }
    

    int size()
    {
        return range;
    }
    
    ~LinkedList()
    {
        clear();
    }
    
    void show()
    {
        Node* a = start;
        while (a != NULL)
        {
            cout << a->data << endl;
            a = a->next;
        }
    }

};



#endif /* LinkedList_h */
