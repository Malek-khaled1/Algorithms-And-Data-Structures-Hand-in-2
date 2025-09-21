#include <iostream>
#include "Dict.hpp"

int main() {
    Dict<std::string, int> d;

    // Test 1: Insert new key
    std::cout << "Test 1 (insert new key): ";
    std::cout << (d.insert("apple", 10) ? "OK" : "FAIL") << std::endl;

    // Test 2: Insert duplicate key
    std::cout << "Test 2 (insert duplicate key): ";
    std::cout << (!d.insert("apple", 20) ? "OK" : "FAIL") << std::endl;

    // Test 3: Contains existing key
    std::cout << "Test 3 (contains existing): ";
    std::cout << (d.contains("apple") ? "OK" : "FAIL") << std::endl;

    // Test 4: Contains non-existing key
    std::cout << "Test 4 (contains non-existing): ";
    std::cout << (!d.contains("banana") ? "OK" : "FAIL") << std::endl;

    // Test 5: Remove existing key
    std::cout << "Test 5 (remove existing key): ";
    std::cout << (d.remove("apple") ? "OK" : "FAIL") << std::endl;

    // Test 6: Remove non-existing key
    std::cout << "Test 6 (remove non-existing key): ";
    std::cout << (!d.remove("banana") ? "OK" : "FAIL") << std::endl;

    // Test 7: Remove from empty dictionary
    d.remove("apple"); // dictionary already empty
    std::cout << "Test 7 (remove from empty): ";
    std::cout << (!d.remove("apple") ? "OK" : "FAIL") << std::endl;

    // Test 8: operator[] insert new key via operator[]
    std::cout << "Test 8 (operator[] inserts new key): ";
    d["banana"] = 42;
    std::cout << (d.contains("banana") && d["banana"] == 42 ? "OK" : "FAIL") << std::endl;

    // Test 9: operator[] access existing key
    std::cout << "Test 9 (operator[] access existing key): ";
    d["banana"] = 99;
    std::cout << (d["banana"] == 99 ? "OK" : "FAIL") << std::endl;

    // Test 10: isEmpty + size
    std::cout << "Test 10 (isEmpty + size): ";
    d.insert("pear", 15);
    std::cout << ((!d.isEmpty() && d.size() == 2) ? "OK" : "FAIL") << std::endl;

    return 0;
}
