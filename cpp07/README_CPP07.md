# 📚 CPP07 - TEMPLATES EN C++

## 🎯 Objetivos del Módulo

Este módulo te enseñará a dominar los templates en C++, incluyendo template functions, template classes, especialización de templates, y patrones avanzados de metaprogramación.

---

## 🔧 1. TEMPLATE FUNCTIONS

### 📋 **1.1 Sintaxis Básica de Template Functions**

```cpp
// Sintaxis básica
template<typename T>
T maximo(T a, T b) {
    return (a > b) ? a : b;
}

// Uso
int resultado_int = maximo(10, 20);           // T = int
double resultado_double = maximo(3.14, 2.71); // T = double
char resultado_char = maximo('A', 'Z');       // T = char
```

### 📋 **1.2 Múltiples Parámetros de Template**

```cpp
// Múltiples tipos
template<typename T, typename U>
auto suma(T a, U b) -> decltype(a + b) {
    return a + b;
}

// Uso
auto resultado1 = suma(10, 3.14);    // int + double = double
auto resultado2 = suma(3.14, 10);    // double + int = double
auto resultado3 = suma(10, 20);      // int + int = int
```

### 📋 **1.3 Template Functions con Parámetros No-Tipo**

```cpp
// Parámetros no-tipo (valores constantes)
template<typename T, int SIZE>
class Array {
private:
    T datos[SIZE];
public:
    T& operator[](int index) {
        return datos[index];
    }
    const T& operator[](int index) const {
        return datos[index];
    }
};

// Uso
Array<int, 10> array_enteros;
Array<double, 5> array_doubles;
```

### 📋 **1.4 Template Functions con Valores por Defecto**

```cpp
// Valores por defecto para parámetros de template
template<typename T = int, int SIZE = 10>
class Vector {
private:
    T datos[SIZE];
public:
    Vector() {
        for (int i = 0; i < SIZE; ++i) {
            datos[i] = T{};
        }
    }
};

// Uso
Vector<> vector_default;        // Vector<int, 10>
Vector<double> vector_double;  // Vector<double, 10>
Vector<int, 5> vector_custom;   // Vector<int, 5>
```

---

## 🏗️ 2. TEMPLATE CLASSES

### 📋 **2.1 Sintaxis Básica de Template Classes**

```cpp
// Template class básica
template<typename T>
class Pila {
private:
    T* datos;
    int capacidad;
    int tope;
    
public:
    Pila(int cap = 10) : capacidad(cap), tope(-1) {
        datos = new T[capacidad];
    }
    
    ~Pila() {
        delete[] datos;
    }
    
    void push(const T& elemento) {
        if (tope < capacidad - 1) {
            datos[++tope] = elemento;
        }
    }
    
    T pop() {
        if (tope >= 0) {
            return datos[tope--];
        }
        throw std::runtime_error("Pila vacía");
    }
    
    bool empty() const {
        return tope == -1;
    }
};

// Uso
Pila<int> pila_enteros;
Pila<std::string> pila_strings;
```

### 📋 **2.2 Template Classes con Múltiples Parámetros**

```cpp
// Template class con múltiples parámetros
template<typename T, typename U>
class Par {
private:
    T primero;
    U segundo;
    
public:
    Par(const T& p, const U& s) : primero(p), segundo(s) {}
    
    T getPrimero() const { return primero; }
    U getSegundo() const { return segundo; }
    
    void setPrimero(const T& p) { primero = p; }
    void setSegundo(const U& s) { segundo = s; }
};

// Uso
Par<int, std::string> par1(42, "Hola");
Par<double, char> par2(3.14, 'A');
```

### 📋 **2.3 Template Classes con Herencia**

```cpp
// Clase base template
template<typename T>
class Contenedor {
protected:
    T* datos;
    int tamaño;
    
public:
    Contenedor(int tam) : tamaño(tam) {
        datos = new T[tamaño];
    }
    
    virtual ~Contenedor() {
        delete[] datos;
    }
    
    virtual void mostrar() const = 0;
};

// Clase derivada template
template<typename T>
class Lista : public Contenedor<T> {
public:
    Lista(int tam) : Contenedor<T>(tam) {}
    
    void mostrar() const override {
        for (int i = 0; i < this->tamaño; ++i) {
            std::cout << this->datos[i] << " ";
        }
        std::cout << std::endl;
    }
};

// Uso
Lista<int> lista_enteros(5);
Lista<std::string> lista_strings(3);
```

