# DIAGRAMA UML - EJERCICIO EX02 (CPP05) - FORMATO MERMAID

## 📊 **DIAGRAMA DE CLASES PRINCIPAL**

``` mermaid
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
    Bureaucrat ..> Form : signForm()
    Bureaucrat ..> Form : executeForm()
```

## 🔄 **DIAGRAMA DE SECUENCIA**

``` mermaid
sequenceDiagram
    participant B as Bureaucrat
    participant F as Form
    participant SF as ShrubberyForm
    participant R as RobotomyForm
    participant P as PresidentialForm

    Note over B,P: Flujo de Ejecución Principal

    B->>F: signForm(form)
    F->>F: beSigned(bureaucrat)
    alt Grade suficiente
        F-->>B: Form signed successfully
    else Grade insuficiente
        F-->>B: GradeTooLowException
    end

    B->>F: executeForm(form)
    F->>SF: execute(bureaucrat)
    SF->>SF: Validar form firmado
    SF->>SF: Validar grade suficiente
    SF->>SF: Crear archivo ASCII
    SF-->>F: Shrubbery planted
    F-->>B: Form executed successfully

    Note over B,P: Ejemplo con RobotomyForm

    B->>F: executeForm(robotomyForm)
    F->>R: execute(bureaucrat)
    R->>R: Validar form firmado
    R->>R: Validar grade suficiente
    R->>R: rand() % 2 == 0
    alt 50% éxito
        R-->>F: Robotomy successful
    else 50% fallo
        R-->>F: Robotomy failed
    end
    F-->>B: Form executed
```

## 🏗️ **DIAGRAMA DE COMPONENTES**

```mermaid
graph TB
    subgraph "Main Program"
        M[Main Function]
        M --> B[Bureaucrat Manager]
        M --> F[Form Manager]
    end

    subgraph "Bureaucrat Component"
        B --> B1[High Level Bureaucrat]
        B --> B2[Low Level Bureaucrat]
        B1 --> B3[signForm method]
        B1 --> B4[executeForm method]
    end

    subgraph "Form Components"
        F --> F1[Form Base Class]
        F1 --> F2[ShrubberyCreationForm]
        F1 --> F3[RobotomyRequestForm]
        F1 --> F4[PresidentialPardonForm]
        
        F2 --> F5[File Creation Logic]
        F3 --> F6[Random Success Logic]
        F4 --> F7[Pardon Logic]
    end

    subgraph "Exception Handling"
        E1[GradeTooHighException]
        E2[GradeTooLowException]
        E3[FormException]
    end

    B3 --> E2
    B4 --> E3
    F1 --> E1
    F1 --> E2
    F1 --> E3
```

## 🔄 **DIAGRAMA DE FLUJO DE DATOS**

```mermaid
flowchart TD
    Start([Inicio del Programa]) --> CreateB[Crear Bureaucrat]
    CreateB --> CreateF[Crear Form]
    CreateF --> Sign[signForm]
    
    Sign --> CheckGrade{Grade suficiente?}
    CheckGrade -->|Sí| SignSuccess[Form firmado]
    CheckGrade -->|No| SignError[GradeTooLowException]
    
    SignSuccess --> Execute[executeForm]
    Execute --> CheckSigned{Form firmado?}
    CheckSigned -->|No| FormError[FormException]
    CheckSigned -->|Sí| CheckGrade2{Grade suficiente?}
    
    CheckGrade2 -->|No| GradeError[GradeTooLowException]
    CheckGrade2 -->|Sí| ExecuteAction[Ejecutar acción específica]
    
    ExecuteAction --> Shrubbery[Crear archivo ASCII]
    ExecuteAction --> Robotomy[Robotomizar con 50% éxito]
    ExecuteAction --> Pardon[Perdón presidencial]
    
    Shrubbery --> Success[Éxito]
    Robotomy --> Success
    Pardon --> Success
    
    SignError --> End([Fin])
    FormError --> End
    GradeError --> End
    Success --> End
```

## 🎯 **DIAGRAMA DE ESTADOS**

```mermaid
stateDiagram-v2
    [*] --> FormCreated: Crear Form
    FormCreated --> FormSigned: signForm() exitoso
    FormCreated --> FormError: signForm() fallido
    
    FormSigned --> FormExecuted: executeForm() exitoso
    FormSigned --> FormError: executeForm() fallido
    
    FormExecuted --> ShrubberyAction: ShrubberyCreationForm
    FormExecuted --> RobotomyAction: RobotomyRequestForm
    FormExecuted --> PardonAction: PresidentialPardonForm
    
    ShrubberyAction --> Success: Archivo creado
    RobotomyAction --> Success: Robotomy exitoso
    RobotomyAction --> Failure: Robotomy fallido
    PardonAction --> Success: Perdón otorgado
    
    FormError --> [*]
    Success --> [*]
    Failure --> [*]
```

## 🔗 **DIAGRAMA DE DEPENDENCIAS**

```mermaid
graph LR
    subgraph "Core Classes"
        B[Bureaucrat]
        F[Form]
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
    end
    
    B --> F
    F --> SF
    F --> RF
    F --> PF
    
    B --> STL
    SF --> IO
    RF --> RAND
    RF --> TIME
    
    F --> STL
```

## 📊 **DIAGRAMA DE CASOS DE USO**

```mermaid
graph TB
    subgraph "Actores"
        U[Usuario]
        B[Bureaucrat]
    end
    
    subgraph "Casos de Uso"
        UC1[Crear Bureaucrat]
        UC2[Crear Form]
        UC3[Firmar Form]
        UC4[Ejecutar Form]
        UC5[Manejar Excepciones]
    end
    
    subgraph "Formularios Específicos"
        UC6[Crear Shrubbery]
        UC7[Crear Robotomy]
        UC8[Crear Pardon]
    end
    
    U --> UC1
    U --> UC2
    B --> UC3
    B --> UC4
    B --> UC5
    
    UC2 --> UC6
    UC2 --> UC7
    UC2 --> UC8
    
    UC4 --> UC6
    UC4 --> UC7
    UC4 --> UC8
```

## 🎨 **DIAGRAMA DE ARQUITECTURA**

```mermaid
graph TB
    subgraph "Presentation Layer"
        M[Main Function]
        T[Test Cases]
    end
    
    subgraph "Business Logic Layer"
        BM[Bureaucrat Manager]
        FM[Form Manager]
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
    M --> FM
    T --> BM
    T --> FM
    
    BM --> B
    FM --> F
    
    B --> E
    F --> E
    F --> F
    F --> R
```

## 📝 **INSTRUCCIONES DE USO**

### **Para usar estos diagramas:**

1. **Copia el código Mermaid** de cualquier sección
2. **Pega en un editor que soporte Mermaid** como:
   - GitHub (en archivos .md)
   - GitLab
   - Notion
   - Mermaid Live Editor (https://mermaid.live/)
   - VS Code con extensión Mermaid

### **Ejemplo de uso en GitHub:**
```markdown
```mermaid
classDiagram
    class Bureaucrat {
        -const string _name
        -int _grade
        +getName() const string&
        +getGrade() int
    }
```

### **Herramientas recomendadas:**
- **Mermaid Live Editor**: https://mermaid.live/
- **VS Code**: Extensión "Mermaid Preview"
- **GitHub**: Soporte nativo en archivos .md
- **GitLab**: Soporte nativo en archivos .md

---

*Estos diagramas Mermaid proporcionan una representación visual completa del ejercicio ex02, incluyendo clases, relaciones, flujos de ejecución y arquitectura del sistema.*
