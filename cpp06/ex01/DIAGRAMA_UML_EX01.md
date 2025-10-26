# 📐 DIAGRAMAS UML - Serializer (ex01)

## 🏗️ Diagrama de Clases

```
┌─────────────────────────────┐
│       <<struct>>            │
│          Data               │
├─────────────────────────────┤
│  + int numero               │
│  + char letra               │
│  + float decimal            │
└─────────────────────────────┘
              △
              │
              │ uses
              │
┌─────────────────────────────┐
│    <<static class>>         │
│       Serializer            │
├─────────────────────────────┤
│  - Serializer()             │
│  - Serializer(const &)      │
│  - operator=(const &)       │
│  - ~Serializer()            │
├─────────────────────────────┤
│  + serialize(Data*): ulong  │
│  + deserialize(ulong): Data*│
└─────────────────────────────┘
```

**Explicación:**
- `Data`: Estructura simple con 3 campos (numero, letra, decimal)
- `Serializer`: Clase estática - no se puede instanciar
  - Constructor privado (-)
  - Métodos públicos estáticos (+): `serialize()` y `deserialize()`

---

## 🔄 Flujo Completo de Serialización

```
┌─────────────┐   serialize    ┌──────────────┐   deserialize   ┌─────────────┐
│ Objeto Data │──────────────→ │    Número    │───────────────→ │ Puntero al  │
│ en memoria  │   (puntero →   │ unsigned long│  (número →      │mismo objeto │
│ {42,'A',3.14}  número)       │ 14073479...  │   puntero)      │ Data        │
└─────────────┘                └──────────────┘                 └─────────────┘
      ↑                                                                 │
      │                                                                 │
      └─────────────────────────────────────────────────────────────────┘
                    Ambos punteros apuntan al mismo objeto
```

---

## 📍 PASO 1: Crear Objeto Data

```
                    MEMORIA RAM
        ┌─────────────────────────────────┐
        │  Dirección: 0x7fff5fbff8a0      │
        ├─────────────────────────────────┤
        │  +0x0:  numero  = 42    (int)   │
        │  +0x4:  letra   = 'A'   (char)  │
        │  +0x5:          [padding]       │
        │  +0x8:  decimal = 3.14  (float) │
        └─────────────────────────────────┘
                       ↑
                       │
            ┌──────────┴──────────┐
            │   Data original     │
            │ (variable en stack) │
            └─────────────────────┘
```

**Código:**
```cpp
Data original;
original.numero = 42;
original.letra = 'A';
original.decimal = 3.14;
```

---

## 📤 PASO 2: Serialización (Puntero → Número)

```
ANTES                           DURANTE                      DESPUÉS
                                                         
┌──────────────┐               ┌──────────────┐         ┌──────────────┐
│ Data* ptr    │               │  Serializer  │         │ unsigned long│
│              │──────────────→│  ::serialize │────────→│  serializado │
│0x7fff5fbff8a0│  (puntero)    │              │ (número)│              │
│              │               │reinterpret_  │         │140734799814816
│              │               │    cast      │         │              │
└──────────────┘               └──────────────┘         └──────────────┘
    (tipo: Data*)                                          (tipo: unsigned long)
```

**Conversión detallada:**
```
ENTRADA:  Data* ptr = 0x7fff5fbff8a0
                ↓
          reinterpret_cast<unsigned long>(ptr)
                ↓
SALIDA:   unsigned long = 140734799814816

NOTA: 0x7fff5fbff8a0 (hexadecimal) = 140734799814816 (decimal)
```

**Código:**
```cpp
Data* ptr = &original;                          // 0x7fff5fbff8a0
unsigned long serializado = Serializer::serialize(ptr);
// serializado = 140734799814816
```

---

## 📥 PASO 3: Deserialización (Número → Puntero)

