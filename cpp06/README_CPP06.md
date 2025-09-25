# 📚 CPP06 - CASTING Y CONVERSIÓN DE TIPOS EN C++

## 🎯 Objetivos del Módulo

Este módulo te enseñará a manejar las conversiones de tipos en C++, incluyendo los diferentes tipos de casting, conversiones implícitas y explícitas, y el manejo seguro de errores durante las conversiones.

---

## 🔧 1. CASTING EN C++

### 📋 Tipos de Cast en C++

C++ proporciona cuatro tipos de casting específicos para diferentes situaciones:

#### 🎯 **1.1 `static_cast` - Conversiones Seguras en Tiempo de Compilación**

```cpp
// Sintaxis: static_cast<tipo_destino>(expresión)

// Conversiones numéricas seguras
int entero = 42;
double decimal = static_cast<double>(entero);  // int → double
float flotante = static_cast<float>(decimal); // double → float

// Conversiones entre tipos relacionados
char caracter = 'A';
int ascii = static_cast<int>(caracter);       // char → int

// Conversiones de punteros en jerarquías de herencia
Base* base_ptr = new Derived();
Derived* derived_ptr = static_cast<Derived*>(base_ptr); // ⚠️ PELIGROSO sin verificación
```

**✅ Cuándo usar `static_cast`:**
- Conversiones numéricas seguras
- Conversiones explícitas entre tipos relacionados
- Conversiones de `void*` a otros tipos de punteros
- Conversiones de enumeraciones a enteros

**❌ Cuándo NO usar:**
- Downcasting sin verificación (usa `dynamic_cast`)
- Conversiones entre tipos no relacionados
- Conversiones que pueden perder información

#### 🎯 **1.2 `dynamic_cast` - Downcasting Seguro entre Clases Polimórficas**

```cpp
// Sintaxis: dynamic_cast<tipo_destino>(expresión)

class Base {
public:
    virtual ~Base() {}  // ⚠️ REQUIERE función virtual para ser polimórfica
};

class Derived : public Base {
public:
    void metodo_especifico() {}
};

// Uso seguro de dynamic_cast
Base* base_ptr = new Derived();
Derived* derived_ptr = dynamic_cast<Derived*>(base_ptr);

if (derived_ptr != nullptr) {
    // Conversión exitosa
    derived_ptr->metodo_especifico();
} else {
    // La conversión falló
    std::cout << "No es un objeto Derived" << std::endl;
}

// Con referencias (lanza std::bad_cast si falla)
try {
    Derived& derived_ref = dynamic_cast<Derived&>(*base_ptr);
    derived_ref.metodo_especifico();
} catch (const std::bad_cast& e) {
    std::cout << "Error de conversión: " << e.what() << std::endl;
}
```

**✅ Cuándo usar `dynamic_cast`:**
- Downcasting en jerarquías de herencia
- Verificación de tipos en tiempo de ejecución
- Implementación de patrones como Visitor

**❌ Cuándo NO usar:**
- Con clases no polimórficas (sin funciones virtuales)
- Para conversiones numéricas
- Cuando el rendimiento es crítico (es más lento)

#### 🎯 **1.3 `reinterpret_cast` - Reinterpretación de Bits (PELIGROSO)**

```cpp
// Sintaxis: reinterpret_cast<tipo_destino>(expresión)

int valor = 0x12345678;
char* bytes = reinterpret_cast<char*>(&valor);

// Conversión entre punteros no relacionados
int* int_ptr = new int(42);
char* char_ptr = reinterpret_cast<char*>(int_ptr);

// Conversión de función a puntero
void (*func_ptr)() = reinterpret_cast<void(*)()>(0x12345678);
```

**⚠️ PELIGROS de `reinterpret_cast`:**
- No hay verificación de tipos
- Puede causar comportamiento indefinido
- Dependiente de la arquitectura
- Difícil de debuggear

**✅ Cuándo usar (muy limitado):**
- Serialización de datos binarios
- Interfaz con código C
- Manipulación de bits a bajo nivel

