//
//  LinkedDeque.h
//  Lab 4
//
//  Created by Seong-Eun Cho on 5/24/16.
//  Copyright © 2016 Seong-Eun Cho. All rights reserved.
//

#ifndef IRDeque_h
#define IRDeque_h

namespace railroad{
    template<typename T>
    class IRDeque{
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
        IRDeque() : Left(NULL), Right(NULL), length(0) {}
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
        void push(const T& item){
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
        void pop_left(){
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
        void pop_right(){
            if (!empty()){
                Node* oldRight = Right;
                Right = Right->next;
                if (Right == NULL){
                    Left = NULL;
                }
                delete oldRight;
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

#endif /* IRDeque_h */
