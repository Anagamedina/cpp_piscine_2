# 📊 DIAGRAMA DE FLUJO - ScalarConverter (ex00)

## 🎯 Flujo Principal - Vista General

```
                        ┌─────────────┐
                        │ INICIO main │
                        └──────┬──────┘
                               │
                               ↓
                        ┌──────────────┐
                        │ argc == 2?   │
                        └──┬────────┬──┘
                           │        │
                      NO   │        │  SI
                           ↓        ↓
                    ┌────────────┐  │
                    │Error Usage │  │
                    └──────┬─────┘  │
                           │        │
                           ↓        │
                      ┌─────────┐   │
                      │   FIN   │   │
                      │  error  │   │
                      └─────────┘   │
                                    ↓
                          ┌──────────────────────┐
                          │ScalarConverter::     │
                          │    convert()         │
                          └──────────┬───────────┘
                                     │
                                     ↓
                          ┌──────────────────────┐
                          │ Detección de Tipo    │
                          └──────────┬───────────┘
                                     │
                ┌────────────────────┼────────────────────┬───────────┐
                │                    │                    │           │
                ↓                    ↓                    ↓           ↓
         ┌──────────┐         ┌──────────┐        ┌──────────┐  ┌──────────┐
         │Caso CHAR │         │Caso INT  │        │Caso FLOAT│  │Caso DOUBLE
         └────┬─────┘         └────┬─────┘        └────┬─────┘  └────┬─────┘
              │                    │                    │            │
              ↓                    ↓                    ↓            ↓
         ┌──────────┐         ┌──────────┐        ┌──────────┐  ┌──────────┐
         │Imprimir  │         │Imprimir  │        │Imprimir  │  │Imprimir  │
         │4 tipos   │         │4 tipos   │        │4 tipos   │  │4 tipos   │
         └────┬─────┘         └────┬─────┘        └────┬─────┘  └────┬─────┘
              │                    │                    │            │
              └────────────────────┴────────────────────┴────────────┘
                                     │
                                     ↓
                                ┌─────────┐
                                │   FIN   │
                                └─────────┘
```

---

## 📝 CASO 1: Detección y Conversión de CHAR

```
┌──────────────────────────────────────────────────────────────┐
│                   DETECCIÓN DE CHAR                          │
└──────────────────────────────────────────────────────────────┘

Input: literal (string)
    │
    ↓
┌─────────────────────────┐
│  checkIfChar()?         │
│  • len == 1             │
│  • isprint()            │
│  • NOT isdigit()        │
└────┬────────────┬───────┘
     │            │
   NO│            │SI
     │            ↓
     │    ┌───────────────┐
     │    │ char c =      │
     │    │ literal[0]    │
     │    └───────┬───────┘
     │            │
     │            ↓
     │    ┌───────────────┐
     │    │displayCharType│
     │    └───────┬───────┘
     │            │
     │            ↓
     │    ┌───────────────┐
     │    │displayIntType │
     │    └───────┬───────┘
     │            │
     │            ↓
     │    ┌───────────────┐
     │    │displayFloatType
     │    └───────┬───────┘
     │            │
     │            ↓
     │    ┌───────────────┐
     │    │displayDoubleType
     │    └───────┬───────┘
     │            │
     │            ↓
     │       ┌────────┐
     │       │ RETURN │
     │       └────────┘
     │
     ↓
Pasar a verificar INT
```

**Ejemplo:**
```
Input: "c"
  → checkIfChar() = SI
  → char c = 'c'
  → Imprimir:
      char:   'c'
      int:    99
      float:  99.0f
      double: 99.0
```

---

## 🔢 CASO 2: Detección y Conversión de INT

