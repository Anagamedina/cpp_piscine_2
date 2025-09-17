# Apuntes - Ex01: Form y Bureaucrat

## 📋 Conceptos Clave del Ejercicio 01

### 1. **Clase Form (Formulario)**
La clase `Form` representa un documento que puede ser firmado por un burócrata. Es el concepto central de este ejercicio.

#### **Atributos de Form:**
- `_name`: Nombre del formulario (constante)
- `_signed`: Estado de firma (true/false)
- `_gradeToSign`: Grado mínimo requerido para firmar
- `_gradeToExecute`: Grado mínimo requerido para ejecutar

#### **Concepto Importante:**
- **Grado 1 = Máximo nivel** (más alto)
- **Grado 150 = Mínimo nivel** (más bajo)
- Un burócrata con grado 5 puede firmar un formulario que requiere grado 10, pero NO puede firmar uno que requiere grado 3.

### 2. **Relación entre Bureaucrat y Form**

```
Bureaucrat (Grado 5) → Puede firmar → Form (requiere grado 10)
Bureaucrat (Grado 5) → NO puede firmar → Form (requiere grado 3)
```

#### **Lógica de Firma:**
```cpp
if (bureaucrat.getGrade() <= form.getGradeToSign()) {
    // Puede firmar
    form.setSigned(true);
} else {
    // No puede firmar - lanzar excepción
    throw GradeTooLowException();
}
```

### 3. **Manejo de Excepciones**

#### **Excepciones en Form:**
- `GradeTooHighException`: Cuando se intenta crear un Form con grado < 1
- `GradeTooLowException`: Cuando se intenta crear un Form con grado > 150 o cuando un burócrata no tiene suficiente grado para firmar

#### **Patrón de Excepciones:**
```cpp
class GradeTooHighException : public std::exception {
public:
    virtual const char* what() const throw() {
        return "Grade is too high!";
    }
};
```

### 4. **Conceptos de Programación Orientada a Objetos**

#### **Encapsulación:**
- Atributos privados con getters públicos
- Validación en constructores y métodos

#### **Constantes:**
- `_name`, `_gradeToSign`, `_gradeToExecute` son constantes
- Solo `_signed` puede cambiar después de la creación

#### **Sobrecarga de Operadores:**
- `operator<<` para imprimir información del Form

### 5. **Flujo de Trabajo Típico**

1. **Crear un Form:**
   ```cpp
   Form form("Contrato", 10, 5); // Requiere grado 10 para firmar, grado 5 para ejecutar
   ```

2. **Crear un Bureaucrat:**
   ```cpp
   Bureaucrat bob("Bob", 8); // Bob tiene grado 8
   ```

3. **Intentar firmar:**
   ```cpp
   try {
       form.beSigned(bob); // Bob (grado 8) puede firmar (requiere grado 10)
       std::cout << "Formulario firmado exitosamente!" << std::endl;
   } catch (const std::exception& e) {
       std::cout << "Error: " << e.what() << std::endl;
   }
   ```

### 6. **Diferencias Clave con Ex00**

- **Ex00**: Solo manejaba Bureaucrat con sus grados
- **Ex01**: Introduce Form y la **interacción** entre Bureaucrat y Form
- **Nueva funcionalidad**: Sistema de firma con validación de grados
- **Nuevas excepciones**: Específicas para el proceso de firma

### 7. **Puntos Importantes a Recordar**

1. **Validación en Constructor**: El Form debe validar que los grados estén entre 1-150
2. **Método beSigned()**: Debe verificar si el burócrata tiene suficiente grado
3. **Excepciones**: Deben ser lanzadas en casos de error, no devolver valores
4. **Constantes**: Los grados no pueden cambiar después de la creación
5. **Estado**: Solo el estado de firma puede cambiar

### 8. **Ejemplo de Uso Completo**

```cpp
int main() {
    try {
        // Crear formulario que requiere grado 10 para firmar
        Form contract("Contrato de Trabajo", 10, 5);
        
        // Crear burócrata con grado 8
        Bureaucrat manager("Manager", 8);
        
        std::cout << contract << std::endl;
        std::cout << manager << std::endl;
        
        // Intentar firmar
        contract.beSigned(manager);
        std::cout << "¡Formulario firmado!" << std::endl;
        
    } catch (const std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    
    return 0;
}
```

## 🎯 Objetivo del Ejercicio

El objetivo es entender:
- **Composición de clases**: Cómo una clase puede usar otra
- **Validación de datos**: Cómo asegurar que los datos sean correctos
- **Manejo de excepciones**: Cómo manejar errores de forma elegante
- **Encapsulación**: Cómo proteger los datos internos de una clase
- **Interacción entre objetos**: Cómo los objetos pueden trabajar juntos
