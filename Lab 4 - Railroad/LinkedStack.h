#ifndef STACK_H_
#define STACK_H_

namespace railroad {
    /** A stack is a data structure that provides last-in first-out
     access to the items that are stored in it. Only the most recently
     inserted item is accessible.
     */
    template<typename T>
    class LinkedStack {
    public:
        // Constructor and member functions
        /** Constructs an initially empty stack. */
        LinkedStack() : Top(NULL), length(0) {}
        bool find(T value)
        {
            bool x;
            Node* a = Top;
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
        /** Pushes an item onto the top of the stack.
         @param item The item to be inserted
         */
        void push(const T& item){
            Top = new Node(item, Top);
            length++;
        }
        /** Returns a reference to the object at the top of the stack
         without removing it.
         @return A reference to the object at the top of the stack
         */
        T& top(){
            return Top->data;
        }
        /** Returns a const reference to the object at the at the
         top of the stack without removing it.
         @return A const reference to the object at the top of the stack
         */
        const T& top() const{
            return Top->data;
        }
        /** Removes the top item from the stack. */
        void pop(){
            if (Top != NULL){
                Node* oldTop = Top;
                Top = Top->next;
                delete oldTop;
                length--;
            }
        }
        /** Determines whether the stack is empty. */
        bool empty() const{
            return Top == NULL;
        }
        /** Returns the number of items in the stack. */
        int size() const{
            return length;
        }
    private:
        // Data fields
        /** A sequential container to contain the stack items */
        struct Node
        {
            T data;
            Node* next;
            Node(T data, Node* next){
                this->data = data;
                this->next = next;
            }
        };
        Node* Top;
        int length;

    }; // End class stack

} // End namespace railroad
#endif