---

## 🎯 3. ESPECIALIZACIÓN DE TEMPLATES

### 📋 **3.1 Especialización Completa**

```cpp
// Template genérico
template<typename T>
class Comparador {
public:
    static bool esMayor(const T& a, const T& b) {
        return a > b;
    }
};

// Especialización completa para std::string
template<>
class Comparador<std::string> {
public:
    static bool esMayor(const std::string& a, const std::string& b) {
        return a.length() > b.length();  // Comparar por longitud
    }
};

// Uso
bool resultado1 = Comparador<int>::esMayor(10, 5);           // true
bool resultado2 = Comparador<std::string>::esMayor("Hola", "Mundo"); // false (4 < 5)
```

### 📋 **3.2 Especialización Parcial**

```cpp
// Template genérico
template<typename T, typename U>
class Par {
private:
    T primero;
    U segundo;
    
public:
    Par(const T& p, const U& s) : primero(p), segundo(s) {}
    
    void mostrar() const {
        std::cout << "Par genérico: " << primero << ", " << segundo << std::endl;
    }
};

// Especialización parcial para cuando ambos tipos son iguales
template<typename T>
class Par<T, T> {
private:
    T primero;
    T segundo;
    
public:
    Par(const T& p, const T& s) : primero(p), segundo(s) {}
    
    void mostrar() const {
        std::cout << "Par especializado: " << primero << ", " << segundo << std::endl;
    }
    
    T suma() const {
        return primero + segundo;
    }
};

// Uso
Par<int, double> par1(10, 3.14);    // Usa template genérico
Par<int, int> par2(10, 20);         // Usa especialización parcial
```

### 📋 **3.3 Especialización de Template Functions**

```cpp
// Template function genérica
template<typename T>
void procesar(T valor) {
    std::cout << "Procesando genérico: " << valor << std::endl;
}

// Especialización para std::string
template<>
void procesar<std::string>(std::string valor) {
    std::cout << "Procesando string: " << valor << " (longitud: " << valor.length() << ")" << std::endl;
}

// Uso
procesar(42);           // Usa template genérico
procesar(3.14);         // Usa template genérico
procesar(std::string("Hola")); // Usa especialización
```

---

## 🔍 4. TRAITS Y SFINAE

### 📋 **4.1 Type Traits Básicos**

```cpp
#include <type_traits>

// Template function que usa type traits
template<typename T>
void procesar_solo_enteros(T valor) {
    static_assert(std::is_integral_v<T>, "T debe ser un tipo entero");
    std::cout << "Procesando entero: " << valor << std::endl;
}

// Template function que usa type traits para diferentes comportamientos
template<typename T>
void mostrar_info(T valor) {
    if constexpr (std::is_integral_v<T>) {
        std::cout << "Es un entero: " << valor << std::endl;
    } else if constexpr (std::is_floating_point_v<T>) {
        std::cout << "Es un flotante: " << valor << std::endl;
    } else if constexpr (std::is_same_v<T, std::string>) {
        std::cout << "Es un string: " << valor << " (longitud: " << valor.length() << ")" << std::endl;
    } else {
        std::cout << "Tipo desconocido: " << valor << std::endl;
    }
}
```

### 📋 **4.2 SFINAE (Substitution Failure Is Not An Error)**

```cpp
// SFINAE para seleccionar diferentes implementaciones
template<typename T>
typename std::enable_if<std::is_integral_v<T>, T>::type
procesar_entero(T valor) {
    return valor * 2;
}

template<typename T>
typename std::enable_if<std::is_floating_point_v<T>, T>::type
procesar_entero(T valor) {
    return valor * 2.0;
}

// Uso
int resultado1 = procesar_entero(10);     // Usa primera versión
double resultado2 = procesar_entero(3.14); // Usa segunda versión
```

### 📋 **4.3 Conceptos (C++20) - Alternativa Moderna a SFINAE**

