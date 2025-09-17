# 📚 EXCEPCIONES EN C++

## 🎯 ¿QUÉ SON LAS EXCEPCIONES?

Las excepciones son un **mecanismo de manejo de errores** que permite separar el **flujo normal** del programa del **flujo de manejo de errores**. Es como tener un sistema de emergencia independiente que se activa cuando algo sale mal.

### ¿Por qué usar excepciones?
- **Separación clara**: El código normal no se mezcla con el manejo de errores
- **Propagación automática**: Los errores "suben" automáticamente por la pila de llamadas
- **Destrucción segura**: Los objetos se destruyen automáticamente durante el proceso
- **Flexibilidad**: Puedes manejar errores donde sea más conveniente

---

## 🔄 FLUJO BÁSICO: DETECCIÓN → AVISO → RESPUESTA

```
┌─────────────────┐    ┌─────────────────┐    ┌─────────────────┐
│   TRY           │───▶│   THROW         │───▶│   CATCH         │
│ (DETECCIÓN)     │    │ (AVISO)         │    │ (RESPUESTA)     │
│ Vigila el código│    │ Lanza excepción │    │ Maneja el error │
└─────────────────┘    └─────────────────┘    └─────────────────┘
```

### 1. **THROW** (El que avisa)
- Lanza una excepción cuando detecta un problema
- Puede estar dentro o fuera de un bloque `try`
- Sintaxis: `throw TipoExcepcion("mensaje");`

### 2. **TRY** (El que vigila)
- Vigila el código que puede fallar
- **NO resuelve** la excepción, solo la detecta
- Pasa la excepción al bloque `catch`

### 3. **CATCH** (El que resuelve)
- Maneja la excepción lanzada por `throw`
- Debe coincidir el tipo de excepción
- Puede haber múltiples bloques `catch`

---

## 💻 SINTAXIS BÁSICA

```cpp
try {
    // Código que puede fallar
    funcionPeligrosa();
}
catch (const std::exception& e) {
    // Manejo del error
    std::cout << "Error: " << e.what() << std::endl;
}
```

---

## 🏗️ CÓMO FUNCIONA INTERNAMENTE

### 1. **En tiempo de compilación**
- El compilador crea **tablas de excepciones** (`.gcc_except_table`)
- Estas tablas dicen: "Si hay un `throw` aquí, salta a este `catch`"
- **Costo cero** en el flujo normal (no afecta rendimiento)

### 2. **En tiempo de ejecución**
Cuando ocurre un `throw`:

1. **Creación del objeto excepción**
   ```cpp
   throw std::runtime_error("Error!");
   // Se crea un objeto en memoria especial del runtime
   ```

2. **Búsqueda del handler**
   - El runtime consulta las tablas de excepciones
   - Busca un `catch` compatible en la pila de llamadas
   - Si no encuentra, continúa subiendo hasta `main`

3. **Stack Unwinding (Desenrollado de pila)**
   - **IMPORTANTE**: Antes de saltar al `catch`, se destruyen automáticamente todos los objetos locales
   - Se llaman los destructores de variables automáticas
   - Esto evita fugas de memoria

4. **Transferencia de control**
   - Salta al bloque `catch` correspondiente
   - Ejecuta el código de manejo del error

---

## 🎭 EJEMPLO PRÁCTICO: Viaje en coche

```
┌─────────────────────────────────────────────────────────────┐
│                    AUTOPISTA (TRY)                          │
│  ┌─────────────────┐    ┌─────────────────┐                │
│  │   Conduciendo   │───▶│   ACCIDENTE     │                │
│  │   normalmente   │    │   (THROW)       │                │
│  └─────────────────┘    └─────────────────┘                │
│                                │                           │
│                                ▼                           │
│  ┌─────────────────────────────────────────────────────────┐│
│  │         SALIDA DE EMERGENCIA (CATCH)                   ││
│  │  - Llamas a grúa                                       ││
│  │  - Llamas al seguro                                    ││
│  │  - Reanudas tu viaje por otra ruta                     ││
│  └─────────────────────────────────────────────────────────┘│
└─────────────────────────────────────────────────────────────┘
```

