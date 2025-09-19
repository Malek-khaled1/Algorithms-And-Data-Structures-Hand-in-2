#include <iostream>
#include "Set.hpp"

int main() {
    // Opret et Set med kapacitet 5
    Set<int> s;

    // Edge 1: Fjern fra tomt Set
    std::cout << "Test 1 (remove fra tomt): ";
    s.remove(10); // bør ikke crashe
    std::cout << (s.isEmpty() ? "OK" : "FEJL") << "\n";

    // Edge 2: Indeholder-tjek i tomt Set
    std::cout << "Test 2 (contains i tomt): ";
    std::cout << (s.contains(42) ? "FEJL" : "OK") << "\n";

    // Normal insert
    s.insert(1);
    s.insert(2);
    s.insert(3);

    // Edge 3: Indsæt samme element to gange
    std::cout << "Test 3 (insert duplikat): ";
    s.insert(2); // må ikke indsætte en ekstra 2
    std::cout << (s.contains(2) ? "OK" : "FEJL") << "\n";

    // Edge 4: Fjern element der findes
    std::cout << "Test 4 (remove eksisterende): ";
    s.remove(2);
    std::cout << (!s.contains(2) ? "OK" : "FEJL") << "\n";

    // Edge 5: Fjern element der ikke findes
    std::cout << "Test 5 (remove ikke-eksisterende): ";
    s.remove(99); // bør ikke ændre noget
    std::cout << (!s.contains(99) ? "OK" : "FEJL") << "\n";

    // Edge 6: Insert indtil køen er fuld
    std::cout << "Test 6 (insert indtil fuld): ";
    try {
        s.insert(10);
        s.insert(11);
        s.insert(12);
        s.insert(13); // afhængig af Queue-kapacitet -> kan kaste assert
        std::cout << "OK (hvis ingen crash)\n";
    } catch (...) {
        std::cout << "FEJL: kapacitetsproblem\n";
    }

    // Edge 7: Tjek isEmpty på ikke-tomt Set
    std::cout << "Test 7 (isEmpty != true): ";
    std::cout << (!s.isEmpty() ? "OK" : "FEJL") << "\n";

    // Edge 8: Fjern alle elementer
    std::cout << "Test 8 (tøm Set): ";
    s.remove(1);
    s.remove(3);
    s.remove(10);
    s.remove(11);
    s.remove(12);
    s.remove(13);
    std::cout << (s.isEmpty() ? "OK" : "FEJL") << "\n";

    return 0;
}
