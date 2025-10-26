# 🎯 DYNAMIC_CAST - Explicación Completa

## 🤔 ¿Qué es dynamic_cast?

**dynamic_cast** es un operador de conversión (cast) de C++ que permite convertir punteros o referencias de una clase base a una clase derivada de forma **segura** en tiempo de ejecución.

```cpp
// Sintaxis básica:
dynamic_cast<TipoDestino>(objeto)

// Con punteros:
Derivada* ptr = dynamic_cast<Derivada*>(ptrBase);

// Con referencias:
Derivada& ref = dynamic_cast<Derivada&>(refBase);
```

---

## 🎯 ¿Para qué sirve?

Sirve para **identificar el tipo real** de un objeto cuando trabajas con polimorfismo:

```cpp
Base* ptr = ???;  // ¿Es un objeto A, B o C?

// Verificar si es un objeto A:
A* a = dynamic_cast<A*>(ptr);
if (a != NULL) {
    std::cout << "Es un objeto de tipo A" << std::endl;
} else {
    std::cout << "NO es un objeto de tipo A" << std::endl;
}
```

---

## 🔑 Característica Clave: Es SEGURO

A diferencia de otros casts, `dynamic_cast` **verifica en tiempo de ejecución** si la conversión es válida:

```cpp
Base* ptr = new B();  // Realmente es un objeto B

A* a = dynamic_cast<A*>(ptr);  // Intentar convertir a A*
// ✅ dynamic_cast detecta que NO es un A
// ✅ Retorna NULL
// ✅ No hay crash, es seguro

B* b = dynamic_cast<B*>(ptr);  // Intentar convertir a B*
// ✅ dynamic_cast detecta que SÍ es un B
// ✅ Retorna puntero válido
// ✅ Puedes usarlo sin problemas
```

---

## 📋 Requisitos para usar dynamic_cast

```
╔════════════════════════════════════════════════════════╗
║         REQUISITOS PARA dynamic_cast                   ║
╠════════════════════════════════════════════════════════╣
║                                                        ║
║  1. La clase base DEBE tener al menos                  ║
║     UNA función virtual                                ║
║                                                        ║
║     ✅ Correcto:                                       ║
║        class Base {                                    ║
║            virtual ~Base();  // ← Función virtual      ║
║        };                                              ║
║                                                        ║
║     ❌ Incorrecto:                                     ║
║        class Base {                                    ║
║            ~Base();  // ← NO virtual                   ║
║        };                                              ║
║        // dynamic_cast NO funcionará                   ║
║                                                        ║
║  2. Debe haber una relación de herencia                ║
║                                                        ║
║  3. Solo funciona con clases polimórficas              ║
║     (que tienen tabla virtual - vtable)                ║
║                                                        ║
╚════════════════════════════════════════════════════════╝
```

---

## 🔄 dynamic_cast con Punteros

### Comportamiento:

```cpp
Derivada* ptr = dynamic_cast<Derivada*>(ptrBase);
```

**Si la conversión es válida:**
- ✅ Retorna un puntero válido al objeto
- ✅ Puedes usar el puntero normalmente

**Si la conversión NO es válida:**
- ⚠️ Retorna `NULL` (puntero nulo)
- ✅ No hay crash ni error
- ✅ Debes verificar si es NULL antes de usar

### Ejemplo completo:

```cpp
class Base {
public:
    virtual ~Base() { }
};

class A : public Base { };
class B : public Base { };
class C : public Base { };

int main() {
    Base* ptr = new B();  // Objeto real: B
    
    // Intentar convertir a A*
    A* a = dynamic_cast<A*>(ptr);
    if (a == NULL) {
        std::cout << "NO es un A" << std::endl;  // ← Imprime esto
    }
    
    // Intentar convertir a B*
    B* b = dynamic_cast<B*>(ptr);
    if (b != NULL) {
        std::cout << "SÍ es un B" << std::endl;  // ← Imprime esto
    }
    
    // Intentar convertir a C*
    C* c = dynamic_cast<C*>(ptr);
    if (c == NULL) {
        std::cout << "NO es un C" << std::endl;  // ← Imprime esto
    }
    
    delete ptr;
    return 0;
}
```

**Salida:**
```
NO es un A
SÍ es un B
NO es un C
```

---