```
ANTES                           DURANTE                      DESPUÉS
                                                         
┌──────────────┐               ┌──────────────┐         ┌──────────────┐
│ unsigned long│               │  Serializer  │         │  Data* ptr   │
│ serializado  │──────────────→│ ::deserialize│────────→│  restaurado  │
│              │  (número)     │              │(puntero)│              │
│140734799814816               │reinterpret_  │         │0x7fff5fbff8a0│
│              │               │    cast      │         │              │
└──────────────┘               └──────────────┘         └──────────────┘
  (tipo: unsigned long)                                    (tipo: Data*)
```

**Conversión detallada:**
```
ENTRADA:  unsigned long = 140734799814816
                ↓
          reinterpret_cast<Data*>(raw)
                ↓
SALIDA:   Data* = 0x7fff5fbff8a0

NOTA: 140734799814816 (decimal) = 0x7fff5fbff8a0 (hexadecimal)
```

**Código:**
```cpp
unsigned long num = 140734799814816;
Data* restaurado = Serializer::deserialize(num);
// restaurado = 0x7fff5fbff8a0
```

---

## ✅ PASO 4: Verificación

```
        ┌──────────────────┐         ┌──────────────────┐
        │  &original       │         │  restaurado      │
        │  = 0x7fff5fbff8a0│         │  = 0x7fff5fbff8a0│
        └────────┬─────────┘         └────────┬─────────┘
                 │                            │
                 └────────────┬───────────────┘
                              ↓
                    ┌─────────────────┐
                    │ ¿Son iguales?   │
                    │                 │
                    │  restaurado ==  │
                    │   &original     │
                    └────────┬────────┘
                             ↓
                          ┌─────┐
                          │ SÍ! │
                          └─────┘
                             ↓
                   Apuntan al mismo objeto
                             ↓
                    ┌─────────────────┐
                    │   MEMORIA RAM   │
                    │ 0x7fff5fbff8a0  │
                    │                 │
                    │ numero:  42     │
                    │ letra:   'A'    │
                    │ decimal: 3.14   │
                    └─────────────────┘
```

**Código:**
```cpp
if (restaurado == &original) {
    std::cout << "✓ ÉXITO: Apuntan al mismo objeto" << std::endl;
    std::cout << restaurado->numero;   // 42
    std::cout << restaurado->letra;    // 'A'
    std::cout << restaurado->decimal;  // 3.14
}
```

---

## 🔄 Diagrama de Secuencia Completo

```
main()          Serializer                    Memoria
  │                 │                            │
  ├────────────────────────────────────────────→ │
  │   Crear Data original {42, 'A', 3.14}       │
  │                 │                            │
  │ ←──────────────────────────────────────────┤ │
  │        Objeto en dirección 0x7fff5fbff8a0   │
  │                 │                            │
  │                 │                            │
  ├───────────────→ │                            │
  │ serialize(&original)                        │
  │                 │                            │
  │                 ├─────────┐                  │
  │                 │ reinterpret_cast           │
  │                 │ Data* → unsigned long      │
  │                 ├─────────┘                  │
  │                 │                            │
  │ ←──────────────┤                            │
  │    140734799814816                          │
  │                 │                            │
  │                 │                            │
  ├───────────────→ │                            │
  │ deserialize(140734799814816)                │
  │                 │                            │
  │                 ├─────────┐                  │
  │                 │ reinterpret_cast           │
  │                 │ unsigned long → Data*      │
  │                 ├─────────┘                  │
  │                 │                            │
  │ ←──────────────┤                            │
  │  Data* = 0x7fff5fbff8a0                     │
  │                 │                            │
  │                 │                            │
  ├────────────────────────────────────────────→ │
  │  restaurado->numero                         │
  │                 │                            │
  │ ←──────────────────────────────────────────┤ │
  │              42                              │
  │                 │                            │
```

---

## 🧠 Visualización Completa de Memoria