```cpp
// Conceptos para restricciones de tipos
template<typename T>
concept Entero = std::is_integral_v<T>;

template<typename T>
concept Flotante = std::is_floating_point_v<T>;

// Uso de conceptos
template<Entero T>
T procesar_entero(T valor) {
    return valor * 2;
}

template<Flotante T>
T procesar_flotante(T valor) {
    return valor * 2.0;
}
```

---

## 🧮 5. METAPROGRAMACIÓN CON TEMPLATES

### 📋 **5.1 Template Recursivo para Cálculos en Tiempo de Compilación**

```cpp
// Cálculo de factorial en tiempo de compilación
template<int N>
struct Factorial {
    static const int valor = N * Factorial<N-1>::valor;
};

// Caso base
template<>
struct Factorial<0> {
    static const int valor = 1;
};

// Uso
const int factorial_5 = Factorial<5>::valor;  // 120 (calculado en compilación)
```

### 📋 **5.2 Template Recursivo para Potencias**

```cpp
// Cálculo de potencia en tiempo de compilación
template<int BASE, int EXP>
struct Potencia {
    static const int valor = BASE * Potencia<BASE, EXP-1>::valor;
};

// Caso base
template<int BASE>
struct Potencia<BASE, 0> {
    static const int valor = 1;
};

// Uso
const int potencia_2_3 = Potencia<2, 3>::valor;  // 8 (calculado en compilación)
```

### 📋 **5.3 Template para Generación de Arrays**

```cpp
// Template para generar arrays con valores calculados
template<int N>
struct ArrayGenerado {
    static const int valores[N];
    
    static void mostrar() {
        for (int i = 0; i < N; ++i) {
            std::cout << valores[i] << " ";
        }
        std::cout << std::endl;
    }
};

// Definición de los valores
template<int N>
const int ArrayGenerado<N>::valores[N] = {};

// Especialización para generar valores específicos
template<>
const int ArrayGenerado<5>::valores[5] = {1, 2, 3, 4, 5};
```

---

## 🎨 6. PATRONES DE DISEÑO CON TEMPLATES

### 📋 **6.1 Patrón Singleton Template**

```cpp
template<typename T>
class Singleton {
private:
    static T* instancia;
    
public:
    static T& getInstancia() {
        if (instancia == nullptr) {
            instancia = new T();
        }
        return *instancia;
    }
    
    static void destruir() {
        delete instancia;
        instancia = nullptr;
    }
};

// Definición estática
template<typename T>
T* Singleton<T>::instancia = nullptr;

// Uso
class MiClase {
public:
    void metodo() {
        std::cout << "Método de MiClase" << std::endl;
    }
};

// Uso del singleton
MiClase& instancia = Singleton<MiClase>::getInstancia();
instancia.metodo();
```

### 📋 **6.2 Patrón Factory Template**

```cpp
template<typename T>
class Factory {
public:
    static T* crear() {
        return new T();
    }
    
    static T* crearConParametros(auto... args) {
        return new T(args...);
    }
};

// Uso
class ProductoA {
public:
    ProductoA(int valor) : _valor(valor) {}
    void mostrar() { std::cout << "ProductoA: " << _valor << std::endl; }
private:
    int _valor;
};

// Uso del factory
ProductoA* producto = Factory<ProductoA>::crearConParametros(42);
producto->mostrar();
delete producto;
```

### 📋 **6.3 Patrón Observer Template**

```cpp
template<typename T>
class Observer {
public:
    virtual ~Observer() = default;
    virtual void actualizar(const T& dato) = 0;
};

template<typename T>
class Subject {
private:
    std::vector<Observer<T>*> observadores;
    
public:
    void agregarObserver(Observer<T>* obs) {
        observadores.push_back(obs);
    }
    
    void removerObserver(Observer<T>* obs) {
        observadores.erase(
            std::remove(observadores.begin(), observadores.end(), obs),
            observadores.end()
        );
    }
    
    void notificar(const T& dato) {
        for (auto* obs : observadores) {
            obs->actualizar(dato);
        }
    }
};
```

---

## 🔧 7. EJERCICIOS TÍPICOS DEL MÓDULO

### 📋 **7.1 EX00: Template Function Básica**

**Objetivo**: Implementar una template function que encuentre el máximo de dos valores.

