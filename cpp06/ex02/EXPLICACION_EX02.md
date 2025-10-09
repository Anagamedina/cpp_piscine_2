# 📚 EXPLICACIÓN SENCILLA - EX02 IDENTIFICACIÓN DE TIPOS

## 🎯 ¿Qué hace este ejercicio?

Este ejercicio demuestra cómo **identificar el tipo real** de un objeto en tiempo de ejecución usando `dynamic_cast`.

---

## 🔍 CONCEPTOS CLAVE

### **¿Qué es Identificación de Tipos?**

Imagina que tienes una caja marcada como "Base", pero adentro puede haber un objeto A, B o C.
El ejercicio te enseña a **mirar dentro de la caja** para saber qué tipo de objeto realmente es.

```cpp
Base* caja = ???;  // Puede ser A, B o C
// ¿Cómo sabemos qué es?
```

### **¿Por qué es útil?**

```cpp
// Situaciones donde necesitas identificar tipos:
1. Cuando recibes un puntero Base* y necesitas saber si es A, B o C
2. Para ejecutar código específico según el tipo real
3. Para evitar crashes al hacer downcasting
4. Para implementar comportamiento polimórfico avanzado
```

---

## 🏗️ ESTRUCTURA DEL CÓDIGO

### **Jerarquía de Clases**

```
       Base
      /  |  \
     A   B   C
```

```cpp
class Base {
public:
    virtual ~Base();  // ← IMPORTANTE: hace la clase polimórfica
};

class A : public Base {};
class B : public Base {};
class C : public Base {};
```

**¿Por qué `virtual`?**
- Hace que Base sea **polimórfica**
- Esto es NECESARIO para que `dynamic_cast` funcione
- Añade una tabla virtual (vtable) al objeto

---

## 🔧 CÓMO FUNCIONA

### **FUNCIÓN 1: generate() - Generar objetos aleatorios**

```cpp
Base* generate(void) {
    int random = rand() % 3;  // 0, 1 o 2
    
    switch (random) {
        case 0: return new A();  // Crear objeto A
        case 1: return new B();  // Crear objeto B
        case 2: return new C();  // Crear objeto C
    }
}
```

**¿Qué hace?**
1. Genera un número aleatorio (0, 1 o 2)
2. Según el número, crea un objeto A, B o C
3. Retorna un puntero `Base*` (polimorfismo)

### **FUNCIÓN 2: identify(Base* p) - Identificar con punteros**

```cpp
void identify(Base* p) {
    // Intentar convertir a A*
    if (dynamic_cast<A*>(p)) {
        std::cout << "Tipo identificado: A" << std::endl;
    }
    // Intentar convertir a B*
    else if (dynamic_cast<B*>(p)) {
        std::cout << "Tipo identificado: B" << std::endl;
    }
    // Intentar convertir a C*
    else if (dynamic_cast<C*>(p)) {
        std::cout << "Tipo identificado: C" << std::endl;
    }
}
```

**¿Qué hace `dynamic_cast`?**

```cpp
A* a_ptr = dynamic_cast<A*>(p);

// Si p apunta a un objeto A:
//   → dynamic_cast retorna el puntero convertido
//   → a_ptr != NULL

// Si p NO apunta a un objeto A:
//   → dynamic_cast retorna NULL
//   → a_ptr == NULL
```

### **FUNCIÓN 3: identify(Base& p) - Identificar con referencias**

```cpp
void identify(Base& p) {
    // Intentar convertir a A&
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Tipo identificado: A" << std::endl;
        return;
    } catch (std::bad_cast&) {
        // No es tipo A, continuamos
    }
    
    // Similar para B y C...
}
```

**¿Por qué `try-catch`?**

Con **punteros**: `dynamic_cast` retorna `NULL` si falla
Con **referencias**: `dynamic_cast` lanza una **excepción** `std::bad_cast` si falla

```cpp
// PUNTEROS
A* ptr = dynamic_cast<A*>(base_ptr);
if (ptr == NULL) {
    // Falló la conversión
}

// REFERENCIAS
try {
    A& ref = dynamic_cast<A&>(base_ref);
    // Éxito
} catch (std::bad_cast&) {
    // Falló la conversión
}
```

---

## 📊 EJEMPLO VISUAL

### **Caso 1: Objeto es tipo A**

```
┌─────────────────────┐
│   Base* p           │
│   (apunta a A)      │
└─────────────────────┘
          ↓
   dynamic_cast<A*>(p)
          ↓
   ¿Es tipo A? ✅ SÍ
          ↓
   Retorna puntero A*
          ↓
   Output: "Tipo identificado: A"
```

### **Caso 2: Objeto NO es tipo A**