## 🔄 dynamic_cast con Referencias

### Comportamiento:

```cpp
Derivada& ref = dynamic_cast<Derivada&>(refBase);
```

**Si la conversión es válida:**
- ✅ Retorna una referencia válida al objeto
- ✅ Puedes usar la referencia normalmente

**Si la conversión NO es válida:**
- ❌ **Lanza una excepción** `std::bad_cast`
- ⚠️ NO retorna NULL (las referencias no pueden ser NULL)
- ✅ Debes usar try-catch para manejarla

### Ejemplo completo:

```cpp
#include <iostream>
#include <exception>

class Base {
public:
    virtual ~Base() { }
};

class A : public Base { };
class B : public Base { };

int main() {
    Base* ptr = new B();  // Objeto real: B
    Base& ref = *ptr;     // Referencia al objeto
    
    // Intentar convertir a A&
    try {
        A& a = dynamic_cast<A&>(ref);
        std::cout << "Es un A" << std::endl;
    } catch (std::bad_cast& e) {
        std::cout << "NO es un A (excepción)" << std::endl;  // ← Imprime esto
    }
    
    // Intentar convertir a B&
    try {
        B& b = dynamic_cast<B&>(ref);
        std::cout << "SÍ es un B" << std::endl;  // ← Imprime esto
    } catch (std::bad_cast& e) {
        std::cout << "NO es un B (excepción)" << std::endl;
    }
    
    delete ptr;
    return 0;
}
```

**Salida:**
```
NO es un A (excepción)
SÍ es un B
```

---

## 📊 Comparación: Punteros vs Referencias

```
╔════════════════════════════════════════════════════════════════╗
║                  PUNTEROS          │        REFERENCIAS        ║
╠════════════════════════════════════════════════════════════════╣
║                                    │                           ║
║  SINTAXIS:                         │                           ║
║  A* a = dynamic_cast<A*>(ptr);     │  A& a = dynamic_cast<A&>(ref);
║                                    │                           ║
║  SI ES VÁLIDO:                     │                           ║
║  ✅ Retorna puntero válido         │  ✅ Retorna referencia    ║
║                                    │                           ║
║  SI NO ES VÁLIDO:                  │                           ║
║  ⚠️ Retorna NULL                   │  ❌ Lanza std::bad_cast   ║
║                                    │                           ║
║  CÓMO VERIFICAR:                   │                           ║
║  if (a != NULL) { }                │  try { } catch { }        ║
║                                    │                           ║
║  USO TÍPICO:                       │                           ║
║  Cuando quieres verificar          │  Cuando estás seguro      ║
║  sin excepciones                   │  o quieres excepciones    ║
║                                    │                           ║
╚════════════════════════════════════════════════════════════════╝
```

---

## 🎯 En el Código del ex02

### Función identify() con PUNTEROS:

```cpp
// main.cpp - líneas 57-73
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
    else {
        std::cout << "Tipo desconocido" << std::endl;
    }
}
```

**Cómo funciona:**

```
Base* p = ???;  (puede ser A*, B* o C*)

┌──────────────────────────────────┐
│ dynamic_cast<A*>(p)              │
├──────────────────────────────────┤
│ ¿Es p realmente un A*?           │
│                                  │
│ SI → Retorna puntero válido      │
│      if (dynamic_cast<A*>(p))    │
│      → TRUE → Es un A            │
│                                  │
│ NO → Retorna NULL                │
│      if (NULL)                   │
│      → FALSE → No es un A        │
└──────────────────────────────────┘
```

### Función identify() con REFERENCIAS:

```cpp
// main.cpp - líneas 86-115
void identify(Base& p) {
    // Intentar convertir a A&
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "Tipo identificado: A" << std::endl;
        return;
    } catch (std::bad_cast&) {
        // No es tipo A, continuamos
    }
    
    // Intentar convertir a B&
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "Tipo identificado: B" << std::endl;
        return;
    } catch (std::bad_cast&) {
        // No es tipo B, continuamos
    }
    
    // Intentar convertir a C&
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "Tipo identificado: C" << std::endl;
        return;
    } catch (std::bad_cast&) {
        // No es tipo C
    }
    
    std::cout << "Tipo desconocido" << std::endl;
}
```

**Cómo funciona:**

