# APUNTES EX02 - CPP05: Formularios y Herencia

## 📋 **Temas Principales del Ejercicio**

### 1. **Herencia en C++**
- **Clase Base Abstracta**: `Form` es una clase abstracta con método virtual puro
- **Herencia Pública**: Las clases derivadas heredan de `Form`
- **Polimorfismo**: Uso de punteros/referencias a la clase base
- **Métodos Virtuales**: `execute()` es virtual puro en la clase base

### 2. **Clases Abstractas y Métodos Virtuales Puros**
```cpp
class Form {
public:
    virtual void execute(const Bureaucrat& executor) const = 0;  // Método virtual puro
};
```
- **`= 0`**: Indica que es un método virtual puro
- **Clase Abstracta**: No se puede instanciar directamente
- **Implementación Obligatoria**: Las clases derivadas DEBEN implementar el método

### 3. **Excepciones Personalizadas**
```cpp
class GradeTooHighException : public std::exception {
public:
    virtual const char* what() const throw();
};
```
- **Herencia de `std::exception`**: Para compatibilidad con el sistema de excepciones
- **Método `what()`**: Debe ser virtual y retornar `const char*`
- **`throw()`**: Especificación de excepción (C++98)

### 4. **Gestión de Archivos con `std::ofstream`**
```cpp
std::ofstream file((_target + "_shrubbery").c_str());
if (file.is_open()) {
    // Escribir datos
    file.close();
}
```
- **`std::ofstream`**: Para escribir archivos
- **`.c_str()`**: Convierte `std::string` a `const char*`
- **Verificación de apertura**: `is_open()` antes de escribir

### 5. **Números Aleatorios en C++98**
```cpp
std::srand(std::time(0));  // Semilla
if (std::rand() % 2 == 0) {
    // 50% de probabilidad
}
```
- **`std::srand()`**: Inicializa el generador de números aleatorios
- **`std::time(0)`**: Usa el tiempo actual como semilla
- **`std::rand() % 2`**: Genera 0 o 1 (50% probabilidad)

## 🏗️ **Arquitectura del Sistema**

### **Jerarquía de Clases**
```
Form (Clase Abstracta)
├── ShrubberyCreationForm
├── RobotomyRequestForm
└── PresidentialPardonForm
```

### **Relaciones entre Clases**
- **`Bureaucrat`** ↔ **`Form`**: Relación de uso (bureaucrat usa forms)
- **`Form`** → **`Bureaucrat`**: Dependencia (form necesita bureaucrat para ejecutarse)

## 📝 **Implementación de Cada Formulario**

### **1. ShrubberyCreationForm**
- **Grados**: Sign=145, Execute=137
- **Función**: Crear archivo con arte ASCII de árbol
- **Validaciones**: Form firmado + grade suficiente

### **2. RobotomyRequestForm**
- **Grados**: Sign=72, Execute=45
- **Función**: Robotomización con 50% de éxito
- **Característica**: Resultado aleatorio

### **3. PresidentialPardonForm**
- **Grados**: Sign=25, Execute=5
- **Función**: Perdón presidencial
- **Mensaje**: "has been pardoned by Zaphod Beeblebrox"

## 🔧 **Métodos Clave del Bureaucrat**

### **`signForm(Form& form)`**
```cpp
void Bureaucrat::signForm(Form& form) {
    try {
        form.beSigned(*this);
        std::cout << _name << " signed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << _name << " couldn't sign " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}
```

### **`executeForm(const Form& form)`**
```cpp
void Bureaucrat::executeForm(const Form& form) {
    try {
        form.execute(*this);
        std::cout << _name << " executed " << form.getName() << std::endl;
    } catch (const std::exception& e) {
        std::cout << _name << " couldn't execute " << form.getName() 
                  << " because " << e.what() << std::endl;
    }
}
```

## ⚠️ **Validaciones y Excepciones**

### **Validaciones en `execute()`**
1. **Form firmado**: `if (!getSigned()) throw FormException();`
2. **Grade suficiente**: `if (executor.getGrade() > getGradeToExecute()) throw GradeTooLowException();`

### **Tipos de Excepciones**
- **`GradeTooHighException`**: Grade < 1
- **`GradeTooLowException`**: Grade > 150 o insuficiente para ejecutar
- **`FormException`**: Form no firmado

## 🎯 **Conceptos Importantes a Recordar**

### **1. Herencia Virtual**
- **Destructor virtual**: `virtual ~Form();`
- **Métodos virtuales**: Para polimorfismo
- **Clase abstracta**: No se puede instanciar

### **2. Gestión de Memoria**
- **RAII**: Resource Acquisition Is Initialization
- **Destructores**: Limpieza automática
- **Const-correctness**: Uso de `const` donde corresponde

### **3. Encapsulación**
- **Miembros privados**: `_name`, `_Signed`, `_gradeToSign`, `_gradeToExecute`
- **Getters**: Acceso controlado a datos privados
- **Setters**: Solo a través de métodos específicos