```cpp
#include <iostream>

template<typename T>
T max(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    std::cout << "Max(10, 20): " << max(10, 20) << std::endl;
    std::cout << "Max(3.14, 2.71): " << max(3.14, 2.71) << std::endl;
    std::cout << "Max('A', 'Z'): " << max('A', 'Z') << std::endl;
    
    return 0;
}
```

### 📋 **7.2 EX01: Template Class con Especialización**

**Objetivo**: Implementar una template class que almacene un valor y tenga diferentes comportamientos según el tipo.

```cpp
#include <iostream>
#include <string>

template<typename T>
class Almacen {
private:
    T valor;
    
public:
    Almacen(const T& v) : valor(v) {}
    
    void mostrar() const {
        std::cout << "Valor genérico: " << valor << std::endl;
    }
};

// Especialización para std::string
template<>
class Almacen<std::string> {
private:
    std::string valor;
    
public:
    Almacen(const std::string& v) : valor(v) {}
    
    void mostrar() const {
        std::cout << "String: " << valor << " (longitud: " << valor.length() << ")" << std::endl;
    }
};

int main() {
    Almacen<int> almacen_int(42);
    Almacen<std::string> almacen_string("Hola Mundo");
    
    almacen_int.mostrar();
    almacen_string.mostrar();
    
    return 0;
}
```

### 📋 **7.3 EX02: Template Class con Múltiples Parámetros**

**Objetivo**: Implementar una template class que represente un par de valores de diferentes tipos.

```cpp
#include <iostream>
#include <string>

template<typename T, typename U>
class Par {
private:
    T primero;
    U segundo;
    
public:
    Par(const T& p, const U& s) : primero(p), segundo(s) {}
    
    T getPrimero() const { return primero; }
    U getSegundo() const { return segundo; }
    
    void mostrar() const {
        std::cout << "Par: (" << primero << ", " << segundo << ")" << std::endl;
    }
};

int main() {
    Par<int, std::string> par1(42, "Hola");
    Par<double, char> par2(3.14, 'A');
    
    par1.mostrar();
    par2.mostrar();
    
    return 0;
}
```

---

## 🎯 8. MEJORES PRÁCTICAS

### ✅ **Do's (Hacer)**

1. **Usa nombres descriptivos para parámetros de template**
2. **Documenta las restricciones de tipos**
3. **Usa `constexpr` para cálculos en tiempo de compilación**
4. **Implementa especializaciones cuando sea necesario**
5. **Usa conceptos (C++20) para restricciones claras**

### ❌ **Don'ts (No hacer)**

1. **No abuses de la metaprogramación**
2. **No uses templates para casos simples**
3. **No ignores los errores de compilación de templates**
4. **No uses `auto` excesivamente en templates**
5. **No olvides las restricciones de tipos**

### 🔧 **Patrones Útiles**

```cpp
// Patrón: Template con restricciones
template<typename T>
concept Numerico = std::is_arithmetic_v<T>;

template<Numerico T>
T calcular_promedio(const std::vector<T>& valores) {
    T suma = T{};
    for (const auto& valor : valores) {
        suma += valor;
    }
    return suma / valores.size();
}

// Patrón: Template con valores por defecto
template<typename T, int SIZE = 10>
class Array {
    // Implementación...
};

// Patrón: Template con SFINAE
template<typename T>
typename std::enable_if<std::is_integral_v<T>, T>::type
procesar_entero(T valor) {
    return valor * 2;
}
```

---

## 📚 9. RECURSOS ADICIONALES

- **cppreference.com** - Documentación completa de templates
- **ISO/IEC 14882** - Estándar C++
- **Vandevoorde, David** - "C++ Templates: The Complete Guide"
- **Alexandrescu, Andrei** - "Modern C++ Design"

---

## 🎯 Resumen del Módulo

CPP07 te enseñará a:
1. **Dominar template functions** y template classes
2. **Implementar especializaciones** de templates
3. **Usar type traits** y SFINAE
4. **Aplicar metaprogramación** con templates
5. **Implementar patrones de diseño** con templates

¡Con estos conocimientos estarás preparado para enfrentar cualquier ejercicio de CPP07! 🚀