```
Base& p = ???;  (puede ser A&, B& o C&)

┌──────────────────────────────────┐
│ try {                            │
│   dynamic_cast<A&>(p);           │
│ }                                │
├──────────────────────────────────┤
│ ¿Es p realmente un A&?           │
│                                  │
│ SI → Conversión exitosa          │
│      No lanza excepción          │
│      → Es un A                   │
│                                  │
│ NO → Lanza std::bad_cast         │
│      catch lo captura            │
│      → No es un A                │
└──────────────────────────────────┘
```

---

## 🧠 Visualización del Proceso

### Ejemplo con objeto B:

```
MEMORIA:
┌────────────────────────────┐
│  Objeto B                  │
│  ┌──────────────────────┐  │
│  │ vptr → VTABLE de B   │  │
│  ├──────────────────────┤  │
│  │ Parte de Base        │  │
│  ├──────────────────────┤  │
│  │ Parte de B           │  │
│  └──────────────────────┘  │
└────────────────────────────┘
         ↑
         │
    Base* ptr


PROCESO de dynamic_cast:

1. dynamic_cast<A*>(ptr)
   ┌────────────────────┐
   │ Consultar vptr     │
   │ VTABLE dice: "B"   │
   │ ¿B es un A? NO     │
   │ → Retornar NULL    │
   └────────────────────┘
   Resultado: NULL ✗

2. dynamic_cast<B*>(ptr)
   ┌────────────────────┐
   │ Consultar vptr     │
   │ VTABLE dice: "B"   │
   │ ¿B es un B? SÍ     │
   │ → Retornar ptr     │
   └────────────────────┘
   Resultado: puntero válido ✓

3. dynamic_cast<C*>(ptr)
   ┌────────────────────┐
   │ Consultar vptr     │
   │ VTABLE dice: "B"   │
   │ ¿B es un C? NO     │
   │ → Retornar NULL    │
   └────────────────────┘
   Resultado: NULL ✗
```

---

## 💡 ¿Cómo Funciona Internamente?

### 1. Necesita Información de Tipo en Runtime (RTTI)

```cpp
class Base {
    virtual ~Base();  // ← Esto crea una VTABLE
};

VTABLE de Base:
┌─────────────────────────┐
│ Información de tipo: Base│
│ ~Base()                 │
│ ...                     │
└─────────────────────────┘

VTABLE de A:
┌─────────────────────────┐
│ Información de tipo: A  │ ← dynamic_cast usa esta info
│ ~A()                    │
│ ...                     │
└─────────────────────────┘
```

### 2. Proceso de Conversión

```
dynamic_cast<A*>(ptr):

PASO 1: Obtener tipo real del objeto
┌────────────────────────┐
│ ptr → Objeto           │
│       vptr → VTABLE    │
│              │         │
│              ↓         │
│       "Tipo real: B"   │
└────────────────────────┘

PASO 2: Verificar si B puede convertirse a A
┌────────────────────────┐
│ ¿B hereda de A? NO     │
│ ¿B es A? NO            │
│ → Conversión INVÁLIDA  │
└────────────────────────┘

PASO 3: Retornar resultado
┌────────────────────────┐
│ Conversión inválida    │
│ → Retornar NULL        │
└────────────────────────┘
```

---

## 🔍 Comparación con otros Casts

```
╔════════════════════════════════════════════════════════════════════╗
║  CAST         │  SEGURIDAD  │  VERIFICA EN  │  USO                 ║
║               │             │  RUNTIME      │                      ║
╠════════════════════════════════════════════════════════════════════╣
║               │             │               │                      ║
║ static_cast   │ ❌ No       │ ❌ No         │ Conversiones         ║
║               │             │               │ conocidas en         ║
║               │             │               │ compile-time         ║
║               │             │               │                      ║
╠═══════════════╪═════════════╪═══════════════╪══════════════════════╣
║               │             │               │                      ║
║ dynamic_cast  │ ✅ Sí       │ ✅ Sí         │ Conversiones con     ║
║               │             │               │ herencia, seguro     ║
║               │             │               │                      ║
╠═══════════════╪═════════════╪═══════════════╪══════════════════════╣
║               │             │               │                      ║
║ reinterpret_  │ ❌ No       │ ❌ No         │ Conversión de        ║
║ cast          │             │               │ punteros/números     ║
║               │             │               │                      ║
╠═══════════════╪═════════════╪═══════════════╪══════════════════════╣
║               │             │               │                      ║
║ const_cast    │ ⚠️ Limitado │ ❌ No         │ Quitar/añadir const  ║
║               │             │               │                      ║
╚════════════════════════════════════════════════════════════════════╝
```

