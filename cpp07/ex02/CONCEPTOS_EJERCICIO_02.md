# 🎓 CONCEPTOS CLAVE - Ejercicio 02 (Array)

## ❓ Pregunta 1: ¿Qué es `new T[n]()` y para qué sirve?

### 🔍 Desglose Completo

```cpp
new T[n]()
│   │ │ ↑
│   │ │ └─ () = INICIALIZA a 0/vacío
│   │ └─ [n] = Array de n elementos
│   └─ T = Tipo (int, double, string...)
└─ new = Reserva memoria dinámica
```

### 📊 Comparación: Con `()` vs Sin `()`

```cpp
// ❌ SIN () - NO inicializa (BASURA)
int* arr1 = new int[5];
// arr1 = [?, ?, ?, ?, ?]  ← Valores aleatorios (basura)

// ✅ CON () - SÍ inicializa a 0
int* arr2 = new int[5]();
// arr2 = [0, 0, 0, 0, 0]  ← Valores inicializados a 0
```

### 🎨 Visualización:

```
MEMORIA SIN INICIALIZAR (sin ()):
════════════════════════════════════════════════════════
┌───────────────────────────────────────┐
│ int* arr = new int[3];                │
└───────────────────────────────────────┘
         ↓
    MEMORIA:
    ┌──────────┬──────────┬──────────┐
    │   ???    │   ???    │   ???    │  ← BASURA (valores aleatorios)
    │ (23456)  │ (-9999)  │  (0)     │
    └──────────┴──────────┴──────────┘


MEMORIA INICIALIZADA (con ()):
════════════════════════════════════════════════════════
┌───────────────────────────────────────┐
│ int* arr = new int[3]();              │
└───────────────────────────────────────┘
         ↓
    MEMORIA:
    ┌──────────┬──────────┬──────────┐
    │    0     │    0     │    0     │  ← INICIALIZADO a 0
    └──────────┴──────────┴──────────┘
```

### 📋 Tabla de Inicialización según Tipo

```
╔════════════════╦═══════════════════════╦═══════════════════════╗
║     TIPO       ║   new T[n]            ║   new T[n]()          ║
║                ║   (sin ())            ║   (con ())            ║
╠════════════════╬═══════════════════════╬═══════════════════════╣
║                ║                       ║                       ║
║ int            ║ [?, ?, ?] (basura)    ║ [0, 0, 0]             ║
║                ║                       ║                       ║
╠════════════════╬═══════════════════════╬═══════════════════════╣
║                ║                       ║                       ║
║ double         ║ [?, ?, ?] (basura)    ║ [0.0, 0.0, 0.0]       ║
║                ║                       ║                       ║
╠════════════════╬═══════════════════════╬═══════════════════════╣
║                ║                       ║                       ║
║ char           ║ [?, ?, ?] (basura)    ║ ['\0', '\0', '\0']    ║
║                ║                       ║                       ║
╠════════════════╬═══════════════════════╬═══════════════════════╣
║                ║                       ║                       ║
║ string         ║ ["", "", ""]          ║ ["", "", ""]          ║
║                ║ (constructor default) ║ (constructor default) ║
║                ║                       ║                       ║
╠════════════════╬═══════════════════════╬═══════════════════════╣
║                ║                       ║                       ║
║ bool           ║ [?, ?, ?] (basura)    ║ [false, false, false] ║
║                ║                       ║                       ║
╚════════════════╩═══════════════════════╩═══════════════════════╝
```

### 💡 En tu Array<T>:

```cpp
template<typename T>
class Array {
private:
    T* _elements;
    size_t _size;
public:
    Array(unsigned int n) : _elements(new T[n]()), _size(n) {
    //                                        ↑↑
    //                                        └┴─ ESTO inicializa
    }
};
```

**Ejemplo:**
```cpp
Array<int> nums(5);
// nums internamente: [0, 0, 0, 0, 0]

Array<double> decimals(3);
// decimals internamente: [0.0, 0.0, 0.0]

Array<string> words(2);
// words internamente: ["", ""]
```

---

