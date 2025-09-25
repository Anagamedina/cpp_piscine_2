# CPP PISCINE 02 - PROGRAMACIÓN ORIENTADA A OBJETOS

## 📋 **DESCRIPCIÓN GENERAL**

Este repositorio contiene la segunda parte de la piscina C++ de 42, enfocada en **Programación Orientada a Objetos (POO)** y conceptos avanzados de C++98. Cada módulo introduce progresivamente conceptos más complejos de OOP, patrones de diseño y gestión de memoria.

## 🎯 **OBJETIVOS DE LA PISCINA**

- **Herencia y Polimorfismo**: Jerarquías de clases y métodos virtuales
- **Patrones de Diseño**: Factory Method, Template Method, Strategy
- **Gestión de Memoria**: RAII, new/delete, punteros inteligentes
- **Excepciones**: Manejo robusto de errores
- **C++98**: Compatibilidad total con el estándar C++98
- **Contenedores STL**: Vectores, listas, mapas, algoritmos
- **Algoritmos**: Ordenación, búsqueda, manipulación de datos

## 📁 **ESTRUCTURA DEL REPOSITORIO**

```
cpp_piscine_2/
├── cpp05/          # Excepciones, Herencia, Polimorfismo
├── cpp06/          # Casts, Serialización
├── cpp07/          # Templates
├── cpp08/          # STL Containers
├── cpp09/          # STL Algorithms
└── README.md       # Este archivo
```

## 🚀 **MÓDULOS IMPLEMENTADOS**

### **CPP05 - EXCEPCIONES, HERENCIA Y POLIMORFISMO** ✅
- **Tema**: Manejo de excepciones, herencia, clases abstractas
- **Conceptos**: Bureaucrat, Formularios, Factory Method
- **Ejercicios**: 4 ejercicios (ex00-ex03)
- **Enlace**: [Ver CPP05](./cpp05/)

**Temas clave:**
- Excepciones personalizadas
- Herencia y polimorfismo
- Clases abstractas
- Factory Method Pattern
- Template Method Pattern

### **CPP06 - CASTS Y SERIALIZACIÓN** 🔄
- **Tema**: Casts explícitos, serialización de objetos
- **Conceptos**: static_cast, dynamic_cast, reinterpret_cast, const_cast
- **Estado**: En desarrollo
- **Enlace**: [Ver CPP06](./cpp06/)

### **CPP07 - TEMPLATES** 🔄
- **Tema**: Programación genérica con templates
- **Conceptos**: Template classes, template functions, specialization
- **Estado**: En desarrollo
- **Enlace**: [Ver CPP07](./cpp07/)

### **CPP08 - CONTENEDORES STL** 🔄
- **Tema**: Contenedores de la Standard Template Library
- **Conceptos**: vector, list, map, set, stack, queue
- **Estado**: En desarrollo
- **Enlace**: [Ver CPP08](./cpp08/)

### **CPP09 - ALGORITMOS STL** 🔄
- **Tema**: Algoritmos de la Standard Template Library
- **Conceptos**: sort, find, transform, accumulate, for_each
- **Estado**: En desarrollo
- **Enlace**: [Ver CPP09](./cpp09/)

## 🎓 **PROGRESIÓN DE CONCEPTOS**

### **CPP05 - Fundamentos OOP**
```
Bureaucrat (ex00) → Form (ex01) → AForm + Subclases (ex02) → Factory (ex03)
```

### **CPP06 - Casts y Serialización**
```
Casts explícitos → Serialización → Deserialización → Type safety
```

### **CPP07 - Templates**
```
Template functions → Template classes → Specialization → Metaprogramming
```

### **CPP08 - Contenedores STL**
```
vector → list → map → set → stack → queue → deque
```

### **CPP09 - Algoritmos STL**
```
sort → find → transform → accumulate → for_each → custom comparators
```

## 🔧 **CARACTERÍSTICAS TÉCNICAS**

### **Compatibilidad C++98**
- ✅ **Compilación**: `-std=c++98`
- ✅ **Sin warnings**: `-Wall -Wextra -Werror`
- ✅ **Punteros a función**: Sintaxis C++98
- ✅ **Gestión de memoria**: new/delete
- ✅ **Excepciones**: std::exception

### **Patrones de Diseño Implementados**
- **Factory Method**: Creación dinámica de objetos
- **Template Method**: Algoritmos con pasos variables
- **Strategy Pattern**: Comportamientos intercambiables
- **RAII**: Gestión automática de recursos

