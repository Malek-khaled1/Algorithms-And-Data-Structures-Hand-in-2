#ifndef _ARRAY_STACK_
#define _ARRAY_STACK_
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include<algorithm>

template<typename T>
class ArrayStack
{
private:
    T* data; // pointer to the array
    int theCapacity = 100; // capacity of the array
    int theSize; // size of the array/ num of elements
    
public:
    // Default contructor
    explicit ArrayStack() {
        theSize = 0; // Stack is empty
        theCapacity = 100; // initial capacity
        data = new T[theCapacity]; // Dynamic allocation of stack with capacity
    }

    ArrayStack(int capacity)
    {
        theSize = 0; // Stack is empty
        theCapacity = capacity; // defined capacity
        data = new T[capacity]; // Dynamic allocation of stack with capacity

    }
    ~ArrayStack() {

        delete[] data;
        data = nullptr; // Idiomatic reasons only
    }

    int size() const {
      
        return theSize; 
    }

    int capacity() const {return theCapacity;}

    T pop();
    void push(T x);

    void resize();

};



template<typename T>
T ArrayStack<T>::pop()
{
    if(theSize == 0)
        {throw std::underflow_error("Error! Stack is empty, no elements to pop");}
    
    --theSize;
    T value = data[theSize];

    return value;
}
template<typename T>
void ArrayStack<T>::push(T x)
{
    if(theSize == theCapacity)
    {
        resize();
    }
    data[theSize] = x; // push element on the stack 
    ++theSize;
}
template<typename T>
void ArrayStack<T>::resize()
{   
    // Double the capacity of the stack
    T* newStack = new T[theCapacity* 2];

    for (int i = 0; i < theSize; i++)
    {
        newStack[i] = std::move(data[i]);
    }
    theCapacity *= 2; // updata the capacity
    std::swap(data, newStack); // Swap the pointers
    delete[] newStack; // delete the old Stack

}

#endif