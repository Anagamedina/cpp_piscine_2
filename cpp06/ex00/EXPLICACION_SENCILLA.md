# 📚 EXPLICACIÓN SENCILLA - SCALAR CONVERTER

## 🎯 ¿Qué hace este programa?

El programa recibe un **literal** (string) y lo convierte a los 4 tipos básicos de C++:
- `char` (carácter)
- `int` (entero)
- `float` (decimal de precisión simple)
- `double` (decimal de precisión doble)

## 📝 NOMBRES DE LAS FUNCIONES AUXILIARES

Este código usa nombres únicos y descriptivos:

### **Funciones de Detección:**
- `checkIfChar()` - Verifica si el input es un carácter
- `checkIfInteger()` - Verifica si el input es un entero
- `checkIfFloatType()` - Verifica si el input es un float
- `checkIfDoubleType()` - Verifica si el input es un double

### **Funciones de Impresión:**
- `displayCharType()` - Muestra el resultado como char
- `displayIntType()` - Muestra el resultado como int
- `displayFloatType()` - Muestra el resultado como float
- `displayDoubleType()` - Muestra el resultado como double
- `outputImpossibleForAll()` - Muestra "impossible" para todos los tipos

---

## 🔍 PASO A PASO: ¿Cómo funciona?

### **PASO 1: Detectar el tipo del input**

El programa analiza el string y decide qué tipo es:

```cpp
// CHAR: un solo carácter que NO sea dígito
"A" → char

// INT: solo números (puede tener +/- al inicio)
"42", "-123" → int

// FLOAT: termina en 'f' o pseudoliterales
"3.14f", "nanf", "+inff" → float

// DOUBLE: tiene punto decimal o pseudoliterales
"3.14159", "nan", "+inf" → double
```

### **PASO 2: Parsear el valor**

Usamos funciones de C para convertir el string a número:

- **`strtol()`**: Para enteros (long)
- **`strtod()`**: Para decimales (double)

```cpp
// Ejemplo con INT:
long num = std::strtol("42", &end, 10);
int i = static_cast<int>(num);  // num = 42

// Ejemplo con DOUBLE:
double d = std::strtod("3.14", &end);  // d = 3.14
```

### **PASO 3: Convertir a los 4 tipos**

Una vez que tenemos el valor, usamos `static_cast` para convertirlo:

```cpp
// Si recibimos '42' (int):
int i = 42;

char c = static_cast<char>(i);      // c = '*' (ASCII 42)
float f = static_cast<float>(i);    // f = 42.0f
double d = static_cast<double>(i);  // d = 42.0
```

### **PASO 4: Imprimir con formato correcto**

Cada tipo tiene reglas específicas:

#### **CHAR:**
- `'A'` → Si es imprimible (32-126)
- `Non displayable` → Si es carácter de control (0-31)
- `impossible` → Si está fuera de rango (< 0 o > 127)

#### **INT:**
- `42` → Si es válido
- `impossible` → Si es NaN, infinito, o fuera de rango

#### **FLOAT:**
- `42.0f` → Números normales (siempre con .0f)
- `nanf` → Not a Number
- `+inff` / `-inff` → Infinito

#### **DOUBLE:**
- `42.0` → Números normales (siempre con .0)
- `nan` → Not a Number
- `+inf` / `-inf` → Infinito

---

## 🧩 ESTRUCTURA DEL CÓDIGO

### **1. Funciones de Detección**

**`checkIfChar()`** - Detecta si es un carácter único:
```cpp
"A" → true
"5" → false (es dígito)
"AB" → false (son 2 caracteres)
```

**`checkIfInteger()`** - Detecta si es un número entero:
```cpp
"42" → true
"-123" → true
"3.14" → false (tiene punto)
```

**`checkIfFloatType()`** - Detecta si es un float (termina en 'f'):
```cpp
"3.14f" → true
"nanf" → true
"3.14" → false
```

**`checkIfDoubleType()`** - Detecta si es un double (tiene punto decimal):
```cpp
"3.14159" → true
"nan" → true
"42" → false
```

### **2. Funciones de Impresión**

**`displayCharType()`** - Imprime el tipo char:
```cpp
- Si es NaN o infinito → "impossible"
- Si está fuera de rango → "impossible"
- Si no es imprimible → "Non displayable"
- Si es imprimible → "'A'"
```

**`displayIntType()`** - Imprime el tipo int:
```cpp
- Si es NaN o infinito → "impossible"
- Si está fuera de rango → "impossible"
- Sino → el número
```

**`displayFloatType()`** - Imprime el tipo float:
```cpp
- Si es NaN → "nanf"
- Si es infinito → "+inff" o "-inff"
- Sino → número con ".0f"
```

**`displayDoubleType()`** - Imprime el tipo double:
```cpp
- Si es NaN → "nan"
- Si es infinito → "+inf" o "-inf"
- Sino → número con ".0"
```

**`outputImpossibleForAll()`** - Imprime "impossible" para todos los tipos cuando el input es inválido.

### **3. Función Principal (convert)**

Esta es la función que coordina todo:

```cpp
void ScalarConverter::convert(const std::string& literal) {
    // 1. ¿Es un CHAR? → checkIfChar() → Convertir y mostrar con display*Type()
    // 2. ¿Es un INT? → checkIfInteger() → Convertir y mostrar con display*Type()
    // 3. ¿Es un FLOAT? → checkIfFloatType() → Convertir y mostrar con display*Type()
    // 4. ¿Es un DOUBLE? → checkIfDoubleType() → Convertir y mostrar con display*Type()
    // 5. ¿Es inválido? → outputImpossibleForAll()
}
```

