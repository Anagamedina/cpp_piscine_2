# APUNTES EX03 - CPP05: Intern y Factory Method Pattern

## 📋 **Temas Principales del Ejercicio**

### 1. **Factory Method Pattern**
- **Clase Factory**: `Intern` actúa como factory para crear formularios
- **Creación Dinámica**: Formularios creados en tiempo de ejecución
- **Polimorfismo**: Todos los formularios devueltos como punteros a `Form`
- **Encapsulación**: Lógica de creación encapsulada en la clase Intern

### 2. **Intern Class - Clase Factory**
```cpp
class Intern {
public:
    Form* makeForm(const std::string& formName, const std::string& target);
private:
    static Form* createShrubberyForm(const std::string& target);
    static Form* createRobotomyForm(const std::string& target);
    static Form* createPresidentialForm(const std::string& target);
};
```

### 3. **Array de Punteros a Función**
```cpp
Form* (*formCreators[3])(const std::string&) = {
    createShrubberyForm,
    createRobotomyForm,
    createPresidentialForm
};
```
- **Punteros a función**: Para llamar métodos estáticos
- **Array de funciones**: Mapeo entre nombres y creadores
- **C++98 compatible**: Sintaxis estándar de C++98

### 4. **Manejo de Formularios Desconocidos**
```cpp
// Form name not found
std::cout << "Intern couldn't create form: " << formName << " (unknown form type)" << std::endl;
return NULL;
```
- **Validación**: Verificar si el nombre existe
- **Manejo de errores**: Devolver NULL para formularios desconocidos
- **Feedback**: Mensajes informativos al usuario

## 🏗️ **Arquitectura del Sistema**

### **Jerarquía de Clases**
```
Intern (Factory)
├── Form (Abstract Base)
│   ├── ShrubberyCreationForm
│   ├── RobotomyRequestForm
│   └── PresidentialPardonForm
└── Bureaucrat (User)
```

### **Flujo de Creación**
1. **Usuario** llama a `Intern::makeForm()`
2. **Intern** busca el nombre en el array
3. **Intern** llama a la función creadora correspondiente
4. **Función creadora** crea el formulario específico
5. **Intern** devuelve puntero a `Form`

## 📝 **Implementación de la Clase Intern**

### **makeForm() - Método Principal**
```cpp
Form* Intern::makeForm(const std::string& formName, const std::string& target){
    // Array de nombres de formularios
    std::string formNames[3] = { 
        "shrubbery creation", 
        "robotomy request", 
        "presidential pardon"
    };

    // Array de punteros a funciones creadoras
    Form* (*formCreators[3])(const std::string&) = {
        createShrubberyForm,
        createRobotomyForm,
        createPresidentialForm
    };

    // Buscar formulario coincidente
    for (int i = 0; i < 3; i++){
        if (formName == formNames[i]){
            std::cout << "Intern creates " << formName << " form for " << target << std::endl;
            return formCreators[i](target);
        } 
    }
    
    // Formulario no encontrado
    std::cout << "Intern couldn't create form: " << formName << " (unknown form type)" << std::endl;
    return NULL;
}
```

### **Funciones Creadoras Estáticas**
```cpp
// Creador para ShrubberyCreationForm
Form* Intern::createShrubberyForm(const std::string& target){
    return new ShrubberyCreationForm(target);
}

// Creador para RobotomyRequestForm
Form* Intern::createRobotomyForm(const std::string& target){
    return new RobotomyRequestForm(target);
}

// Creador para PresidentialPardonForm
Form* Intern::createPresidentialForm(const std::string& target){
    return new PresidentialPardonForm(target);
}
```

## 🎯 **Conceptos Importantes a Recordar**

### **1. Factory Method Pattern**
- **Propósito**: Crear objetos sin especificar sus clases exactas
- **Ventaja**: Fácil añadir nuevos tipos de formularios
- **Flexibilidad**: Creación dinámica basada en strings
- **Encapsulación**: Lógica de creación oculta del cliente

### **2. Punteros a Función en C++98**
```cpp
// Declaración de puntero a función
Form* (*functionPtr)(const std::string&);

// Asignación
functionPtr = createShrubberyForm;

// Llamada
Form* form = functionPtr("target");
```

### **3. Arrays de Punteros a Función**
```cpp
// Array de punteros a función
Form* (*creators[3])(const std::string&) = {
    createShrubberyForm,
    createRobotomyForm,
    createPresidentialForm
};

// Uso del array
Form* form = creators[index](target);
```

### **4. Gestión de Memoria**
```cpp
// Creación dinámica
Form* form = intern.makeForm("shrubbery creation", "garden");

// Uso del formulario
if (form) {
    bureaucrat.signForm(*form);
    bureaucrat.executeForm(*form);
    delete form;  // Liberar memoria
}
```

## ⚠️ **Validaciones y Manejo de Errores**

### **Validaciones en makeForm()**
1. **Nombre válido**: Verificar si existe en el array
2. **Target válido**: String no vacío
3. **Memoria disponible**: new puede fallar

### **Casos de Error**
```cpp
// Formulario desconocido
Form* unknown = intern.makeForm("unknown form", "target");
if (unknown) {
    // Procesar formulario
    delete unknown;
} else {
    // Manejar error
    std::cout << "Formulario no creado" << std::endl;
}
```

### **Manejo de Excepciones**
- **new puede lanzar**: `std::bad_alloc`
- **Constructores pueden lanzar**: Excepciones de validación
- **Manejo apropiado**: Try-catch en el código cliente

## 🧪 **Casos de Prueba Importantes**

### **1. Caso Exitoso**
```cpp
Form* shrubbery = intern.makeForm("shrubbery creation", "garden");
if (shrubbery) {
    bureaucrat.signForm(*shrubbery);
    bureaucrat.executeForm(*shrubbery);
    delete shrubbery;
}
```

