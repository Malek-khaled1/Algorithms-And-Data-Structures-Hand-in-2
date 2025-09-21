#include <iostream>
#include "Set.hpp"

int main() {
    Set<int> s;

    std::cout << "=== Test 1: Empty set checks ===\n";
    std::cout << "isEmpty(): " << (s.isEmpty() ? "true" : "false") << "\n"; // forventet: true
    std::cout << "contains(5): " << (s.contains(5) ? "true" : "false") << "\n"; // forventet: false
    s.remove(5); // fjern element der ikke findes (skal ikke crashe)

    std::cout << "\n=== Test 2: Insert one element ===\n";
    s.insert(10);
    std::cout << "isEmpty(): " << (s.isEmpty() ? "true" : "false") << "\n"; // forventet: false
    std::cout << "contains(10): " << (s.contains(10) ? "true" : "false") << "\n"; // forventet: true
    std::cout << "contains(11): " << (s.contains(11) ? "true" : "false") << "\n"; // forventet: false

    std::cout << "\n=== Test 3: Insert duplicates ===\n";
    s.insert(10);  // duplikat
    s.insert(10);  // duplikat igen
    s.display();   // forventet: kun én 10 udskrives

    std::cout << "\n=== Test 4: Insert multiple elements ===\n";
    s.insert(20);
    s.insert(30);
    s.insert(40);
    s.display();   // forventet: 10, 20, 30, 40 (i rækkefølge)

    std::cout << "\n=== Test 5: Remove element in middle ===\n";
    s.remove(30);
    s.display();   // forventet: 10, 20, 40
    std::cout << "contains(30): " << (s.contains(30) ? "true" : "false") << "\n"; // forventet: false

    std::cout << "\n=== Test 6: Remove element not in set ===\n";
    s.remove(99);  // findes ikke
    s.display();   // skal stadig være 10, 20, 40

    std::cout << "\n=== Test 7: Remove last element repeatedly ===\n";
    s.remove(40);
    s.remove(20);
    s.remove(10);
    s.display();   // forventet: tomt output
    std::cout << "isEmpty(): " << (s.isEmpty() ? "true" : "false") << "\n"; // forventet: true

    std::cout << "\n=== Test 8: insert from 0-4 in set ===\n";
    for (int i = 0; i < 5; i++) {
        s.insert(i);
    }
    s.display();  // forventet: 0,1,2,3,4
    for (int i = 0; i < 5; i++) {
        s.remove(i);
    }
    std::cout << "isEmpty(): " << (s.isEmpty() ? "true" : "false") << "\n"; // forventet: true

    return 0;
}