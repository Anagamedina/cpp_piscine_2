# 🔬 ¿Por qué si son diferentes falló la copia profunda?

## 🎯 El Flujo del Test

```cpp
// PASO 1: Crear y llenar numbers y mirror con MISMOS valores
Array<int> numbers(750);
int* mirror = new int[750];

for (int i = 0; i < 750; i++) {
    const int value = rand();  // Número aleatorio
    numbers[i] = value;        // Guardado en numbers
    mirror[i] = value;         // Guardado en mirror (copia)
}

// En este punto: numbers y mirror tienen EXACTAMENTE los mismos valores
// numbers = [42, 17, 93, ...]
// mirror  = [42, 17, 93, ...]


// PASO 2: Crear copias y destruirlas
{
    Array<int> tmp = numbers;   // Copia de numbers
    Array<int> test(tmp);       // Copia de tmp
}  // ← tmp y test se DESTRUYEN aquí


// PASO 3: Verificar que numbers SIGUE INTACTO
for (int i = 0; i < 750; i++) {
    if (mirror[i] != numbers[i]) {  // ← Si son diferentes = PROBLEMA
        std::cerr << "didn't save the same value!!" << std::endl;
        return 1;
    }
}
```

---

## 🔍 ¿Por qué sería diferente si la copia es superficial?

### CON COPIA SUPERFICIAL (❌ MAL):

```
PASO 1: Crear numbers
─────────────────────────────────────────
numbers._elements → [42, 17, 93, ...]  (Memoria A)
mirror            → [42, 17, 93, ...]  (Memoria B)


PASO 2: Copiar (copia superficial - MAL)
─────────────────────────────────────────
Array<int> tmp = numbers;

numbers._elements → [42, 17, 93, ...]  (Memoria A)
                    ↑
tmp._elements ──────┘  ← ¡Apunta a LA MISMA memoria!

Array<int> test(tmp);

test._elements ────────┘  ← ¡También apunta a la misma!


PASO 3: Destruir tmp y test
─────────────────────────────────────────
}  // Salir del scope

~tmp() ejecuta:
    delete[] _elements;  → Libera Memoria A

~test() ejecuta:
    delete[] _elements;  → Intenta liberar Memoria A de nuevo
                         → ¡CRASH! o corrupción


PASO 4: numbers apunta a memoria LIBERADA
─────────────────────────────────────────
numbers._elements → [basura, basura, basura]  ← Memoria liberada
                    ¿???? Los valores están corruptos

mirror            → [42, 17, 93, ...]  ← Valores originales

Comparación:
mirror[0] = 42
numbers[0] = ??? (basura, podría ser cualquier valor)

42 != ??? → DIFERENTES
         → Imprime "didn't save the same value!!"
```

---

### CON COPIA PROFUNDA (✅ BIEN):

```
PASO 1: Crear numbers
─────────────────────────────────────────
numbers._elements → [42, 17, 93, ...]  (Memoria A)
mirror            → [42, 17, 93, ...]  (Memoria B)


PASO 2: Copiar (copia profunda - BIEN)
─────────────────────────────────────────
Array<int> tmp = numbers;

numbers._elements → [42, 17, 93, ...]  (Memoria A)

tmp._elements     → [42, 17, 93, ...]  (Memoria C - NUEVA)
                    ↑
                    └─ Copia los valores a NUEVA memoria

Array<int> test(tmp);

test._elements    → [42, 17, 93, ...]  (Memoria D - NUEVA)


PASO 3: Destruir tmp y test
─────────────────────────────────────────
}  // Salir del scope

~tmp() ejecuta:
    delete[] _elements;  → Libera Memoria C ✓

~test() ejecuta:
    delete[] _elements;  → Libera Memoria D ✓


PASO 4: numbers sigue INTACTO
─────────────────────────────────────────
numbers._elements → [42, 17, 93, ...]  ← Memoria A (intacta)

mirror            → [42, 17, 93, ...]  ← Valores originales

Comparación:
mirror[0] = 42
numbers[0] = 42

42 == 42 → IGUALES ✓
         → No imprime nada
         → ¡Test pasado!
```

---

## 🔑 La Clave del Test:

```
mirror GUARDA los valores originales de numbers
            ↓
Se crean y destruyen copias (tmp, test)
            ↓
Si la copia es SUPERFICIAL:
    → Al destruir tmp/test se libera la memoria de numbers
    → numbers queda apuntando a basura
    → mirror[i] != numbers[i]  ← DIFERENTES

Si la copia es PROFUNDA:
    → Al destruir tmp/test se libera SU propia memoria
    → numbers sigue intacto con sus valores
    → mirror[i] == numbers[i]  ← IGUALES
```

---

## 📊 Visualización del Problema:

```
TIMELINE CON COPIA SUPERFICIAL (❌):
════════════════════════════════════════════════════════

Tiempo 1: Crear numbers y mirror
    numbers → [42, 17, 93, ...]
    mirror  → [42, 17, 93, ...]  ✓ Iguales

Tiempo 2: Crear tmp (copia superficial)
    numbers → [42, 17, 93, ...]  ← Memoria A
              ↑
    tmp ──────┘  ← Apunta a la misma

Tiempo 3: Destruir tmp
    delete[] Memoria A  ← ¡Se libera!
    
    numbers → [????, ????, ????]  ← Apunta a memoria liberada
    mirror  → [42, 17, 93, ...]

Tiempo 4: Comparar
    mirror[0] (42) != numbers[0] (????)
    → DIFERENTES
    → "didn't save the same value!!"


TIMELINE CON COPIA PROFUNDA (✅):
════════════════════════════════════════════════════════

Tiempo 1: Crear numbers y mirror
    numbers → [42, 17, 93, ...]  ← Memoria A
    mirror  → [42, 17, 93, ...]  ← Memoria B

Tiempo 2: Crear tmp (copia profunda)
    numbers → [42, 17, 93, ...]  ← Memoria A
    tmp     → [42, 17, 93, ...]  ← Memoria C (nueva)

Tiempo 3: Destruir tmp
    delete[] Memoria C  ← Solo libera C
    
    numbers → [42, 17, 93, ...]  ← Memoria A (intacta)
    mirror  → [42, 17, 93, ...]  ← Memoria B

Tiempo 4: Comparar
    mirror[0] (42) == numbers[0] (42)
    → IGUALES
    → ¡Test pasado!
```

---

## 🎯 Resumen:

**Si mirror[i] != numbers[i]:**
- Significa que `numbers` tiene valores corruptos/basura
- Esto pasa cuando la copia es superficial
- Al destruir las copias, se libera la memoria de `numbers`
- `numbers` queda apuntando a memoria liberada (basura)

**Si mirror[i] == numbers[i]:**
- Significa que `numbers` mantiene sus valores originales
- Esto pasa cuando la copia es profunda
- Al destruir las copias, solo se libera SU memoria
- `numbers` sigue intacto con su propia memoria

**Por eso el test es tan inteligente:** Usa `mirror` como "testigo" de los valores originales para detectar si hubo corrupción.