### **Conceptos OOP**
- **Encapsulación**: Datos privados, métodos públicos
- **Herencia**: Jerarquías de clases
- **Polimorfismo**: Métodos virtuales
- **Abstracción**: Clases abstractas

## 📊 **ESTADÍSTICAS DEL PROYECTO**

| Módulo | Ejercicios | Estado | Conceptos Clave |
|--------|------------|--------|-----------------|
| CPP05  | 4/4        | ✅     | Excepciones, Herencia, Polimorfismo |
| CPP06  | 0/4        | 🔄     | Casts, Serialización |
| CPP07  | 0/4        | 🔄     | Templates, Metaprogramming |
| CPP08  | 0/4        | 🔄     | STL Containers |
| CPP09  | 0/4        | 🔄     | STL Algorithms |

## 🧪 **CASOS DE PRUEBA**

### **CPP05 - Formularios Burocráticos**
- Creación y validación de Bureaucrats
- Firma y ejecución de formularios
- Manejo de excepciones
- Factory Method para creación dinámica

### **CPP06 - Casts y Serialización**
- Casts seguros entre tipos
- Serialización de objetos complejos
- Deserialización con validación
- Type safety en runtime

### **CPP07 - Templates**
- Funciones genéricas
- Clases template
- Especialización de templates
- Metaprogramación básica

### **CPP08 - Contenedores STL**
- Operaciones con vectores
- Manipulación de listas
- Uso de mapas y conjuntos
- Pilas y colas

### **CPP09 - Algoritmos STL**
- Ordenación y búsqueda
- Transformación de datos
- Acumulación de valores
- Iteradores personalizados

## 🎯 **PUNTOS CLAVE PARA EL EXAMEN**

### **1. Programación Orientada a Objetos**
- Herencia y polimorfismo
- Clases abstractas
- Métodos virtuales
- Encapsulación

### **2. Patrones de Diseño**
- Factory Method
- Template Method
- Strategy Pattern
- RAII

### **3. Gestión de Memoria**
- new/delete
- Punteros inteligentes
- RAII
- Gestión de excepciones

### **4. STL (Standard Template Library)**
- Contenedores
- Algoritmos
- Iteradores
- Functores

### **5. C++98**
- Templates
- Casts explícitos
- Excepciones
- Compatibilidad

## 🚀 **CÓMO USAR EL REPOSITORIO**

### **Navegación**
```bash
# Ver módulo específico
cd cpp05/
cd cpp06/
cd cpp07/
cd cpp08/
cd cpp09/

# Ver ejercicio específico
cd cpp05/ex00/
cd cpp05/ex01/
cd cpp05/ex02/
cd cpp05/ex03/
```

### **Compilación**
```bash
# Compilar ejercicio específico
cd cpp05/ex00 && make
cd cpp05/ex01 && make
cd cpp05/ex02 && make
cd cpp05/ex03 && make
```

### **Ejecución**
```bash
# Ejecutar programa
./form
./abstract_form
./intern_form

# Limpiar archivos
make clean
make fclean
```

## 📚 **RECURSOS ADICIONALES**

### **Documentación**
- [C++98 Standard](https://en.cppreference.com/w/cpp/98)
- [Design Patterns](https://refactoring.guru/design-patterns)
- [STL Reference](https://en.cppreference.com/w/cpp/container)
- [C++ Exceptions](https://en.cppreference.com/w/cpp/error/exception)

### **Conceptos Importantes**
- **OOP**: Herencia, Polimorfismo, Encapsulación
- **Patrones**: Factory, Template, Strategy
- **STL**: Contenedores, Algoritmos, Iteradores
- **Memoria**: RAII, new/delete, Punteros

## 🎓 **CONCLUSIÓN**

Este repositorio demuestra la implementación progresiva de conceptos avanzados de C++98:

- ✅ **CPP05**: Excepciones, Herencia, Polimorfismo, Patrones de Diseño
- 🔄 **CPP06**: Casts, Serialización (En desarrollo)
- 🔄 **CPP07**: Templates, Metaprogramación (En desarrollo)
- 🔄 **CPP08**: STL Containers (En desarrollo)
- 🔄 **CPP09**: STL Algorithms (En desarrollo)

**El proyecto está en desarrollo continuo y se actualiza regularmente.**

---

*Este README proporciona una visión general completa de la piscina C++02, incluyendo todos los módulos, conceptos implementados y recursos adicionales.*