### **4. Const-correctness**
```cpp
void execute(const Bureaucrat& executor) const;  // Método const
const std::string& getName() const;              // Getter const
```

## 🧪 **Casos de Prueba Importantes**

### **1. Caso Exitoso**
- Bureaucrat con grade alto
- Form firmado y ejecutado correctamente

### **2. Caso de Error - Grade Insuficiente**
- Bureaucrat con grade bajo
- No puede ejecutar el form

### **3. Caso de Error - Form No Firmado**
- Form sin firmar
- No se puede ejecutar

### **4. Caso Aleatorio - Robotomy**
- 50% de probabilidad de éxito
- Demuestra uso de números aleatorios

## 📚 **Conceptos de C++98 Específicos**

### **1. Especificación de Excepciones**
```cpp
virtual const char* what() const throw();  // C++98 style
```

### **2. Inicialización de Miembros**
```cpp
Form(const std::string name, int gradetosign, int gradetoexecute) 
    : _name(name), _Signed(false), _gradeToSign(gradetosign), _gradeToExecute(gradetoexecute) {
    // Validaciones en el cuerpo
}
```

### **3. Operador de Asignación**
```cpp
Form& operator=(const Form& obj) {
    if (this != &obj) {
        _Signed = obj._Signed;  // Solo copiar lo que se puede modificar
    }
    return *this;
}
```

## 🎓 **Puntos Clave para el Examen**

1. **Entender herencia**: Clase base abstracta con métodos virtuales puros
2. **Manejo de excepciones**: Crear excepciones personalizadas
3. **Polimorfismo**: Uso correcto de métodos virtuales
4. **Gestión de archivos**: `std::ofstream` para escritura
5. **Números aleatorios**: `std::srand()` y `std::rand()`
6. **Const-correctness**: Uso apropiado de `const`
7. **RAII**: Gestión automática de recursos
8. **Encapsulación**: Protección de datos privados

## 🔍 **Errores Comunes a Evitar**

1. **No implementar métodos virtuales puros**
2. **Olvidar verificar si el form está firmado**
3. **No validar grades antes de ejecutar**
4. **No cerrar archivos después de escribir**
5. **Usar `new`/`delete` innecesariamente**
6. **No manejar excepciones correctamente**
7. **Olvidar incluir headers necesarios**

## 📖 **Referencias y Recursos**

- **C++98 Standard**: Especificación oficial
- **Herencia**: Conceptos de OOP
- **Excepciones**: Manejo de errores
- **I/O Streams**: Gestión de archivos
- **Random Numbers**: Generación de números aleatorios

---

## 🎲 **TEORÍA DETALLADA: `rand()` y Números Aleatorios**

### **¿Qué es `rand()`?**
`rand()` es una función de la biblioteca estándar de C++ que genera números pseudoaleatorios. Es parte de `<cstdlib>` y genera enteros en el rango `[0, RAND_MAX]`.

### **Características de `rand()`**
```cpp
#include <cstdlib>
#include <iostream>

int main() {
    std::cout << "RAND_MAX = " << RAND_MAX << std::endl;  // Típicamente 32767
    std::cout << "rand() = " << rand() << std::endl;      // Número aleatorio
    return 0;
}
```

### **¿Por qué "Pseudoaleatorio"?**
- **No es verdaderamente aleatorio**: Usa un algoritmo matemático
- **Determinístico**: Con la misma semilla, produce la misma secuencia
- **Periódico**: Eventualmente se repite la secuencia
- **Rápido**: Muy eficiente computacionalmente

### **El Problema de la Semilla**
```cpp
// ❌ MALO - Sin semilla
for (int i = 0; i < 5; i++) {
    std::cout << rand() << " ";  // Siempre la misma secuencia
}
// Output: 1804289383 846930886 1681692777 1714636915 1957747793

// ✅ BUENO - Con semilla
std::srand(std::time(0));
for (int i = 0; i < 5; i++) {
    std::cout << rand() << " ";  // Diferente cada ejecución
}
```

### **Función `srand()` - Inicialización**
```cpp
void srand(unsigned int seed);
```
- **Propósito**: Inicializa el generador de números aleatorios
- **Parámetro**: Semilla (seed) - valor inicial
- **Efecto**: Cambia la secuencia de números generados

### **Semillas Comunes**
```cpp
// 1. Tiempo actual (más común)
std::srand(std::time(0));

// 2. Valor fijo (para debugging)
std::srand(42);

// 3. PID del proceso
std::srand(getpid());

// 4. Combinación
std::srand(std::time(0) ^ getpid());
```

### **Generando Rangos Específicos**

#### **Rango [0, n-1]**
```cpp
int random = rand() % n;  // 0 a n-1
```

#### **Rango [1, n]**
```cpp
int random = (rand() % n) + 1;  // 1 a n
```