```
┌──────────────────────────────────────────────────────────────┐
│                   DETECCIÓN DE INT                           │
└──────────────────────────────────────────────────────────────┘

Input: literal (string)
    │
    ↓
┌─────────────────────────┐
│  checkIfInteger()?      │
│  • Solo dígitos         │
│  • Opcional +/- inicio  │
└────┬────────────┬───────┘
     │            │
   NO│            │SI
     │            ↓
     │    ┌───────────────┐
     │    │ long num =    │
     │    │ strtol()      │
     │    └───────┬───────┘
     │            │
     │            ↓
     │    ┌───────────────────┐
     │    │ ¿Overflow o       │
     │    │ fuera de rango?   │
     │    └───┬───────┬───────┘
     │        │       │
     │      SI│       │NO
     │        │       │
     │        ↓       ↓
     │  ┌──────────┐  ┌──────────────┐
     │  │impossible│  │ int i = num  │
     │  │para todos│  └──────┬───────┘
     │  └────┬─────┘         │
     │       │               ↓
     │       │        ┌──────────────┐
     │       │        │displayCharType
     │       │        └──────┬───────┘
     │       │               │
     │       │               ↓
     │       │        ┌──────────────┐
     │       │        │displayIntType│
     │       │        └──────┬───────┘
     │       │               │
     │       │               ↓
     │       │        ┌──────────────┐
     │       │        │displayFloatType
     │       │        └──────┬───────┘
     │       │               │
     │       │               ↓
     │       │        ┌──────────────┐
     │       │        │displayDoubleType
     │       │        └──────┬───────┘
     │       │               │
     │       ↓               ↓
     │   ┌────────┐      ┌────────┐
     │   │ RETURN │      │ RETURN │
     │   └────────┘      └────────┘
     │
     ↓
Pasar a verificar FLOAT
```

**Ejemplo:**
```
Input: "42"
  → checkIfInteger() = SI
  → long num = 42
  → Verificar overflow = NO
  → int i = 42
  → Imprimir:
      char:   '*'
      int:    42
      float:  42.0f
      double: 42.0
```

---

## 🔸 CASO 3: Detección y Conversión de FLOAT

```
┌──────────────────────────────────────────────────────────────┐
│                   DETECCIÓN DE FLOAT                         │
└──────────────────────────────────────────────────────────────┘

Input: literal (string)
    │
    ↓
┌─────────────────────────┐
│  checkIfFloatType()?    │
│  • Termina en 'f'       │
│  • O nanf/+inff/-inff   │
└────┬────────────┬───────┘
     │            │
   NO│            │SI
     │            ↓
     │    ┌───────────────────┐
     │    │ ¿Pseudoliteral?   │
     │    │ nanf/+inff/-inff  │
     │    └───┬───────┬───────┘
     │        │       │
     │      SI│       │NO
     │        │       │
     │        ↓       ↓
     │  ┌──────────┐  ┌──────────────┐
     │  │f = NaN/  │  │Quitar 'f'    │
     │  │Infinity  │  │temp = strtod │
     │  └────┬─────┘  └──────┬───────┘
     │       │               │
     │       │               ↓
     │       │        ┌──────────────┐
     │       │        │¿Error de     │
     │       │        │conversión?   │
     │       │        └──┬───────┬───┘
     │       │           │       │
     │       │         SI│       │NO
     │       │           │       │
     │       │           ↓       ↓
     │       │     ┌──────────┐  ┌──────────────┐
     │       │     │impossible│  │f = (float)temp
     │       │     │para todos│  └──────┬───────┘
     │       │     └────┬─────┘         │
     │       │          │               │
     │       └──────────┴───────────────┘
     │                  │
     │                  ↓
     │          ┌──────────────┐
     │          │displayCharType
     │          └──────┬───────┘
     │                 │
     │                 ↓
     │          ┌──────────────┐
     │          │displayIntType│
     │          └──────┬───────┘
     │                 │
     │                 ↓
     │          ┌──────────────┐
     │          │displayFloatType
     │          └──────┬───────┘
     │                 │
     │                 ↓
     │          ┌──────────────┐
     │          │displayDoubleType
     │          └──────┬───────┘
     │                 │
     │                 ↓
     │             ┌────────┐
     │             │ RETURN │
     │             └────────┘
     │
     ↓
Pasar a verificar DOUBLE
```

**Ejemplos:**
```
Input: "42.5f"
  → checkIfFloatType() = SI (termina en 'f')
  → Quitar 'f' → "42.5"
  → temp = strtod("42.5") = 42.5
  → f = (float)42.5
  → Imprimir:
      char:   '*'
      int:    42
      float:  42.5f
      double: 42.5

Input: "nanf"
  → checkIfFloatType() = SI (pseudoliteral)
  → f = quiet_NaN()
  → Imprimir:
      char:   impossible
      int:    impossible
      float:  nanf
      double: nan
```

---

## 🔹 CASO 4: Detección y Conversión de DOUBLE

