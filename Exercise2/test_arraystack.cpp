#include<iostream>
#include<cassert>
#include"array_stack.hpp"

int main(void){

    ArrayStack<int> s(2);

    std::cout << s.capacity() << '\n';
    std::cout << s.size() << '\n';
    
    
    s.push(0);
    s.push(1);
    
    std::cout << s.size() << '\n';
    s.push(3);
    std::cout << s.capacity() << '\n';
    return 0;
}