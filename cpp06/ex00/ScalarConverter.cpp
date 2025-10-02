/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anamedin <anamedin@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 17:30:18 by anamedin          #+#    #+#             */
/*   Updated: 2025/10/02 18:47:10 by anamedin         ###   ########.fr       */
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

/*
### **PASO 1: Estructura básica**
1. Crea `ScalarConverter.hpp` con:
   - Include guards
   - Includes necesarios (`iostream`, `string`)
   - Clase con constructor/destructor/operador= privados
   - Método estático `convert(const std::string& literal)`

2. Crea `ScalarConverter.cpp` con:
   - Include del header
   - Includes adicionales que necesites
   - Implementación vacía de `convert()`

3. Crea `main.cpp` con:
   - Verificación de argumentos (debe recibir exactamente 1 argumento)
   - Llamada a `ScalarConverter::convert()`

### **PASO 2: Pseudoliterales especiales**
1. Identifica los 6 pseudoliterales:
   - 3 para float: `"+inff"`, `"-inff"`, `"nanf"`
   - 3 para double: `"+inf"`, `"-inf"`, `"nan"`

2. Implementa la lógica para detectarlos y manejarlos por separado

### **PASO 3: Detección de tipos normales**
1. Implementa funciones para detectar:
   - **Char**: longitud 1, printable, no dígito
   - **Int**: solo dígitos (opcional +/- al inicio)
   - **Float**: termina en 'f'
   - **Double**: contiene punto decimal

2. Orden de verificación: pseudoliterales → char → int → float → double

### **PASO 4: Parsing con funciones C**
1. Para **int**: usa `strtol()` y verifica rango `INT_MIN` a `INT_MAX`
2. Para **float**: usa `strtod()` y verifica que termine en 'f'
3. Para **double**: usa `strtod()` y verifica que se parseó completamente
4. Para **char**: conversión directa

### **PASO 5: Conversiones entre tipos**
1. Una vez que tienes el tipo original, convierte a los otros 3:
   - Usa `static_cast` para todas las conversiones
   - Maneja casos especiales (NaN, infinito)

### **PASO 6: Reglas de impresión**
1. **Char**:
   - `"impossible"` si NaN, infinito, o fuera de rango [0,255]
   - `"Non displayable"` si no es printable (32-126)
   - `"'X'"` si es printable

2. **Int**:
   - `"impossible"` si NaN, infinito, o fuera de rango
   - El valor numérico si es válido

3. **Float**:
   - `"nanf"`, `"+inff"`, `"-inff"` para casos especiales
   - Formato: valor + "f" (si es entero, añade ".0")

4. **Double**:
   - `"nan"`, `"+inf"`, `"-inf"` para casos especiales
   - Formato: valor (si es entero, añade ".0")

### **PASO 7: Casos edge**
1. Maneja overflow en conversiones
2. Maneja pérdida de precisión
3. Maneja literales inválidos (imprime "impossible" para todos)

### **PASO 8: Makefile**
1. Configura para compilar con `-std=c++98`
2. Incluye todos los archivos fuente
3. Reglas: `all`, `clean`, `fclean`, `re`

### **PASO 9: Pruebas**
1. Casos básicos: `"A"`, `"42"`, `"3.14f"`, `"3.14159"`
2. Pseudoliterales: `"nan"`, `"+inf"`, `"nanf"`
3. Casos edge: `"300"`, `"0"`, `"abc"`

## 🎯 **ORDEN DE IMPLEMENTACIÓN:**

1. Estructura básica
2. Pseudoliterales
3. Detección de tipos
4. Parsing
5. Conversiones
6. Impresión
7. Casos edge
8. Makefile
9. Pruebas
*/
/*static bool isPrintableChar(int value)
{
    return (value >= 32 && value <= 126);
}

static bool isIntLiteral(const std::string &s)
{
    if (s.empty()) return false;
    std::string::size_type i = 0;
    if (s[i] == '+' || s[i] == '-') i++;
    if (i >= s.size()) return false;
    for (; i < s.size(); ++i) if (!std::isdigit(s[i])) return false;
    return true;
}

static bool isFloatLiteral(const std::string &s)
{
    if (s.size() < 2) return false;
    if (s[s.size() - 1] != 'f') return false;
    // Basic pattern check: must contain at least one digit or a dot before 'f'
    bool hasDigit = false;
    bool hasDot = false;
    std::string::size_type i = 0;
    if (s[i] == '+' || s[i] == '-') i++;
    for (; i + 1 < s.size(); ++i) {
        if (std::isdigit(s[i])) hasDigit = true;
        else if (s[i] == '.') {
            if (hasDot) return false;
            hasDot = true;
        } else return false;
    }
    return hasDigit || hasDot;
}

static bool isDoubleLiteral(const std::string &s)
{
    // Must contain a dot or be a valid numeric without trailing 'f'
    if (s.empty()) return false;
    bool hasDigit = false;
    bool hasDot = false;
    std::string::size_type i = 0;
    if (s[i] == '+' || s[i] == '-') i++;
    if (i >= s.size()) return false;
    for (; i < s.size(); ++i) {
        if (std::isdigit(s[i])) hasDigit = true;
        else if (s[i] == '.') {
            if (hasDot) return false;
            hasDot = true;
        } else return false;
    }
    return hasDigit && hasDot;
}

void ScalarConverter::convert(const std::string &literal)
{
    char c = 0;
    int i = 0;
    float f = 0.0f;
    double d = 0.0;

    // Handle pseudo-literals first
    if (literal == "+inff" || literal == "-inff" || literal == "nanf") {
        if (literal[0] == '+') f = std::numeric_limits<float>::infinity();
        else if (literal[0] == '-') f = -std::numeric_limits<float>::infinity();
        else f = std::numeric_limits<float>::quiet_NaN();
        d = static_cast<double>(f);

        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << literal << std::endl;
        std::cout << "double: " << (std::isnan(f) ? "nan" : (std::isinf(f) ? (f > 0 ? "+inf" : "-inf") : "")) << std::endl;
        return;
    }
    if (literal == "nan" || literal == "+inf" || literal == "-inf") {
        if (literal[0] == '+') d = std::numeric_limits<double>::infinity();
        else if (literal[0] == '-') d = -std::numeric_limits<double>::infinity();
        else d = std::numeric_limits<double>::quiet_NaN();
        f = static_cast<float>(d);

        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: " << (std::isnan(d) ? "nanf" : (std::isinf(d) ? (d > 0 ? "+inff" : "-inff") : "")) << std::endl;
        std::cout << "double: " << literal << std::endl;
        return;
    }

    // Single printable non-digit char
    if (literal.size() == 1 && std::isprint(literal[0]) && !std::isdigit(literal[0])) {
        c = literal[0];
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    } else if (isIntLiteral(literal)) {
        char *end = 0;
        long v = std::strtol(literal.c_str(), &end, 10);
        if (*end != '\0' || v < INT_MIN || v > INT_MAX) {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
        i = static_cast<int>(v);
        c = static_cast<char>(i);
        f = static_cast<float>(i);
        d = static_cast<double>(i);
    } else if (isFloatLiteral(literal)) {
        char *end = 0;
        f = static_cast<float>(std::strtod(literal.c_str(), &end));
        if (!end || *end != 'f' || *(end + 1) != '\0') {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
        d = static_cast<double>(f);
        i = static_cast<int>(f);
        c = static_cast<char>(i);
    } else if (isDoubleLiteral(literal)) {
        char *end = 0;
        d = std::strtod(literal.c_str(), &end);
        if (*end != '\0') {
            std::cout << "char: impossible" << std::endl;
            std::cout << "int: impossible" << std::endl;
            std::cout << "float: impossible" << std::endl;
            std::cout << "double: impossible" << std::endl;
            return;
        }
        f = static_cast<float>(d);
        i = static_cast<int>(d);
        c = static_cast<char>(i);
    } else {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return;
    }

    // char output
    if (std::isnan(d) || std::isinf(d) || i < 0 || i > 255) {
        std::cout << "char: impossible" << std::endl;
    } else if (!isPrintableChar(i)) {
        std::cout << "char: Non displayable" << std::endl;
    } else {
        std::cout << "char: '" << c << "'" << std::endl;
    }

    // int output
    if (std::isnan(d) || std::isinf(d) || d < static_cast<double>(INT_MIN) || d > static_cast<double>(INT_MAX)) {
        std::cout << "int: impossible" << std::endl;
    } else {
        std::cout << "int: " << i << std::endl;
    }

    // float output
    if (std::isnan(f)) {
        std::cout << "float: nanf" << std::endl;
    } else if (std::isinf(f)) {
        std::cout << "float: " << (f > 0 ? "+inff" : "-inff") << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision((f == static_cast<int>(f)) ? 1 : 6);
        std::cout << "float: " << f << "f" << std::endl;
    }

    // double output
    if (std::isnan(d)) {
        std::cout << "double: nan" << std::endl;
    } else if (std::isinf(d)) {
        std::cout << "double: " << (d > 0 ? "+inf" : "-inf") << std::endl;
    } else {
        std::cout << std::fixed << std::setprecision((d == static_cast<int>(d)) ? 1 : 6);
        std::cout << "double: " << d << std::endl;
    }
}
	*/