```
┌──────────────────────────────────────────────────────────────┐
│                   DETECCIÓN DE DOUBLE                        │
└──────────────────────────────────────────────────────────────┘

Input: literal (string)
    │
    ↓
┌─────────────────────────┐
│  checkIfDoubleType()?   │
│  • Contiene '.'         │
│  • O nan/+inf/-inf      │
└────┬────────────┬───────┘
     │            │
   NO│            │SI
     │            ↓
     │    ┌───────────────────┐
     │    │ ¿Pseudoliteral?   │
     │    │ nan/+inf/-inf     │
     │    └───┬───────┬───────┘
     │        │       │
     │      SI│       │NO
     │        │       │
     │        ↓       ↓
     │  ┌──────────┐  ┌──────────────┐
     │  │d = NaN/  │  │d = strtod()  │
     │  │Infinity  │  └──────┬───────┘
     │  └────┬─────┘         │
     │       │               ↓
     │       │        ┌──────────────┐
     │       │        │¿Error de     │
     │       │        │conversión?   │
     │       │        └──┬───────┬───┘
     │       │           │       │
     │       │         SI│       │NO
     │       │           │       │
     │       │           ↓       │
     │       │     ┌──────────┐  │
     │       │     │impossible│  │
     │       │     │para todos│  │
     │       │     └────┬─────┘  │
     │       │          │        │
     │       └──────────┴────────┘
     │                  │
     │                  ↓
     │          ┌──────────────┐
     │          │displayCharType
     │          └──────┬───────┘
     │                 │
     │                 ↓
     │          ┌──────────────┐
     │          │displayIntType│
     │          └──────┬───────┘
     │                 │
     │                 ↓
     │          ┌──────────────┐
     │          │displayFloatType
     │          └──────┬───────┘
     │                 │
     │                 ↓
     │          ┌──────────────┐
     │          │displayDoubleType
     │          └──────┬───────┘
     │                 │
     │                 ↓
     │             ┌────────┐
     │             │ RETURN │
     │             └────────┘
     │
     ↓
Input INVÁLIDO
```

**Ejemplos:**
```
Input: "42.5"
  → checkIfDoubleType() = SI (tiene '.')
  → d = strtod("42.5") = 42.5
  → Imprimir:
      char:   '*'
      int:    42
      float:  42.5f
      double: 42.5

Input: "+inf"
  → checkIfDoubleType() = SI (pseudoliteral)
  → d = infinity()
  → Imprimir:
      char:   impossible
      int:    impossible
      float:  +inff
      double: +inf
```

---

## ❌ CASO 5: Input Inválido

```
┌──────────────────────────────────────────┐
│  Ningún tipo fue detectado               │
└──────────────────┬───────────────────────┘
                   │
                   ↓
         ┌──────────────────┐
         │outputImpossibleForAll()
         └──────────┬───────┘
                    │
                    ↓
         ┌──────────────────┐
         │ char: impossible │
         └──────────┬───────┘
                    │
                    ↓
         ┌──────────────────┐
         │ int: impossible  │
         └──────────┬───────┘
                    │
                    ↓
         ┌──────────────────┐
         │ float: impossible│
         └──────────┬───────┘
                    │
                    ↓
         ┌──────────────────┐
         │double: impossible│
         └──────────┬───────┘
                    │
                    ↓
                ┌────────┐
                │ RETURN │
                └────────┘
```

**Ejemplo:**
```
Input: "abc"
  → No es CHAR (más de 1 carácter)
  → No es INT (tiene letras)
  → No es FLOAT (no termina en 'f')
  → No es DOUBLE (no tiene '.')
  → Imprimir:
      char:   impossible
      int:    impossible
      float:  impossible
      double: impossible
```

---

## 🎯 Subflujo: displayCharType(double value)

