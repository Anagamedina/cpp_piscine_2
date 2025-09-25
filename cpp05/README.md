# CPP05 - PISCINE C++

## 📋 **DESCRIPCIÓN DEL PROYECTO**

Este proyecto implementa un sistema de gestión de formularios burocráticos en C++98, demostrando conceptos avanzados de programación orientada a objetos, patrones de diseño y manejo de excepciones.

## 🎯 **OBJETIVOS DEL PROYECTO**

- **Herencia**: Implementar jerarquías de clases con herencia
- **Polimorfismo**: Uso de métodos virtuales y punteros base
- **Excepciones**: Manejo personalizado de errores
- **Patrones de Diseño**: Factory Method, Template Method, Strategy
- **Gestión de Memoria**: RAII y new/delete apropiados
- **C++98**: Compatibilidad total con el estándar C++98

## 📁 **ESTRUCTURA DEL PROYECTO**

```
cpp05/
├── ex00/          # Bureaucrat básico
├── ex01/          # Formularios y herencia
├── ex02/          # Formularios específicos
├── ex03/          # Intern y Factory Method
└── README.md      # Este archivo
```

## 🚀 **EJERCICIOS IMPLEMENTADOS**

### **EX00 - Bureaucrat Básico**
- **Tema**: Clases, constructores, excepciones
- **Conceptos**: Encapsulación, validaciones, operadores
- **Archivos**: `Bureaucrat.hpp`, `Bureaucrat.cpp`, `main.cpp`
- **Enlace**: [Ver Ex00](./ex00/)

**Temas importantes:**
- Constructores y destructores
- Excepciones personalizadas
- Operadores de asignación
- Validaciones de datos

### **EX01 - Formularios y Herencia**
- **Tema**: Herencia, clases abstractas, polimorfismo
- **Conceptos**: Form base class, herencia pública, métodos virtuales
- **Archivos**: `Form.hpp`, `Form.cpp`, `Bureaucrat.hpp`, `Bureaucrat.cpp`
- **Enlace**: [Ver Ex01](./ex01/)

**Temas importantes:**
- Herencia en C++
- Clases abstractas
- Métodos virtuales
- Polimorfismo

### **EX02 - Formularios Específicos**
- **Tema**: Formularios concretos, herencia, excepciones
- **Conceptos**: ShrubberyCreationForm, RobotomyRequestForm, PresidentialPardonForm
- **Archivos**: Formularios específicos + Form base + Bureaucrat
- **Enlace**: [Ver Ex02](./ex02/)

**Temas importantes:**
- Herencia de clases abstractas
- Implementación de métodos virtuales puros
- Gestión de archivos (std::ofstream)
- Números aleatorios (std::rand)
- Manejo de excepciones

### **EX03 - Intern y Factory Method**
- **Tema**: Patrón Factory Method, creación dinámica
- **Conceptos**: Intern class, punteros a función, arrays de creadores
- **Archivos**: Intern + todos los formularios + Bureaucrat
- **Enlace**: [Ver Ex03](./ex03/)

**Temas importantes:**
- Factory Method Pattern
- Punteros a función en C++98
- Arrays de punteros a función
- Creación dinámica de objetos
- Gestión de memoria

## 🎓 **CONCEPTOS CLAVE IMPLEMENTADOS**

### **1. Herencia y Polimorfismo**
```cpp
class Form {  // Clase base abstracta
    virtual void execute(const Bureaucrat& executor) const = 0;
};

class ShrubberyCreationForm : public Form {  // Herencia
    void execute(const Bureaucrat& executor) const;  // Implementación
};
```

### **2. Excepciones Personalizadas**
```cpp
class GradeTooHighException : public std::exception {
public:
    virtual const char* what() const throw();
};
```

### **3. Factory Method Pattern**
```cpp
class Intern {
public:
    Form* makeForm(const std::string& formName, const std::string& target);
private:
    static Form* createShrubberyForm(const std::string& target);
};
```

### **4. Punteros a Función (C++98)**
```cpp
Form* (*formCreators[3])(const std::string&) = {
    createShrubberyForm,
    createRobotomyForm,
    createPresidentialForm
};
```

## 📊 **DIAGRAMAS UML**

### **Ex02 - Diagrama de Clases**
- [Diagrama UML Ex02](./ex02/DIAGRAMA_UML_MERMAID.md)
- [Flowcharts Ex02](./ex02/FLOWCHARTS_EX02.md)

### **Ex03 - Diagrama de Clases**
- [Diagrama UML Ex03](./ex03/DIAGRAMA_UML_EX03.md)

