#include "double_list.hpp"
#include <cassert>
#include <iostream>
#include <stdexcept>


int main() {
    
    List<int> lst;
    std::cout<<"Initialise list"<<'\n';
    
    std::cout<<"Check if list is empty:"<<'\n';
    assert(lst.empty() == true);
    std::cout<<"List is empty"<< '\n';
    
    std::cout<<"Push 1 on the list"<<'\n';
    lst.push_back(1);
    std::cout<<"Push 2 on the list"<<'\n';
    lst.push_back(2);
    std::cout<<"Push 3 on the list"<<'\n';
    lst.push_back(3);
    std::cout<<"Push 4 on the list"<<'\n';
    lst.push_back(4);
    std::cout << "Print list: expected --> 1 2 3 4" << std::endl;
    lst.print_lst();
    // Output: 1 2 3 4
    
    std::cout << "Reverse and list: expected --> 4 3 2 1" << std::endl;
    lst.reverse();
    lst.print_lst();
    // Output: 4 3 2 1

    // find specified element
    std::cout << "Find element number 3: expected --> true" << std::endl; 
    lst.find(3);

    std::cout << "pop front: expected --> 4 " << lst.pop_front() << std::endl;
    std::cout << "pop back: expected --> 1 " << lst.pop_back() << std::endl;
    
    std::cout <<"Return size of list: expected --> 2"<<'\n';
    assert(lst.size()==2);
    
    
    std::cout << "remove element on index 1: expected --> 2"<< '\n';
    lst.remove(1);

    
    std::cout << "push -1 to the front" << std::endl;
    lst.push_front(-1);
    std::cout<<"push 2 to the front"<< std:: endl; 
    lst.push_front(2); 
    std::cout << "print list: expected --> 2 -1 3" << std::endl;
    lst.print_lst();
    
    std::cout<<"Clear list"<<'\n';
    lst.clear();
    assert(lst.empty() == true);
    std::cout<<"List is clear!"<<'\n';
    
    
    

    return 0;
}