```
displayCharType(double value)
    │
    ↓
┌─────────────────────────┐
│ ¿isnan(value) o         │
│  isinf(value)?          │
└────┬────────────┬───────┘
     │            │
   SI│            │NO
     │            ↓
     │    ┌───────────────────┐
     │    │ ¿value < 0 o      │
     │    │  value > 127?     │
     │    └────┬──────────┬───┘
     │         │          │
     │       SI│          │NO
     │         │          ↓
     │         │   ┌──────────────┐
     │         │   │char c = value│
     │         │   └──────┬───────┘
     │         │          │
     │         │          ↓
     │         │   ┌──────────────────┐
     │         │   │¿value >= 32 &&   │
     │         │   │ value <= 126?    │
     │         │   └────┬─────────┬───┘
     │         │        │         │
     │         │      SI│         │NO
     │         │        │         │
     │         │        ↓         ↓
     │         │  ┌─────────┐ ┌────────────┐
     │         │  │print 'c'│ │print Non   │
     │         │  │         │ │displayable │
     │         │  └────┬────┘ └──────┬─────┘
     │         │       │             │
     │         ↓       ↓             ↓
     │   ┌──────────┐  │             │
     │   │print     │  │             │
     │   │impossible│  │             │
     │   └────┬─────┘  │             │
     │        │        │             │
     └────────┴────────┴─────────────┘
              │
              ↓
          ┌────────┐
          │ return │
          └────────┘
```

**Ejemplos:**
```
value = 65.0        → char: 'A'
value = 10.0        → char: Non displayable
value = 200.0       → char: impossible
value = NaN         → char: impossible
value = +infinity   → char: impossible
```

---

## 🔢 Subflujo: displayIntType(double value)

```
displayIntType(double value)
    │
    ↓
┌─────────────────────────────┐
│ ¿isnan(value) o isinf(value)│
│  o fuera de rango INT?      │
└────┬────────────────┬───────┘
     │                │
   SI│                │NO
     │                ↓
     │        ┌──────────────┐
     │        │int i = value │
     │        └──────┬───────┘
     │               │
     │               ↓
     │        ┌──────────────┐
     │        │ print i      │
     │        └──────┬───────┘
     │               │
     ↓               │
┌──────────┐         │
│print     │         │
│impossible│         │
└────┬─────┘         │
     │               │
     └───────────────┘
             │
             ↓
         ┌────────┐
         │ return │
         └────────┘
```

**Ejemplos:**
```
value = 42.0        → int: 42
value = -100.0      → int: -100
value = NaN         → int: impossible
value = 9999999999  → int: impossible (overflow)
```

---

## 🔸 Subflujo: displayFloatType(float value)

```
displayFloatType(float value)
    │
    ↓
┌─────────────────┐
│ ¿isnan(value)?  │
└────┬────────┬───┘
     │        │
   SI│        │NO
     │        ↓
     │  ┌──────────────┐
     │  │¿isinf(value)?│
     │  └────┬─────┬───┘
     │       │     │
     │     SI│     │NO
     │       │     │
     │       ↓     ↓
     │  ┌────────┐ ┌──────────────┐
     │  │¿value  │ │print value   │
     │  │ > 0?   │ │con .1f       │
     │  └──┬──┬──┘ └──────┬───────┘
     │     │  │           │
     │   SI│  │NO         │
     │     │  │           │
     │     ↓  ↓           │
     │ ┌────┐ ┌────┐      │
     │ │+inff│-inff│      │
     │ └──┬─┘ └─┬──┘      │
     │    │     │         │
     ↓    │     │         │
┌────────┐│     │         │
│ nanf   ││     │         │
└───┬────┘│     │         │
    │     │     │         │
    └─────┴─────┴─────────┘
          │
          ↓
      ┌────────┐
      │ return │
      └────────┘
```

**Ejemplos:**
```
value = 42.0        → float: 42.0f
value = 3.14159     → float: 3.1f
value = NaN         → float: nanf
value = +infinity   → float: +inff
value = -infinity   → float: -inff
```

---

## 🔹 Subflujo: displayDoubleType(double value)

```
displayDoubleType(double value)
    │
    ↓
┌─────────────────┐
│ ¿isnan(value)?  │
└────┬────────┬───┘
     │        │
   SI│        │NO
     │        ↓
     │  ┌──────────────┐
     │  │¿isinf(value)?│
     │  └────┬─────┬───┘
     │       │     │
     │     SI│     │NO
     │       │     │
     │       ↓     ↓
     │  ┌────────┐ ┌──────────────┐
     │  │¿value  │ │print value   │
     │  │ > 0?   │ │con .1        │
     │  └──┬──┬──┘ └──────┬───────┘
     │     │  │           │
     │   SI│  │NO         │
     │     │  │           │
     │     ↓  ↓           │
     │ ┌────┐ ┌────┐      │
     │ │+inf│ │-inf│      │
     │ └──┬─┘ └─┬──┘      │
     │    │     │         │
     ↓    │     │         │
┌────────┐│     │         │
│  nan   ││     │         │
└───┬────┘│     │         │
    │     │     │         │
    └─────┴─────┴─────────┘
          │
          ↓
      ┌────────┐
      │ return │
      └────────┘
```

