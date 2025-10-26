#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include "easyfind.hpp"

static void testVector() {
    std::vector<int> values;
    values.push_back(10);
    values.push_back(20);
    values.push_back(30);

    try {
        std::vector<int>::iterator it = easyfind(values, 20);
        std::cout << "Encontrado en vector: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Vector: " << e.what() << std::endl;
    }

    try {
        std::vector<int>::iterator it = easyfind(values, 99);
        std::cout << "Encontrado en vector: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Vector: " << e.what() << std::endl;
    }
}

static void testListConst() {
    std::list<int> values;
    values.push_back(1);
    values.push_back(2);
    values.push_back(3);
    const std::list<int>& cvalues = values;

    try {
        std::list<int>::const_iterator it = easyfind(cvalues, 3);
        std::cout << "Encontrado en list const: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << "List const: " << e.what() << std::endl;
    }

    try {
        std::list<int>::const_iterator it = easyfind(cvalues, -5);
        std::cout << "Encontrado en list const: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << "List const: " << e.what() << std::endl;
    }
}

static void testDeque() {
    std::deque<int> values;
    values.push_back(7);
    values.push_back(8);
    values.push_back(9);

    try {
        std::deque<int>::iterator it = easyfind(values, 8);
        std::cout << "Encontrado en deque: " << *it << std::endl;
    } catch (const std::exception& e) {
        std::cout << "Deque: " << e.what() << std::endl;
    }
}

int main() {
    testVector();
    testListConst();
    testDeque();
    return 0;
}
