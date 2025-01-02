#ifndef QUEUE_H_
#define QUEUE_H_

namespace railroad {
    /** A queue is a data structure that provides first-in first-out
     access to the items that are stored in it. Only the least recently
     inserted item is accessible.
     */
    template<typename T>
    class LinkedQueue {
    public:
        // Constructor and member functions
        /** Constructs an empty queue. */
        LinkedQueue() : Front(NULL), Back(NULL), length(0) {}

        bool find(T value)
        {
            bool x;
            Node* a = Front;
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
        /** Pushes an item onto the back of the queue.
         @param item The item to be inserted
         */
        void push(const T& item){
            if (Front == NULL){
                Back = new Node(item, NULL);
                Front = Back;
            }
            else{
                Back->next = new Node(item, NULL);
                Back = Back->next;
            }
            length++;
        }
        /** Returns a reference to the object at the front of the queue
         without removing it.
         @return A reference to the object at the front of the queue
         */
        T& front(){
            return Front->data;
        }
        /** Returns a const reference to the object at the
         front of the queue without removing it.
         @return A const reference to the object at the front of the queue
         */
        const T& front() const{
            return Front->data;
        }
        /** Removes the front item from the queue. */
        void pop(){
            if (Front != NULL){
                Node* oldFront = Front;
                Front = Front->next;
                if (Front == NULL){
                    Back = NULL;
                }
                delete oldFront;
                length--;
            }
            
        }
        /** Determines whether the queue is empty. */
        bool empty() const{
            return Front == NULL;
        }
        /** Returns the number of items in the queue */
        int size() const{
            return length;
        }
    private:
        // Insert implementation-specific data fields
        struct Node
        {
            T data;
            Node* next;
            Node(T data, Node* next){
                this->data = data;
                this->next = next;
            }
        };
        Node* Front;
        Node* Back;
        int length;
    }; // End class queue

} // End namespace railroad
#endif
