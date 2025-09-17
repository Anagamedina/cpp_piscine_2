
## 🔄 Cambios Realizados

### **Bureaucrat.hpp**
**Antes:**
```cpp
int _grade; //del 1 al 150
//constructores
//destructores 
//setter y getters
//funciones miembro para incrementar o decrementar el grado del burocrata
//clases de excepciones
//TODO: 
//constructor que toma un mensaje y lo almacena 
//explicit MiExepcion(const std::string& msg) : mensaje(mg){}
//virtual const char* what() const noexcept override{return mensaje.c_str();}
//sobrecarga del operador de insersion (<<)
```

**Después:**
```cpp
int _grade; // Grade 1-150 (1=highest, 150=lowest)
// Constructors
// Destructor
// Getters
// Grade management (1=highest, 150=lowest)
// Exceptions
// Output operator
```

### **Bureaucrat.cpp**
**Antes:**
```cpp
//constructores
// Grado 1 es el más alto, <1 es demasiado alto
// Grado 150 es el más bajo, >150 es demasiado bajo
//implementar cualquier intento de crear un Bureaucrat con un grado invalido
//debe lanzar una excepcion
//destructor
//getter y setters
//creamos nuestras exepciones !!! TODO:
// Si ya está en grado 1 (máximo), no puede subir más
// Decrementar el número = subir de grado
// Si ya está en grado 150 (mínimo), no puede bajar más
// Incrementar el número = bajar de grado
//metodo what
//sobrecarga del operator de insertion
```

**Después:**
```cpp
// Constructors
// Grade 1 is highest, <1 is too high
// Grade 150 is lowest, >150 is too low
// Invalid grade throws exception
// Destructor
// Getters
// Grade management methods
// Already at highest grade (1)
// Decrease number = increase grade level
// Already at lowest grade (150)
// Increase number = decrease grade level
// Exception messages
// Output operator
```

### **main.cpp**
**Antes:**
```cpp
// Test 1: Crear un Bureaucrat válido
// Test 2: Incrementar grado (subir en la jerarquía)
b.incrementGrade(); // De 5 a 4
// Test 3: Decrementar grado (bajar en la jerarquía)
c.decrementGrade(); // De 149 a 150
// Test 4: Intentar crear un Bureaucrat con grado inválido (muy alto)
// Test 5: Intentar crear un Bureaucrat con grado inválido (muy bajo)
// Test 6: Intentar incrementar cuando ya está en el grado más alto
f.incrementGrade(); // Esto debería lanzar excepción
// Test 7: Intentar decrementar cuando ya está en el grado más bajo
g.decrementGrade(); // Esto debería lanzar excepción
// Test 8: Copia de Bureaucrat
```

**Después:**
```cpp
// Test 1: Create valid bureaucrat
// Test 2: Increment grade (move up hierarchy)
b.incrementGrade(); // From 5 to 4
// Test 3: Decrement grade (move down hierarchy)
c.decrementGrade(); // From 149 to 150
// Test 4: Try to create bureaucrat with invalid grade (too high)
// Test 5: Try to create bureaucrat with invalid grade (too low)
// Test 6: Try to increment when already at highest grade
f.incrementGrade(); // This should throw exception
// Test 7: Try to decrement when already at lowest grade
g.decrementGrade(); // This should throw exception
// Test 8: Copy bureaucrat
```
