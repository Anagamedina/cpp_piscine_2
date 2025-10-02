# 📚 TEORÍA COMPLETA - SCALAR CONVERTER (CPP06 EX00)

## 🎯 Objetivo del Ejercicio

El ejercicio `ScalarConverter` consiste en crear un programa que tome un literal (string) y lo convierta a todos los tipos primitivos de C++: `char`, `int`, `float`, y `double`. Es un ejercicio fundamental para entender las conversiones de tipos en C++98.

---

## 🔧 1. CONCEPTOS FUNDAMENTALES DE CASTING EN C++98

### 📋 **1.1 ¿Qué es el Casting?**

El casting es la conversión explícita de un tipo de dato a otro. En C++98, tenemos cuatro tipos principales:

```cpp
// 1. static_cast - Conversiones seguras en tiempo de compilación
int entero = 42;
double decimal = static_cast<double>(entero);  // int → double

// 2. dynamic_cast - Para jerarquías de herencia (no aplica aquí)
// 3. reinterpret_cast - Reinterpretación de bits (peligroso)
// 4. const_cast - Modificar const (no aplica aquí)
```

### 📋 **1.2 ¿Por qué usar `static_cast` en lugar de C-style cast?**

```cpp
// ❌ MALO: C-style cast (evitar en C++)
double valor = (double)entero;

// ✅ BUENO: static_cast (recomendado)
double valor = static_cast<double>(entero);
```

**Ventajas de `static_cast`:**
- Más explícito y legible
- El compilador puede detectar errores
- Fácil de buscar en el código
- No permite conversiones peligrosas

---

## 🔄 2. CONVERSIÓN DE LITERALES A TIPOS PRIMITIVOS

### 📋 **2.1 Detección del Tipo de Literal**

El primer paso es identificar qué tipo de literal tenemos:

```cpp
// Pseudoliterales especiales
"+inff", "-inff", "nanf"  // → float
"+inf", "-inf", "nan"     // → double

// Carácter único
"A", "!", "5"             // → char (si es printable y no dígito)

// Entero
"42", "-123", "+456"      // → int

// Float
"3.14f", "2.0f", "1e5f"  // → float

// Double
"3.14159", "2.0", "1e10" // → double
```

### 📋 **2.2 Algoritmo de Detección**

```cpp
// Orden de verificación (importante):
1. Pseudoliterales especiales (nan, inf)
2. Carácter único printable
3. Entero (solo dígitos, opcional +/-)
4. Float (termina en 'f')
5. Double (contiene punto decimal)
```

---

## 🧮 3. PARSING EN C++98

### 📋 **3.1 ¿Por qué `strtod` y `strtol` en lugar de `std::stod`?**

En C++98, `std::stod` y `std::stof` **NO EXISTEN**. Debemos usar las funciones C:

```cpp
#include <cstdlib>  // Para strtod, strtol

// Para double
char* end;
double valor = strtod(literal.c_str(), &end);
if (*end != '\0') {
    // Error: no se pudo parsear completamente
}

// Para long (para verificar rango de int)
long valor_long = strtol(literal.c_str(), &end, 10);
if (valor_long < INT_MIN || valor_long > INT_MAX) {
    // Error: fuera de rango de int
}
```

### 📋 **3.2 Validación de Rangos**

```cpp
#include <climits>    // Para INT_MIN, INT_MAX
#include <limits>     // Para numeric_limits

// Verificar rango de int
if (valor < INT_MIN || valor > INT_MAX) {
    std::cout << "int: impossible" << std::endl;
}

// Verificar rango de char (0-255)
if (valor < 0 || valor > 255) {
    std::cout << "char: impossible" << std::endl;
}
```

---

## 🔢 4. VALORES ESPECIALES: NaN e INFINITO

### 📋 **4.1 ¿Qué son NaN e Infinito?**

```cpp
#include <cmath>      // Para isnan, isinf
#include <limits>     // Para numeric_limits

// Crear valores especiales
double nan_val = std::numeric_limits<double>::quiet_NaN();
double inf_pos = std::numeric_limits<double>::infinity();
double inf_neg = -std::numeric_limits<double>::infinity();

// Detectar valores especiales
if (std::isnan(valor)) {
    // Es NaN
}
if (std::isinf(valor)) {
    // Es infinito
}
```

### 📋 **4.2 Propiedades de NaN**

```cpp
// NaN tiene propiedades especiales:
double nan_val = std::numeric_limits<double>::quiet_NaN();

nan_val == nan_val;  // false (¡importante!)
nan_val != nan_val;  // true
std::isnan(nan_val); // true
```

### 📋 **4.3 Pseudoliterales en el Ejercicio**

```cpp
// Float pseudoliterales
"+inff" → +infinito en float
"-inff" → -infinito en float  
"nanf"  → NaN en float

// Double pseudoliterales
"+inf"  → +infinito en double
"-inf"  → -infinito en double
"nan"   → NaN en double
```

