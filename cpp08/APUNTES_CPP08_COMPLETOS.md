# 📚 APUNTES CPP08 - STL (Standard Template Library)

## 🎯 ¿QUÉ ES CPP08?

CPP08 se enfoca en la **Biblioteca Estándar de Plantillas (STL)** de C++. Es el módulo donde aprendes a usar las herramientas más poderosas de C++ para manejar datos de forma eficiente y elegante.

---

## 🔑 CONCEPTOS FUNDAMENTALES

### 1. **STL (Standard Template Library)**
La STL es una colección de:
- **Contenedores**: Estructuras de datos predefinidas
- **Algoritmos**: Funciones para manipular datos
- **Iteradores**: "Punteros inteligentes" para recorrer contenedores

### 2. **Contenedores STL**
Son como "cajas inteligentes" que guardan datos:

#### 📦 **Contenedores Secuenciales**
```cpp
std::vector<int> vec;        // Array dinámico (como int arr[])
std::list<int> lista;        // Lista doblemente enlazada
std::deque<int> cola;        // Doble cola (front + back)
```

#### 🗂️ **Contenedores Asociativos**
```cpp
std::map<string, int> mapa;  // Diccionario: clave → valor
std::set<int> conjunto;      // Conjunto único (sin duplicados)
std::multimap<string, int> multimapa; // Múltiples valores por clave
```

### 3. **Iteradores**
Son como "cursosres" que te permiten recorrer contenedores:

```cpp
std::vector<int> vec = {1, 2, 3, 4, 5};

// Iterador tradicional
for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << " ";  // *it accede al elemento
}

// Auto (C++11, pero útil para entender)
for (auto it = vec.begin(); it != vec.end(); ++it) {
    std::cout << *it << " ";
}

// Range-based for (C++11, más moderno)
for (const auto& elemento : vec) {
    std::cout << elemento << " ";
}
```

---

## 🛠️ CONCEPTOS TÉCNICOS IMPORTANTES

### **1. Templates en STL**
```cpp
std::vector<int> vec_int;           // Vector de enteros
std::vector<string> vec_string;     // Vector de strings
std::map<int, string> mapa;         // Mapa int → string
```

### **2. Gestión de Memoria**
```cpp
std::vector<int> vec;
vec.push_back(42);     // Añade elemento
vec.pop_back();        // Quita último elemento
vec.size();            // Tamaño actual
vec.capacity();        // Capacidad reservada
```

### **3. Algoritmos STL**
```cpp
#include <algorithm>

std::vector<int> vec = {3, 1, 4, 1, 5};

// Ordenar
std::sort(vec.begin(), vec.end());

// Buscar
auto it = std::find(vec.begin(), vec.end(), 4);

// Contar
int count = std::count(vec.begin(), vec.end(), 1);

// Aplicar función a cada elemento
std::for_each(vec.begin(), vec.end(), [](int n) {
    std::cout << n << " ";
});
```

---

## 📋 EJERCICIOS TÍPICOS DE CPP08

### **Ejercicio 00: Easy Find**
- Implementar función `easyfind` que busque un valor en un contenedor
- Usar templates y algoritmos STL
- Manejar excepciones cuando no se encuentra

```cpp
template<typename T>
typename T::iterator easyfind(T& container, int value) {
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    if (it == container.end()) {
        throw std::exception();
    }
    return it;
}
```

### **Ejercicio 01: Span**
- Implementar clase `Span` que almacene números
- Métodos: `addNumber()`, `shortestSpan()`, `longestSpan()`
- Usar contenedores STL apropiados

### **Ejercicio 02: Mutated Stack**
- Implementar pila (stack) con funcionalidades adicionales
- Usar `std::stack` como base
- Implementar iteradores personalizados

---

## 🎯 CONCEPTOS CLAVE PARA DOMINAR

### **1. Iteradores**
```cpp
// Tipos de iteradores
std::vector<int>::iterator it;           // Lectura/escritura
std::vector<int>::const_iterator cit;    // Solo lectura
std::vector<int>::reverse_iterator rit;  // Al revés
```

### **2. Pair y Make_pair**
```cpp
std::pair<int, string> par;
par.first = 42;
par.second = "hola";

// O usar make_pair
auto par2 = std::make_pair(42, "hola");
```

### **3. Map y Set**
```cpp
std::map<string, int> edades;
edades["Ana"] = 25;
edades["Luis"] = 30;

std::set<int> numeros;
numeros.insert(42);
numeros.insert(24);
numeros.insert(42);  // No se duplica
```

---

## 🔧 HERRAMIENTAS Y SINTAXIS

### **Includes Necesarios**
```cpp
#include <vector>    // std::vector
#include <list>      // std::list
#include <map>       // std::map
#include <set>       // std::set
#include <algorithm> // std::find, std::sort, etc.
#include <iterator>  // std::iterator
#include <exception> // std::exception
```

### **Const Correctness**
```cpp
// Función que no modifica el contenedor
void imprimir(const std::vector<int>& vec) {
    for (std::vector<int>::const_iterator it = vec.begin(); 
         it != vec.end(); ++it) {
        std::cout << *it << " ";
    }
}
```

---

## 💡 CONSEJOS PRÁCTICOS

### **1. Elige el Contenedor Correcto**
- **`vector`**: Acceso rápido por índice, inserción al final
- **`list`**: Inserción/eliminación rápida en cualquier lugar
- **`map`**: Búsqueda rápida por clave
- **`set`**: Elementos únicos, búsqueda rápida

### **2. Usa Iteradores Correctamente**
```cpp
// ✅ Correcto
for (auto it = vec.begin(); it != vec.end(); ++it) {
    // *it es el elemento
}

// ❌ Incorrecto (puede ser peligroso)
for (auto it = vec.begin(); it != vec.end(); it++) {
    // ++it es más eficiente
}
```

### **3. Maneja Excepciones**
```cpp
try {
    auto it = easyfind(vec, 42);
    std::cout << "Encontrado: " << *it << std::endl;
} catch (const std::exception& e) {
    std::cout << "No encontrado" << std::endl;
}
```

---

## 🚀 PREPARACIÓN PARA CPP08

### **Antes de Empezar:**
1. ✅ Domina templates de CPP07
2. ✅ Entiende punteros y referencias
3. ✅ Conoces manejo de excepciones
4. ✅ Sabes usar `const` correctamente

### **Durante CPP08:**
1. 🎯 Practica con cada contenedor
2. 🎯 Experimenta con iteradores
3. 🎯 Usa algoritmos STL
4. 🎯 Escribe código genérico

### **Al Final de CPP08:**
- 🏆 Sabrás elegir el contenedor correcto
- 🏆 Dominarás los iteradores
- 🏆 Usarás algoritmos STL eficientemente
- 🏆 Escribirás código más limpio y eficiente

---

## 📚 RECURSOS ADICIONALES

- **cppreference.com**: Documentación completa de STL
- **cplusplus.com**: Tutoriales y ejemplos
- **42 Docs**: Documentación específica del módulo

---











