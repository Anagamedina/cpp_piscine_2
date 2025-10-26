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
#include "Array.hpp"

#define MAX_VAL 750

int main(int, char**)
{
    // ==========================================
    // TEST 1: Array de enteros (test del subject)
    // ==========================================
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++)
    {
        const int value = rand();
        numbers[i] = value;
        mirror[i] = value;
    }
    
    // SCOPE (bloque) para probar constructor de copia
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        if (mirror[i] != numbers[i])
        {
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    
    // Test de acceso fuera de rango
    try
    {
        numbers[-2] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Excepción capturada: índice negativo" << std::endl;
    }
    
    try
    {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << "Excepción capturada: índice fuera de rango" << std::endl;
    }

    for (int i = 0; i < MAX_VAL; i++)
    {
        numbers[i] = rand();
    }
    delete [] mirror;
    
    // ==========================================
    // TEST 2: Array vacío
    // ==========================================
    std::cout << "\n=== TEST ARRAY VACÍO ===" << std::endl;
    Array<int> empty;
    std::cout << "Tamaño array vacío: " << empty.size() << std::endl;
    
    // ==========================================
    // TEST 3: Array de strings
    // ==========================================
    std::cout << "\n=== TEST ARRAY DE STRINGS ===" << std::endl;
    Array<std::string> words(5);
    std::cout << "Tamaño: " << words.size() << std::endl;
    
    words[0] = "Hola";
    words[1] = "Mundo";
    words[2] = "CPP";
    words[3] = "Module";
    words[4] = "07";
    
    std::cout << "Contenido: ";
    for (size_t i = 0; i < words.size(); i++) {
        std::cout << words[i] << " ";
    }
    std::cout << std::endl;
    
    // ==========================================
    // TEST 4: Copia profunda
    // ==========================================
    std::cout << "\n=== TEST COPIA PROFUNDA ===" << std::endl;
    Array<int> original(3);
    original[0] = 10;
    original[1] = 20;
    original[2] = 30;
    
    std::cout << "Original: ";
    for (size_t i = 0; i < original.size(); i++) {
        std::cout << original[i] << " ";
    }
    std::cout << std::endl;
    
    Array<int> copia(original);
    std::cout << "Copia: ";
    for (size_t i = 0; i < copia.size(); i++) {
        std::cout << copia[i] << " ";
    }
    std::cout << std::endl;
    
    // Modificar original
    original[0] = 999;
    std::cout << "\nDespués de modificar original[0] = 999:" << std::endl;
    std::cout << "Original[0]: " << original[0] << std::endl;
    std::cout << "Copia[0]: " << copia[0] << " (no cambió, copia profunda)" << std::endl;
    
    // ==========================================
    // TEST 5: Inicialización por defecto
    // ==========================================
    std::cout << "\n=== TEST INICIALIZACIÓN POR DEFECTO ===" << std::endl;
    Array<int> defaultInit(5);
    std::cout << "Valores por defecto: ";
    for (size_t i = 0; i < defaultInit.size(); i++) {
        std::cout << defaultInit[i] << " ";
    }
    std::cout << "(todos deberían ser 0)" << std::endl;
    
    return 0;
}