---

## 🖨️ 5. FORMATO DE SALIDA

### 📋 **5.1 Reglas de Impresión para CHAR**

```cpp
// Casos para char:
if (std::isnan(valor) || std::isinf(valor)) {
    std::cout << "char: impossible" << std::endl;
} else if (valor < 0 || valor > 255) {
    std::cout << "char: impossible" << std::endl;
} else if (valor < 32 || valor > 126) {
    std::cout << "char: Non displayable" << std::endl;
} else {
    std::cout << "char: '" << static_cast<char>(valor) << "'" << std::endl;
}
```

### 📋 **5.2 Reglas de Impresión para INT**

```cpp
// Casos para int:
if (std::isnan(valor) || std::isinf(valor)) {
    std::cout << "int: impossible" << std::endl;
} else if (valor < INT_MIN || valor > INT_MAX) {
    std::cout << "int: impossible" << std::endl;
} else {
    std::cout << "int: " << static_cast<int>(valor) << std::endl;
}
```

### 📋 **5.3 Reglas de Impresión para FLOAT**

```cpp
// Casos para float:
if (std::isnan(f)) {
    std::cout << "float: nanf" << std::endl;
} else if (std::isinf(f)) {
    std::cout << "float: " << (f > 0 ? "+inff" : "-inff") << std::endl;
} else {
    // Formato especial: si es entero, mostrar .0f
    if (f == static_cast<int>(f)) {
        std::cout << "float: " << f << ".0f" << std::endl;
    } else {
        std::cout << "float: " << f << "f" << std::endl;
    }
}
```

### 📋 **5.4 Reglas de Impresión para DOUBLE**

```cpp
// Casos para double:
if (std::isnan(d)) {
    std::cout << "double: nan" << std::endl;
} else if (std::isinf(d)) {
    std::cout << "double: " << (d > 0 ? "+inf" : "-inf") << std::endl;
} else {
    // Formato especial: si es entero, mostrar .0
    if (d == static_cast<int>(d)) {
        std::cout << "double: " << d << ".0" << std::endl;
    } else {
        std::cout << "double: " << d << std::endl;
    }
}
```

---

## 🔍 6. ALGORITMO COMPLETO DE CONVERSIÓN

### 📋 **6.1 Flujo Principal**

```cpp
void ScalarConverter::convert(const std::string &literal) {
    // 1. Verificar pseudoliterales especiales
    if (es_pseudoliteral_float(literal)) {
        manejar_pseudoliteral_float(literal);
        return;
    }
    if (es_pseudoliteral_double(literal)) {
        manejar_pseudoliteral_double(literal);
        return;
    }
    
    // 2. Detectar tipo del literal
    if (es_char(literal)) {
        convertir_desde_char(literal[0]);
    } else if (es_int(literal)) {
        convertir_desde_int(literal);
    } else if (es_float(literal)) {
        convertir_desde_float(literal);
    } else if (es_double(literal)) {
        convertir_desde_double(literal);
    } else {
        // Literal inválido
        imprimir_imposible();
    }
}
```

### 📋 **6.2 Detección de Tipos**

```cpp
// Carácter único
bool es_char(const std::string &s) {
    return s.size() == 1 && std::isprint(s[0]) && !std::isdigit(s[0]);
}

// Entero
bool es_int(const std::string &s) {
    if (s.empty()) return false;
    size_t i = 0;
    if (s[i] == '+' || s[i] == '-') i++;
    if (i >= s.size()) return false;
    for (; i < s.size(); ++i) {
        if (!std::isdigit(s[i])) return false;
    }
    return true;
}

// Float (termina en 'f')
bool es_float(const std::string &s) {
    return s.size() > 1 && s[s.size()-1] == 'f';
}

// Double (contiene punto decimal)
bool es_double(const std::string &s) {
    return s.find('.') != std::string::npos;
}
```

---

## ⚠️ 7. CASOS EDGE Y MANEJO DE ERRORES

### 📋 **7.1 Overflow en Conversiones**

```cpp
// Verificar overflow antes de convertir
long valor_long = strtol(literal.c_str(), &end, 10);
if (valor_long < INT_MIN || valor_long > INT_MAX) {
    std::cout << "int: impossible" << std::endl;
    return;
}
int valor_int = static_cast<int>(valor_long);
```

### 📋 **7.2 Pérdida de Precisión**

```cpp
// Al convertir double → float
double d = 3.14159265358979323846;
float f = static_cast<float>(d);  // Puede perder precisión

// Al convertir float → int
float f = 3.9f;
int i = static_cast<int>(f);  // Trunca a 3
```

### 📋 **7.3 Caracteres No Imprimibles**

```cpp
// Verificar si un carácter es imprimible
bool es_imprimible(int valor) {
    return valor >= 32 && valor <= 126;
}

// Casos especiales:
// - valor < 32: caracteres de control (tab, newline, etc.)
// - valor > 126: caracteres extendidos
// - valor < 0 o valor > 255: fuera de rango de char
```

