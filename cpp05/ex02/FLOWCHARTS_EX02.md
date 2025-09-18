# FLOWCHARTS - EJERCICIO EX02 (CPP05)

## 🔄 **FLOWCHART PRINCIPAL DEL PROGRAMA**

``` mermaid
flowchart TD
    Start([🚀 Inicio del Programa]) --> CreateB[👤 Crear Bureaucrat]
    CreateB --> CreateF[📄 Crear Form]
    CreateF --> Sign[✍️ signForm]
    
    Sign --> CheckGrade{❓ Grade suficiente?}
    CheckGrade -->|✅ Sí| SignSuccess[✅ Form firmado exitosamente]
    CheckGrade -->|❌ No| SignError[❌ GradeTooLowException]
    
    SignSuccess --> Execute[⚡ executeForm]
    Execute --> CheckSigned{❓ Form firmado?}
    CheckSigned -->|❌ No| FormError[❌ FormException]
    CheckSigned -->|✅ Sí| CheckGrade2{❓ Grade suficiente?}
    
    CheckGrade2 -->|❌ No| GradeError[❌ GradeTooLowException]
    CheckGrade2 -->|✅ Sí| ExecuteAction[🎯 Ejecutar acción específica]
    
    ExecuteAction --> Shrubbery[🌳 Crear archivo ASCII]
    ExecuteAction --> Robotomy[🤖 Robotomizar con 50% éxito]
    ExecuteAction --> Pardon[👑 Perdón presidencial]
    
    Shrubbery --> Success[🎉 Éxito - Shrubbery plantado]
    Robotomy --> Success2[🎉 Éxito - Robotomy exitoso]
    Robotomy --> Failure[💥 Fallo - Robotomy fallido]
    Pardon --> Success3[🎉 Éxito - Perdón otorgado]
    
    SignError --> End([🏁 Fin del programa])
    FormError --> End
    GradeError --> End
    Success --> End
    Success2 --> End
    Failure --> End
    Success3 --> End
```

## 🎯 **FLOWCHART DE VALIDACIONES**

```mermaid
flowchart TD
    Start([🔍 Inicio de Validaciones]) --> Input[📥 Recibir Bureaucrat y Form]
    Input --> CheckBureaucrat{❓ Bureaucrat válido?}
    
    CheckBureaucrat -->|❌ No| BureaucratError[❌ Grade < 1 o > 150]
    CheckBureaucrat -->|✅ Sí| CheckForm{❓ Form válido?}
    
    CheckForm -->|❌ No| FormError[❌ Grade < 1 o > 150]
    CheckForm -->|✅ Sí| CheckSigned{❓ Form firmado?}
    
    CheckSigned -->|❌ No| NotSigned[❌ FormException]
    CheckSigned -->|✅ Sí| CheckGrade{❓ Grade suficiente?}
    
    CheckGrade -->|❌ No| GradeError[❌ GradeTooLowException]
    CheckGrade -->|✅ Sí| Valid[✅ Todas las validaciones pasaron]
    
    BureaucratError --> End([🏁 Fin])
    FormError --> End
    NotSigned --> End
    GradeError --> End
    Valid --> End
```

## 🌳 **FLOWCHART DE SHRUBBERY CREATION FORM**

```mermaid
flowchart TD
    Start([🌳 Shrubbery Creation Form]) --> Validate[🔍 Validar form firmado y grade]
    Validate --> CheckValid{❓ Validaciones OK?}
    
    CheckValid -->|❌ No| ThrowException[❌ Lanzar excepción]
    CheckValid -->|✅ Sí| CreateFile[📁 Crear archivo _shrubbery]
    
    CreateFile --> CheckFile{❓ Archivo creado?}
    CheckFile -->|❌ No| FileError[❌ Error: No se pudo crear archivo]
    CheckFile -->|✅ Sí| WriteASCII[✍️ Escribir arte ASCII del árbol]
    
    WriteASCII --> CloseFile[🔒 Cerrar archivo]
    CloseFile --> Success[✅ Shrubbery plantado exitosamente]
    
    ThrowException --> End([🏁 Fin])
    FileError --> End
    Success --> End
```

## 🤖 **FLOWCHART DE ROBOTOMY REQUEST FORM**