#### 🎯 **1.4 `const_cast` - Añadir o Quitar `const`**

```cpp
// Sintaxis: const_cast<tipo_destino>(expresión)

// Quitar const
const int valor_const = 42;
int* ptr_mutable = const_cast<int*>(&valor_const);
*ptr_mutable = 100; // ⚠️ PELIGROSO si el objeto original era const

// Añadir const
int valor_mutable = 42;
const int* ptr_const = const_cast<const int*>(&valor_mutable);

// Ejemplo práctico: función que acepta const pero necesita modificar
void procesar_string(const std::string& str) {
    // Si necesitamos modificar str temporalmente
    std::string& str_mutable = const_cast<std::string&>(str);
    // ⚠️ Solo si estamos seguros de que es seguro
}
```

**✅ Cuándo usar `const_cast`:**
- Interfaz con APIs que no son const-correct
- Eliminar const de objetos que sabemos que son mutables
- Implementación de funciones de utilidad

**❌ Cuándo NO usar:**
- Para modificar objetos que realmente son const
- Como solución rápida a problemas de diseño
- Sin entender completamente las implicaciones

---

## 🔄 2. CONVERSIÓN DE TIPOS

### 📋 **2.1 Conversiones Implícitas (Automáticas)**

```cpp
// Promociones aritméticas
int entero = 42;
double decimal = entero;  // int → double (promoción)

// Conversiones de tipos relacionados
char caracter = 'A';
int ascii = caracter;     // char → int

// Conversiones en expresiones
int a = 10;
double b = 3.14;
double resultado = a + b; // int promociona a double
```

**Tipos de conversiones implícitas:**
- **Promociones aritméticas**: `char` → `int`, `float` → `double`
- **Conversiones estándar**: `int` → `double`, `int` → `float`
- **Conversiones de punteros**: `Derived*` → `Base*`
- **Conversiones de referencias**: `Derived&` → `Base&`

### 📋 **2.2 Conversiones Explícitas (Forzadas)**

```cpp
// C-style cast (evitar en C++)
int entero = 42;
double decimal = (double)entero;

// static_cast (recomendado)
double decimal2 = static_cast<double>(entero);

// Conversiones peligrosas
double valor = 3.14159;
int truncado = static_cast<int>(valor);  // Pérdida de precisión
```

### 📋 **2.3 Conversiones Peligrosas y Pérdida de Precisión**

```cpp
// Ejemplos de conversiones peligrosas
double valor_grande = 1e20;
int entero_pequeno = static_cast<int>(valor_grande);  // Overflow

float flotante = 3.14159f;
int truncado = static_cast<int>(flotante);  // 3 (pérdida de decimales)

// Verificación de rangos
bool es_seguro_int(double valor) {
    return (valor >= INT_MIN && valor <= INT_MAX);
}

if (es_seguro_int(valor_double)) {
    int entero_seguro = static_cast<int>(valor_double);
}
```

### 📋 **2.4 Control de Conversiones con `explicit`**

```cpp
class MiClase {
public:
    // Constructor explícito (previene conversiones implícitas)
    explicit MiClase(int valor) : _valor(valor) {}
    
    // Operador de conversión explícito
    explicit operator int() const { return _valor; }
    
private:
    int _valor;
};

// Uso
MiClase obj(42);
// int valor = obj;  // ❌ ERROR: conversión implícita bloqueada
int valor = static_cast<int>(obj);  // ✅ OK: conversión explícita
```

---

## ⚠️ 3. EXCEPCIONES EN CONVERSIONES

### 📋 **3.1 Manejo de Errores con `try`, `catch`, `throw`**

```cpp
// Función que puede lanzar excepciones
double dividir_seguro(double a, double b) {
    if (b == 0.0) {
        throw std::invalid_argument("División por cero");
    }
    return a / b;
}

// Manejo de excepciones
try {
    double resultado = dividir_seguro(10.0, 0.0);
    std::cout << "Resultado: " << resultado << std::endl;
} catch (const std::invalid_argument& e) {
    std::cerr << "Error: " << e.what() << std::endl;
} catch (const std::exception& e) {
    std::cerr << "Error general: " << e.what() << std::endl;
}
```