```
═══════════════════════════════════════════════════════════════
                         MEMORIA RAM
═══════════════════════════════════════════════════════════════

  Dirección: 0x7fff5fbff8a0
  ┌─────────────────────────────────────────────┐
  │  Offset  │  Campo   │  Valor    │  Tipo     │
  ├──────────┼──────────┼───────────┼───────────┤
  │  +0x0    │  numero  │    42     │   int     │
  │  +0x4    │  letra   │   'A'     │   char    │
  │  +0x5    │ (padding)│    ---    │    ---    │
  │  +0x8    │  decimal │   3.14    │   float   │
  └─────────────────────────────────────────────┘
           ↑              ↑              ↑
           │              │              │
           │              │              │
  ┌────────┴───────┬──────┴────────┬────┴──────────┐
  │                │               │               │
  │  &original     │  ptr          │  restaurado   │
  │  (original)    │  (antes)      │  (después)    │
  │                │               │               │
  │ Data* =        │ Data* =       │ Data* =       │
  │ 0x7fff5fbff8a0 │ 0x7fff5fbff8a0│ 0x7fff5fbff8a0│
  └────────────────┴───────────────┴───────────────┘
                           │
                           │ serialize/deserialize
                           ↓
                 ┌──────────────────┐
                 │   serializado    │
                 │                  │
                 │ unsigned long =  │
                 │ 140734799814816  │
                 └──────────────────┘

NOTA: Todos los punteros apuntan a la MISMA ubicación en memoria
```

---

## 📊 Tabla de Conversión Paso a Paso

```
╔════════════╦════════════════╦═══════════════════╦═══════════════════════════╗
║   PASO     ║   VARIABLE     ║       TIPO        ║          VALOR            ║
╠════════════╬════════════════╬═══════════════════╬═══════════════════════════╣
║            ║                ║                   ║                           ║
║    1       ║  original      ║  Data             ║  {42, 'A', 3.14}          ║
║            ║                ║                   ║  en 0x7fff5fbff8a0        ║
║────────────╫────────────────╫───────────────────╫───────────────────────────╢
║            ║                ║                   ║                           ║
║    2       ║  &original     ║  Data*            ║  0x7fff5fbff8a0           ║
║            ║                ║  (puntero)        ║  (hexadecimal)            ║
║────────────╫────────────────╫───────────────────╫───────────────────────────╢
║            ║                ║                   ║  ┌──────────────────────┐ ║
║    3       ║  serializado   ║  unsigned long    ║  │ 140734799814816      │ ║
║            ║                ║  (número)         ║  │ (decimal)            │ ║
║            ║                ║                   ║  │                      │ ║
║            ║                ║                   ║  │ = 0x7fff5fbff8a0     │ ║
║            ║                ║                   ║  └──────────────────────┘ ║
║────────────╫────────────────╫───────────────────╫───────────────────────────╢
║            ║                ║                   ║                           ║
║    4       ║  restaurado    ║  Data*            ║  0x7fff5fbff8a0           ║
║            ║                ║  (puntero)        ║  (hexadecimal)            ║
║────────────╫────────────────╫───────────────────╫───────────────────────────╢
║            ║                ║                   ║                           ║
║    5       ║  Verificación  ║  bool             ║  restaurado == &original  ║
║            ║                ║                   ║  → TRUE ✓                 ║
╚════════════╩════════════════╩═══════════════════╩═══════════════════════════╝
```

---

## 🔬 Detalle del reinterpret_cast

