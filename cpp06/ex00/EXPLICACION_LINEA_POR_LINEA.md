# 📖 EXPLICACIÓN LÍNEA POR LÍNEA - ScalarConverter.cpp

## 📚 ÍNDICE
- [Sección 1: Headers e Includes (líneas 1-21)](#seccion-1-headers-e-includes)
- [Sección 2: Constructores y Destructor (líneas 23-36)](#seccion-2-constructores-y-destructor)
- [Sección 3: Funciones de Impresión (líneas 38-111)](#seccion-3-funciones-de-impresion)
- [Sección 4: Funciones de Detección (líneas 113-170)](#seccion-4-funciones-de-deteccion)
- [Sección 5: Función Principal convert() (líneas 172-276)](#seccion-5-funcion-principal-convert)

---

## SECCIÓN 1: Headers e Includes (líneas 1-21)

### **Líneas 1-11: Header de 42**
```cpp
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
```
**¿Qué hace?**
- Header estándar de 42 con información del archivo
- Autor, fecha de creación, última modificación
- Solo documentación, no afecta el código

---

### **Línea 13: Include del header propio**
```cpp
#include "ScalarConverter.hpp"
```
**¿Qué hace?**
- Incluye la declaración de la clase `ScalarConverter`
- Contiene los prototipos de las funciones que implementaremos
- Las comillas `""` indican que es un archivo local (no de sistema)

---

### **Línea 14: iostream**
```cpp
#include <iostream>
```
**¿Qué hace?**
- Permite usar `std::cout`, `std::cerr`, `std::endl`
- Necesario para imprimir en pantalla

**Ejemplo de uso:**
```cpp
std::cout << "char: 'A'" << std::endl;
```

---

### **Línea 15: string**
```cpp
#include <string>
```
**¿Qué hace?**
- Permite usar `std::string`
- Métodos como `.length()`, `.c_str()`, `.substr()`, `.find()`

**Ejemplo de uso:**
```cpp
std::string literal = "42";
literal.length();  // 2
```

---

### **Línea 16: limits**
```cpp
#include <limits>
```
**¿Qué hace?**
- Proporciona `std::numeric_limits<T>`
- Obtener valores mínimos, máximos, especiales (NaN, infinito)

**Ejemplo de uso:**
```cpp
std::numeric_limits<int>::min()          // -2147483648
std::numeric_limits<int>::max()          // 2147483647
std::numeric_limits<double>::quiet_NaN() // NaN
std::numeric_limits<float>::infinity()   // +inf
```

---

### **Línea 17: cstdlib**
```cpp
#include <cstdlib>
```
**¿Qué hace?**
- Funciones de conversión C: `strtol()`, `strtod()`
- Define `NULL`

**Ejemplo de uso:**
```cpp
char* end;
long num = std::strtol("42", &end, 10);  // Convierte "42" a 42
```

---

### **Línea 18: cmath**
```cpp
#include <cmath>
```
**¿Qué hace?**
- Funciones matemáticas: `std::isnan()`, `std::isinf()`
- Detectar valores especiales

**Ejemplo de uso:**
```cpp
double d = std::numeric_limits<double>::quiet_NaN();
std::isnan(d);  // true
std::isinf(d);  // false
```

---

### **Línea 19: iomanip**
```cpp
#include <iomanip>
```
**¿Qué hace?**
- Manipuladores de formato: `std::fixed`, `std::setprecision()`
- Controlar cómo se muestran los números

**Ejemplo de uso:**
```cpp
std::cout << std::fixed << std::setprecision(1) << 3.14;
// Output: 3.1
```

---

### **Línea 20: climits**
```cpp
#include <climits>
```
**¿Qué hace?**
- Define constantes de límites: `INT_MIN`, `INT_MAX`, etc.
- Aunque también usamos `std::numeric_limits`, esto es compatibilidad C

**Ejemplo de uso:**
```cpp
INT_MIN  // -2147483648
INT_MAX  // 2147483647
```

---

### **Línea 21: cerrno**
```cpp
#include <cerrno>
```
**¿Qué hace?**
- Define `errno` (variable global de errores)
- Define `ERANGE` (error de rango)
- Detectar overflow/underflow en conversiones

**Ejemplo de uso:**
```cpp
errno = 0;
long num = std::strtol("999999999999999", &end, 10);
if (errno == ERANGE) {
    // Hubo overflow
}
```

---

## SECCIÓN 2: Constructores y Destructor (líneas 23-36)

### **Líneas 23-25: Comentario**
```cpp
// ============================================================================
// CONSTRUCTORES Y DESTRUCTOR (privados para que no se puedan crear instancias)
// ============================================================================
```
**¿Qué hace?**
- Separador visual para organizar el código
- Explica que los constructores son privados (patrón Static Class)

---

### **Línea 27: Constructor por defecto**
```cpp
ScalarConverter::ScalarConverter() {}
```
**¿Qué hace?**
- Constructor por defecto (sin parámetros)
- Está **vacío** `{}` porque no necesita inicializar nada
- Es **privado** (definido así en el .hpp)
- **NO SE PUEDE usar** desde fuera de la clase

**¿Por qué privado?**
```cpp
// ❌ NO se puede hacer esto:
ScalarConverter converter;  // Error: constructor es privado

// ✅ Solo se puede usar así:
ScalarConverter::convert("42");  // Método estático
```

**Efecto:**
- Previene crear instancias de la clase
- Implementa el patrón Static Class / Utility Class

---

### **Línea 29: Constructor de copia**
```cpp
ScalarConverter::ScalarConverter(const ScalarConverter& other) { (void)other; }
```
**¿Qué hace?**
- Constructor de copia (copia otro objeto `ScalarConverter`)
- `(void)other;` → Evita warning de "parámetro no usado"
- También es **privado**

**¿Por qué `(void)other;`?**
```cpp
// Sin esto:
ScalarConverter(const ScalarConverter& other) {
    // Warning: 'other' never used
}

// Con esto:
ScalarConverter(const ScalarConverter& other) {
    (void)other;  // Dice al compilador: "lo ignoro a propósito"
}
```

**¿Por qué está vacío?**
- No hay nada que copiar (clase sin estado/miembros)
- Solo existe para prohibir copias
- Al ser privado, nadie puede copiar objetos

---

### **Líneas 31-34: Operador de asignación**
```cpp
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
    (void)other;
    return *this;
}
```
**¿Qué hace?**
- Sobrecarga del operador `=` (asignación)
- Línea 32: `(void)other;` → Evita warning
- Línea 33: `return *this;` → Retorna referencia al objeto actual
- También es **privado**

**Desglose:**
```cpp
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
//      ↑                  ↑                          ↑
//  Retorna           Nombre del              Parámetro
//  referencia        operador                (otro objeto)
```

**¿Por qué `return *this;`?**
```cpp
// Permite encadenar asignaciones:
a = b = c;

// Equivale a:
a.operator=(b.operator=(c));

// b.operator=(c) retorna b
// a.operator=(b) retorna a
```

**¿Por qué está vacío?**
- No hay miembros que copiar
- Solo existe para prohibir asignaciones
- Al ser privado, nadie puede asignar objetos

---

### **Línea 36: Destructor**
```cpp
ScalarConverter::~ScalarConverter() {}
```
**¿Qué hace?**
- Destructor (se llama cuando el objeto se destruye)
- Está **vacío** porque no hay recursos que liberar
- Es **privado**

**¿Qué liberaría un destructor normalmente?**
```cpp
// Si tuviéramos memoria dinámica:
class OtraClase {
    int* ptr;
public:
    OtraClase() : ptr(new int(42)) {}
    ~OtraClase() { delete ptr; }  // ← Liberar memoria
};

// Pero ScalarConverter no tiene miembros, así que:
~ScalarConverter() {}  // Vacío
```

---

## SECCIÓN 3: Funciones de Impresión (líneas 38-111)

### **Líneas 38-40: Comentario separador**
```cpp
// ============================================================================
// FUNCIONES AUXILIARES DE IMPRESIÓN
// ============================================================================
```
**¿Qué hace?**
- Organización visual del código
- Indica nueva sección: funciones de impresión

---

### **Líneas 42-48: outputImpossibleForAll()**

#### **Línea 42-43: Declaración**
```cpp
// Imprime "impossible" para todos los tipos
static void outputImpossibleForAll() {
```
**Desglose:**
- `static` → Función visible solo en este archivo (.cpp)
- `void` → No retorna nada
- `outputImpossibleForAll` → Nombre descriptivo
- `()` → Sin parámetros

**¿Por qué `static`?**
```cpp
// static = función con "linkage interno"
// Solo visible en ScalarConverter.cpp
// No se puede usar desde otros archivos

// Sin static:
void outputImpossibleForAll();  // Visible en todo el programa

// Con static:
static void outputImpossibleForAll();  // Solo en este archivo
```

---

#### **Líneas 44-47: Cuerpo de la función**
```cpp
    std::cout << "char: impossible" << std::endl;
    std::cout << "int: impossible" << std::endl;
    std::cout << "float: impossible" << std::endl;
    std::cout << "double: impossible" << std::endl;
```
**¿Qué hace?**
- Imprime "impossible" para los 4 tipos
- Se usa cuando el input es inválido o no se puede convertir

**Ejemplo de salida:**
```
char: impossible
int: impossible
float: impossible
double: impossible
```

**¿Cuándo se llama?**
```cpp
ScalarConverter::convert("abc");  // Input inválido
// Output:
// char: impossible
// int: impossible
// float: impossible
// double: impossible
```

---

### **Líneas 50-72: displayCharType()**

#### **Línea 50-51: Declaración**
```cpp
// Imprime el CHAR a partir de un valor numérico
static void displayCharType(double value) {
```
**Parámetro:**
- `double value` → Valor numérico a convertir a char

**¿Por qué `double`?**
```cpp
// Usamos double como tipo "universal" para recibir cualquier número
displayCharType(65);        // int → double → char
displayCharType(3.14);      // double → char
displayCharType(65.0f);     // float → double → char
```

---

#### **Línea 52: Imprimir etiqueta**
```cpp
    std::cout << "char: ";
```
**¿Qué hace?**
- Imprime `"char: "` sin salto de línea
- El resultado (el carácter o mensaje) vendrá después

**Ejemplo:**
```
char: 'A'
      ↑ se imprime después
```

---

#### **Líneas 54-58: Verificar NaN o infinito**
```cpp
    // Si es NaN o infinito → impossible
    if (std::isnan(value) || std::isinf(value)) {
        std::cout << "impossible" << std::endl;
        return;
    }
```
**¿Qué hace?**
- Línea 55: Verifica si `value` es NaN (Not a Number) O infinito
  - `std::isnan(value)` → true si es NaN
  - `std::isinf(value)` → true si es +inf o -inf
  - `||` → OR lógico (si cualquiera es true)
- Línea 56: Si es especial, imprime "impossible"
- Línea 57: `return` → Sale de la función (no sigue ejecutando)

**Ejemplo:**
```cpp
displayCharType(std::numeric_limits<double>::quiet_NaN());
// Output: char: impossible
//         (porque NaN no se puede convertir a char)

displayCharType(std::numeric_limits<double>::infinity());
// Output: char: impossible
//         (porque infinito no se puede convertir a char)
```

---

#### **Líneas 60-64: Verificar rango de char**
```cpp
    // Si está fuera del rango de char (0-127 o 0-255) → impossible
    if (value < 0 || value > 127) {
        std::cout << "impossible" << std::endl;
        return;
    }
```
**¿Qué hace?**
- Línea 61: Verifica si está fuera del rango de char ASCII (0-127)
  - `value < 0` → Negativos no son válidos para char
  - `value > 127` → Mayor a 127 está fuera de rango
- Si está fuera, imprime "impossible" y sale

**¿Por qué 0-127?**
```cpp
// Rango de char en ASCII:
char c;  // -128 a 127 (signed)
         //    0 a 255 (unsigned)

// Usamos 0-127 para seguridad (compatible con ambos)
```

**Ejemplo:**
```cpp
displayCharType(-5);
// Output: char: impossible
//         (negativo, fuera de rango)

displayCharType(300);
// Output: char: impossible
//         (mayor a 127, fuera de rango)
```

---

#### **Líneas 66-71: Convertir e imprimir**
```cpp
    // Si está en el rango pero no es imprimible (32-126) → Non displayable
    char c = static_cast<char>(value);
    if (value >= 32 && value <= 126)
        std::cout << "'" << c << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
```
**¿Qué hace?**
- Línea 67: Convierte el double a char
  - `static_cast<char>(value)` → Conversión explícita
  - Trunca la parte decimal si la hay
- Línea 68-69: Si es imprimible (32-126), imprime entre comillas
- Línea 70-71: Si no es imprimible (0-31 o 127), imprime "Non displayable"

**Desglose de línea 67:**
```cpp
char c = static_cast<char>(value);
//   ↑        ↑                ↑
//  Tipo   Operador        Valor a
// destino  de cast       convertir
```

**¿Qué son caracteres imprimibles?**
```cpp
// ASCII 0-31: Caracteres de control (no imprimibles)
\0, \n, \t, etc.

// ASCII 32-126: Caracteres imprimibles
' ', '!', 'A', 'Z', '0', '9', etc.

// ASCII 127: DEL (no imprimible)
```

**Ejemplos:**
```cpp
displayCharType(65);
// Output: char: 'A'
//         (65 es ASCII de 'A', es imprimible)

displayCharType(10);
// Output: char: Non displayable
//         (10 es '\n', no es imprimible)

displayCharType(65.7);
// Output: char: 'A'
//         (65.7 se trunca a 65, que es 'A')
```

---

### **Líneas 74-87: displayIntType()**

#### **Línea 74-76: Declaración e inicio**
```cpp
// Imprime el INT a partir de un valor double
static void displayIntType(double value) {
    std::cout << "int: ";
```
**Similar a displayCharType:**
- Recibe un `double`
- Imprime etiqueta "int: "

---

#### **Líneas 78-84: Verificaciones**
```cpp
    // Si es NaN, infinito o fuera de rango → impossible
    if (std::isnan(value) || std::isinf(value) ||
        value < std::numeric_limits<int>::min() ||
        value > std::numeric_limits<int>::max()) {
        std::cout << "impossible" << std::endl;
        return;
    }
```
**¿Qué hace?**
- Línea 79: Verifica NaN o infinito
- Línea 80: Verifica si es menor que INT_MIN (-2147483648)
- Línea 81: Verifica si es mayor que INT_MAX (2147483647)
- Si cualquiera es true, imprime "impossible"

**Desglose:**
```cpp
std::numeric_limits<int>::min()  // -2147483648
std::numeric_limits<int>::max()  //  2147483647
```

**Ejemplos:**
```cpp
displayIntType(std::numeric_limits<double>::quiet_NaN());
// Output: int: impossible

displayIntType(3000000000.0);  // Mayor que INT_MAX
// Output: int: impossible

displayIntType(-3000000000.0);  // Menor que INT_MIN
// Output: int: impossible
```

---

#### **Línea 86: Convertir e imprimir**
```cpp
    std::cout << static_cast<int>(value) << std::endl;
```
**¿Qué hace?**
- `static_cast<int>(value)` → Convierte double a int
- Trunca decimales (no redondea)
- Imprime el resultado

**Ejemplos:**
```cpp
displayIntType(42.0);
// Output: int: 42

displayIntType(42.9);
// Output: int: 42  (trunca, no redondea)

displayIntType(-42.9);
// Output: int: -42
```

---

### **Líneas 89-99: displayFloatType()**

#### **Línea 89-91: Declaración**
```cpp
// Imprime el FLOAT con formato correcto
static void displayFloatType(float value) {
    std::cout << "float: ";
```
**Diferencia:**
- Recibe `float` (no `double`)
- Más preciso para valores float

---

#### **Líneas 93-98: Casos especiales y normales**
```cpp
    if (std::isnan(value))
        std::cout << "nanf" << std::endl;
    else if (std::isinf(value))
        std::cout << (value > 0 ? "+inff" : "-inff") << std::endl;
    else
        std::cout << std::fixed << std::setprecision(1) << value << "f" << std::endl;
```
**¿Qué hace?**
- Línea 93-94: Si es NaN, imprime "nanf"
- Línea 95-96: Si es infinito:
  - `value > 0` → "+inff"
  - `value <= 0` → "-inff"
  - Operador ternario: `condicion ? si_true : si_false`
- Línea 97-98: Si es normal:
  - `std::fixed` → Notación fija (no científica)
  - `std::setprecision(1)` → 1 decimal
  - `value` → El número
  - `"f"` → Sufijo de float

**Desglose línea 96:**
```cpp
(value > 0 ? "+inff" : "-inff")
//    ↑         ↑         ↑
// condición  si true  si false
```

**Ejemplos:**
```cpp
displayFloatType(3.14f);
// Output: float: 3.1f
//         (1 decimal con std::setprecision(1))

displayFloatType(std::numeric_limits<float>::quiet_NaN());
// Output: float: nanf

displayFloatType(std::numeric_limits<float>::infinity());
// Output: float: +inff

displayFloatType(-std::numeric_limits<float>::infinity());
// Output: float: -inff
```

---

### **Líneas 101-111: displayDoubleType()**

```cpp
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
```
**Idéntico a displayFloatType EXCEPTO:**
- Recibe `double` (no `float`)
- NaN se imprime como "nan" (no "nanf")
- Infinito como "+inf" / "-inf" (no "+inff" / "-inff")
- No añade "f" al final

**Comparación:**
```cpp
displayFloatType(3.14f);   // float: 3.1f
displayDoubleType(3.14);   // double: 3.1
```

---

## SECCIÓN 4: Funciones de Detección (líneas 113-170)

### **Líneas 113-115: Comentario separador**
```cpp
// ============================================================================
// FUNCIONES DE DETECCIÓN DE TIPO
// ============================================================================
```
**Nueva sección:** Funciones que detectan qué tipo de literal es.

---

### **Líneas 117-122: checkIfChar()**

```cpp
// Detecta si es un CHAR (1 solo carácter imprimible que NO sea dígito)
static bool checkIfChar(const std::string& literal) {
    return (literal.length() == 1 && 
            std::isprint(literal[0]) && 
            !std::isdigit(literal[0]));
}
```

**Desglose línea por línea:**

**Línea 118:**
```cpp
static bool checkIfChar(const std::string& literal) {
//  ↑    ↑         ↑                ↑
// static bool  Nombre         Parámetro
//            (retorna         (referencia
//           true/false)       constante)
```
- `static` → Solo visible en este archivo
- `bool` → Retorna true (es char) o false (no es char)
- `const std::string&` → Referencia constante (eficiente, no copia)

**Líneas 119-121: Condiciones**
```cpp
    return (literal.length() == 1 &&        // Condición 1
            std::isprint(literal[0]) &&     // Condición 2
            !std::isdigit(literal[0]));     // Condición 3
```
- **Condición 1:** `literal.length() == 1`
  - El string debe tener exactamente 1 carácter
  - "A" ✅ | "AB" ❌

- **Condición 2:** `std::isprint(literal[0])`
  - El carácter debe ser imprimible
  - 'A' ✅ | '\n' ❌

- **Condición 3:** `!std::isdigit(literal[0])`
  - El carácter NO debe ser dígito
  - 'A' ✅ | '5' ❌
  - `!` = NOT lógico

**¿Por qué `&&` (AND)?**
```cpp
// TODAS las condiciones deben ser true:
"A"  → length=1 ✅  print=✅  !digit=✅  → TRUE
"5"  → length=1 ✅  print=✅  !digit=❌  → FALSE
"AB" → length=1 ❌  print=✅  !digit=✅  → FALSE
"\n" → length=1 ✅  print=❌  !digit=✅  → FALSE
```

**Ejemplos:**
```cpp
checkIfChar("A");   // true  (1 char, imprimible, no dígito)
checkIfChar("!");   // true  (1 char, imprimible, no dígito)
checkIfChar("5");   // false (es dígito)
checkIfChar("AB");  // false (2 caracteres)
checkIfChar("\n");  // false (no imprimible)
```

---

### **Líneas 124-147: checkIfInteger()**

#### **Líneas 124-127: Inicio y verificación vacío**
```cpp
// Detecta si es un INT (solo dígitos, opcionalmente +/- al inicio)
static bool checkIfInteger(const std::string& literal) {
    if (literal.empty())
        return false;
```
- Línea 126: Verifica si el string está vacío
- `literal.empty()` → true si length == 0
- Si está vacío, retorna false (no es entero)

**Ejemplo:**
```cpp
checkIfInteger("");  // false (vacío)
```

---

#### **Línea 129: Variable índice**
```cpp
    size_t i = 0;
```
- `size_t` → Tipo sin signo para tamaños (0, 1, 2, ...)
- `i` → Índice para recorrer el string
- Empieza en 0 (primer carácter)

**¿Qué es `size_t`?**
```cpp
// Tipo sin signo (solo positivos)
// Usado para tamaños e índices
size_t i = 0;   // ✅ 0, 1, 2, 3, ...
int i = 0;      // También válido pero menos preciso
```

---

#### **Líneas 131-133: Saltar signo opcional**
```cpp
    // Saltar signo opcional
    if (literal[i] == '+' || literal[i] == '-')
        i++;
```
- Línea 132: Verifica si el primer carácter es '+' o '-'
- Línea 133: Si hay signo, incrementa `i` (salta al siguiente carácter)

**Ejemplos:**
```cpp
"+42"  → i empieza en 0, ve '+', i ahora es 1
"-42"  → i empieza en 0, ve '-', i ahora es 1
"42"   → i empieza en 0, no hay signo, i sigue en 0
```

---

#### **Líneas 135-137: Verificar que haya dígitos**
```cpp
    // Debe haber al menos un dígito después del signo
    if (i >= literal.length())
        return false;
```
- Línea 136: Verifica si ya llegamos al final del string
- Si `i >= length`, significa que solo había un signo sin dígitos
- Ejemplo: "+" o "-" → false

**Ejemplos:**
```cpp
"+"    → i=1, length=1, i>=length ✅ → false
"-"    → i=1, length=1, i>=length ✅ → false
"+42"  → i=1, length=3, i<length ✅  → continúa
```

---

#### **Líneas 139-144: Verificar todos los dígitos**
```cpp
    // Todos los caracteres restantes deben ser dígitos
    while (i < literal.length()) {
        if (!std::isdigit(literal[i]))
            return false;
        i++;
    }
```
**¿Qué hace?**
- Línea 140: Bucle que recorre el resto del string
- Línea 141: Verifica si el carácter actual es dígito
  - `std::isdigit()` → true si es '0'-'9'
  - `!` → NOT, así que si NO es dígito...
- Línea 142: ...retorna false (no es entero)
- Línea 143: Incrementa `i` para siguiente carácter

**Flujo visual:**
```
"42"
 ↑
i=0, '4' es dígito ✅, i++
 
"42"
  ↑
i=1, '2' es dígito ✅, i++

i=2, i >= length (2), sale del while
```

**Ejemplos:**
```cpp
"42"   → '4' ✅, '2' ✅ → true
"4a"   → '4' ✅, 'a' ❌ → false
"-42"  → salta '-', '4' ✅, '2' ✅ → true
"a42"  → 'a' ❌ → false (primer char no es signo ni dígito)
```

---

#### **Línea 146: Retornar true**
```cpp
    return true;
```
- Si llegamos aquí, todas las verificaciones pasaron
- El string es un entero válido

---

### **Líneas 149-160: checkIfFloatType()**

#### **Líneas 149-153: Pseudoliterales**
```cpp
// Detecta si es un FLOAT (termina en 'f' o es un pseudoliteral float)
static bool checkIfFloatType(const std::string& literal) {
    // Pseudoliterales especiales de float
    if (literal == "nanf" || literal == "+inff" || literal == "-inff")
        return true;
```
- Línea 152: Verifica si es uno de los 3 pseudoliterales especiales
  - "nanf" → Not a Number (float)
  - "+inff" → Infinito positivo (float)
  - "-inff" → Infinito negativo (float)
- Si es cualquiera, retorna true

**Ejemplos:**
```cpp
checkIfFloatType("nanf");   // true
checkIfFloatType("+inff");  // true
checkIfFloatType("-inff");  // true
```

---

#### **Líneas 155-157: Verificar terminación en 'f'**
```cpp
    // Debe terminar en 'f' y tener al menos 2 caracteres
    if (literal.length() < 2 || literal[literal.length() - 1] != 'f')
        return false;
```
**Desglose:**
- `literal.length() < 2` → Menos de 2 caracteres
  - "f" solo no es válido
  - Necesita al menos "Xf" (número + f)
- `literal[literal.length() - 1]` → Último carácter
  - `length() - 1` porque los índices empiezan en 0
- `!= 'f'` → No termina en 'f'

**Ejemplos:**
```cpp
"f"      → length < 2 ✅ → false
"3.14f"  → length >= 2 ✅, termina en 'f' ✅ → continúa
"3.14"   → length >= 2 ✅, NO termina en 'f' ❌ → false
```

---

#### **Línea 159: Retornar true**
```cpp
    return true;
```
- Si llegó aquí, es un float válido (termina en 'f')

---

### **Líneas 162-170: checkIfDoubleType()**

```cpp
// Detecta si es un DOUBLE (pseudoliterales o contiene punto decimal)
static bool checkIfDoubleType(const std::string& literal) {
    // Pseudoliterales especiales de double
    if (literal == "nan" || literal == "+inf" || literal == "-inf")
        return true;
    
    // Puede contener punto decimal
    return (literal.find('.') != std::string::npos);
}
```

**Líneas 164-166: Pseudoliterales**
- Similar a float pero sin 'f':
  - "nan" (no "nanf")
  - "+inf" (no "+inff")
  - "-inf" (no "-inff")

**Línea 169: Verificar punto decimal**
```cpp
return (literal.find('.') != std::string::npos);
```
**Desglose:**
- `literal.find('.')` → Busca el carácter '.' en el string
  - Retorna posición si lo encuentra (0, 1, 2, ...)
  - Retorna `std::string::npos` si NO lo encuentra
- `std::string::npos` → "no position" (valor especial: -1 o máximo de size_t)
- `!= std::string::npos` → "es diferente de no-encontrado" = "SÍ encontrado"

**¿Qué es `npos`?**
```cpp
std::string::npos  // Valor especial que significa "no encontrado"
// Internamente es size_t(-1) o el valor máximo de size_t

// Uso típico:
size_t pos = texto.find('.');
if (pos != std::string::npos) {
    // Se encontró el punto
}
```

**Ejemplos:**
```cpp
checkIfDoubleType("3.14");   // find('.') → 1, 1 != npos → true
checkIfDoubleType("42");     // find('.') → npos, npos == npos → false
checkIfDoubleType("nan");    // pseudoliteral → true
checkIfDoubleType(".5");     // find('.') → 0, 0 != npos → true
```

---

## SECCIÓN 5: Función Principal convert() (líneas 172-276)

### **Líneas 172-175: Inicio de convert()**
```cpp
// ============================================================================
// FUNCIÓN PRINCIPAL: CONVERT
// ============================================================================

void ScalarConverter::convert(const std::string& literal) {
```
- Línea 176: Método estático público de la clase
- Parámetro: `const std::string& literal` → El string a convertir
- No retorna nada (`void`), solo imprime

---

### **CASO 1: CHAR (líneas 178-187)**

#### **Línea 179: Detectar si es char**
```cpp
    if (checkIfChar(literal)) {
```
- Llama a `checkIfChar()` para verificar
- Si retorna true, entra en el if

---

#### **Línea 180: Obtener el carácter**
```cpp
        char c = literal[0];
```
- `literal[0]` → Primer (y único) carácter del string
- Lo guarda en variable `c` de tipo char

**Ejemplo:**
```cpp
literal = "A"
c = literal[0]  // c = 'A'
```

---

#### **Líneas 182-185: Convertir e imprimir**
```cpp
        displayCharType(static_cast<double>(c));
        displayIntType(static_cast<double>(c));
        displayFloatType(static_cast<float>(c));
        displayDoubleType(static_cast<double>(c));
```
**¿Qué hace cada línea?**

**Línea 182:** `displayCharType(static_cast<double>(c));`
- Convierte char → double
- Llama displayCharType()
- Imprime: `char: 'A'`

**Línea 183:** `displayIntType(static_cast<double>(c));`
- Convierte char → double
- Llama displayIntType()
- Imprime: `int: 65` (valor ASCII)

**Línea 184:** `displayFloatType(static_cast<float>(c));`
- Convierte char → float
- Llama displayFloatType()
- Imprime: `float: 65.0f`

**Línea 185:** `displayDoubleType(static_cast<double>(c));`
- Convierte char → double
- Llama displayDoubleType()
- Imprime: `double: 65.0`

**Ejemplo completo:**
```cpp
ScalarConverter::convert("A");
// c = 'A' (ASCII 65)
// Output:
// char: 'A'
// int: 65
// float: 65.0f
// double: 65.0
```

---

#### **Línea 186: Salir**
```cpp
        return;
```
- Sale de la función (no continúa a los otros casos)

---

### **CASO 2: INT (líneas 189-209)**

#### **Línea 190: Detectar si es int**
```cpp
    if (checkIfInteger(literal)) {
```
- Llama a `checkIfInteger()`
- Si es entero, entra en el if

---

#### **Líneas 191-192: Variables para parsing**
```cpp
        char* end;
        errno = 0;
```
**Línea 191:** `char* end;`
- Puntero que usará `strtol()` para indicar dónde terminó de convertir
- Si convierte todo correctamente, `*end` será '\0'

**Línea 192:** `errno = 0;`
- Resetea la variable global de errores
- Necesario para detectar overflow

**¿Qué es `errno`?**
```cpp
// Variable global que indica errores
errno = 0;  // Sin error
// Después de strtol():
errno == ERANGE  // Hubo overflow/underflow
errno == 0       // Sin error
```

---

#### **Línea 193: Parsear el string**
```cpp
        long num = std::strtol(literal.c_str(), &end, 10);
```
**Desglose:**
```cpp
long num = std::strtol(literal.c_str(), &end, 10);
//   ↑          ↑             ↑          ↑    ↑
// Variable  Función    String C    Puntero Base
//                                   a end   (decimal)
```
- `literal.c_str()` → Convierte std::string a const char* (string C)
- `&end` → Dirección del puntero end (se modificará)
- `10` → Base decimal (base 10)
- Retorna el número convertido como `long`

**¿Cómo funciona `strtol`?**
```cpp
// Entrada: "42abc"
char* end;
long num = strtol("42abc", &end, 10);
// num = 42
// end apunta a "abc" (donde dejó de convertir)

// Entrada: "42"
long num = strtol("42", &end, 10);
// num = 42
// end apunta a '\0' (fin del string)
```

---

#### **Líneas 195-201: Verificar errores**
```cpp
        // Verificar si hay overflow o si no es válido
        if (errno == ERANGE || *end != '\0' ||
            num < std::numeric_limits<int>::min() ||
            num > std::numeric_limits<int>::max()) {
            outputImpossibleForAll();
            return;
        }
```
**Condiciones de error:**

**1. `errno == ERANGE`**
- Hubo overflow (número demasiado grande)
- Ejemplo: "999999999999999999999"

**2. `*end != '\0'`**
- No se convirtió todo el string
- Quedaron caracteres sin convertir
- Ejemplo: "42abc" → end apunta a "abc", *end = 'a' ≠ '\0'

**3. `num < std::numeric_limits<int>::min()`**
- Número menor que INT_MIN (-2147483648)
- Aunque sea long válido, no cabe en int

**4. `num > std::numeric_limits<int>::max()`**
- Número mayor que INT_MAX (2147483647)
- Aunque sea long válido, no cabe en int

**Si cualquiera es true:**
- Llama `outputImpossibleForAll()`
- Imprime "impossible" para todos los tipos
- Sale con `return`

---

#### **Líneas 203-208: Convertir e imprimir**
```cpp
        int i = static_cast<int>(num);
        displayCharType(static_cast<double>(i));
        displayIntType(static_cast<double>(i));
        displayFloatType(static_cast<float>(i));
        displayDoubleType(static_cast<double>(i));
        return;
```
**Similar al caso char:**
- Línea 203: Convierte long → int
- Líneas 204-207: Imprime los 4 tipos
- Línea 208: Sale de la función

**Ejemplo:**
```cpp
ScalarConverter::convert("42");
// num = 42, i = 42
// Output:
// char: '*'          (ASCII 42 es '*')
// int: 42
// float: 42.0f
// double: 42.0
```

---

### **CASO 3: FLOAT (líneas 211-242)**

#### **Línea 212: Detectar si es float**
```cpp
    if (checkIfFloatType(literal)) {
```

---

#### **Línea 213: Variable para el float**
```cpp
        float f;
```
- Declara variable `f` (sin inicializar todavía)
- Se asignará en las líneas siguientes

---

#### **Líneas 215-221: Pseudoliterales**
```cpp
        // Pseudoliterales especiales
        if (literal == "nanf")
            f = std::numeric_limits<float>::quiet_NaN();
        else if (literal == "+inff")
            f = std::numeric_limits<float>::infinity();
        else if (literal == "-inff")
            f = -std::numeric_limits<float>::infinity();
```
**¿Qué hace?**
- Línea 216-217: Si es "nanf", asigna NaN
  - `std::numeric_limits<float>::quiet_NaN()` → Crea NaN
- Línea 218-219: Si es "+inff", asigna +infinito
  - `std::numeric_limits<float>::infinity()` → Crea +inf
- Línea 220-221: Si es "-inff", asigna -infinito
  - Negar infinity() da -inf

**Ejemplos:**
```cpp
literal = "nanf"   → f = NaN
literal = "+inff"  → f = +infinito
literal = "-inff"  → f = -infinito
```

---

#### **Líneas 222-235: Float normal**
```cpp
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
```

**Línea 224:** Quitar la 'f'
```cpp
std::string numStr = literal.substr(0, literal.length() - 1);
```
- `literal.substr(inicio, longitud)` → Extrae substring
- `0` → Desde el inicio
- `literal.length() - 1` → Hasta antes del último carácter
- Ejemplo: "3.14f" → "3.14"

**Línea 225-227:** Preparar parsing
```cpp
char* end;
errno = 0;
double temp = std::strtod(numStr.c_str(), &end);
```
- Similar a `strtol` pero para double
- `strtod` = "string to double"
- Convierte "3.14" → 3.14

**Líneas 229-232:** Verificar errores
```cpp
if (errno == ERANGE || *end != '\0') {
    outputImpossibleForAll();
    return;
}
```
- Igual que con int: verifica overflow y conversión completa

**Línea 234:** Convertir a float
```cpp
f = static_cast<float>(temp);
```
- Convierte el double temporal a float
- Puede haber pérdida de precisión

**Ejemplo:**
```cpp
literal = "3.14f"
numStr = "3.14"
temp = 3.14 (double)
f = 3.14f (float)
```

---

#### **Líneas 237-241: Imprimir**
```cpp
        displayCharType(static_cast<double>(f));
        displayIntType(static_cast<double>(f));
        displayFloatType(f);
        displayDoubleType(static_cast<double>(f));
        return;
```
- Imprime los 4 tipos
- Nota: displayFloatType(f) recibe float directamente

**Ejemplo:**
```cpp
ScalarConverter::convert("3.14f");
// f = 3.14f
// Output:
// char: Non displayable  (3.14 truncado a 3, no imprimible)
// int: 3                 (trunca decimales)
// float: 3.1f
// double: 3.1
```

---

### **CASO 4: DOUBLE (líneas 244-272)**

```cpp
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
```

**Muy similar al caso float EXCEPTO:**
- No quita 'f' (no tiene)
- Pseudoliterales sin 'f': "nan", "+inf", "-inf"
- Usa `strtod` directamente (no convierte desde string recortado)
- displayDoubleType(d) recibe double directamente

**Ejemplo:**
```cpp
ScalarConverter::convert("3.14159");
// d = 3.14159
// Output:
// char: Non displayable
// int: 3
// float: 3.1f
// double: 3.1
```

---

### **CASO 5: Input inválido (líneas 274-275)**

```cpp
    // ========== CASO 5: Input inválido ==========
    outputImpossibleForAll();
```
- Si no es char, int, float ni double
- Imprime "impossible" para todos

**Ejemplo:**
```cpp
ScalarConverter::convert("abc");
// No pasa ningún check
// Output:
// char: impossible
// int: impossible
// float: impossible
// double: impossible
```

---

## 🎯 RESUMEN DEL FLUJO COMPLETO

```
convert("literal")
    ↓
¿Es CHAR? (1 carácter, imprimible, no dígito)
├─ SÍ → Convertir char → todos los tipos → Imprimir → return
└─ NO ↓

¿Es INT? (solo dígitos, opcional +/-)
├─ SÍ → Parsear con strtol() → Verificar rango → Convertir → Imprimir → return
└─ NO ↓

¿Es FLOAT? (termina en 'f' o nanf/±inff)
├─ SÍ → ¿Pseudoliteral? → Crear especial | Parsear sin 'f' → Convertir → Imprimir → return
└─ NO ↓

¿Es DOUBLE? (tiene '.' o nan/±inf)
├─ SÍ → ¿Pseudoliteral? → Crear especial | Parsear → Convertir → Imprimir → return
└─ NO ↓

Input inválido → outputImpossibleForAll()
```

---

## 💡 CONCEPTOS CLAVE

1. **static_cast**: Conversión segura entre tipos
2. **strtol/strtod**: Parsing de strings en C++98
3. **errno**: Detección de overflow
4. **std::numeric_limits**: Límites y valores especiales
5. **Referencias constantes**: Eficiencia sin copiar
6. **Funciones static**: Visibilidad limitada al archivo

¡Espero que esta explicación línea por línea te ayude a entender completamente el código! 🚀