```mermaid
flowchart TD
    Start([🤖 Robotomy Request Form]) --> Validate[🔍 Validar form firmado y grade]
    Validate --> CheckValid{❓ Validaciones OK?}
    
    CheckValid -->|❌ No| ThrowException[❌ Lanzar excepción]
    CheckValid -->|✅ Sí| SeedRandom[🎲 Inicializar generador aleatorio]
    
    SeedRandom --> GenerateRandom[🎯 Generar número aleatorio]
    GenerateRandom --> CheckRandom{❓ rand() % 2 == 0?}
    
    CheckRandom -->|✅ Sí| Success[✅ Robotomy exitoso]
    CheckRandom -->|❌ No| Failure[💥 Robotomy fallido]
    
    ThrowException --> End([🏁 Fin])
    Success --> End
    Failure --> End
```

## 👑 **FLOWCHART DE PRESIDENTIAL PARDON FORM**

```mermaid
flowchart TD
    Start([👑 Presidential Pardon Form]) --> Validate[🔍 Validar form firmado y grade]
    Validate --> CheckValid{❓ Validaciones OK?}
    
    CheckValid -->|❌ No| ThrowException[❌ Lanzar excepción]
    CheckValid -->|✅ Sí| PrintPardon[📢 Imprimir mensaje de perdón]
    
    PrintPardon --> Success[✅ Perdón otorgado por Zaphod Beeblebrox]
    
    ThrowException --> End([🏁 Fin])
    Success --> End
```

## 🔧 **FLOWCHART DE MANEJO DE EXCEPCIONES**

```mermaid
flowchart TD
    Start([⚠️ Manejo de Excepciones]) --> TryBlock[🔄 Bloque try]
    TryBlock --> Operation[⚡ Operación (sign/execute)]
    
    Operation --> CheckException{❓ ¿Excepción lanzada?}
    CheckException -->|❌ No| Success[✅ Operación exitosa]
    CheckException -->|✅ Sí| CatchBlock[🛡️ Bloque catch]
    
    CatchBlock --> CheckType{❓ ¿Tipo de excepción?}
    CheckType -->|GradeTooHigh| HighException[❌ GradeTooHighException]
    CheckType -->|GradeTooLow| LowException[❌ GradeTooLowException]
    CheckType -->|FormNotSigned| FormException[❌ FormException]
    
    HighException --> PrintError[📢 Imprimir mensaje de error]
    LowException --> PrintError
    FormException --> PrintError
    
    PrintError --> End([🏁 Fin])
    Success --> End
```

## 🎮 **FLOWCHART DE CASOS DE PRUEBA**

```mermaid
flowchart TD
    Start([🧪 Casos de Prueba]) --> CreateHighB[👤 Crear Bureaucrat de alto nivel]
    CreateHighB --> CreateLowB[👤 Crear Bureaucrat de bajo nivel]
    
    CreateLowB --> CreateForms[📄 Crear diferentes formularios]
    CreateForms --> TestShrubbery[🌳 Probar ShrubberyCreationForm]
    
    TestShrubbery --> TestRobotomy[🤖 Probar RobotomyRequestForm]
    TestRobotomy --> TestPardon[👑 Probar PresidentialPardonForm]
    
    TestPardon --> TestLowLevel[👤 Probar con Bureaucrat de bajo nivel]
    TestLowLevel --> TestExceptions[⚠️ Probar manejo de excepciones]
    
    TestExceptions --> TestResults[📊 Mostrar resultados]
    TestResults --> End([🏁 Fin de pruebas])
```

## 🔄 **FLOWCHART DE CICLO DE VIDA DEL FORM**

```mermaid
flowchart TD
    Start([🔄 Ciclo de Vida del Form]) --> Create[📄 Crear Form]
    Create --> Initialize[🔧 Inicializar atributos]
    Initialize --> SetUnsigned[❌ _Signed = false]
    
    SetUnsigned --> WaitForSign[⏳ Esperar a ser firmado]
    WaitForSign --> SignForm[✍️ signForm()]
    
    SignForm --> CheckGrade{❓ Grade suficiente?}
    CheckGrade -->|❌ No| SignError[❌ GradeTooLowException]
    CheckGrade -->|✅ Sí| SetSigned[✅ _Signed = true]
    
    SetSigned --> WaitForExecute[⏳ Esperar a ser ejecutado]
    WaitForExecute --> ExecuteForm[⚡ executeForm()]
    
    ExecuteForm --> CheckSigned{❓ Form firmado?}
    CheckSigned -->|❌ No| ExecuteError[❌ FormException]
    CheckSigned -->|✅ Sí| CheckGrade2{❓ Grade suficiente?}
    
    CheckGrade2 -->|❌ No| GradeError[❌ GradeTooLowException]
    CheckGrade2 -->|✅ Sí| ExecuteAction[🎯 Ejecutar acción específica]
    
    ExecuteAction --> Complete[✅ Form completado]
    
    SignError --> End([🏁 Fin])
    ExecuteError --> End
    GradeError --> End
    Complete --> End
```

