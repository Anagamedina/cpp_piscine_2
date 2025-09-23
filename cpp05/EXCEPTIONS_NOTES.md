# EXCEPCIONES EN C++ (CPP05) – FUNDAMENTOS Y USO EN EL PROYECTO

## 📚 ¿Qué es una excepción en C++?
- Una excepción representa una condición anómala que ocurre en tiempo de ejecución.
- El flujo de control se desvía mediante `throw` y se maneja con `try/catch`.
- En C++98, la especificación de excepciones para funciones que no lanzan se declara con `throw()`.

```cpp
try {
    // code that may throw
} catch (const std::exception& e) {
    std::cout << e.what() << std::endl;
}
```

## 🧩 Jerarquía estándar de excepciones (C++98)

```mermaid
classDiagram
    std::exception <|-- std::logic_error
    std::exception <|-- std::runtime_error

    std::logic_error <|-- std::domain_error
    std::logic_error <|-- std::invalid_argument
    std::logic_error <|-- std::length_error
    std::logic_error <|-- std::out_of_range

    std::runtime_error <|-- std::range_error
    std::runtime_error <|-- std::overflow_error
    std::runtime_error <|-- std::underflow_error

    class std::exception{
        +what() const char* throw()
    }
```

- Base “fundamental”: `std::exception` (todas heredan de aquí y proporcionan `what()`).
- Errores lógicos (no dependen del estado del sistema): `std::logic_error`, `std::invalid_argument`, `std::out_of_range`, etc.
- Errores de ejecución (dependen del entorno/estado): `std::runtime_error`, `std::overflow_error`, `std::underflow_error`, etc.

## 🏛️ Excepciones específicas del proyecto (CPP05)

En este proyecto definimos excepciones personalizadas dentro de las clases. Todas heredan de `std::exception` y sobreescriben `what()`.

```mermaid
classDiagram
    std::exception <|-- Bureaucrat::GradeTooHighException
    std::exception <|-- Bureaucrat::GradeTooLowException
    std::exception <|-- Form::GradeTooHighException
    std::exception <|-- Form::GradeTooLowException
    std::exception <|-- Form::FormException

    class Bureaucrat::GradeTooHighException{
        +what() const char* throw()
    }
    class Bureaucrat::GradeTooLowException{
        +what() const char* throw()
    }
    class Form::GradeTooHighException{
        +what() const char* throw()
    }
    class Form::GradeTooLowException{
        +what() const char* throw()
    }
    class Form::FormException{
        +what() const char* throw()
    }
```

- `Bureaucrat::GradeTooHighException`: se lanza cuando el grade < 1.
- `Bureaucrat::GradeTooLowException`: se lanza cuando el grade > 150 o una operación lo empeora por debajo del mínimo.
- `Form::GradeTooHighException` / `Form::GradeTooLowException`: validaciones de límites para firmar/ejecutar.
- `Form::FormException`: el formulario no está firmado (o condición contractual incumplida antes de ejecutar).

## 🔧 Cómo usamos las excepciones personalizadas

- Validamos al construir o modificar estado:
```cpp
if (grade < 1) throw GradeTooHighException();
if (grade > 150) throw GradeTooLowException();
```

- Comprobaciones previas a ejecutar formularios:
```cpp
if (!getSigned()) throw Form::FormException();
if (executor.getGrade() > getGradeToExecute()) throw Form::GradeTooLowException();
```

- Captura en los límites (métodos de `Bureaucrat`) para informar claramente:
```cpp
try {
    form.beSigned(*this);
    std::cout << _name << " signed " << form.getName() << std::endl;
} catch (const std::exception& e) {
    std::cout << _name << " couldn't sign " << form.getName()
              << " because " << e.what() << std::endl;
}
```

## 🧠 Notas técnicas (C++98)
- `what()` debe declararse como `virtual const char* what() const throw();`.
- Lanza por valor y captura por referencia constante (`catch (const X& e)`).
- Evita lanzar desde destructores; si es inevitable, captura dentro del destructor para no propagar.
- Mantén las clases de excepción ligeras (sin miembros pesados ni asignaciones dinámicas).

## 🧪 Cómo probar las excepciones
- Construye `Bureaucrat` con valores límite (1 y 150) y valores fuera de rango.
- Intenta ejecutar un `Form` sin firmar: debe lanzar `FormException`.
- Intenta ejecutar con un grade insuficiente: debe lanzar `GradeTooLowException`.
- Verifica mensajes de `what()` para que sean claros y útiles.

## ✅ Buenas prácticas
- Mensajes de `what()` cortos y claros (en inglés para coherencia con el código).
- Valida condiciones en el punto de origen (constructores, setters, operaciones críticas).
- Lanza cerca de la causa; captura en capas superiores (puntos de entrada, UI, main, o métodos “orquestadores”).
- Evita asignaciones dinámicas en rutas de manejo de errores.

## 🗂️ Archivos del proyecto relacionados
- `ex02/` y `ex03/` usan intensivamente estas excepciones.
- Revisa `Bureaucrat.hpp/.cpp`, `Form.hpp/.cpp`, y cada `...Form.hpp/.cpp` derivado para ver los lanzamientos (`throw`) y capturas (`try/catch`).