### 📋 **3.2 Diferencia entre Lanzar y Capturar Excepciones**

```cpp
// LANZAR excepciones (throw)
void validar_edad(int edad) {
    if (edad < 0) {
        throw std::invalid_argument("La edad no puede ser negativa");
    }
    if (edad > 150) {
        throw std::invalid_argument("La edad no puede ser mayor a 150");
    }
}

// CAPTURAR excepciones (catch)
void procesar_usuario(int edad) {
    try {
        validar_edad(edad);
        std::cout << "Edad válida: " << edad << std::endl;
    } catch (const std::invalid_argument& e) {
        std::cerr << "Error de validación: " << e.what() << std::endl;
        // Manejar el error apropiadamente
    }
}
```

### 📋 **3.3 Buenas Prácticas vs Casts Inseguros**

```cpp
// ❌ MALO: Cast inseguro sin verificación
Base* base_ptr = obtener_objeto();
Derived* derived_ptr = static_cast<Derived*>(base_ptr);  // PELIGROSO
derived_ptr->metodo_especifico();  // Puede crashear

// ✅ BUENO: Cast seguro con verificación
Base* base_ptr = obtener_objeto();
Derived* derived_ptr = dynamic_cast<Derived*>(base_ptr);
if (derived_ptr != nullptr) {
    derived_ptr->metodo_especifico();  // Seguro
} else {
    std::cerr << "No es un objeto Derived" << std::endl;
}

// ✅ BUENO: Excepción personalizada para conversiones
class ConversionError : public std::exception {
public:
    const char* what() const throw() override {
        return "Error de conversión de tipo";
    }
};

void convertir_seguro(int valor) {
    if (valor < 0 || valor > 255) {
        throw ConversionError();
    }
    char resultado = static_cast<char>(valor);
}
```

---

## 🏗️ 4. EJERCICIOS TÍPICOS DEL MÓDULO

### 📋 **4.1 EX00: Conversión de Literales**

**Objetivo**: Implementar un programa que convierta un literal (char, int, float, double) a todos los demás tipos.

```cpp
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

class ScalarConverter {
public:
    static void convert(const std::string& literal) {
        // Detectar el tipo del literal
        if (es_char(literal)) {
            convertir_desde_char(literal[0]);
        } else if (es_int(literal)) {
            convertir_desde_int(std::stoi(literal));
        } else if (es_float(literal)) {
            convertir_desde_float(std::stof(literal));
        } else if (es_double(literal)) {
            convertir_desde_double(std::stod(literal));
        } else {
            std::cout << "Literal no válido" << std::endl;
        }
    }

private:
    static bool es_char(const std::string& literal) {
        return literal.length() == 1 && std::isprint(literal[0]);
    }
    
    static bool es_int(const std::string& literal) {
        try {
            std::stoi(literal);
            return true;
        } catch (...) {
            return false;
        }
    }
    
    static bool es_float(const std::string& literal) {
        return literal.back() == 'f' && literal.length() > 1;
    }
    
    static bool es_double(const std::string& literal) {
        return literal.find('.') != std::string::npos;
    }
    
    static void convertir_desde_char(char c) {
        std::cout << "char: '" << c << "'" << std::endl;
        std::cout << "int: " << static_cast<int>(c) << std::endl;
        std::cout << "float: " << static_cast<float>(c) << ".0f" << std::endl;
        std::cout << "double: " << static_cast<double>(c) << ".0" << std::endl;
    }
    
    static void convertir_desde_int(int valor) {
        // char
        if (valor >= 32 && valor <= 126) {
            std::cout << "char: '" << static_cast<char>(valor) << "'" << std::endl;
        } else {
            std::cout << "char: Non displayable" << std::endl;
        }
        
        // int
        std::cout << "int: " << valor << std::endl;
        
        // float
        std::cout << "float: " << static_cast<float>(valor) << ".0f" << std::endl;
        
        // double
        std::cout << "double: " << static_cast<double>(valor) << ".0" << std::endl;
    }
    
    static void convertir_desde_float(float valor) {
        // char
        if (std::isnan(valor) || std::isinf(valor)) {
            std::cout << "char: impossible" << std::endl;
        } else if (valor >= 32 && valor <= 126) {
            std::cout << "char: '" << static_cast<char>(valor) << "'" << std::endl;
        } else {
            std::cout << "char: Non displayable" << std::endl;
        }
        
        // int
        if (std::isnan(valor) || std::isinf(valor)) {
            std::cout << "int: impossible" << std::endl;
        } else {
            std::cout << "int: " << static_cast<int>(valor) << std::endl;
        }
        
        // float
        std::cout << "float: " << valor;
        if (valor == static_cast<int>(valor)) {
            std::cout << ".0f";
        }
        std::cout << "f" << std::endl;
        
        // double
        std::cout << "double: " << static_cast<double>(valor);
        if (valor == static_cast<int>(valor)) {
            std::cout << ".0";
        }
        std::cout << std::endl;
    }
    
    static void convertir_desde_double(double valor) {
        // Similar a float pero con double
        // Implementar lógica similar...
    }
};

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Uso: " << argv[0] << " <literal>" << std::endl;
        return 1;
    }
    
    ScalarConverter::convert(argv[1]);
    return 0;
}
```

