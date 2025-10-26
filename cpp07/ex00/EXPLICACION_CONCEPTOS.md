# 🎓 EXPLICACIÓN DE CONCEPTOS - EX00

## ❓ Pregunta 1: ¿swap, min y max son templates?

### Respuesta: ✅ SÍ, LOS TRES son templates

```cpp
// SWAP es un template
template<typename T>
void swap(T& a, T& b) { ... }

// MIN es un template
template<typename T>
T const & min(T const & a, T const & b) { ... }

// MAX es un template
template<typename T>
T const & max(T const & a, T const & b) { ... }
```

**Los tres son templates** porque:
- Todos tienen `template<typename T>` antes de su definición
- Todos pueden trabajar con cualquier tipo (int, double, string, etc.)

---

## ❓ Pregunta 2: ¿Qué es `template<typename T>` y `T const &`?

### 📌 `template<typename T>`

```cpp
template<typename T>
//       ↑       ↑
//       |       └─ Nombre del parámetro (puedes usar cualquier nombre)
//       └─ Palabra clave que indica "esto es un tipo"
```

**Significado:**
- `template` = "Esto es un molde/plantilla"
- `typename` = "T es un TIPO" (puede ser int, double, string, etc.)
- `T` = El nombre del parámetro de tipo (convención: usar mayúsculas)

**Ejemplos:**

```cpp
// T puede ser int
int a = 5, b = 10;
swap(a, b);  // El compilador usa: template<typename int>

// T puede ser double
double x = 3.14, y = 2.71;
swap(x, y);  // El compilador usa: template<typename double>

// T puede ser string
string s1 = "hola", s2 = "adiós";
swap(s1, s2);  // El compilador usa: template<typename string>
```

### 📌 `T const &` (Referencia constante a T)

```cpp
T const & min(T const & a, T const & b)
//↑     ↑          ↑     ↑        ↑
//|     |          |     |        └─ Segundo parámetro
//|     |          |     └─ Referencia constante
//|     |          └─ Primer parámetro
//|     └─ Referencia
//└─ Tipo (que sea T)
```

**Desglose de `T const &`:**

```
T       → El tipo (int, double, string...)
const   → No se puede modificar
&       → Referencia (no se copia, se pasa la dirección)

T const & = "Referencia constante al tipo T"
```

**¿Por qué usar `const &`?**

```cpp
// ❌ SIN const &: Se hace una COPIA (lento si es un objeto grande)
T min(T a, T b) {
    return (a < b) ? a : b;
}

// ✅ CON const &: NO se copia, se pasa la referencia (rápido)
T const & min(T const & a, T const & b) {
    return (a < b) ? a : b;
}
```

**Ejemplo visual:**

```
SIN const & (copia):
────────────────────────────────────────
string s1 = "texto largo...";
string s2 = "otro texto largo...";

min(s1, s2);
    ↓
Crea COPIAS de s1 y s2 (lento, desperdicia memoria)


CON const & (referencia):
────────────────────────────────────────
string s1 = "texto largo...";
string s2 = "otro texto largo...";

min(s1, s2);
    ↓
Pasa referencias (rápido, eficiente)
```

---

## ❓ Pregunta 3: ¿Qué es `::`? ¿Por qué `::swap`, `::min`, `::max`?

### 📌 `::` es el Operador de Resolución de Ámbito (Scope Resolution)

**Significado:**
```cpp
::swap    // "usa la función swap del ámbito GLOBAL"
::min     // "usa la función min del ámbito GLOBAL"
::max     // "usa la función max del ámbito GLOBAL"
```

### ⚠️ EL PROBLEMA: std también tiene swap, min y max

```cpp
#include <algorithm>  // Tiene std::swap, std::min, std::max

int a = 5, b = 10;

// ❌ SIN ::  → Puede llamar a std::swap (NO es tu función)
swap(a, b);     // ¿Tu swap o std::swap? ¡Ambiguo!

// ✅ CON ::  → Llama SIEMPRE a tu función (del ámbito global)
::swap(a, b);   // Tu función swap (la que definiste)
```

### 🔍 Comparación Visual

```
TU CÓDIGO:
────────────────────────────────────────
template<typename T>
void swap(T& a, T& b) {  // Tu función (global)
    T temp = a;
    a = b;
    b = temp;
}

BIBLIOTECA STD:
────────────────────────────────────────
namespace std {
    template<typename T>
    void swap(T& a, T& b) {  // std::swap
        // Implementación de la biblioteca
    }
}

CUANDO LLAMAS:
────────────────────────────────────────
swap(a, b);      // ¿Cuál? Puede ser ambiguo
::swap(a, b);    // TU función (global)
std::swap(a, b); // Función de std
```

### 📊 Tabla de Ámbitos

```
╔════════════════╦═══════════════════════════════════════╗
║    SINTAXIS    ║           SIGNIFICADO                 ║
╠════════════════╬═══════════════════════════════════════╣
║                ║                                       ║
║  ::swap        ║  Función swap del ámbito GLOBAL       ║
║                ║  (la que TÚ definiste)                ║
║                ║                                       ║
╠════════════════╬═══════════════════════════════════════╣
║                ║                                       ║
║  std::swap     ║  Función swap del namespace std       ║
║                ║  (de la biblioteca estándar)          ║
║                ║                                       ║
╠════════════════╬═══════════════════════════════════════╣
║                ║                                       ║
║  swap          ║  Función swap (sin especificar)       ║
║                ║  Puede ser ambiguo                    ║
║                ║  El compilador busca la mejor opción  ║
║                ║                                       ║
╚════════════════╩═══════════════════════════════════════╝
```

