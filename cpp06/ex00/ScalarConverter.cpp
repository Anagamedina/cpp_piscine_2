/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:30:18 by anamedin          #+#    #+#             */
/*   Updated: 2025/10/09 18:47:10 by anamedin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <iostream>
#include <string>
#include <limits>
#include <cstdlib>
#include <cmath>
#include <iomanip>
#include <climits>
#include <cerrno>

// ============================================================================
// CONSTRUCTORES Y DESTRUCTOR (privados para que no se puedan crear instancias)
// ============================================================================

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}

ScalarConverter::~ScalarConverter() {}

// ============================================================================
// FUNCIONES AUXILIARES DE IMPRESIÓN
// ============================================================================

// Imprime "impossible" para todos los tipos
static void outputImpossibleForAll() {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

// Imprime el CHAR a partir de un valor numérico
static void displayCharType(double value) {
    std::cout << "char: ";
    
    // Si es NaN o infinito → impossible
    if (std::isnan(value) || std::isinf(value)) {
        std::cout << "impossible" << std::endl;
        return;
    }
    
    // Si está fuera del rango de char (0-127 o 0-255) → impossible
    if (value < 0 || value > 127) {
        std::cout << "impossible" << std::endl;
        return;
    }
    
    // Si está en el rango pero no es imprimible (32-126) → Non displayable
    char c = static_cast<char>(value);
    if (value >= 32 && value <= 126)
        std::cout << "'" << c << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
}

// Imprime el INT a partir de un valor double
static void displayIntType(double value) {
    std::cout << "int: ";
    
    // Si es NaN, infinito o fuera de rango → impossible
    if (std::isnan(value) || std::isinf(value) ||
        value < std::numeric_limits<int>::min() ||
        value > std::numeric_limits<int>::max()) {
        std::cout << "impossible" << std::endl;
        return;
    }
    
    std::cout << static_cast<int>(value) << std::endl;
}

// Imprime el FLOAT con formato correcto
static void displayFloatType(float value) {
    std::cout << "float: ";
    
    if (std::isnan(value))
        std::cout << "nanf" << std::endl;
    else if (std::isinf(value))
        std::cout << (value > 0 ? "+inff" : "-inff") << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << value << "f" << std::endl;
}

// Imprime el DOUBLE con formato correcto
static void displayDoubleType(double value) {
    std::cout << "double: ";
    
    if (std::isnan(value))
        std::cout << "nan" << std::endl;
    else if (std::isinf(value))
        std::cout << (value > 0 ? "+inf" : "-inf") << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << value << std::endl;
}

// ============================================================================
// FUNCIONES DE DETECCIÓN DE TIPO
// ============================================================================

// Detecta si es un CHAR (1 solo carácter imprimible que NO sea dígito)
static bool checkIfChar(const std::string& literal) {
    return (literal.length() == 1 && 
            std::isprint(literal[0]) && 
            !std::isdigit(literal[0]));
}

// Detecta si es un INT (solo dígitos, opcionalmente +/- al inicio)
static bool checkIfInteger(const std::string& literal) {
    if (literal.empty())
        return false;
    
    size_t i = 0;
    
    // Saltar signo opcional
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    
    // Debe haber al menos un dígito después del signo
    if (i >= literal.length())
        return false;
    
    // Todos los caracteres restantes deben ser dígitos
    while (i < literal.length()) {
        if (!std::isdigit(literal[i]))
            return false;
        i++;
    }
    
    return true;
}
/*
// Detecta si es un FLOAT (termina en 'f' o es un pseudoliteral float)
static bool checkIfFloatType(const std::string& literal) {
    // Pseudoliterales especiales de float
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        return true;
    
    // Debe terminar en 'f' y tener al menos 2 caracteres
    if (literal.length() < 2 || literal[literal.length() - 1] != 'f')
        return false;
    
    return true;
}

// Detecta si es un DOUBLE (pseudoliterales o contiene punto decimal)
static bool checkIfDoubleType(const std::string& literal) {
    // Pseudoliterales especiales de double
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
        return true;
    
    // Puede contener punto decimal
    return (literal.find('.') != std::string::npos);
}
*/
// ============================================================================
// FUNCIÓN PRINCIPAL: CONVERT
// ============================================================================

/*void ScalarConverter::convert(const std::string& literal) {
    
    // ========== CASO 1: CHAR (un solo carácter no dígito) ==========
    if (checkIfChar(literal)) {
        char c = literal[0];
        
        displayCharType(static_cast<double>(c));
        displayIntType(static_cast<double>(c));
        displayFloatType(static_cast<float>(c));
        displayDoubleType(static_cast<double>(c));
        return;
    }
    
    // ========== CASO 2: INT (solo dígitos) ==========
    if (checkIfInteger(literal)) {
        char* end;
        errno = 0;
        long num = std::strtol(literal.c_str(), &end, 10);
        
        // Verificar si hay overflow o si no es válido
        if (errno == ERANGE || *end != '\0' ||
            num < std::numeric_limits<int>::min() ||
            num > std::numeric_limits<int>::max()) {
            outputImpossibleForAll();
            return;
        }
        
        int i = static_cast<int>(num);
        displayCharType(static_cast<double>(i));
        displayIntType(static_cast<double>(i));
        displayFloatType(static_cast<float>(i));
        displayDoubleType(static_cast<double>(i));
        return;
    }
    
    // ========== CASO 3: FLOAT (termina en 'f' o pseudoliterales) ==========
    if (checkIfFloatType(literal)) {
        float f;
        
        // Pseudoliterales especiales
        if (literal == "nanf")
            f = std::numeric_limits<float>::quiet_NaN();
        else if (literal == "+inff")
            f = std::numeric_limits<float>::infinity();
        else if (literal == "-inff")
            f = -std::numeric_limits<float>::infinity();
        else {
            // Quitar la 'f' del final y parsear
            std::string numStr = literal.substr(0, literal.length() - 1);
            char* end;
            errno = 0;
            double temp = std::strtod(numStr.c_str(), &end);
            
            if (errno == ERANGE || *end != '\0') {
                outputImpossibleForAll();
                return;
            }
            
            f = static_cast<float>(temp);
        }
        
        displayCharType(static_cast<double>(f));
        displayIntType(static_cast<double>(f));
        displayFloatType(f);
        displayDoubleType(static_cast<double>(f));
        return;
    }
    
    // ========== CASO 4: DOUBLE (contiene punto o pseudoliterales) ==========
    if (checkIfDoubleType(literal)) {
        double d;
        
        // Pseudoliterales especiales
        if (literal == "nan")
            d = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inf")
            d = std::numeric_limits<double>::infinity();
        else if (literal == "-inf")
            d = -std::numeric_limits<double>::infinity();
        else {
            // Parsear normalmente
            char* end;
            errno = 0;
            d = std::strtod(literal.c_str(), &end);
            
            if (errno == ERANGE || *end != '\0') {
                outputImpossibleForAll();
                return;
            }
        }
        
        displayCharType(d);
        displayIntType(d);
        displayFloatType(static_cast<float>(d));
        displayDoubleType(d);
        return;
    }
    
    // ========== CASO 5: Input inválido ==========
    outputImpossibleForAll();
}*/
