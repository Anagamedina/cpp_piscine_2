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