## ❓ Pregunta 2: ¿Por qué devolvemos algo en `operator[]`? ¿Qué es `throw`?

### 🎯 ¿Por qué devolver una referencia?

```cpp
T& operator[](size_t index) {
  ↑
  └─ Devuelve REFERENCIA (permite modificar)
  
    if (index >= _size)
        throw std::exception();  // ← Lanza excepción si fuera de rango
    
    return _elements[index];  // ← Devuelve referencia al elemento
}
```

### 📊 ¿Qué pasa si devolvemos referencia vs valor?

```cpp
// CON REFERENCIA (T&):
────────────────────────────────────────────────
T& operator[](size_t index) {
    return _elements[index];  // Devuelve referencia
}

Array<int> nums(5);
nums[0] = 42;  // ✅ FUNCIONA (modifica el elemento)
std::cout << nums[0];  // 42


// CON VALOR (T):
────────────────────────────────────────────────
T operator[](size_t index) {
    return _elements[index];  // Devuelve COPIA
}

Array<int> nums(5);
nums[0] = 42;  // ❌ ERROR: No puedes asignar a una copia temporal
               // Es como hacer: 5 = 42; (no tiene sentido)
```

### 🔍 Visualización:

```
CON T& (referencia):
════════════════════════════════════════════════════════

Array<int> nums(5);
    ↓
┌───────────────────────────┐
│ _elements → [0, 0, 0, ...] │
└───────────────────────────┘
                  ↑
                  │ (referencia)
                  │
            nums[0] = 42;
                  │
                  ↓
┌───────────────────────────┐
│ _elements → [42, 0, 0, ...] │  ← Se modifica directamente
└───────────────────────────┘


SIN T& (valor):
════════════════════════════════════════════════════════

Array<int> nums(5);
    ↓
┌───────────────────────────┐
│ _elements → [0, 0, 0, ...] │
└───────────────────────────┘
                  
nums[0] = 42;  ← Se crea una COPIA temporal
    ↓
┌───────┐
│ copia │ = 42  ← Modifica la copia (que luego se destruye)
└───────┘

┌───────────────────────────┐
│ _elements → [0, 0, 0, ...] │  ← ¡No cambia nada!
└───────────────────────────┘
```

### 🚨 ¿Qué es `throw`?

```cpp
throw std::exception();
  ↑         ↑
  │         └─ Tipo de excepción
  └─ Lanzar/arrojar excepción
```

**Significado:**
> "Algo salió mal, lanza una alarma y detén la ejecución normal"

**Ejemplo:**
```cpp
T& operator[](size_t index) {
    if (index >= _size) {
        throw std::exception();  // ← "¡Alto! Índice inválido"
    }
    return _elements[index];
}

// Uso:
try {
    Array<int> nums(5);
    nums[10] = 42;  // ← Índice fuera de rango (10 >= 5)
                    // ← throw lanza excepción
} catch (std::exception& e) {
    std::cout << "Error capturado!" << std::endl;
}
```

**Flujo:**
```
nums[10] = 42;
    ↓
operator[](10)
    ↓
if (10 >= 5)  → TRUE
    ↓
throw std::exception();  ← ¡ALARMA!
    ↓
Salta al catch
    ↓
std::cout << "Error capturado!"
```

---

## ❓ Pregunta 3: ¿Por qué hay versión const y non-const de `operator[]`?

### 🔍 EL PROBLEMA:

```cpp
class Array {
public:
    // Solo esta versión:
    T& operator[](size_t index) {
        return _elements[index];
    }
};

// Problema:
void imprimir(Array<int> const & arr) {  // ← const
    std::cout << arr[0];  // ❌ ERROR
    // arr es const, pero operator[] no es const
}
```

### ✅ LA SOLUCIÓN: Dos versiones

```cpp
// VERSIÓN 1: Non-const (para modificar)
T& operator[](size_t index) {
    if (index >= _size)
        throw std::exception();
    return _elements[index];
}

// VERSIÓN 2: Const (para solo leer)
T const & operator[](size_t index) const {
  ↑                                    ↑
  │                                    └─ El método es const
  └─ Devuelve referencia const
  
    if (index >= _size)
        throw std::exception();
    return _elements[index];
}
```