### 📋 **4.2 EX01: Serialización de Punteros**

**Objetivo**: Serializar punteros (convertir puntero a entero y viceversa).

```cpp
#include <iostream>
#include <cstdint>

class Serializer {
public:
    // Convertir puntero a entero
    static uintptr_t serialize(void* ptr) {
        return reinterpret_cast<uintptr_t>(ptr);
    }
    
    // Convertir entero a puntero
    static void* deserialize(uintptr_t raw) {
        return reinterpret_cast<void*>(raw);
    }
};

int main() {
    int valor = 42;
    int* ptr = &valor;
    
    // Serializar puntero a entero
    uintptr_t serializado = Serializer::serialize(ptr);
    std::cout << "Puntero original: " << ptr << std::endl;
    std::cout << "Serializado: " << serializado << std::endl;
    
    // Deserializar entero a puntero
    int* ptr_restaurado = static_cast<int*>(Serializer::deserialize(serializado));
    std::cout << "Puntero restaurado: " << ptr_restaurado << std::endl;
    std::cout << "Valor: " << *ptr_restaurado << std::endl;
    
    return 0;
}
```

### 📋 **4.3 EX02: Identificación de Tipos con `dynamic_cast`**

**Objetivo**: Identificar el tipo real de objeto usando `dynamic_cast`.

```cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

class Base {
public:
    virtual ~Base() {}
    virtual void identificar() const = 0;
};

class A : public Base {
public:
    void identificar() const override {
        std::cout << "Soy de tipo A" << std::endl;
    }
};

class B : public Base {
public:
    void identificar() const override {
        std::cout << "Soy de tipo B" << std::endl;
    }
};

class C : public Base {
public:
    void identificar() const override {
        std::cout << "Soy de tipo C" << std::endl;
    }
};

Base* generate() {
    int tipo = rand() % 3;
    switch (tipo) {
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
        default: return nullptr;
    }
}

void identify(Base* p) {
    if (A* a = dynamic_cast<A*>(p)) {
        std::cout << "Identificado como A: ";
        a->identificar();
    } else if (B* b = dynamic_cast<B*>(p)) {
        std::cout << "Identificado como B: ";
        b->identificar();
    } else if (C* c = dynamic_cast<C*>(p)) {
        std::cout << "Identificado como C: ";
        c->identificar();
    } else {
        std::cout << "Tipo desconocido" << std::endl;
    }
}

void identify(Base& p) {
    try {
        A& a = dynamic_cast<A&>(p);
        std::cout << "Identificado como A: ";
        a.identificar();
    } catch (const std::bad_cast&) {
        try {
            B& b = dynamic_cast<B&>(p);
            std::cout << "Identificado como B: ";
            b.identificar();
        } catch (const std::bad_cast&) {
            try {
                C& c = dynamic_cast<C&>(p);
                std::cout << "Identificado como C: ";
                c.identificar();
            } catch (const std::bad_cast&) {
                std::cout << "Tipo desconocido" << std::endl;
            }
        }
    }
}

int main() {
    srand(time(NULL));
    
    // Generar objetos aleatorios
    for (int i = 0; i < 10; i++) {
        Base* obj = generate();
        if (obj) {
            std::cout << "Objeto " << i + 1 << ": ";
            identify(obj);
            delete obj;
        }
    }
    
    return 0;
}
```

