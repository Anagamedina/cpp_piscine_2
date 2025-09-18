# DIAGRAMA UML - EJERCICIO EX03 (CPP05) - INTERN Y FACTORY METHOD

## 📊 **DIAGRAMA DE CLASES PRINCIPAL**

```mermaid
classDiagram
    class Bureaucrat {
        -const string _name
        -int _grade
        +Bureaucrat()
        +Bureaucrat(string name, int grade)
        +Bureaucrat(const Bureaucrat&)
        +operator=(const Bureaucrat&) Bureaucrat&
        +~Bureaucrat()
        +getName() const string&
        +getGrade() int
        +incrementGrade() void
        +decrementGrade() void
        +signForm(Form& form) void
        +executeForm(const Form& form) void
        +GradeTooHighException
        +GradeTooLowException
    }

    class Form {
        <<abstract>>
        -const string _name
        -bool _Signed
        -const int _gradeToSign
        -const int _gradeToExecute
        +Form(string name, int gradeToSign, int gradeToExecute)
        +Form(const Form&)
        +operator=(const Form&) Form&
        +~Form()
        +getName() const string&
        +getSigned() bool
        +getGradeToSign() int
        +getGradeToExecute() int
        +beSigned(const Bureaucrat&) void
        +execute(const Bureaucrat&) void*
        +GradeTooHighException
        +GradeTooLowException
        +FormException
    }

    class Intern {
        +Intern()
        +Intern(const Intern&)
        +operator=(const Intern&) Intern&
        +~Intern()
        +makeForm(string formName, string target) Form*
        -createShrubberyForm(string target) Form*
        -createRobotomyForm(string target) Form*
        -createPresidentialForm(string target) Form*
    }

    class ShrubberyCreationForm {
        -string _target
        +ShrubberyCreationForm()
        +ShrubberyCreationForm(const string& target)
        +ShrubberyCreationForm(const ShrubberyCreationForm&)
        +operator=(const ShrubberyCreationForm&) ShrubberyCreationForm&
        +~ShrubberyCreationForm()
        +execute(const Bureaucrat&) void
    }

    class RobotomyRequestForm {
        -string _target
        +RobotomyRequestForm()
        +RobotomyRequestForm(const string& target)
        +RobotomyRequestForm(const RobotomyRequestForm&)
        +operator=(const RobotomyRequestForm&) RobotomyRequestForm&
        +~RobotomyRequestForm()
        +execute(const Bureaucrat&) void
    }

    class PresidentialPardonForm {
        -string _target
        +PresidentialPardonForm()
        +PresidentialPardonForm(const string& target)
        +PresidentialPardonForm(const PresidentialPardonForm&)
        +operator=(const PresidentialPardonForm&) PresidentialPardonForm&
        +~PresidentialPardonForm()
        +execute(const Bureaucrat&) void
    }

    %% Relaciones de herencia
    Form <|-- ShrubberyCreationForm
    Form <|-- RobotomyRequestForm
    Form <|-- PresidentialPardonForm

    %% Relaciones de uso
    Bureaucrat --> Form : uses
    Intern --> Form : creates
    Intern ..> ShrubberyCreationForm : creates
    Intern ..> RobotomyRequestForm : creates
    Intern ..> PresidentialPardonForm : creates
```

## 🔄 **DIAGRAMA DE SECUENCIA - INTERN WORKFLOW**

```mermaid
sequenceDiagram
    participant M as Main
    participant I as Intern
    participant F as Form
    participant B as Bureaucrat
    participant SF as ShrubberyForm
    participant R as RobotomyForm
    participant P as PresidentialForm

    Note over M,P: Intern Factory Method Workflow

    M->>I: makeForm("shrubbery creation", "garden")
    I->>I: Search formNames array
    I->>I: Find matching form type
    I->>SF: createShrubberyForm("garden")
    SF-->>I: new ShrubberyCreationForm
    I-->>M: Form* shrubbery

    M->>B: signForm(*shrubbery)
    B->>F: beSigned(bureaucrat)
    F-->>B: Form signed
    B-->>M: Form signed successfully

    M->>B: executeForm(*shrubbery)
    B->>F: execute(bureaucrat)
    F->>SF: execute(bureaucrat)
    SF->>SF: Validate form signed
    SF->>SF: Validate bureaucrat grade
    SF->>SF: Create ASCII file
    SF-->>F: Shrubbery planted
    F-->>B: Form executed
    B-->>M: Form executed successfully

    Note over M,P: Unknown Form Type

    M->>I: makeForm("unknown form", "target")
    I->>I: Search formNames array
    I->>I: No matching form found
    I-->>M: NULL (unknown form type)
```

