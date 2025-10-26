#include <iostream>
#include "MutantStack.hpp"

static void basicTest() {
    std::cout << "--- basicTest ---" << std::endl;
    MutantStack<int> ms;
    ms.push(5);
    ms.push(17);
    std::cout << "top: " << ms.top() << std::endl; // 17
    ms.pop();
    std::cout << "size: " << ms.size() << std::endl; // 1
    ms.push(3);
    ms.push(5);
    ms.push(737);
    ms.push(0);

    std::cout << "iterate forward: ";
    for (MutantStack<int>::iterator it = ms.begin(); it != ms.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;

    std::cout << "iterate reverse: ";
    for (MutantStack<int>::reverse_iterator rit = ms.rbegin(); rit != ms.rend(); ++rit) {
        std::cout << *rit << ' ';
    }
    std::cout << std::endl;
}

static void constIterTest() {
    std::cout << "--- constIterTest ---" << std::endl;
    MutantStack<int> ms;
    ms.push(1);
    ms.push(2);
    ms.push(3);
    const MutantStack<int>& cms = ms;

    for (MutantStack<int>::const_iterator it = cms.begin(); it != cms.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << std::endl;
}

int main() {
    basicTest();
    constIterTest();
    return 0;
}