---

## 🧮 5. FUNCIONES MATEMÁTICAS Y VALORES ESPECIALES

### 📋 **5.1 `std::srand` y Generación de Números Aleatorios**

```cpp
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
    // Inicializar semilla del generador aleatorio
    srand(time(NULL));
    
    // Generar números aleatorios
    for (int i = 0; i < 5; i++) {
        int aleatorio = rand() % 100;  // 0-99
        std::cout << "Número aleatorio: " << aleatorio << std::endl;
    }
    
    return 0;
}
```

### 📋 **5.2 Valores Especiales: `NaN` e `Inf`**

```cpp
#include <iostream>
#include <cmath>
#include <limits>

int main() {
    // NaN (Not a Number)
    double nan_val = std::numeric_limits<double>::quiet_NaN();
    std::cout << "NaN: " << nan_val << std::endl;
    std::cout << "Es NaN: " << std::isnan(nan_val) << std::endl;
    
    // Infinito positivo
    double inf_pos = std::numeric_limits<double>::infinity();
    std::cout << "Infinito positivo: " << inf_pos << std::endl;
    std::cout << "Es infinito: " << std::isinf(inf_pos) << std::endl;
    
    // Infinito negativo
    double inf_neg = -std::numeric_limits<double>::infinity();
    std::cout << "Infinito negativo: " << inf_neg << std::endl;
    
    // Operaciones que producen NaN
    double resultado_nan = 0.0 / 0.0;
    std::cout << "0/0 = " << resultado_nan << " (NaN)" << std::endl;
    
    // Operaciones que producen infinito
    double resultado_inf = 1.0 / 0.0;
    std::cout << "1/0 = " << resultado_inf << " (Inf)" << std::endl;
    
    return 0;
}
```

### 📋 **5.3 Librerías Necesarias**

```cpp
#include <cstdlib>  // Para srand, rand
#include <ctime>    // Para time
#include <cmath>    // Para isnan, isinf, etc.
#include <limits>   // Para numeric_limits
#include <iomanip>  // Para formateo de salida
```

---

## 🎯 6. MEJORES PRÁCTICAS Y CONSEJOS

### ✅ **Do's (Hacer)**

1. **Usa `static_cast` para conversiones seguras**
2. **Usa `dynamic_cast` para downcasting seguro**
3. **Verifica siempre los resultados de `dynamic_cast`**
4. **Maneja excepciones apropiadamente**
5. **Documenta qué conversiones puede lanzar cada función**

### ❌ **Don'ts (No hacer)**

1. **No uses C-style casts `(tipo)expresión`**
2. **No uses `reinterpret_cast` a menos que sea absolutamente necesario**
3. **No ignores los resultados de `dynamic_cast`**
4. **No lances excepciones desde destructores**
5. **No uses `const_cast` para modificar objetos realmente const**

### 🔧 **Patrones Útiles**

```cpp
// Patrón: Safe Cast con verificación
template<typename T, typename U>
T* safe_cast(U* ptr) {
    return dynamic_cast<T*>(ptr);
}

// Patrón: Conversión con validación
template<typename T>
T convert_with_validation(double value) {
    if (std::isnan(value) || std::isinf(value)) {
        throw std::invalid_argument("Valor no válido para conversión");
    }
    if (value < std::numeric_limits<T>::min() || 
        value > std::numeric_limits<T>::max()) {
        throw std::overflow_error("Valor fuera de rango");
    }
    return static_cast<T>(value);
}
```

---