```
┌────────────────────────────────────────────────────────────┐
│                    REINTERPRET_CAST                        │
├────────────────────────────────────────────────────────────┤
│                                                            │
│  ¿Qué hace?                                                │
│  ───────────────────────────────────────────────────────   │
│  • NO copia datos                                          │
│  • NO modifica bits                                        │
│  • Solo CAMBIA la interpretación del tipo                 │
│  • Los bits permanecen IDÉNTICOS                          │
│                                                            │
│  Ejemplo:                                                  │
│  ───────────────────────────────────────────────────────   │
│                                                            │
│  ANTES (Data*):                                            │
│  ┌──────────────────────────────────────────────────┐     │
│  │  0111 1111 1111 1111 0101 1111 ... (64 bits)     │     │
│  └──────────────────────────────────────────────────┘     │
│        ↓                                                   │
│   reinterpret_cast<unsigned long>                         │
│        ↓                                                   │
│  DESPUÉS (unsigned long):                                 │
│  ┌──────────────────────────────────────────────────┐     │
│  │  0111 1111 1111 1111 0101 1111 ... (64 bits)     │     │
│  └──────────────────────────────────────────────────┘     │
│                                                            │
│  → LOS BITS SON EXACTAMENTE IGUALES                       │
│  → Solo cambia cómo el compilador los interpreta          │
│                                                            │
└────────────────────────────────────────────────────────────┘
```

---

## 💡 Analogía: Casa y Dirección

```
┌──────────────────────────────────────────────────────────────┐
│                         LA CASA                              │
│                  (Objeto Data en memoria)                    │
│                                                              │
│   ┌────────────────────────────────────────────┐            │
│   │        🏠                                   │            │
│   │    Calle Principal 42                      │            │
│   │                                            │            │
│   │    Interior:                               │            │
│   │    • Habitación 1: numero = 42             │            │
│   │    • Habitación 2: letra = 'A'             │            │
│   │    • Habitación 3: decimal = 3.14          │            │
│   └────────────────────────────────────────────┘            │
│                        ↑                                     │
│                        │                                     │
└────────────────────────┼─────────────────────────────────────┘
                         │
        ┌────────────────┴────────────────┐
        │                                 │
        ↓                                 ↓
┌─────────────────┐             ┌─────────────────┐
│  DIRECCIÓN      │             │  COORDENADAS    │
│  (texto)        │             │  GPS (números)  │
│                 │ serialize   │                 │
│ "Calle          │ ─────────→  │  40.7128,       │
│  Principal 42"  │             │  -74.0060       │
│                 │ deserialize │                 │
│                 │ ←──────────  │                 │
│ Data*           │             │ unsigned long   │
│ 0x7fff5fbff8a0  │             │ 140734799814816 │
└─────────────────┘             └─────────────────┘

MORALEJA: Diferentes formas de representar la MISMA ubicación
```

---

## 🎯 Ejemplo Completo con Código y Diagrama

```cpp
// 1. Crear objeto
Data original;
original.numero = 42;
original.letra = 'A';
original.decimal = 3.14;

// 2. Serializar (puntero → número)
unsigned long serializado = Serializer::serialize(&original);

// 3. Deserializar (número → puntero)
Data* restaurado = Serializer::deserialize(serializado);

// 4. Verificar
if (restaurado == &original) {
    std::cout << "✓ ÉXITO" << std::endl;
}
```

**Diagrama del flujo:**

```
    1. CREAR
    ────────
    ┌──────────┐
    │ original │ numero=42, letra='A', decimal=3.14
    │ en RAM   │ dirección: 0x7fff5fbff8a0
    └──────────┘
         │
         ↓
    2. SERIALIZAR
    ──────────────
    ┌──────────┐    serialize()    ┌──────────────┐
    │&original │ ─────────────────→ │ serializado  │
    │0x7fff... │   (puntero→num)    │ 14073479...  │
    └──────────┘                    └──────────────┘
                                           │
                                           ↓
                                    3. DESERIALIZAR
                                    ────────────────
                                    ┌──────────────┐
                                    │ deserialize()│
                                    │ (num→puntero)│
                                    └──────┬───────┘
                                           │
                                           ↓
                                    ┌──────────────┐
                                    │ restaurado   │
                                    │ 0x7fff...    │
                                    └──────────────┘
                                           │
                                           ↓
                                    4. VERIFICAR
                                    ─────────────
                                    restaurado == &original
                                           ↓
                                         TRUE ✓
                                           ↓
                                    Apuntan al mismo objeto
                                           ↓
                                    ┌──────────────┐
                                    │ MEMORIA RAM  │
                                    │ 0x7fff...    │
                                    │ 42, 'A', 3.14│
                                    └──────────────┘
```

