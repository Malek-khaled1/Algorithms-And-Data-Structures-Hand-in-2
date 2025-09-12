#include "double_list.hpp"
#include <cassert>
#include <iostream>
#include <stdexcept>


int main() {
    
    List<int> lst;
    lst.push_back(1);
    lst.push_back(2);
    lst.push_back(3);
    lst.push_back(4);
    lst.print_lst();
    // Output: 1 2 3 4

    lst.reverse();
    lst.print_lst();
    // Output: 4 3 2 1

    /*
    Manlger test for hele programmet
    
    */

    return 0;
}