## 🏗️ **DIAGRAMA DE COMPONENTES - INTERN ARCHITECTURE**

```mermaid
graph TB
    subgraph "Main Program"
        M[Main Function]
        M --> B[Bureaucrat Manager]
        M --> I[Intern Manager]
    end

    subgraph "Intern Component"
        I --> I1[makeForm method]
        I1 --> I2[Form Name Array]
        I1 --> I3[Form Creator Array]
        I2 --> I4[shrubbery creation]
        I2 --> I5[robotomy request]
        I2 --> I6[presidential pardon]
        I3 --> I7[createShrubberyForm]
        I3 --> I8[createRobotomyForm]
        I3 --> I9[createPresidentialForm]
    end

    subgraph "Form Components"
        F[Form Base Class]
        F --> F1[ShrubberyCreationForm]
        F --> F2[RobotomyRequestForm]
        F --> F3[PresidentialPardonForm]
        
        F1 --> F4[File Creation Logic]
        F2 --> F5[Random Success Logic]
        F3 --> F6[Pardon Logic]
    end

    subgraph "Bureaucrat Component"
        B --> B1[High Level Bureaucrat]
        B --> B2[Low Level Bureaucrat]
        B1 --> B3[signForm method]
        B1 --> B4[executeForm method]
    end

    I7 --> F1
    I8 --> F2
    I9 --> F3
    B3 --> F
    B4 --> F
```

## 🔄 **DIAGRAMA DE FLUJO - INTERN FACTORY METHOD**

```mermaid
flowchart TD
    Start([🚀 makeForm called]) --> Input[📥 Receive formName and target]
    Input --> Search[🔍 Search formNames array]
    Search --> CheckMatch{❓ Form name found?}
    
    CheckMatch -->|✅ Yes| GetIndex[📍 Get array index]
    CheckMatch -->|❌ No| UnknownForm[❌ Unknown form type]
    
    GetIndex --> CallCreator[🎯 Call formCreators[index]]
    CallCreator --> CreateForm[📄 Create specific form]
    
    CreateForm --> Shrubbery[🌳 ShrubberyCreationForm]
    CreateForm --> Robotomy[🤖 RobotomyRequestForm]
    CreateForm --> Pardon[👑 PresidentialPardonForm]
    
    Shrubbery --> Success[✅ Form created successfully]
    Robotomy --> Success
    Pardon --> Success
    
    UnknownForm --> PrintError[📢 Print error message]
    PrintError --> ReturnNull[🔙 Return NULL]
    
    Success --> PrintSuccess[📢 Print success message]
    PrintSuccess --> ReturnForm[🔙 Return Form*]
    
    ReturnNull --> End([🏁 End])
    ReturnForm --> End
```

## 🎯 **DIAGRAMA DE ESTADOS - FORM LIFECYCLE WITH INTERN**

```mermaid
stateDiagram-v2
    [*] --> InternCreated: Create Intern
    InternCreated --> FormRequested: makeForm() called
    FormRequested --> FormCreated: Form creation successful
    FormRequested --> FormError: Unknown form type
    
    FormCreated --> FormSigned: signForm() called
    FormCreated --> FormError: Invalid form type
    
    FormSigned --> FormExecuted: executeForm() called
    FormSigned --> FormError: Grade insufficient
    
    FormExecuted --> ShrubberyAction: ShrubberyCreationForm
    FormExecuted --> RobotomyAction: RobotomyRequestForm
    FormExecuted --> PardonAction: PresidentialPardonForm
    
    ShrubberyAction --> Success: File created
    RobotomyAction --> Success: Robotomy successful
    RobotomyAction --> Failure: Robotomy failed
    PardonAction --> Success: Pardon granted
    
    FormError --> [*]
    Success --> [*]
    Failure --> [*]
```

## 🔗 **DIAGRAMA DE DEPENDENCIAS - INTERN SYSTEM**