---

## ⚙️ Funciones del Serializer

### serialize() - Convierte Puntero a Número

```
┌─────────────────────────────────────────────────────┐
│  unsigned long Serializer::serialize(Data* ptr)     │
│  {                                                  │
│      return reinterpret_cast<unsigned long>(ptr);  │
│  }                                                  │
└─────────────────────────────────────────────────────┘

Input:  Data* ptr (puntero)
        ↓
        reinterpret_cast<unsigned long>
        ↓
Output: unsigned long (número)

Ejemplo:
  Input:  0x7fff5fbff8a0
  Output: 140734799814816
```

### deserialize() - Convierte Número a Puntero

```
┌─────────────────────────────────────────────────────┐
│  Data* Serializer::deserialize(unsigned long raw)   │
│  {                                                  │
│      return reinterpret_cast<Data*>(raw);          │
│  }                                                  │
└─────────────────────────────────────────────────────┘

Input:  unsigned long raw (número)
        ↓
        reinterpret_cast<Data*>
        ↓
Output: Data* (puntero)

Ejemplo:
  Input:  140734799814816
  Output: 0x7fff5fbff8a0
```

---

## ✅ Lo que HACE el Serializer

```
┌──────────────────────────────────────────────────────┐
│  ✓ Convierte puntero a número                       │
│                                                      │
│  ✓ Convierte número de vuelta a puntero             │
│                                                      │
│  ✓ Permite guardar direcciones como números         │
│                                                      │
│  ✓ Permite transmitir punteros como datos           │
│                                                      │
│  ✓ El puntero restaurado apunta al objeto original  │
└──────────────────────────────────────────────────────┘
```

---

## ❌ Lo que NO hace el Serializer

```
┌──────────────────────────────────────────────────────┐
│  ✗ NO copia el objeto Data                          │
│                                                      │
│  ✗ NO guarda los valores (numero, letra, decimal)   │
│                                                      │
│  ✗ NO crea un nuevo objeto                          │
│                                                      │
│  ✗ NO modifica la memoria                           │
│                                                      │
│  ✗ NO hace el número portable entre procesos        │
└──────────────────────────────────────────────────────┘
```

---

## ⚠️ Advertencias y Precauciones

```
┌────────────────────────────────────────────────────────────┐
│  ⚠️  IMPORTANTE - LEE ESTO CON ATENCIÓN                    │
├────────────────────────────────────────────────────────────┤
│                                                            │
│  1. El objeto original DEBE existir en memoria            │
│     ───────────────────────────────────────────────────   │
│     ✓ Correcto:                                           │
│       Data original;                                      │
│       ulong num = serialize(&original);                   │
│       Data* ptr = deserialize(num);  // OK               │
│                                                            │
│     ✗ Incorrecto:                                         │
│       Data* ptr = new Data();                             │
│       ulong num = serialize(ptr);                         │
│       delete ptr;                    // ⚠️ DESTRUIDO      │
│       Data* restored = deserialize(num);  // ❌ ERROR     │
│                                                            │
│  2. Solo funciona en el MISMO proceso                     │
│     ───────────────────────────────────────────────────   │
│     • El número no es válido en otro programa             │
│     • Las direcciones cambian entre ejecuciones           │
│                                                            │
│  3. NO usar después de free/delete                        │
│     ───────────────────────────────────────────────────   │
│     • Dangling pointer (puntero colgante)                 │
│     • Comportamiento indefinido                           │
│                                                            │
│  4. El número NO es portable                              │
│     ───────────────────────────────────────────────────   │
│     • No guardar en archivos                              │
│     • No enviar por red a otra máquina                    │
│                                                            │
└────────────────────────────────────────────────────────────┘
```

**Ejemplo de error común:**