**Mientras sales de la autopista**: Recoges todas tus pertenencias del coche (destructores de objetos locales).

---

## 📋 TIPOS DE EXCEPCIONES

### Excepciones de tipos fundamentales
```cpp
try {
    throw 42;  // int
    throw 3.14; // double
    throw 'A'; // char
}
catch (int value) {
    std::cout << "Error: " << value << std::endl;
}
catch (double value) {
    std::cout << "Error: " << value << std::endl;
}
```

### Excepciones de tipos no fundamentales
```cpp
try {
    throw std::runtime_error("Error de runtime");
}
catch (const std::exception& e) {  // Por referencia constante
    std::cout << "Error: " << e.what() << std::endl;
}
```

---

## ⚠️ REGLAS IMPORTANTES

1. **No hay conversiones implícitas** en excepciones (excepto herencia)
2. **El manejo es inmediato**: Una vez ejecutado `throw`, el resto del código en el mismo bloque se salta
3. **Try y Catch van juntos**: No puedes usar uno sin el otro
4. **Stack Unwinding**: Proceso automático de limpieza de memoria

---

## 🔧 IMPLEMENTACIÓN PRÁCTICA

### Crear tu propia excepción
```cpp
class MiExcepcion : public std::exception {
private:
    std::string mensaje;
public:
    explicit MiExcepcion(const std::string& msg) : mensaje(msg) {}
    virtual const char* what() const noexcept override {
        return mensaje.c_str();
    }
};
```

### Usar tu excepción
```cpp
void funcionPeligrosa() {
    if (algo_malo) {
        throw MiExcepcion("Algo salió mal!");
    }
}

int main() {
    try {
        funcionPeligrosa();
    }
    catch (const MiExcepcion& e) {
        std::cout << "Capturado: " << e.what() << std::endl;
    }
    return 0;
}
```

---

## 🎯 RESUMEN TÉCNICO:

> "C++ implementa excepciones con un modelo zero-cost: el compilador genera tablas de excepción y el runtime usa `__cxa_throw` para iniciar el unwinding. Durante el stack unwinding se invocan los destructores de los objetos automáticos, y si se encuentra un `catch` compatible según las tablas, el control se transfiere a él; de lo contrario se invoca `std::terminate()`."

---

## 🚀 VENTAJAS Y DESVENTAJAS

### ✅ Ventajas
- Separación clara de código normal vs manejo de errores
- Propagación automática de errores
- Destrucción segura de objetos (RAII)
- No afecta rendimiento en flujo normal

### ❌ Desventajas
- Costo alto cuando se lanza excepción
- Puede ser difícil de debuggear
- Requiere disciplina en el diseño

---

## 💡 CONSEJOS PRÁCTICOS

1. **Usa excepciones para errores excepcionales**, no para control de flujo normal
2. **Captura por referencia constante** para objetos: `catch (const std::exception& e)`
3. **Usa `noexcept`** cuando sepas que una función nunca lanza excepciones
4. **Sigue RAII** para que los destructores hagan la limpieza automáticamente
5. **Documenta qué excepciones puede lanzar** cada función

---

## 🔍 MANEJO DE ERRORES EN PROGRAMACIÓN

### 📋 Tipos de errores

#### 1. **Errores sintácticos**
- Errores de **gramática** del lenguaje
- **Ejemplo**: `int x = ;` (falta valor)
- **Solución**: El compilador los detecta y **no permite compilar**

#### 2. **Errores semánticos**
- El código **compila** pero hace algo diferente a lo esperado
- **Ejemplo**: `if (x = 5)` en lugar de `if (x == 5)`
- **Solución**: Debugging y testing cuidadoso