### **2. Caso de Error - Formulario Desconocido**
```cpp
Form* unknown = intern.makeForm("unknown form", "target");
if (unknown) {
    delete unknown;
} else {
    std::cout << "Formulario desconocido" << std::endl;
}
```

### **3. Caso de Error - Bureaucrat Insuficiente**
```cpp
Form* form = intern.makeForm("shrubbery creation", "test");
if (form) {
    lowLevelBureaucrat.signForm(*form);
    lowLevelBureaucrat.executeForm(*form);  // Fallará
    delete form;
}
```

## 🎓 **Puntos Clave para el Examen**

### **1. Factory Method Pattern**
- **Entender**: Cómo funciona la creación dinámica
- **Implementar**: Arrays de punteros a función
- **Manejar**: Formularios desconocidos

### **2. Punteros a Función**
- **Sintaxis**: `ReturnType (*ptr)(Parameters)`
- **Arrays**: `ReturnType (*array[])(Parameters)`
- **Llamadas**: `ptr(args)` o `array[index](args)`

### **3. Gestión de Memoria**
- **new/delete**: Para formularios dinámicos
- **Verificación**: Siempre verificar si new fue exitoso
- **Limpieza**: delete apropiado para evitar memory leaks

### **4. Polimorfismo**
- **Punteros base**: `Form*` para todos los formularios
- **Métodos virtuales**: `execute()` implementado por cada tipo
- **Llamadas polimórficas**: Funcionan correctamente

## 🔍 **Errores Comunes a Evitar**

### **1. Memory Leaks**
```cpp
// ❌ MALO - Sin delete
Form* form = intern.makeForm("shrubbery creation", "garden");
bureaucrat.signForm(*form);
// Olvidar delete form;

// ✅ BUENO - Con delete
Form* form = intern.makeForm("shrubbery creation", "garden");
if (form) {
    bureaucrat.signForm(*form);
    bureaucrat.executeForm(*form);
    delete form;
}
```

### **2. Verificación de NULL**
```cpp
// ❌ MALO - Sin verificación
Form* form = intern.makeForm("unknown", "target");
bureaucrat.signForm(*form);  // Crash si form es NULL

// ✅ BUENO - Con verificación
Form* form = intern.makeForm("unknown", "target");
if (form) {
    bureaucrat.signForm(*form);
    bureaucrat.executeForm(*form);
    delete form;
}
```

### **3. Arrays de Punteros**
```cpp
// ❌ MALO - Sintaxis incorrecta
Form* formCreators[3] = { ... };  // Error de tipos

// ✅ BUENO - Sintaxis correcta
Form* (*formCreators[3])(const std::string&) = { ... };
```

## 📚 **Conceptos de C++98 Específicos**

### **1. Punteros a Función**
```cpp
// Declaración
ReturnType (*functionPtr)(ParameterTypes);

// Asignación
functionPtr = functionName;

// Llamada
ReturnType result = functionPtr(arguments);
```

### **2. Arrays de Punteros a Función**
```cpp
// Declaración
ReturnType (*array[])(ParameterTypes) = {
    function1,
    function2,
    function3
};

// Uso
ReturnType result = array[index](arguments);
```

### **3. Gestión de Memoria**
```cpp
// Creación
Type* ptr = new Type(constructorArgs);

// Verificación
if (ptr) {
    // Usar ptr
    delete ptr;
}
```

## 🎨 **Patrones de Diseño Implementados**

### **1. Factory Method Pattern**
- **Clase**: Intern
- **Método**: makeForm()
- **Propósito**: Crear formularios dinámicamente

### **2. Template Method Pattern**
- **Clase base**: Form
- **Método**: execute() (virtual puro)
- **Implementaciones**: En clases derivadas

### **3. Strategy Pattern**
- **Contexto**: Bureaucrat
- **Estrategias**: Diferentes tipos de formularios
- **Selección**: Basada en el tipo de formulario

### **4. RAII Pattern**
- **Recursos**: Memoria dinámica
- **Gestión**: new/delete apropiados
- **Limpieza**: Automática en destructores

## 🔧 **Mejores Prácticas**

### **1. Nombres de Formularios**
```cpp
// Usar nombres consistentes
std::string formNames[3] = { 
    "shrubbery creation",    // Minúsculas, espacios
    "robotomy request",     // Consistente
    "presidential pardon"   // Formato uniforme
};
```

### **2. Manejo de Errores**
```cpp
// Siempre verificar NULL
if (form) {
    // Procesar formulario
    delete form;
} else {
    // Manejar error
}
```

### **3. Comentarios en Inglés**
```cpp
// Form creation method
Form* makeForm(const std::string& formName, const std::string& target);

// Static form creator functions
static Form* createShrubberyForm(const std::string& target);
```

## 📖 **Referencias y Recursos**

- **Factory Method Pattern**: Patrón de diseño creacional
- **Punteros a Función**: C++98 function pointers
- **Polimorfismo**: Herencia y métodos virtuales
- **Gestión de Memoria**: new/delete en C++98
- **RAII**: Resource Acquisition Is Initialization

## 🎯 **Resumen de Conceptos Clave**

1. **Factory Method**: Intern crea formularios dinámicamente
2. **Punteros a Función**: Arrays de creadores
3. **Polimorfismo**: Formularios como punteros a Form
4. **Gestión de Memoria**: new/delete apropiados
5. **Manejo de Errores**: Verificación de NULL
6. **Comentarios en Inglés**: Breves pero importantes
7. **Couts Profesionales**: Mensajes claros y informativos

---

*Este documento cubre todos los conceptos esenciales del ejercicio ex03. Estudia cada sección y practica implementando los conceptos por ti mismo.*