### 📊 ¿Cuándo se usa cada una?

```
VERSIÓN NON-CONST:
════════════════════════════════════════════════════════

Array<int> nums(5);  // ← Objeto NO const
nums[0] = 42;        // ← Usa versión non-const (puede modificar)

• Objeto: NO const
• Acción: Modificar
• Usa: T& operator[](size_t)


VERSIÓN CONST:
════════════════════════════════════════════════════════

Array<int> const nums(5);  // ← Objeto const
std::cout << nums[0];      // ← Usa versión const (solo lee)

• Objeto: const
• Acción: Leer
• Usa: T const & operator[](size_t) const


EN FUNCIONES:
════════════════════════════════════════════════════════

void imprimir(Array<int> const & arr) {  // ← Parámetro const
    std::cout << arr[0];  // ← Usa versión const
}

void modificar(Array<int>& arr) {  // ← Parámetro NO const
    arr[0] = 100;  // ← Usa versión non-const
}
```

### 🎨 Visualización Completa:

```
OBJETO NO CONST:
════════════════════════════════════════════════════════

Array<int> nums(5);
    ↓
nums[0] = 42;  → operator[](size_t)  (non-const)
    ↓
T& operator[](size_t index) {
    return _elements[index];  // Devuelve T& (puede modificar)
}
    ↓
nums internamente: [42, 0, 0, 0, 0]  ✅ Modificado


OBJETO CONST:
════════════════════════════════════════════════════════

Array<int> const nums(5);
    ↓
int x = nums[0];  → operator[](size_t) const  (const)
    ↓
T const & operator[](size_t index) const {
    return _elements[index];  // Devuelve T const & (solo leer)
}
    ↓
x = 0  ✅ Solo leyó, no modificó


SI SOLO TUVIERAS LA VERSIÓN NON-CONST:
════════════════════════════════════════════════════════

Array<int> const nums(5);
    ↓
int x = nums[0];  // ❌ ERROR
                  // nums es const
                  // operator[] no es const
                  // ¡No hay versión compatible!
```

---

## 📋 ¿Qué te pide hacer el Ejercicio 02?

### 🎯 Requisitos del Subject:

```
╔════════════════════════════════════════════════════════════╗
║              QUÉ DEBES IMPLEMENTAR                         ║
╠════════════════════════════════════════════════════════════╣
║                                                            ║
║ 1. Constructor vacío                                       ║
║    ────────────────────────────────────────────────────    ║
║    Array() → Crea array de tamaño 0                        ║
║                                                            ║
║ 2. Constructor con tamaño                                  ║
║    ────────────────────────────────────────────────────    ║
║    Array(unsigned int n) → Crea array de n elementos       ║
║    Inicializa con new T[n]()                               ║
║                                                            ║
║ 3. Constructor de copia (COPIA PROFUNDA)                   ║
║    ────────────────────────────────────────────────────    ║
║    Array(Array const & other) → Copia el array             ║
║    Crear nueva memoria y copiar elemento por elemento      ║
║                                                            ║
║ 4. Operador de asignación (COPIA PROFUNDA)                 ║
║    ────────────────────────────────────────────────────    ║
║    operator=(Array const & other)                          ║
║    Liberar memoria antigua, crear nueva y copiar           ║
║                                                            ║
║ 5. Operador [] (DOS versiones)                             ║
║    ────────────────────────────────────────────────────    ║
║    T& operator[](size_t) → Para modificar                  ║
║    T const & operator[](size_t) const → Para leer          ║
║    Lanzar excepción si fuera de rango                      ║
║                                                            ║
║ 6. Método size()                                           ║
║    ────────────────────────────────────────────────────    ║
║    size_t size() const → Devuelve número de elementos      ║
║                                                            ║
║ 7. Destructor                                              ║
║    ────────────────────────────────────────────────────    ║
║    ~Array() → Libera memoria con delete[]                  ║
║                                                            ║
╚════════════════════════════════════════════════════════════╝
```

---

## 🔑 Conceptos Clave que DEBES entender:

### 1️⃣ COPIA PROFUNDA vs SUPERFICIAL

```
COPIA SUPERFICIAL (❌ MAL):
════════════════════════════════════════════════════════

Array<int> a(3);
Array<int> b = a;

a._elements → [1, 2, 3] ← MISMA memoria
              ↑
b._elements ──┘

Problema: Si destruyes 'a', 'b' apunta a memoria liberada


COPIA PROFUNDA (✅ BIEN):
════════════════════════════════════════════════════════

Array<int> a(3);
Array<int> b = a;

a._elements → [1, 2, 3] ← Memoria de 'a'

b._elements → [1, 2, 3] ← Memoria de 'b' (copia)

Correcto: Cada uno tiene su propia memoria
```

### 2️⃣ REFERENCIAS (devolver `T&`)

```cpp
T& operator[](...) {
  ↑
  └─ Devuelve referencia (permite modificar el original)

// Permite:
arr[0] = 42;  // Modifica el elemento original
```

### 3️⃣ EXCEPCIONES (`throw`)

```cpp
if (index >= _size)
    throw std::exception();  // ← Lanza alarma cuando hay error

// Se captura con try-catch:
try {
    arr[100] = 0;  // Fuera de rango
} catch (std::exception& e) {
    std::cout << "Error!";
}
```

### 4️⃣ CONST CORRECTNESS

```cpp
// Para objetos const:
T const & operator[](size_t) const;
//    ↑                          ↑
//    └─ Devuelve const          └─ Método const

// Para objetos no-const:
T& operator[](size_t);
// Devuelve referencia modificable
```

---

## 🧪 El main que te dan: ¿Qué hace?

```cpp
int main() {
    // 1. Crea Array de 750 elementos
    Array<int> numbers(750);
    int* mirror = new int[750];  // Para comparar
    
    // 2. Los llena con valores aleatorios
    for (int i = 0; i < 750; i++) {
        numbers[i] = rand();
        mirror[i] = numbers[i];
    }
    
    // 3. PRUEBA COPIA PROFUNDA (crucial)
    {
        Array<int> tmp = numbers;   // Copia
        Array<int> test(tmp);       // Otra copia
    }  // tmp y test se destruyen aquí
    
    // 4. Verifica que numbers sigue intacto
    for (int i = 0; i < 750; i++) {
        if (mirror[i] != numbers[i]) {
            // Si aparece este mensaje → copia profunda FALLÓ
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    
    // 5. Prueba excepciones
    try {
        numbers[-2] = 0;  // Debe lanzar excepción
    } catch (...) { }
    
    try {
        numbers[750] = 0;  // Debe lanzar excepción
    } catch (...) { }
    
    delete[] mirror;
    return 0;
}
```

**¿Qué verifica?**
- ✅ Constructor funciona
- ✅ Operador `[]` funciona
- ✅ **Copia profunda funciona** (lo más importante)
- ✅ Excepciones funcionan
- ✅ No hay memory leaks

---

## 💡 Resumen Ultra-Simple

```
┌──────────────────────────────────────────────────────────┐
│                  LO QUE DEBES SABER                      │
├──────────────────────────────────────────────────────────┤
│                                                          │
│  1. new T[n]()                                           │
│     • () inicializa a 0                                  │
│     • Sin () = basura                                    │
│                                                          │
│  2. T& operator[]                                        │
│     • Devuelve referencia para poder modificar           │
│     • arr[0] = 42  ← Solo funciona si devuelves T&       │
│                                                          │
│  3. throw std::exception()                               │
│     • Lanza error cuando índice fuera de rango           │
│     • Se captura con try-catch                           │
│                                                          │
│  4. Dos versiones de operator[]                          │
│     • T& operator[](...) → Para modificar                │
│     • T const & operator[](...) const → Para leer        │
│                                                          │
│  5. Copia profunda                                       │
│     • Crear NUEVA memoria                                │
│     • Copiar elemento por elemento                       │
│     • Cada objeto tiene su propia memoria                │
│                                                          │
└──────────────────────────────────────────────────────────┘
```

---

**¿Quedó más claro ahora?** 😊