---

## 🎯 EJEMPLO COMPLETO EXPLICADO

```cpp
// ==========================================
// DEFINICIÓN DE SWAP (tu template)
// ==========================================
template<typename T>     // ← "T puede ser cualquier tipo"
void swap(T& a, T& b) {  // ← "Toma referencias (puede modificar)"
    T temp = a;          // ← "temp es del mismo tipo T"
    a = b;
    b = temp;
}

// ==========================================
// DEFINICIÓN DE MIN (tu template)
// ==========================================
template<typename T>           // ← "T puede ser cualquier tipo"
T const & min(T const & a,     // ← "Parámetros: referencias constantes"
              T const & b) {   //    (no se copian, no se modifican)
    return (a < b) ? a : b;    // ← "Devuelve referencia al menor"
}

// ==========================================
// USO
// ==========================================
int main() {
    int x = 5, y = 10;
    
    // Sin :: (puede ser ambiguo)
    swap(x, y);     // ¿Tu swap o std::swap?
    
    // Con :: (siempre tu función)
    ::swap(x, y);   // ✅ TU función swap
    ::min(x, y);    // ✅ TU función min
    ::max(x, y);    // ✅ TU función max
}
```

---

## 🔬 Desglose Detallado de `T const &`

```cpp
template<typename T>
T const & min(T const & a, T const & b)
//                ↓
//    Cada parte explicada:


T
───────────────────────────────────────
• Es el TIPO (puede ser int, double, string, etc.)
• El compilador lo deduce automáticamente
• Ejemplo: si a y b son int, T = int


const
───────────────────────────────────────
• Significa "NO SE PUEDE MODIFICAR"
• Los parámetros a y b son solo lectura
• No puedes hacer: a = 10; (error)


&
───────────────────────────────────────
• Es una REFERENCIA
• No se copia el valor, se pasa la dirección
• Más eficiente, especialmente con objetos grandes


T const &
───────────────────────────────────────
• Juntando todo:
  "Referencia constante al tipo T"
• Se lee la dirección de a y b
• Pero no se pueden modificar
```

---

## 💡 Ejemplos Prácticos

### Ejemplo 1: swap con int

```cpp
template<typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int x = 5, y = 10;
::swap(x, y);

// El compilador genera automáticamente:
void swap(int& a, int& b) {  // T = int
    int temp = a;            // temp es int
    a = b;
    b = temp;
}
```

### Ejemplo 2: min con string

```cpp
template<typename T>
T const & min(T const & a, T const & b) {
    return (a < b) ? a : b;
}

string s1 = "zebra", s2 = "apple";
string resultado = ::min(s1, s2);  // "apple"

// El compilador genera:
string const & min(string const & a, string const & b) {  // T = string
    return (a < b) ? a : b;
}
```

### Ejemplo 3: Por qué usar ::

```cpp
#include <algorithm>  // Tiene std::swap

template<typename T>
void swap(T& a, T& b) {
    // Tu implementación
}

int main() {
    int a = 5, b = 10;
    
    // ❌ Ambiguo (puede usar std::swap)
    swap(a, b);
    
    // ✅ Explícito (usa TU swap)
    ::swap(a, b);
    
    // ✅ Explícito (usa std::swap)
    std::swap(a, b);
}
```

---

## 📋 Resumen Rápido

```
╔════════════════════════════════════════════════════════════╗
║                    CONCEPTOS CLAVE                         ║
╠════════════════════════════════════════════════════════════╣
║                                                            ║
║  template<typename T>                                      ║
║  ─────────────────────────────────────────────────────     ║
║  • T es un parámetro de TIPO                               ║
║  • Puede ser int, double, string, etc.                     ║
║  • El compilador lo deduce automáticamente                 ║
║                                                            ║
║  T const &                                                 ║
║  ─────────────────────────────────────────────────────     ║
║  • T = tipo                                                ║
║  • const = no se modifica                                  ║
║  • & = referencia (no copia)                               ║
║  • = "Referencia constante al tipo T"                      ║
║                                                            ║
║  ::                                                        ║
║  ─────────────────────────────────────────────────────     ║
║  • Operador de resolución de ámbito                        ║
║  • ::swap = tu función (ámbito global)                     ║
║  • std::swap = función de biblioteca estándar              ║
║  • Evita ambigüedades                                      ║
║                                                            ║
║  RESUMEN:                                                  ║
║  ─────────────────────────────────────────────────────     ║
║  swap, min y max son TODOS templates                       ║
║  Usan T const & para eficiencia (no copiar)                ║
║  Usas :: para especificar que son TUS funciones            ║
║                                                            ║
╚════════════════════════════════════════════════════════════╝
```

---

## 🎓 Ejercicio de Comprensión

```cpp
template<typename T>
T const & min(T const & a, T const & b) {
    return (a < b) ? a : b;
}

int main() {
    int x = 10, y = 20;
    int resultado = ::min(x, y);
}
```

**Pregunta:** ¿Qué hace el compilador?

**Respuesta:**
1. Ve `::min(x, y)` donde x e y son `int`
2. Deduce: `T = int`
3. Genera esta función:
   ```cpp
   int const & min(int const & a, int const & b) {
       return (a < b) ? a : b;
   }
   ```
4. `resultado` será 10 (el menor)

---