#### 3. **Errores externos**
- Problemas **fuera del control** del programa
- **Ejemplo**: Archivo no encontrado, conexión de red perdida, memoria insuficiente
- **Solución**: Manejo de excepciones (¡esto es donde brillan!)

---

## 🎯 ESTRATEGIAS PARA MANEJAR ERRORES

### **Primera estrategia: Manejar el error donde se produce**

```cpp
void leerArchivo(const std::string& nombre) {
    std::ifstream archivo(nombre);
    if (!archivo.is_open()) {
        std::cerr << "Error: No se puede abrir " << nombre << std::endl;
        return; // Salir de la función sin afectar el resto del programa
    }
    // Continuar con la lectura...
}
```

**Ventajas:**
- Error **localizado** - no afecta otras partes
- **Fácil de debuggear**
- Usar `std::cerr` para errores (no se almacena en buffer)

**Desventajas:**
- **No siempre es posible** solucionar el error localmente
- **Información limitada** para el llamador

### **Segunda estrategia: Devolver el error al llamador**

```cpp
int dividir(int a, int b) {
    if (b == 0) {
        return -1; // Valor especial que indica error
    }
    return a / b;
}

// Problema: ¿Qué pasa si el resultado legítimo es -1?
int resultado = dividir(-10, 10); // ¿Es -1 un error o el resultado correcto?
```

**Problemas de esta estrategia:**
- **Inconsistencias**: ¿Qué valor usar para indicar error?
- **Confusión**: ¿Es -1 un error o un resultado válido?
- **Limitaciones**: No todas las funciones tienen valores "imposibles"

### **Tercera estrategia: Detener la ejecución del programa**

```cpp
void funcionCritica() {
    if (error_critico) {
        std::cerr << "Error crítico! Terminando programa..." << std::endl;
        exit(1); // Termina TODO el programa
    }
}
```

**Usar solo cuando:**
- El error es **irreparable**
- Continuar sería **peligroso**
- **Último recurso**

### **Cuarta estrategia: Lanzar una excepción** ⭐

```cpp
int dividir(int a, int b) {
    if (b == 0) {
        throw std::invalid_argument("División por cero");
    }
    return a / b;
}

int main() {
    try {
        int resultado = dividir(10, 0);
        std::cout << "Resultado: " << resultado << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
```

**Ventajas:**
- **Separación clara** entre flujo normal y manejo de errores
- **Propagación automática** por la pila de llamadas
- **Flexibilidad** para manejar errores donde sea más conveniente

---

## 🔄 PROPAGACIÓN DE PILA (STACK UNWINDING)

### ¿Qué es la propagación de pila?

Cuando se lanza una excepción, C++ **busca hacia arriba** en la pila de llamadas hasta encontrar un `catch` que pueda manejar la excepción.

```cpp
void funcionC() {
    throw std::runtime_error("Error en C");
}

void funcionB() {
    std::cout << "Entrando a B" << std::endl;
    funcionC();
    std::cout << "Saliendo de B" << std::endl; // ❌ NUNCA se ejecuta
}

void funcionA() {
    std::cout << "Entrando a A" << std::endl;
    funcionB();
    std::cout << "Saliendo de A" << std::endl; // ❌ NUNCA se ejecuta
}

int main() {
    try {
        funcionA();
    }
    catch (const std::exception& e) {
        std::cout << "Capturado en main: " << e.what() << std::endl;
    }
}
```

**Salida:**
```
Entrando a A
Entrando a B
Capturado en main: Error en C
```

### ¿Qué pasa durante la propagación?

1. **Se destruyen objetos locales** en cada función que se abandona
2. **Se llaman destructores** automáticamente (RAII)
3. **Se busca el `catch` apropiado** en cada nivel
4. **Se transfiere el control** al primer `catch` encontrado

### Ejemplo con objetos que se destruyen:

```cpp
class MiClase {
public:
    MiClase(const std::string& nombre) : _nombre(nombre) {
        std::cout << "Constructor: " << _nombre << std::endl;
    }
    ~MiClase() {
        std::cout << "Destructor: " << _nombre << std::endl;
    }
private:
    std::string _nombre;
};

void funcionConObjetos() {
    MiClase obj1("Objeto 1");
    MiClase obj2("Objeto 2");
    throw std::runtime_error("Error!");
    // obj1 y obj2 se destruyen automáticamente antes de saltar al catch
}

int main() {
    try {
        funcionConObjetos();
    }
    catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
}
```

**Salida:**
```
Constructor: Objeto 1
Constructor: Objeto 2
Destructor: Objeto 2
Destructor: Objeto 1
Error: Error!
```

---

## 📊 EXCEPCIONES POR TIPO DE DATO

### **Excepciones de tipos fundamentales** (capturadas por valor)

```cpp
try {
    throw 42;        // int
    throw 3.14;      // double
    throw 'A';       // char
}
catch (int valor) {
    std::cout << "Error entero: " << valor << std::endl;
}
catch (double valor) {
    std::cout << "Error double: " << valor << std::endl;
}
catch (char valor) {
    std::cout << "Error char: " << valor << std::endl;
}
```

**¿Por qué por valor?**
- Los tipos fundamentales son **pequeños** (int, char, double)
- **No hay destructores** que llamar
- **Copiar es barato** y rápido

### **Excepciones de tipos no fundamentales** (capturadas por referencia constante)

```cpp
try {
    throw std::string("Error de string");
    throw std::runtime_error("Error de runtime");
}
catch (const std::string& e) {
    std::cout << "Error: " << e << std::endl;
}
catch (const std::exception& e) {
    std::cout << "Error: " << e.what() << std::endl;
}
```

**¿Por qué por referencia constante?**
- **Evita copias costosas** (especialmente con objetos grandes)
- **Preserva la herencia** - puedes capturar clases derivadas
- **Mantiene la semántica** original del objeto
- **No hay slicing** (corte de información de clases derivadas)

### **Ejemplo de slicing problemático:**

```cpp
class BaseExcepcion {
public:
    virtual const char* que() const { return "Base"; }
};

class DerivadaExcepcion : public BaseExcepcion {
public:
    virtual const char* que() const override { return "Derivada"; }
};

// ❌ MAL - captura por valor causa slicing
try {
    throw DerivadaExcepcion();
}
catch (BaseExcepcion e) {  // ¡Slicing! Se pierde información de la clase derivada
    std::cout << e.que() << std::endl; // Imprime "Base" en lugar de "Derivada"
}

// ✅ BIEN - captura por referencia constante
try {
    throw DerivadaExcepcion();
}
catch (const BaseExcepcion& e) {  // Sin slicing, mantiene toda la información
    std::cout << e.que() << std::endl; // Imprime "Derivada" correctamente
}
```

---

## 🎯 RESUMEN FINAL DE MEJORES PRÁCTICAS

1. **Usa excepciones para errores excepcionales**, no para control de flujo normal
2. **Captura tipos fundamentales por valor**: `catch (int e)`
3. **Captura tipos no fundamentales por referencia constante**: `catch (const std::exception& e)`
4. **Usa `std::cerr` para mensajes de error** (no se almacena en buffer)
5. **Diseña tus excepciones** para que hereden de `std::exception`
6. **Documenta qué excepciones** puede lanzar cada función

---

## 📁 ESTE EJERCICIO: BUREAUCRAT

Este ejercicio implementa las excepciones personalizadas:
- `Bureaucrat::GradeTooHighException`
- `Bureaucrat::GradeTooLowException`

**Conceptos aplicados:**
- ✅ Forma Canónica Ortodoxa
- ✅ Excepciones personalizadas que heredan de `std::exception`
- ✅ Manejo de errores en constructores
- ✅ Propagación de excepciones en métodos
- ✅ Sobrecarga del operador `<<`

**Para compilar:**
```bash
make
```

**Para ejecutar:**
```bash
./Bureaucrat
```

---