```cpp
// ❌ ERROR: Usar después de delete
Data* ptr = new Data();
unsigned long num = Serializer::serialize(ptr);

delete ptr;  // ⚠️ Objeto destruido, memoria liberada

Data* restored = Serializer::deserialize(num);
// ❌ 'restored' apunta a memoria liberada
// ❌ Acceder a restored->numero causa comportamiento indefinido
```

---

## 📚 Casos de Uso del Serializer

```
╔══════════════════════╦═══════════════════════════════════════════╗
║    CASO DE USO       ║              DESCRIPCIÓN                  ║
╠══════════════════════╬═══════════════════════════════════════════╣
║                      ║                                           ║
║  Debugging           ║  Ver direcciones de memoria como números ║
║                      ║  útil para comparar punteros              ║
║                      ║                                           ║
║──────────────────────╫───────────────────────────────────────────╢
║                      ║                                           ║
║  Hash tables         ║  Usar direcciones de memoria como claves ║
║                      ║  hash(serializado)                        ║
║                      ║                                           ║
║──────────────────────╫───────────────────────────────────────────╢
║                      ║                                           ║
║  Logging             ║  Imprimir direcciones en logs             ║
║                      ║  "Objeto en: 140734799814816"             ║
║                      ║                                           ║
║──────────────────────╫───────────────────────────────────────────╢
║                      ║                                           ║
║  Comparación         ║  Comparar si dos punteros apuntan         ║
║                      ║  al mismo objeto                          ║
║                      ║                                           ║
╚══════════════════════╩═══════════════════════════════════════════╝
```

---

## 🔑 Resumen Visual del Proceso Completo

```
╔══════════════════════════════════════════════════════════════════╗
║                  PROCESO DE SERIALIZACIÓN                        ║
╠══════════════════════════════════════════════════════════════════╣
║                                                                  ║
║  PASO 1: Objeto en memoria                                      ║
║  ─────────────────────────────────────────────────────────────  ║
║    ┌────────────┐                                               ║
║    │ Data obj   │ {42, 'A', 3.14}                               ║
║    │ 0x7fff...  │                                               ║
║    └────────────┘                                               ║
║         │                                                        ║
║         ↓                                                        ║
║  PASO 2: Obtener puntero                                        ║
║  ─────────────────────────────────────────────────────────────  ║
║    Data* ptr = &obj;  // ptr = 0x7fff5fbff8a0                   ║
║         │                                                        ║
║         ↓                                                        ║
║  PASO 3: Serializar (puntero → número)                          ║
║  ─────────────────────────────────────────────────────────────  ║
║    unsigned long num = Serializer::serialize(ptr);              ║
║    // num = 140734799814816                                     ║
║         │                                                        ║
║         ↓                                                        ║
║  PASO 4: Deserializar (número → puntero)                        ║
║  ─────────────────────────────────────────────────────────────  ║
║    Data* restored = Serializer::deserialize(num);               ║
║    // restored = 0x7fff5fbff8a0                                 ║
║         │                                                        ║
║         ↓                                                        ║
║  PASO 5: Verificar                                              ║
║  ─────────────────────────────────────────────────────────────  ║
║    if (restored == &obj)  // TRUE ✓                             ║
║         │                                                        ║
║         ↓                                                        ║
║  PASO 6: Acceder a datos                                        ║
║  ─────────────────────────────────────────────────────────────  ║
║    restored->numero   // 42                                     ║
║    restored->letra    // 'A'                                    ║
║    restored->decimal  // 3.14                                   ║
║         │                                                        ║
║         ↓                                                        ║
║    ¡ÉXITO! El puntero restaurado apunta al objeto original      ║
║                                                                  ║
╚══════════════════════════════════════════════════════════════════╝
```

---

**Autor**: Serializer - CPP Module 06 - ex01  
**Fecha**: Octubre 2025  
**Nota**: Todos los diagramas usan ASCII art para máxima compatibilidad