---

## 🔧 CONCEPTOS CLAVE

### **1. ¿Qué es `static_cast`?**

Es la forma segura de convertir tipos en C++:

```cpp
int i = 42;
double d = static_cast<double>(i);  // Conversión segura
```

### **2. ¿Qué son los pseudoliterales?**

Son valores especiales de float/double:

```cpp
// FLOAT
"nanf" → Not a Number (float)
"+inff" → +Infinito (float)
"-inff" → -Infinito (float)

// DOUBLE
"nan" → Not a Number (double)
"+inf" → +Infinito (double)
"-inf" → -Infinito (double)
```

### **3. ¿Qué es `strtod` y `strtol`?**

Son funciones de C para convertir strings a números:

```cpp
// strtol: String to Long
char* end;
long num = std::strtol("42", &end, 10);
// num = 42
// end apunta al final del string

// strtod: String to Double
double d = std::strtod("3.14", &end);
// d = 3.14
```

### **4. ¿Cómo verificar si la conversión fue exitosa?**

```cpp
char* end;
double d = std::strtod("42abc", &end);

if (*end != '\0') {
    // ERROR: Hay caracteres extra ("abc")
}
```

---

## 📊 EJEMPLOS PASO A PASO

### **Ejemplo 1: Input = "A"**

```
1. Detectar tipo → checkIfChar("A") = true
2. Obtener valor → char c = 'A'
3. Convertir y mostrar:
   - displayCharType() → char: 'A'
   - displayIntType() → int: 65 (ASCII de 'A')
   - displayFloatType() → float: 65.0f
   - displayDoubleType() → double: 65.0
```

### **Ejemplo 2: Input = "42"**

```
1. Detectar tipo → checkIfInteger("42") = true
2. Parsear → int i = 42
3. Convertir y mostrar:
   - displayCharType() → char: '*' (ASCII 42)
   - displayIntType() → int: 42
   - displayFloatType() → float: 42.0f
   - displayDoubleType() → double: 42.0
```

### **Ejemplo 3: Input = "3.14f"**

```
1. Detectar tipo → checkIfFloatType("3.14f") = true
2. Parsear → float f = 3.14f
3. Convertir y mostrar:
   - displayCharType() → char: Non displayable (3 no es imprimible)
   - displayIntType() → int: 3 (trunca los decimales)
   - displayFloatType() → float: 3.1f
   - displayDoubleType() → double: 3.1
```

### **Ejemplo 4: Input = "nan"**

```
1. Detectar tipo → checkIfDoubleType("nan") = true
2. Crear valor → double d = NaN
3. Convertir y mostrar:
   - displayCharType() → char: impossible (NaN no es convertible)
   - displayIntType() → int: impossible (NaN no es convertible)
   - displayFloatType() → float: nanf
   - displayDoubleType() → double: nan
```

---

## ⚠️ CASOS ESPECIALES

### **1. Caracteres no imprimibles**

```cpp
// ASCII 0-31: Caracteres de control
'\n' (10), '\t' (9) → "Non displayable"

// ASCII 32-126: Caracteres imprimibles
'A' (65), '!' (33) → "'A'", "'!'"

// ASCII 127+: Fuera de rango
200 → "impossible"
```

### **2. Overflow en conversiones**

```cpp
// Si el número es demasiado grande para int
long big = 3000000000;  // Mayor que INT_MAX (2147483647)
→ "int: impossible"
```

### **3. Pérdida de precisión**

```cpp
// Double → Float
double d = 3.14159265358979323846;
float f = static_cast<float>(d);
// f = 3.1415927 (menos precisión)

// Float → Int
float f = 3.9f;
int i = static_cast<int>(f);
// i = 3 (trunca, no redondea)
```

---

## 🎓 RESUMEN VISUAL

```
INPUT: "42"
    ↓
DETECTAR TIPO: checkIfInteger() = true
    ↓
PARSEAR: int i = 42
    ↓
CONVERTIR A 4 TIPOS:
    → char c = static_cast<char>(42)      = '*'
    → int i = 42                          = 42
    → float f = static_cast<float>(42)    = 42.0f
    → double d = static_cast<double>(42)  = 42.0
    ↓
IMPRIMIR CON LAS FUNCIONES display*Type():
    displayCharType()   → char: '*'
    displayIntType()    → int: 42
    displayFloatType()  → float: 42.0f
    displayDoubleType() → double: 42.0
```

---

## 💡 TIPS PARA ENTENDER EL CÓDIGO

1. **Lee primero las funciones de detección** (`checkIfChar`, `checkIfInteger`, etc.)
   - Son simples y te ayudan a entender qué tipo de input esperas

2. **Luego las funciones de impresión** (`displayCharType`, `displayIntType`, etc.)
   - Manejan todos los casos especiales

3. **Finalmente la función convert()**
   - Coordina todo: detecta → parsea → convierte → imprime

4. **Prueba el programa con diferentes inputs**
   ```bash
   ./scalar_converter A
   ./scalar_converter 42
   ./scalar_converter 3.14f
   ./scalar_converter nan
   ```

---

## 🚀 COMANDOS ÚTILES

```bash
# Compilar
make

# Probar casos básicos
./scalar_converter A
./scalar_converter 42
./scalar_converter 3.14f
./scalar_converter 3.14159

# Probar pseudoliterales
./scalar_converter nan
./scalar_converter +inff
./scalar_converter -inf

# Probar casos edge
./scalar_converter 0
./scalar_converter -42
./scalar_converter 300
./scalar_converter abc
```

---

¡Ahora tienes una implementación sencilla y bien comentada! 🎉