---

## 🎯 8. EJEMPLOS PRÁCTICOS

### 📋 **8.1 Ejemplo: Conversión desde Char**

```cpp
// Input: "A"
// Output:
// char: 'A'
// int: 65
// float: 65.0f
// double: 65.0
```

### 📋 **8.2 Ejemplo: Conversión desde Int**

```cpp
// Input: "42"
// Output:
// char: '*'
// int: 42
// float: 42.0f
// double: 42.0
```

### 📋 **8.3 Ejemplo: Conversión desde Float**

```cpp
// Input: "3.14f"
// Output:
// char: Non displayable
// int: 3
// float: 3.14f
// double: 3.14
```

### 📋 **8.4 Ejemplo: Pseudoliteral**

```cpp
// Input: "nan"
// Output:
// char: impossible
// int: impossible
// float: nanf
// double: nan
```

---

## 🔧 9. IMPLEMENTACIÓN TÉCNICA EN C++98

### 📋 **9.1 Headers Necesarios**

```cpp
#include <iostream>   // Para std::cout, std::cerr
#include <string>     // Para std::string
#include <cstdlib>    // Para strtod, strtol
#include <climits>    // Para INT_MIN, INT_MAX
#include <limits>     // Para numeric_limits
#include <cmath>      // Para isnan, isinf
#include <iomanip>    // Para setprecision, fixed
```

### 📋 **9.2 Clase ScalarConverter**

```cpp
class ScalarConverter {
private:
    // Constructor privado (no se puede instanciar)
    ScalarConverter();
    ScalarConverter(const ScalarConverter& other);
    ScalarConverter& operator=(const ScalarConverter& other);
    ~ScalarConverter();

public:
    // Método estático público
    static void convert(const std::string& literal);
};
```

### 📋 **9.3 Main Function**

```cpp
int main(int argc, char **argv) {
    if (argc != 2) {
        std::cerr << "Usage: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }
    
    ScalarConverter::convert(std::string(argv[1]));
    return 0;
}
```

---

## 🎯 10. MEJORES PRÁCTICAS

### ✅ **Do's (Hacer)**

1. **Usa `static_cast` para conversiones seguras**
2. **Verifica rangos antes de convertir**
3. **Maneja casos edge (NaN, infinito, overflow)**
4. **Usa funciones C para parsing en C++98**
5. **Valida completamente el input**

### ❌ **Don'ts (No hacer)**

1. **No uses C-style casts `(tipo)valor`**
2. **No ignores el resultado de `strtod`/`strtol`**
3. **No asumas que las conversiones siempre funcionan**
4. **No uses `std::stod` en C++98 (no existe)**
5. **No olvides verificar caracteres no imprimibles**

---

## 🔬 11. ANÁLISIS TÉCNICO AVANZADO

### 📋 **11.1 Precisión en Conversiones**

```cpp
// Double → Float: puede perder precisión
double d = 3.14159265358979323846;
float f = static_cast<float>(d);
// f ahora es 3.1415927 (menos precisión)

// Float → Int: trunca decimales
float f = 3.9f;
int i = static_cast<int>(f);  // i = 3 (no 4)
```

### 📋 **11.2 Representación Interna**

```cpp
// Los tipos tienen diferentes rangos:
// char: -128 a 127 (signed) o 0 a 255 (unsigned)
// int: -2,147,483,648 a 2,147,483,647 (32-bit)
// float: ~3.4e-38 a ~3.4e38 (precisión simple)
// double: ~1.7e-308 a ~1.7e308 (precisión doble)
```

### 📋 **11.3 Optimizaciones del Compilador**

```cpp
// El compilador puede optimizar static_cast:
int i = 42;
double d = static_cast<double>(i);
// Puede convertirse a: double d = 42.0; (en tiempo de compilación)
```

---

## 📝 12. RESUMEN DE CONCEPTOS CLAVE

1. **Casting**: Conversión explícita entre tipos usando `static_cast`
2. **Parsing**: Interpretación de strings como valores numéricos
3. **Validación**: Verificación de rangos y casos edge
4. **NaN/Infinito**: Valores especiales que requieren manejo especial
5. **Formato**: Reglas específicas para mostrar cada tipo
6. **C++98**: Limitaciones y APIs disponibles en esta versión

Este ejercicio es fundamental para entender las conversiones de tipos en C++ y prepara para conceptos más avanzados como templates y sobrecarga de operadores.

---

## 🚀 13. PRÓXIMOS PASOS

Después de dominar este ejercicio, estarás preparado para:
- **EX01**: Serialización de punteros con `reinterpret_cast`
- **EX02**: Identificación de tipos con `dynamic_cast`
- Conceptos avanzados de herencia y polimorfismo
- Templates y programación genérica

¡El casting es la base de muchas técnicas avanzadas en C++!

