# 📚 EXCEPCIONES EN C++ - APUNTES MEJORADOS

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

## 🎯 RESUMEN TÉCNICO PARA ENTREVISTAS

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

*Estos apuntes te ayudarán a entender mejor el sistema de excepciones de C++ y aplicarlo correctamente en tus proyectos.*
