//
//  LinkedDeque.h
//  Lab 4
//
//  Created by Seong-Eun Cho on 5/24/16.
//  Copyright © 2016 Seong-Eun Cho. All rights reserved.
//

#ifndef ORDeque_h
#define ORDeque_h

namespace railroad{
    template<typename T>
    class ORDeque{
    private:
        struct Node
        {
            T data;
            Node* next;
            Node(T data, Node* next){
                this->data = data;
                this->next = next;
            }
        };
        Node* Left;
        Node* Right;
        int length;
    public:
        ORDeque() : Left(NULL), Right(NULL), length(0) {}
        bool find(T value)
        {
            bool x;
            Node* a = Left;
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
        void push_left(const T& item){
            if (empty()){
                Right = new Node(item, NULL);
                Left = Right;
                length++;
            }
            else{
                Left = new Node(item, Left);
                length++;
            }
        }
        void push_right(const T& item){
            if (empty()){
                Left = new Node(item, NULL);
                Right = Left;
                length++;
            }
            else{
                Right = new Node(item, Right);
                length++;
            }
        }
        void pop(){
            if (!empty()){
                Node* oldLeft = Left;
                Left = Left->next;
                if (Left == NULL){
                    Right = NULL;
                }
                delete oldLeft;
                length--;
            }
        }
        T& left(){
            return Left->data;
        }
        T& right(){
            return Right->data;
        }
        bool empty(){
            return Left == NULL;
        }
        int size() const{
            return length;
        }
        
    };
}

#endif /* ORDeque_h */