---

## 📝 Ejemplos Prácticos Completos

### Ejemplo 1: Sistema de Figuras Geométricas

```cpp
#include <iostream>

class Figura {
public:
    virtual ~Figura() { }
    virtual void dibujar() = 0;
};

class Circulo : public Figura {
private:
    double radio;
public:
    Circulo(double r) : radio(r) { }
    void dibujar() { std::cout << "Dibujando círculo" << std::endl; }
    double getRadio() { return radio; }
};

class Rectangulo : public Figura {
private:
    double ancho, alto;
public:
    Rectangulo(double a, double h) : ancho(a), alto(h) { }
    void dibujar() { std::cout << "Dibujando rectángulo" << std::endl; }
    double getArea() { return ancho * alto; }
};

void procesarFigura(Figura* f) {
    f->dibujar();  // Polimorfismo normal
    
    // ¿Es un círculo? Acceder a método específico
    Circulo* c = dynamic_cast<Circulo*>(f);
    if (c) {
        std::cout << "  Radio: " << c->getRadio() << std::endl;
    }
    
    // ¿Es un rectángulo? Acceder a método específico
    Rectangulo* r = dynamic_cast<Rectangulo*>(f);
    if (r) {
        std::cout << "  Área: " << r->getArea() << std::endl;
    }
}

int main() {
    Figura* figuras[2];
    figuras[0] = new Circulo(5.0);
    figuras[1] = new Rectangulo(4.0, 3.0);
    
    for (int i = 0; i < 2; i++) {
        procesarFigura(figuras[i]);
        delete figuras[i];
    }
    
    return 0;
}
```

**Salida:**
```
Dibujando círculo
  Radio: 5
Dibujando rectángulo
  Área: 12
```

### Ejemplo 2: Sistema de Empleados

```cpp
#include <iostream>
#include <string>

class Empleado {
protected:
    std::string nombre;
public:
    Empleado(std::string n) : nombre(n) { }
    virtual ~Empleado() { }
    virtual void trabajar() = 0;
};

class Programador : public Empleado {
private:
    std::string lenguaje;
public:
    Programador(std::string n, std::string l) 
        : Empleado(n), lenguaje(l) { }
    
    void trabajar() { 
        std::cout << nombre << " está programando en " << lenguaje << std::endl; 
    }
    
    void debuggear() {
        std::cout << nombre << " está debuggeando código" << std::endl;
    }
};

class Manager : public Empleado {
private:
    int numEquipo;
public:
    Manager(std::string n, int num) 
        : Empleado(n), numEquipo(num) { }
    
    void trabajar() { 
        std::cout << nombre << " está gestionando equipo de " 
                  << numEquipo << " personas" << std::endl; 
    }
    
    void organizarReunion() {
        std::cout << nombre << " está organizando reunión" << std::endl;
    }
};

void asignarTarea(Empleado* e) {
    e->trabajar();  // Método polimórfico
    
    // Tareas específicas según el tipo
    Programador* prog = dynamic_cast<Programador*>(e);
    if (prog) {
        prog->debuggear();
    }
    
    Manager* mgr = dynamic_cast<Manager*>(e);
    if (mgr) {
        mgr->organizarReunion();
    }
}

int main() {
    Empleado* empleados[2];
    empleados[0] = new Programador("Ana", "C++");
    empleados[1] = new Manager("Carlos", 5);
    
    for (int i = 0; i < 2; i++) {
        asignarTarea(empleados[i]);
        std::cout << std::endl;
        delete empleados[i];
    }
    
    return 0;
}
```

**Salida:**
```
Ana está programando en C++
Ana está debuggeando código

Carlos está gestionando equipo de 5 personas
Carlos está organizando reunión
```

---

## ⚠️ Errores Comunes

### Error 1: Clase sin funciones virtuales

```cpp
// ❌ INCORRECTO
class Base {
    // NO tiene funciones virtuales
};

class A : public Base { };

int main() {
    Base* ptr = new A();
    A* a = dynamic_cast<A*>(ptr);  // ❌ ERROR de compilación
    // error: 'Base' is not polymorphic
}
```