#### **Rango [min, max]**
```cpp
int random = min + (rand() % (max - min + 1));
```

#### **Rango [0.0, 1.0] (Float)**
```cpp
double random = (double)rand() / RAND_MAX;
```

### **Ejemplos Prácticos**

#### **1. Lanzar un Dado (1-6)**
```cpp
std::srand(std::time(0));
int dice = (rand() % 6) + 1;
std::cout << "Dice roll: " << dice << std::endl;
```

#### **2. Moneda (Cara o Cruz)**
```cpp
std::srand(std::time(0));
bool heads = (rand() % 2) == 0;
std::cout << (heads ? "Heads" : "Tails") << std::endl;
```

#### **3. Porcentaje de Éxito**
```cpp
std::srand(std::time(0));
int success_rate = 75;  // 75% de éxito
bool success = (rand() % 100) < success_rate;
std::cout << (success ? "Success!" : "Failure!") << std::endl;
```

### **Algoritmo Interno de `rand()`**
```cpp
// Implementación simplificada (Linear Congruential Generator)
static unsigned long next = 1;

int rand() {
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % 32768;
}

void srand(unsigned int seed) {
    next = seed;
}
```

### **Limitaciones de `rand()`**

#### **1. Calidad de Aleatoriedad**
- **No criptográficamente seguro**
- **Patrones predecibles**
- **Periodo limitado**

#### **2. Distribución**
- **Puede no ser uniforme**
- **Sesgos en ciertos rangos**
- **Dependiente de la implementación**

#### **3. Thread Safety**
- **No es thread-safe**
- **Estado global compartido**
- **Problemas en programas concurrentes**

### **Alternativas Modernas (C++11+)**

#### **`<random>` Header**
```cpp
#include <random>

// Generador más moderno
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dis(1, 6);

int dice = dis(gen);  // Mejor calidad
```

#### **Comparación**
```cpp
// C++98 (rand)
std::srand(std::time(0));
int old_way = (rand() % 6) + 1;

// C++11+ (modern)
std::random_device rd;
std::mt19937 gen(rd());
std::uniform_int_distribution<> dis(1, 6);
int new_way = dis(gen);
```

### **En Nuestro Ejercicio Ex02**
```cpp
void RobotomyRequestForm::execute(const Bureaucrat& executor) const {
    // ... validaciones ...
    
    std::srand(std::time(0));  // Semilla con tiempo actual
    if (std::rand() % 2 == 0) {  // 50% de probabilidad
        std::cout << "Robotomy successful!" << std::endl;
    } else {
        std::cout << "Robotomy failed!" << std::endl;
    }
}
```

### **Mejores Prácticas**

#### **1. Inicializar una sola vez**
```cpp
// ✅ BUENO
int main() {
    std::srand(std::time(0));  // Una sola vez al inicio
    // ... resto del código ...
}

// ❌ MALO
for (int i = 0; i < 1000; i++) {
    std::srand(std::time(0));  // Reinicializa constantemente
    int random = rand() % 10;
}
```

#### **2. Usar semillas diferentes**
```cpp
// Para diferentes secuencias
std::srand(std::time(0) + getpid());
```

#### **3. Validar rangos**
```cpp
// Asegurar que el rango es correcto
int random_in_range(int min, int max) {
    return min + (rand() % (max - min + 1));
}
```

### **Problemas Comunes**

#### **1. Secuencia Repetitiva**
```cpp
// ❌ Sin semilla
for (int i = 0; i < 5; i++) {
    std::cout << rand() << std::endl;  // Siempre igual
}
```

#### **2. Semilla en Bucle**
```cpp
// ❌ Reinicializa en cada iteración
for (int i = 0; i < 5; i++) {
    std::srand(std::time(0));
    std::cout << rand() << std::endl;  // Puede ser igual
}
```

#### **3. Rango Incorrecto**
```cpp
// ❌ MALO - Sesgo hacia números bajos
int random = rand() % 10;  // 0-9, pero no uniforme

// ✅ MEJOR - Para rangos grandes
int random = min + (rand() % (max - min + 1));
```

### **Testing y Debugging**

#### **Semilla Fija para Testing**
```cpp
std::srand(42);  // Semilla fija para resultados reproducibles
// Útil para debugging y testing
```

#### **Verificar Distribución**
```cpp
std::srand(std::time(0));
int counts[6] = {0};
for (int i = 0; i < 60000; i++) {
    counts[rand() % 6]++;
}
// Verificar que cada número aparece ~10000 veces
```

### **Resumen de Conceptos Clave**

1. **`rand()`**: Genera números pseudoaleatorios
2. **`srand()`**: Inicializa con semilla
3. **Semilla**: Determina la secuencia
4. **Modulo (`%`)**: Para rangos específicos
5. **Una sola inicialización**: Al inicio del programa
6. **No thread-safe**: Problemas en concurrencia
7. **Calidad limitada**: Para aplicaciones simples

---

