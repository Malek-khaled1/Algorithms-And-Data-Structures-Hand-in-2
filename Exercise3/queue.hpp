#ifndef _QUEUE_HPP_
#define _QUEUE_HPP_

#include <stdexcept>
#include "stack_class.hpp"

template<typename object>
class queue
{
private:
    Stack<object> stack_A;
    Stack<object> stack_B;

public:
    queue(){}
    ~queue(){}
    // Push element on stack_A
    void enqueue(object x){stack_A.push(x);}

    object dequeue(){
        
        // throw error if stack is empty
        if (empty())
        {
            throw std::underflow_error("Queue is empty! Nothing to dequeue");
        }
        // if stack_B is empty
        if(stack_B.empty())
        {
            // Move alla element from A -> B
            while (!stack_A.empty())
            {
                stack_B.push(stack_A.pop());
            }
            // Pop the front element
            return stack_B.pop();
        }
        // If there is elements in B --> pop directly already in FIFO order
        else
        {
            return stack_B.pop();
        }
    }
    // If both A and B are empty --> queue is empty
    bool empty() const {return stack_A.empty() && stack_B.empty();}

};


#endif