**Solución:**
```cpp
// ✅ CORRECTO
class Base {
public:
    virtual ~Base() { }  // Al menos una función virtual
};
```

### Error 2: No verificar NULL con punteros

```cpp
// ❌ PELIGROSO
Base* ptr = new B();
A* a = dynamic_cast<A*>(ptr);
a->metodo();  // ❌ Si a es NULL → CRASH
```

**Solución:**
```cpp
// ✅ CORRECTO
Base* ptr = new B();
A* a = dynamic_cast<A*>(ptr);
if (a != NULL) {
    a->metodo();  // ✅ Seguro
}
```

### Error 3: No usar try-catch con referencias

```cpp
// ❌ PELIGROSO
Base& ref = *ptr;
A& a = dynamic_cast<A&>(ref);  // Si no es A → EXCEPCIÓN no capturada
a.metodo();  // Puede no ejecutarse
```

**Solución:**
```cpp
// ✅ CORRECTO
Base& ref = *ptr;
try {
    A& a = dynamic_cast<A&>(ref);
    a.metodo();  // ✅ Solo se ejecuta si es válido
} catch (std::bad_cast& e) {
    std::cout << "No es tipo A" << std::endl;
}
```

---

## 🎓 Cuándo Usar dynamic_cast

```
╔════════════════════════════════════════════════════════════════╗
║              CUÁNDO USAR dynamic_cast                          ║
╠════════════════════════════════════════════════════════════════╣
║                                                                ║
║  ✅ USAR cuando:                                               ║
║  ───────────────────────────────────────────────────────────   ║
║  • Necesitas identificar el tipo real de un objeto            ║
║  • Trabajas con jerarquías de clases                          ║
║  • Quieres acceder a métodos específicos de una clase         ║
║    derivada                                                    ║
║  • Necesitas seguridad en tiempo de ejecución                 ║
║                                                                ║
║  ❌ NO USAR cuando:                                            ║
║  ───────────────────────────────────────────────────────────   ║
║  • Puedes usar polimorfismo normal (funciones virtuales)      ║
║  • La conversión es conocida en compile-time                  ║
║  • Estás haciendo downcasting muy frecuentemente              ║
║    (probablemente mal diseño)                                 ║
║                                                                ║
║  💡 ALTERNATIVAS MEJORES:                                      ║
║  ───────────────────────────────────────────────────────────   ║
║  • Usar funciones virtuales puras                             ║
║  • Patrón Visitor                                             ║
║  • Patrón Strategy                                            ║
║                                                                ║
╚════════════════════════════════════════════════════════════════╝
```

---

## 🔑 Resumen Ejecutivo

```
┌──────────────────────────────────────────────────────────┐
│                  dynamic_cast                            │
├──────────────────────────────────────────────────────────┤
│                                                          │
│  ¿QUÉ ES?                                                │
│  • Conversión segura en runtime                          │
│  • Verifica si el cast es válido                         │
│                                                          │
│  REQUISITOS:                                             │
│  • Clase polimórfica (con virtual)                       │
│  • Relación de herencia                                  │
│                                                          │
│  CON PUNTEROS:                                           │
│  • Si válido → puntero al objeto                         │
│  • Si inválido → NULL                                    │
│  • Verificar con if (ptr != NULL)                        │
│                                                          │
│  CON REFERENCIAS:                                        │
│  • Si válido → referencia al objeto                      │
│  • Si inválido → lanza std::bad_cast                     │
│  • Verificar con try-catch                               │
│                                                          │
│  VENTAJAS:                                               │
│  ✅ Seguro (detecta errores)                             │
│  ✅ No hay crashes por conversiones inválidas            │
│  ✅ Permite identificar tipos reales                     │
│                                                          │
│  DESVENTAJAS:                                            │
│  ❌ Más lento que static_cast                            │
│  ❌ Requiere RTTI (info de tipos)                        │
│  ❌ Uso excesivo indica mal diseño                       │
│                                                          │
└──────────────────────────────────────────────────────────┘
```

---

**Autor**: CPP Module 06 - ex02  
**Fecha**: Octubre 2025  
**Tema**: dynamic_cast - Conversión Segura en Runtime