## 📊 **FLOWCHART DE ARQUITECTURA DEL SISTEMA**

```mermaid
flowchart TD
    subgraph "🎯 Capa de Presentación"
        Main[📱 Main Function]
        Tests[🧪 Test Cases]
    end
    
    subgraph "🧠 Capa de Lógica de Negocio"
        BureaucratMgr[👤 Bureaucrat Manager]
        FormMgr[📄 Form Manager]
    end
    
    subgraph "💾 Capa de Acceso a Datos"
        BureaucratClass[👤 Bureaucrat Class]
        FormClass[📄 Form Class]
        ShrubberyForm[🌳 ShrubberyCreationForm]
        RobotomyForm[🤖 RobotomyRequestForm]
        PardonForm[👑 PresidentialPardonForm]
    end
    
    subgraph "🔧 Capa de Infraestructura"
        ExceptionHandling[⚠️ Exception Handling]
        FileIO[📁 File I/O]
        RandomGen[🎲 Random Generation]
    end
    
    Main --> BureaucratMgr
    Main --> FormMgr
    Tests --> BureaucratMgr
    Tests --> FormMgr
    
    BureaucratMgr --> BureaucratClass
    FormMgr --> FormClass
    FormMgr --> ShrubberyForm
    FormMgr --> RobotomyForm
    FormMgr --> PardonForm
    
    BureaucratClass --> ExceptionHandling
    FormClass --> ExceptionHandling
    ShrubberyForm --> FileIO
    RobotomyForm --> RandomGen
    PardonForm --> ExceptionHandling
```

## 🎨 **FLOWCHART DE PATRONES DE DISEÑO**

```mermaid
flowchart TD
    Start([🎨 Patrones de Diseño]) --> TemplateMethod[📋 Template Method Pattern]
    TemplateMethod --> Strategy[🎯 Strategy Pattern]
    Strategy --> RAII[🛡️ RAII Pattern]
    
    TemplateMethod --> FormBase[📄 Form (Clase Base)]
    FormBase --> DefineAlgorithm[🔧 Define algoritmo en execute()]
    DefineAlgorithm --> DerivedClasses[📄 Clases derivadas implementan]
    
    Strategy --> DifferentForms[📄 Diferentes tipos de Form]
    DifferentForms --> ShrubberyStrategy[🌳 Estrategia Shrubbery]
    DifferentForms --> RobotomyStrategy[🤖 Estrategia Robotomy]
    DifferentForms --> PardonStrategy[👑 Estrategia Pardon]
    
    RAII --> ResourceManagement[🔧 Gestión automática de recursos]
    ResourceManagement --> Destructors[🗑️ Destructores automáticos]
    Destructors --> MemorySafety[🛡️ Seguridad de memoria]
    
    ShrubberyStrategy --> End([🏁 Fin])
    RobotomyStrategy --> End
    PardonStrategy --> End
    MemorySafety --> End
```

## 📝 **INSTRUCCIONES DE USO**

### **Para ver estos flowcharts:**

1. **GitHub/GitLab**: Los diagramas se renderizan automáticamente
2. **VS Code**: Instala "Mermaid Preview" extension
3. **Mermaid Live Editor**: https://mermaid.live/
4. **Notion**: Soporte nativo para Mermaid

### **Ventajas de estos flowcharts:**

- ✅ **Visual**: Fácil de entender el flujo
- ✅ **Interactivo**: Se puede hacer zoom y navegar
- ✅ **Editable**: Fácil de modificar
- ✅ **Portable**: Funciona en múltiples plataformas
- ✅ **Versionable**: Se puede trackear en Git

### **Símbolos utilizados:**

- 🚀 **Inicio/Fin**: Puntos de entrada y salida
- ❓ **Decisión**: Puntos de decisión
- ✅ **Éxito**: Operaciones exitosas
- ❌ **Error**: Manejo de errores
- 🔄 **Proceso**: Operaciones intermedias
- 📄 **Datos**: Formularios y documentos
- 👤 **Actor**: Bureaucrat
- 🎯 **Acción**: Operaciones específicas

---

*Estos flowcharts proporcionan una representación visual completa del flujo de ejecución del ejercicio ex02, incluyendo validaciones, manejo de excepciones y patrones de diseño.*
