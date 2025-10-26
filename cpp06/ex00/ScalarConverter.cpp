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
// CONSTRUCTORS AND DESTRUCTOR (private to prevent instantiation)
// ============================================================================

ScalarConverter::ScalarConverter() {}	// Private default constructor

ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }	// Private copy constructor

ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;						// Suppress unused parameter warning
    return *this;
}

ScalarConverter::~ScalarConverter() {}	// Private destructor

// ============================================================================
// HELPER FUNCTIONS FOR OUTPUT
// ============================================================================

// Print "impossible" for all types
static void outputImpossibleForAll() {
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
}

// Print CHAR from numeric value
static void displayCharType(double value) {
    std::cout << "char: ";
    
    // If NaN or infinity → impossible
    if (std::isnan(value) || std::isinf(value)) {
        std::cout << "impossible" << std::endl;
        return;
    }
    
    // If outside char range (0-127) → impossible
    if (value < 0 || value > 127) {
        std::cout << "impossible" << std::endl;
        return;
    }
    
    // If in range but not printable (32-126) → Non displayable
    char c = static_cast<char>(value);
    if (value >= 32 && value <= 126)
        std::cout << "'" << c << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
}

// Print INT from double value
static void displayIntType(double value) {
    std::cout << "int: ";
    
    // If NaN, infinity or out of range → impossible
    if (std::isnan(value) || std::isinf(value) ||
        value < std::numeric_limits<int>::min() ||
        value > std::numeric_limits<int>::max()) {
        std::cout << "impossible" << std::endl;
        return;
    }
    
    std::cout << static_cast<int>(value) << std::endl;
}

// Print FLOAT with correct format
static void displayFloatType(float value) {
    std::cout << "float: ";
    
    if (std::isnan(value))
        std::cout << "nanf" << std::endl;
    else if (std::isinf(value))
        std::cout << (value > 0 ? "+inff" : "-inff") << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << value << "f" << std::endl;
}

// Print DOUBLE with correct format
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
// TYPE DETECTION FUNCTIONS
// ============================================================================

// Check if it's a CHAR (1 printable character that is NOT a digit)
static bool checkIfChar(const std::string& literal) {
    return (literal.length() == 1 && 
            std::isprint(literal[0]) && 
            !std::isdigit(literal[0]));
}

// Check if it's an INT (only digits, optionally +/- at start)
static bool checkIfInteger(const std::string& literal) {
    if (literal.empty())
        return false;
    
    size_t i = 0;
    
    // Skip optional sign
    if (literal[i] == '+' || literal[i] == '-')
        i++;
    
    // Must have at least one digit after sign
    if (i >= literal.length())
        return false;
    
    // All remaining characters must be digits
    while (i < literal.length()) {
        if (!std::isdigit(literal[i]))
            return false;
        i++;
    }
    
    return true;
}

// Check if it's a FLOAT (ends with 'f' or is float pseudoliteral)
static bool checkIfFloatType(const std::string& literal) {
    // Special float pseudoliterals
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        return true;
    
    // Must end with 'f' and have at least 2 characters
    if (literal.length() < 2 || literal[literal.length() - 1] != 'f')
        return false;
    
    return true;
}

// Check if it's a DOUBLE (pseudoliterals or contains decimal point)
static bool checkIfDoubleType(const std::string& literal) {
    // Special double pseudoliterals
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
        return true;
    
    // Can contain decimal point
    return (literal.find('.') != std::string::npos);
}

// ============================================================================
// MAIN FUNCTION: CONVERT
// ============================================================================

void ScalarConverter::convert(const std::string& literal) {
    
    // ========== CASE 1: CHAR (single non-digit character) ==========
    if (checkIfChar(literal)) {
        char c = literal[0];
        
        displayCharType(static_cast<double>(c));
        displayIntType(static_cast<double>(c));
        displayFloatType(static_cast<float>(c));
        displayDoubleType(static_cast<double>(c));
        return;
    }
    
    // ========== CASE 2: INT (only digits) ==========
    if (checkIfInteger(literal)) {
        char* end;
        errno = 0;
        long num = std::strtol(literal.c_str(), &end, 10);
        
        // Check for overflow or invalid input
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
    
    // ========== CASE 3: FLOAT (ends with 'f' or pseudoliterals) ==========
    if (checkIfFloatType(literal)) {
        float f;
        
        // Special pseudoliterals
        if (literal == "nanf")
            f = std::numeric_limits<float>::quiet_NaN();
        else if (literal == "+inff")
            f = std::numeric_limits<float>::infinity();
        else if (literal == "-inff")
            f = -std::numeric_limits<float>::infinity();
        else {
            // Remove 'f' from end and parse
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
    
    // ========== CASE 4: DOUBLE (contains point or pseudoliterals) ==========
    if (checkIfDoubleType(literal)) {
        double d;
        
        // Special pseudoliterals
        if (literal == "nan")
            d = std::numeric_limits<double>::quiet_NaN();
        else if (literal == "+inf")
            d = std::numeric_limits<double>::infinity();
        else if (literal == "-inf")
            d = -std::numeric_limits<double>::infinity();
        else {
            // Parse normally
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
    
    // ========== CASE 5: Invalid input ==========
    outputImpossibleForAll();
}