**Ejemplos:**
```
value = 42.0        → double: 42.0
value = 3.14159     → double: 3.1
value = NaN         → double: nan
value = +infinity   → double: +inf
value = -infinity   → double: -inf
```

---

## 📋 Tabla de Detección de Tipos

```
╔══════╦════════════════════╦═══════════╦═════════════════════════════════════╗
║ Ord. ║    Función         ║  Detecta  ║          Condiciones                ║
╠══════╬════════════════════╬═══════════╬═════════════════════════════════════╣
║      ║                    ║           ║                                     ║
║  1️⃣  ║ checkIfChar()      ║   CHAR    ║ • length == 1                       ║
║      ║                    ║           ║ • isprint() == true                 ║
║      ║                    ║           ║ • isdigit() == false                ║
║      ║                    ║           ║                                     ║
╠══════╬════════════════════╬═══════════╬═════════════════════════════════════╣
║      ║                    ║           ║                                     ║
║  2️⃣  ║ checkIfInteger()   ║   INT     ║ • Solo dígitos                      ║
║      ║                    ║           ║ • Opcional +/- al inicio            ║
║      ║                    ║           ║ • Al menos 1 dígito después signo   ║
║      ║                    ║           ║                                     ║
╠══════╬════════════════════╬═══════════╬═════════════════════════════════════╣
║      ║                    ║           ║                                     ║
║  3️⃣  ║ checkIfFloatType() ║   FLOAT   ║ • Termina en 'f'                    ║
║      ║                    ║           ║ • O es: nanf, +inff, -inff          ║
║      ║                    ║           ║                                     ║
╠══════╬════════════════════╬═══════════╬═════════════════════════════════════╣
║      ║                    ║           ║                                     ║
║  4️⃣  ║ checkIfDoubleType()║  DOUBLE   ║ • Contiene punto '.'                ║
║      ║                    ║           ║ • O es: nan, +inf, -inf             ║
║      ║                    ║           ║                                     ║
╠══════╬════════════════════╬═══════════╬═════════════════════════════════════╣
║      ║                    ║           ║                                     ║
║  5️⃣  ║ (ninguno)          ║ INVÁLIDO  ║ • Todo lo demás                     ║
║      ║                    ║           ║ • → impossible para todos           ║
║      ║                    ║           ║                                     ║
╚══════╩════════════════════╩═══════════╩═════════════════════════════════════╝
```

---

## 🔄 Orden de Evaluación

```
                  ┌──────────────────────┐
                  │   INPUT STRING       │
                  └──────────┬───────────┘
                             │
                             ↓
              ┌──────────────────────────┐
              │  1️⃣ checkIfChar()?       │
              └────┬─────────────────┬───┘
                   │                 │
                 SI│                 │NO
                   │                 ↓
                   │   ┌──────────────────────────┐
                   │   │  2️⃣ checkIfInteger()?    │
                   │   └────┬─────────────────┬───┘
                   │        │                 │
                   │      SI│                 │NO
                   │        │                 ↓
                   │        │   ┌──────────────────────────┐
                   │        │   │  3️⃣ checkIfFloatType()?  │
                   │        │   └────┬─────────────────┬───┘
                   │        │        │                 │
                   │        │      SI│                 │NO
                   │        │        │                 ↓
                   │        │        │   ┌──────────────────────────┐
                   │        │        │   │  4️⃣ checkIfDoubleType()? │
                   │        │        │   └────┬─────────────────┬───┘
                   │        │        │        │                 │
                   │        │        │      SI│                 │NO
                   │        │        │        │                 │
                   ↓        ↓        ↓        ↓                 ↓
              ┌────────┬────────┬────────┬────────┐    ┌──────────────┐
              │ CHAR   │  INT   │ FLOAT  │ DOUBLE │    │   INVÁLIDO   │
              └────────┴────────┴────────┴────────┘    └──────────────┘
```

**IMPORTANTE:** El primer tipo que coincide gana. Se detiene inmediatamente.

---

## 💡 Ejemplos de Ejecución Completos

