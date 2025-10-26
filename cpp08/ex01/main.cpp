#include <iostream>
#include <vector>
#include "Span.hpp"

static void basicTest() {
    std::cout << "--- basicTest ---" << std::endl;
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);

    std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl; // 2 (entre 9 y 11)
    std::cout << "longestSpan:  " << sp.longestSpan() << std::endl;  // 14 (17-3)
}

static void rangeAddTest() {
    std::cout << "--- rangeAddTest ---" << std::endl;
    Span sp(10);
    int arr[] = {10, 20, 30, 40, 50};
    sp.addRange(arr, arr + 5);
    std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl; // 10
    std::cout << "longestSpan:  " << sp.longestSpan() << std::endl;  // 40
}

static void errorTests() {
    std::cout << "--- errorTests ---" << std::endl;
    Span sp(2);
    try {
        sp.shortestSpan();
    } catch (const std::exception& e) {
        std::cout << "Esperado (no suficientes): " << e.what() << std::endl;
    }

    sp.addNumber(1);
    sp.addNumber(2);
    try {
        sp.addNumber(3);
    } catch (const std::exception& e) {
        std::cout << "Esperado (capacidad excedida): " << e.what() << std::endl;
    }
}

static void bigTest() {
    std::cout << "--- bigTest (10,000 elementos) ---" << std::endl;
    const unsigned int N = 10000;
    Span sp(N);
    for (unsigned int i = 0; i < N; ++i) {
        sp.addNumber(static_cast<int>(i)); // 0..9999
    }
    std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl; // 1
    std::cout << "longestSpan:  " << sp.longestSpan() << std::endl;  // 9999
}

int main() {
    basicTest();
    rangeAddTest();
    errorTests();
    bigTest();
    return 0;
}
