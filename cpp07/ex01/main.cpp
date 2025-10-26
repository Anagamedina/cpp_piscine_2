/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 12:00:00 by anamedin          #+#    #+#             */
/*   Updated: 2025/10/14 12:00:00 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "iter.hpp"

// ==========================================
// FUNCIONES DE PRUEBA CON CONST REFERENCE
// ==========================================

// Imprime un int (no lo modifica, usa const &)
void printInt(int const & x) {
    std::cout << x << " ";
}

// Imprime un string (no lo modifica, usa const &)
void printString(std::string const & s) {
    std::cout << s << " ";
}

// Imprime un char (no lo modifica, usa const &)
void printChar(char const & c) {
    std::cout << c;
}

// ==========================================
// FUNCIONES DE PRUEBA CON NON-CONST REFERENCE
// ==========================================

// Incrementa un int (SÍ lo modifica, usa &)
void incrementInt(int & x) {
    x++;
}

// Duplica un int (SÍ lo modifica, usa &)
void doubleInt(int & x) {
    x *= 2;
}

// Convierte a mayúsculas un char (SÍ lo modifica, usa &)
void toUpperChar(char & c) {
    if (c >= 'a' && c <= 'z')
        c = c - 32;
}

int main() {
    std::cout << "╔════════════════════════════════════════╗" << std::endl;
    std::cout << "║   TEST 1: Array de enteros (const)    ║" << std::endl;
    std::cout << "╚════════════════════════════════════════╝" << std::endl;
    int numbers[] = {1, 2, 3, 4, 5};
    size_t len = 5;
    
    std::cout << "Array original: ";
    ::iter(numbers, len, printInt);
    std::cout << std::endl << std::endl;
    
    std::cout << "╔════════════════════════════════════════╗" << std::endl;
    std::cout << "║   TEST 2: Incrementar elementos        ║" << std::endl;
    std::cout << "╚════════════════════════════════════════╝" << std::endl;
    ::iter(numbers, len, incrementInt);
    std::cout << "Después de incrementar: ";
    ::iter(numbers, len, printInt);
    std::cout << std::endl << std::endl;
    
    std::cout << "╔════════════════════════════════════════╗" << std::endl;
    std::cout << "║   TEST 3: Duplicar elementos           ║" << std::endl;
    std::cout << "╚════════════════════════════════════════╝" << std::endl;
    ::iter(numbers, len, doubleInt);
    std::cout << "Después de duplicar: ";
    ::iter(numbers, len, printInt);
    std::cout << std::endl << std::endl;
    
    std::cout << "╔════════════════════════════════════════╗" << std::endl;
    std::cout << "║   TEST 4: Array de strings             ║" << std::endl;
    std::cout << "╚════════════════════════════════════════╝" << std::endl;
    std::string words[] = {"Hola", "Mundo", "CPP", "Templates"};
    std::cout << "Palabras: ";
    ::iter(words, 4, printString);
    std::cout << std::endl << std::endl;
    
    std::cout << "╔════════════════════════════════════════╗" << std::endl;
    std::cout << "║   TEST 5: Array de chars               ║" << std::endl;
    std::cout << "╚════════════════════════════════════════╝" << std::endl;
    char text[] = {'h', 'e', 'l', 'l', 'o', '\0'};
    std::cout << "Texto original: ";
    ::iter(text, 5, printChar);
    std::cout << std::endl;
    
    ::iter(text, 5, toUpperChar);
    std::cout << "En mayúsculas: ";
    ::iter(text, 5, printChar);
    std::cout << std::endl;
    
    return 0;
}