### Ejemplo 1: Input = "42"

```
Input: "42"
    │
    ↓
┌──────────────────┐
│ checkIfChar()?   │
│ len==1? NO (2)   │
└────┬─────────────┘
     │ NO
     ↓
┌──────────────────┐
│checkIfInteger()? │
│ Solo dígitos? SI │
└────┬─────────────┘
     │ SI
     ↓
┌──────────────────┐
│ long num =       │
│ strtol("42")     │
│ num = 42         │
└────┬─────────────┘
     │
     ↓
┌──────────────────┐
│ Overflow? NO     │
│ int i = 42       │
└────┬─────────────┘
     │
     ↓
┌──────────────────┐
│ IMPRIMIR:        │
│ char:   '*'      │
│ int:    42       │
│ float:  42.0f    │
│ double: 42.0     │
└──────────────────┘
```

### Ejemplo 2: Input = "c"

```
Input: "c"
    │
    ↓
┌──────────────────┐
│ checkIfChar()?   │
│ len==1? SI       │
│ isprint? SI      │
│ isdigit? NO      │
└────┬─────────────┘
     │ SI
     ↓
┌──────────────────┐
│ char c = 'c'     │
└────┬─────────────┘
     │
     ↓
┌──────────────────┐
│ IMPRIMIR:        │
│ char:   'c'      │
│ int:    99       │
│ float:  99.0f    │
│ double: 99.0     │
└──────────────────┘
```

### Ejemplo 3: Input = "nanf"

```
Input: "nanf"
    │
    ↓
┌──────────────────┐
│ checkIfChar()?   │
│ len==1? NO (4)   │
└────┬─────────────┘
     │ NO
     ↓
┌──────────────────┐
│checkIfInteger()? │
│ Solo dígitos? NO │
└────┬─────────────┘
     │ NO
     ↓
┌──────────────────┐
│checkIfFloatType?│
│ == "nanf"? SI    │
└────┬─────────────┘
     │ SI
     ↓
┌──────────────────┐
│ f = quiet_NaN()  │
└────┬─────────────┘
     │
     ↓
┌──────────────────┐
│ IMPRIMIR:        │
│ char:   impossible│
│ int:    impossible│
│ float:  nanf     │
│ double: nan      │
└──────────────────┘
```

### Ejemplo 4: Input = "42.5f"

```
Input: "42.5f"
    │
    ↓
┌──────────────────┐
│ checkIfChar()?   │
│ len==1? NO (5)   │
└────┬─────────────┘
     │ NO
     ↓
┌──────────────────┐
│checkIfInteger()? │
│ Solo dígitos? NO │
│ (tiene '.' y 'f')│
└────┬─────────────┘
     │ NO
     ↓
┌──────────────────┐
│checkIfFloatType?│
│ Termina en f? SI │
└────┬─────────────┘
     │ SI
     ↓
┌──────────────────┐
│ Quitar 'f'       │
│ numStr = "42.5"  │
└────┬─────────────┘
     │
     ↓
┌──────────────────┐
│ temp = strtod()  │
│ temp = 42.5      │
└────┬─────────────┘
     │
     ↓
┌──────────────────┐
│ f = (float)temp  │
│ f = 42.5         │
└────┬─────────────┘
     │
     ↓
┌──────────────────┐
│ IMPRIMIR:        │
│ char:   '*'      │
│ int:    42       │
│ float:  42.5f    │
│ double: 42.5     │
└──────────────────┘
```

### Ejemplo 5: Input = "abc"

```
Input: "abc"
    │
    ↓
┌──────────────────┐
│ checkIfChar()?   │
│ len==1? NO (3)   │
└────┬─────────────┘
     │ NO
     ↓
┌──────────────────┐
│checkIfInteger()? │
│ Solo dígitos? NO │
└────┬─────────────┘
     │ NO
     ↓
┌──────────────────┐
│checkIfFloatType?│
│ Termina en f? NO │
│ Pseudo? NO       │
└────┬─────────────┘
     │ NO
     ↓
┌──────────────────┐
│checkIfDoubleType?│
│ Tiene '.'? NO    │
│ Pseudo? NO       │
└────┬─────────────┘
     │ NO
     ↓
┌──────────────────┐
│ INPUT INVÁLIDO   │
└────┬─────────────┘
     │
     ↓
┌──────────────────┐
│ IMPRIMIR:        │
│ char:   impossible│
│ int:    impossible│
│ float:  impossible│
│ double: impossible│
└──────────────────┘
```

