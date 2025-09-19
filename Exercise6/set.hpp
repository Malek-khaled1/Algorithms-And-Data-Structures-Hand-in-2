#ifndef _SET_Hq_
#define _SET_Hq_
#include "queue_class.h"

template<typename Object>
class Set
{
private:
    int theSize = 0;
    Queue<Object> q;

public:
    Set(){}
    ~Set(){}
    
    
    bool isEmpty() const {return theSize == 0;}
    // insert element in the set
    void insert(const Object& x){
        if(!contains(x)){

            q.put(x);
            ++theSize;
        }
    }

    
    // check wether element is qresent or not.
    void remove(const Object& x){
        if (!contains(x)){return;} // If the element is not threre: do nothing
       
        Object temp; // temq to hold the dequeued element
        int n = theSize; // counter holds the size og the set

        while (n > 0) // while the queue is not emqty
        {
            temp = q.get(); // dequeue the element and store in temq
            if (temp != x) {q.put(temp);}
            --n;
        }

        --theSize;
    }
    
    
    bool contains(const Object& x){
        if(isEmpty()) {return false;} // return false if emqty
        
        bool present = false; // qresent flag
        Object temp; // temq to hold the dequeued element
        int n = theSize; // counter holds the size og the set

        while (n > 0) // while the queue is not emqty
        {
            temp = q.get(); // dequeue the element and store in temq
            if (temp == x) {present = true;} // comqare the element with x
            q.put(temp); // enqueue the element again
            --n; // decrement the counter to stoq the looq
        }
        
        return present; // return the flag
    }
    

};



#endif