```
┌─────────────────────┐
│   Base* p           │
│   (apunta a B)      │
└─────────────────────┘
          ↓
   dynamic_cast<A*>(p)
          ↓
   ¿Es tipo A? ❌ NO
          ↓
   Retorna NULL
          ↓
   Probar siguiente tipo...
```

---

## 💻 CÓDIGO PASO A PASO

### **1. Generar objeto aleatorio**

```cpp
Base* obj = generate();
// Internamente:
// - rand() genera 0, 1 o 2
// - Se crea new A(), new B() o new C()
// - Se retorna como Base*
```

### **2. Identificar con puntero**

```cpp
identify(obj);

// Si obj apunta a B:
if (dynamic_cast<A*>(obj))  // NULL → false
else if (dynamic_cast<B*>(obj))  // puntero válido → true
    std::cout << "Tipo identificado: B";
```

### **3. Identificar con referencia**

```cpp
identify(*obj);  // Pasamos referencia

// Si *obj es tipo C:
try {
    (void)dynamic_cast<A&>(*obj);  // Lanza bad_cast
} catch (std::bad_cast&) {}

try {
    (void)dynamic_cast<B&>(*obj);  // Lanza bad_cast
} catch (std::bad_cast&) {}

try {
    (void)dynamic_cast<C&>(*obj);  // ✅ Éxito
    std::cout << "Tipo identificado: C";
} catch (std::bad_cast&) {}
```

---

## ⚡ DIFERENCIAS CLAVE

### **Punteros vs Referencias**

| Característica | Punteros | Referencias |
|----------------|----------|-------------|
| Si falla | Retorna `NULL` | Lanza `std::bad_cast` |
| Sintaxis | `if (dynamic_cast<A*>(p))` | `try { dynamic_cast<A&>(p); }` |
| Verificación | `if (ptr != NULL)` | `catch (std::bad_cast&)` |
| Uso | Más simple | Más robusto |

### **static_cast vs dynamic_cast**

| `static_cast` | `dynamic_cast` |
|---------------|----------------|
| Conversión en **compilación** | Conversión en **ejecución** |
| **NO verifica** el tipo real | **SÍ verifica** el tipo real |
| Más **rápido** | Más **lento** |
| **Peligroso** si el tipo es incorrecto | **Seguro** - retorna NULL o lanza excepción |

```cpp
// static_cast - PELIGROSO
Base* base_ptr = new Base();
A* a_ptr = static_cast<A*>(base_ptr);  // Compila pero es peligroso
a_ptr->metodo();  // ❌ CRASH

// dynamic_cast - SEGURO
A* a_ptr = dynamic_cast<A*>(base_ptr);  // Retorna NULL
if (a_ptr) {
    a_ptr->metodo();  // No se ejecuta
}
```

---

## 🧪 PRUEBAS

### **Salida del programa**

```bash
./identify
```

```
=== TEST DE IDENTIFICACIÓN DE TIPOS ===

🎲 Test 1:
   [Generado: B]
   Identificar con puntero:    Tipo identificado: B
   Identificar con referencia:    Tipo identificado: B

🎲 Test 2:
   [Generado: A]
   Identificar con puntero:    Tipo identificado: A
   Identificar con referencia:    Tipo identificado: A

🎲 Test 3:
   [Generado: C]
   Identificar con puntero:    Tipo identificado: C
   Identificar con referencia:    Tipo identificado: C
```

---

## 🎯 COMPATIBILIDAD C++98

### **Características usadas (todas disponibles en C++98):**

✅ **`dynamic_cast`** - Disponible en C++98
✅ **`std::bad_cast`** - Disponible en C++98
✅ **Clases polimórficas** - Disponible en C++98
✅ **`try-catch`** - Disponible en C++98
✅ **`rand()` y `srand()`** - Disponible en C++98

### **Lo que NO se usa (no disponible en C++98):**

❌ **`nullptr`** - Se usa `NULL` en C++98
❌ **`auto`** - No disponible en C++98
❌ **Range-based for** - No disponible en C++98

---

## 💡 RESUMEN

1. **`generate()`** crea objetos aleatorios A, B o C
2. **`identify(Base* p)`** usa `dynamic_cast` con punteros
3. **`identify(Base& p)`** usa `dynamic_cast` con referencias
4. **Con punteros**: `dynamic_cast` retorna `NULL` si falla
5. **Con referencias**: `dynamic_cast` lanza `std::bad_cast` si falla
6. **`virtual`** es necesario para que `dynamic_cast` funcione

---

## 🚀 COMANDOS

```bash
# Compilar
make

# Ejecutar
./identify

# Limpiar
make fclean

# Recompilar
make re
```

¡Ahora entiendes cómo identificar tipos en tiempo de ejecución! 🎉