---

## 📌 Pseudoliterales Especiales

```
╔════════════╦═══════════════════════════════════════╗
║   TIPO     ║        VALORES ESPECIALES             ║
╠════════════╬═══════════════════════════════════════╣
║            ║                                       ║
║  FLOAT     ║  • nanf    → Not a Number             ║
║            ║  • +inff   → Infinito positivo        ║
║            ║  • -inff   → Infinito negativo        ║
║            ║                                       ║
╠════════════╬═══════════════════════════════════════╣
║            ║                                       ║
║  DOUBLE    ║  • nan     → Not a Number             ║
║            ║  • +inf    → Infinito positivo        ║
║            ║  • -inf    → Infinito negativo        ║
║            ║                                       ║
╚════════════╩═══════════════════════════════════════╝
```

---

## 📊 Mensajes de Salida Posibles

```
╔══════════╦════════════════════════╦═══════════════════════════╗
║   TIPO   ║      SITUACIÓN         ║         MENSAJE           ║
╠══════════╬════════════════════════╬═══════════════════════════╣
║          ║                        ║                           ║
║          ║ Imprimible [32-126]    ║ 'c' (entre comillas)      ║
║  CHAR    ║ No imprimible [0-31]   ║ Non displayable           ║
║          ║ NaN, ∞, fuera rango    ║ impossible                ║
║          ║                        ║                           ║
╠══════════╬════════════════════════╬═══════════════════════════╣
║          ║                        ║                           ║
║   INT    ║ Valor válido           ║ Número entero (42)        ║
║          ║ NaN, ∞, overflow       ║ impossible                ║
║          ║                        ║                           ║
╠══════════╬════════════════════════╬═══════════════════════════╣
║          ║                        ║                           ║
║          ║ Número normal          ║ 42.0f (precisión .1)      ║
║  FLOAT   ║ NaN                    ║ nanf                      ║
║          ║ +Infinito              ║ +inff                     ║
║          ║ -Infinito              ║ -inff                     ║
║          ║                        ║                           ║
╠══════════╬════════════════════════╬═══════════════════════════╣
║          ║                        ║                           ║
║          ║ Número normal          ║ 42.0 (precisión .1)       ║
║  DOUBLE  ║ NaN                    ║ nan                       ║
║          ║ +Infinito              ║ +inf                      ║
║          ║ -Infinito              ║ -inf                      ║
║          ║                        ║                           ║
╚══════════╩════════════════════════╩═══════════════════════════╝
```

---

## 🔑 Puntos Clave del Algoritmo

```
┌────────────────────────────────────────────────────────────────┐
│                    CARACTERÍSTICAS CLAVE                       │
├────────────────────────────────────────────────────────────────┤
│                                                                │
│  1. Detección Secuencial                                      │
│     ───────────────────────────────────────────────────────   │
│     • Se prueba cada tipo en orden: CHAR → INT → FLOAT →     │
│       DOUBLE → INVÁLIDO                                       │
│     • Primera coincidencia gana (no sigue probando)           │
│                                                                │
│  2. Conversión a Double Intermedio                            │
│     ───────────────────────────────────────────────────────   │
│     • Para imprimir usa static_cast<double> en la mayoría     │
│       de funciones display                                    │
│                                                                │
│  3. Manejo de Errores                                         │
│     ───────────────────────────────────────────────────────   │
│     • Usa errno y ERANGE para detectar overflows              │
│     • Valida rangos para cada tipo                            │
│                                                                │
│  4. Precisión Fija                                            │
│     ───────────────────────────────────────────────────────   │
│     • Siempre imprime con 1 decimal (.1)                      │
│     • Formato: 42.0f (float), 42.0 (double)                   │
│                                                                │
│  5. Clase Estática                                            │
│     ───────────────────────────────────────────────────────   │
│     • No se pueden crear instancias de ScalarConverter        │
│     • Constructor privado                                     │
│     • Solo método estático: convert()                         │
│                                                                │
└────────────────────────────────────────────────────────────────┘
```

---

**Autor**: ScalarConverter - CPP Module 06 - ex00  
**Fecha**: Octubre 2025  
**Nota**: Todos los diagramas usan ASCII art para máxima compatibilidad