```mermaid
graph LR
    subgraph "Core Classes"
        B[Bureaucrat]
        F[Form]
        I[Intern]
    end
    
    subgraph "Form Implementations"
        SF[ShrubberyCreationForm]
        RF[RobotomyRequestForm]
        PF[PresidentialPardonForm]
    end
    
    subgraph "Standard Library"
        STL[std::exception]
        IO[std::ofstream]
        RAND[std::rand]
        TIME[std::time]
        STRING[std::string]
    end
    
    I --> F
    I --> SF
    I --> RF
    I --> PF
    B --> F
    F --> SF
    F --> RF
    F --> PF
    
    B --> STL
    SF --> IO
    RF --> RAND
    RF --> TIME
    I --> STRING
    F --> STL
```

## 📊 **DIAGRAMA DE CASOS DE USO - INTERN SYSTEM**

```mermaid
graph TB
    subgraph "Actores"
        U[Usuario]
        B[Bureaucrat]
        I[Intern]
    end
    
    subgraph "Casos de Uso Principales"
        UC1[Crear Intern]
        UC2[Crear Formulario]
        UC3[Firmar Formulario]
        UC4[Ejecutar Formulario]
        UC5[Manejar Formularios Desconocidos]
    end
    
    subgraph "Formularios Específicos"
        UC6[Crear Shrubbery]
        UC7[Crear Robotomy]
        UC8[Crear Pardon]
    end
    
    U --> UC1
    U --> UC2
    I --> UC2
    B --> UC3
    B --> UC4
    I --> UC5
    
    UC2 --> UC6
    UC2 --> UC7
    UC2 --> UC8
    
    UC4 --> UC6
    UC4 --> UC7
    UC4 --> UC8
```

## 🎨 **DIAGRAMA DE ARQUITECTURA - INTERN PATTERN**

```mermaid
graph TB
    subgraph "Presentation Layer"
        M[Main Function]
        T[Test Cases]
    end
    
    subgraph "Business Logic Layer"
        BM[Bureaucrat Manager]
        IM[Intern Manager]
        FM[Form Manager]
    end
    
    subgraph "Factory Layer"
        I[Intern Class]
        FC[Form Creators]
        FA[Form Array]
    end
    
    subgraph "Data Access Layer"
        F[Form Classes]
        B[Bureaucrat Class]
    end
    
    subgraph "Infrastructure Layer"
        E[Exception Handling]
        F[File I/O]
        R[Random Generation]
    end
    
    M --> BM
    M --> IM
    M --> FM
    T --> BM
    T --> IM
    T --> FM
    
    BM --> B
    IM --> I
    FM --> F
    
    I --> FC
    I --> FA
    FC --> F
    
    B --> E
    F --> E
    F --> F
    F --> R
```

## 🎯 **DIAGRAMA DE PATRONES DE DISEÑO**

```mermaid
graph TB
    subgraph "Factory Method Pattern"
        FM[Factory Method]
        FM --> FC[Form Creators]
        FC --> F1[ShrubberyCreator]
        FC --> F2[RobotomyCreator]
        FC --> F3[PardonCreator]
    end
    
    subgraph "Template Method Pattern"
        TM[Template Method]
        TM --> F[Form Base]
        F --> F1[ShrubberyForm]
        F --> F2[RobotomyForm]
        F --> F3[PardonForm]
    end
    
    subgraph "Strategy Pattern"
        SP[Strategy Pattern]
        SP --> S1[Shrubbery Strategy]
        SP --> S2[Robotomy Strategy]
        SP --> S3[Pardon Strategy]
    end
    
    subgraph "RAII Pattern"
        RAII[RAII Pattern]
        RAII --> R1[Automatic Memory Management]
        RAII --> R2[Resource Cleanup]
    end
    
    FM --> TM
    TM --> SP
    SP --> RAII
```

## 📝 **INSTRUCCIONES DE USO**

### **Para ver estos diagramas:**

1. **GitHub/GitLab**: Los diagramas se renderizan automáticamente
2. **VS Code**: Instala "Mermaid Preview" extension
3. **Mermaid Live Editor**: https://mermaid.live/
4. **Notion**: Soporte nativo para Mermaid

### **Ventajas de estos diagramas:**

- ✅ **Visual**: Fácil de entender la arquitectura
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
- 🏭 **Factory**: Intern como factory

---

*Estos diagramas UML proporcionan una representación visual completa del ejercicio ex03, incluyendo el patrón Factory Method, la clase Intern, y todas las relaciones entre componentes.*
