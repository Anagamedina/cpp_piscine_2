#include <iostream>
#include "MutantStack.hpp"
#include <list>
#include <set>

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

    std::cout << "**********iterate forward: "<< std::endl;
    MutantStack<int>::iterator itb = ms.begin();
    MutantStack<int>::iterator ite = ms.end();

    int i = 1;
    while (itb != ite)
    {
        std::cout << "MutanStack[" << i << "]=" << *itb << std::endl;
		++i;
		++itb;

    }
    std::cout << std::endl;

    std::cout << "**********iterate reverse: ";
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


void test_case_usingList()
{
    std::cout << "\n--- LIST TEST (SIMULATING MUTANTSTACK) ---" << std::endl;
    std::list<int> lst; 

    // ************ PUSH / TOP / POP INICIALES (Como basicTest) ************

    std::cout << "Add 2 numbers to list (PILA): 5, 17" << std::endl;
    lst.push_back(5); 
    lst.push_back(17);
    
    // El 'top' de la pila es el 'back' de la lista
    std::cout << "top (back of list): " << lst.back() << std::endl; // 17

    lst.pop_back(); 
    std::cout << "size after pop: " << lst.size() << std::endl; // 1

    // ************ PUSH RESTANTES ************
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);// new top

    // ************ ITERACIÓN HACIA ADELANTE (BASE a TOPE) ************
    std::cout << "iterate forward: " << std::endl;
    std::list<int>::iterator itb = lst.begin();
    std::list<int>::iterator ite = lst.end();

    int i = 1;
    while (itb != ite)
    {
        std::cout << "List[" << i << "]=" << *itb << std::endl;
        ++i;
        ++itb;
    }
    std::cout << std::endl;

    // ************ ITERACIÓN INVERSA (TOPE a BASE) ************
    std::cout << "iterate reverse: " << std::endl;
    for (std::list<int>::reverse_iterator rit = lst.rbegin(); rit != lst.rend(); ++rit) {
        std::cout << *rit << ' '; // De 0, 737, 5, 3, 5
    }
    std::cout << "\n" << std::endl;

}

int main() {
    basicTest();
    constIterTest();
    test_case_usingList();
    return 0;
}