## 📚 **APUNTES DETALLADOS**

### **Ex02 - Apuntes Completos**
- [Apuntes Ex02](./ex02/APUNTES_EX02.md)
- **Temas**: Herencia, excepciones, gestión de archivos, números aleatorios

### **Ex03 - Apuntes Completos**
- [Apuntes Ex03](./ex03/APUNTES_EX03.md)
- **Temas**: Factory Method, punteros a función, gestión de memoria

### **Notas de Excepciones (Generales)**
- [Apuntes de Excepciones + UML](./EXCEPTIONS_NOTES.md)

## 🔧 **CARACTERÍSTICAS TÉCNICAS**

### **Compatibilidad C++98**
- ✅ **Compilación**: `-std=c++98`
- ✅ **Sin warnings**: `-Wall -Wextra -Werror`
- ✅ **Punteros a función**: Sintaxis C++98
- ✅ **Gestión de memoria**: new/delete
- ✅ **Excepciones**: std::exception

### **Patrones de Diseño**
- **Factory Method**: Intern crea formularios dinámicamente
- **Template Method**: Form define algoritmo, clases derivadas implementan
- **Strategy Pattern**: Diferentes comportamientos por formulario
- **RAII**: Gestión automática de recursos

Para una relación detallada entre ex00–ex03 y patrones de diseño, consulta:
- [Patrones de Diseño en cpp05](./PATRONES_DISENIO_CPP05.md)

### **Gestión de Memoria**
- **new/delete**: Para formularios dinámicos
- **Verificación de NULL**: Siempre verificar punteros
- **Limpieza apropiada**: delete en destructores
- **RAII**: Resource Acquisition Is Initialization

## 🧪 **CASOS DE PRUEBA**

### **Ex00 - Bureaucrat**
- Creación con grades válidos
- Manejo de excepciones
- Incremento/decremento de grades

### **Ex01 - Formularios**
- Creación de formularios
- Firma por Bureaucrat
- Validaciones de grade

### **Ex02 - Formularios Específicos**
- ShrubberyCreationForm: Creación de archivos ASCII
- RobotomyRequestForm: Lógica aleatoria (50% éxito)
- PresidentialPardonForm: Perdón presidencial

### **Ex03 - Intern**
- Creación dinámica de formularios
- Manejo de formularios desconocidos
- Gestión de memoria apropiada

## 🎯 **PUNTOS CLAVE PARA EL EXAMEN**

### **1. Herencia**
- Clases base abstractas
- Métodos virtuales puros
- Polimorfismo

### **2. Excepciones**
- Excepciones personalizadas
- Manejo de errores
- Try-catch apropiado

### **3. Patrones de Diseño**
- Factory Method
- Template Method
- Strategy Pattern

### **4. Gestión de Memoria**
- new/delete
- Verificación de NULL
- RAII

### **5. C++98**
- Punteros a función
- Sintaxis estándar
- Compatibilidad total

## 🚀 **CÓMO USAR EL PROYECTO**

### **Compilación**
```bash
# Ex00
cd ex00 && make

# Ex01
cd ex01 && make

# Ex02
cd ex02 && make

# Ex03
cd ex03 && make
```

### **Ejecución**
```bash
# Ejecutar programa
./form

# Limpiar archivos
make clean
```

## 📖 **RECURSOS ADICIONALES**

### **Documentación**
- [C++98 Standard](https://en.cppreference.com/w/cpp/98)
- [Design Patterns](https://refactoring.guru/design-patterns)
- [C++ Exceptions](https://en.cppreference.com/w/cpp/error/exception)

### **Conceptos Importantes**
- **Herencia**: Jerarquías de clases
- **Polimorfismo**: Métodos virtuales
- **Excepciones**: Manejo de errores
- **Patrones**: Factory, Template, Strategy
- **Memoria**: new/delete, RAII

## 🎓 **CONCLUSIÓN**

Este proyecto demuestra la implementación de conceptos avanzados de C++98:

- ✅ **Herencia y Polimorfismo**: Jerarquías de clases
- ✅ **Excepciones**: Manejo personalizado de errores
- ✅ **Patrones de Diseño**: Factory Method, Template Method
- ✅ **Gestión de Memoria**: RAII y new/delete
- ✅ **C++98**: Compatibilidad total con el estándar

**El proyecto está listo para presentación y evaluación.**

---

*Este README proporciona una visión general completa del proyecto CPP05, incluyendo todos los ejercicios, conceptos implementados y recursos adicionales.*
