
## 🧨 Buscaminas en C++

### 🎯 Descripción del problema

Desarrolla un programa en C++ que simule el clásico juego del **Buscaminas**, permitiendo al usuario jugar en una matriz cuadrada o rectangular de tamaño definido.

---

### 📥 Entrada

El programa debe solicitar al usuario las dimensiones del tablero:  
**Número de filas** y **número de columnas**.  
Por ejemplo:
```
Ingrese las dimensiones del tablero (filas columnas): 4 4
```

---

### 💣 Generación del tablero

- Se debe crear una matriz bidimensional de enteros con las dimensiones indicadas.
- Coloca aleatoriamente una cantidad de minas igual a:
  ```
  Cantidad de minas = columnas + 1
  ```
  En el ejemplo `4 x 4`, se colocarían `5` minas.
- Representa las minas internamente con el valor **-1**.
- Para cada celda sin mina, calcula la cantidad de minas adyacentes (máximo 8).

📌 Las minas y números se calcularán una única vez al inicio del juego.

Ejemplo de tablero generado internamente:

|   | 0 | 1 | 2 | 3 |
|---|---|---|---|---|
| 0 | 0 | 0 | 1 | M |
| 1 | 1 | 2 | 2 | 2 |
| 2 | 2 | M | M | 2 |
| 3 | 1 | M | 3 | M |

> Nota: Usa `M` o `*` al mostrar minas, pero internamente se representan como `-1`.

---

### 🖥️ Interfaz del juego

1. Muestra el tablero al inicio con los valores reales (opcional).
2. Cuando el jugador presione una tecla para comenzar, **borra la pantalla** (`system("cls")`) y muestra una versión **oculta del tablero**:

    |   | 0 | 1 | 2 | 3 |
    |---|---|---|---|---|
    | 0 | - | - | - | - |
    | 1 | - | - | - | - |
    | 2 | - | - | - | - |
    | 3 | - | - | - | - |

---

### ⛏️ Reglas del juego

1. Solicita al jugador la coordenada de la celda que desea destapar:
  ```
  Ingrese fila y columna: 1 1
  ```

2. Aplica las siguientes reglas:
   - Si la celda contiene una **mina (-1)** → **GAME OVER**.
   - Si contiene un **número mayor a 0** → se muestra solo esa celda.
   - Si contiene un **0** → se destapan todas las celdas adyacentes (efecto "cascada"). Si alguna adyacente también es cero, se repite la acción recursivamente hasta que no haya más ceros.

    Ejemplo de jugada (descubrir la celda 0,0):

    |   | 0 | 1 | 2 | 3 |
    |---|---|---|---|---|
    | 0 | 0 | 0 | 1 | - |
    | 1 | 1 | 2 | 2 | - |
    | 2 | - | - | - | - |
    | 3 | - | - | - | - |

3. El juego termina cuando:
   - El jugador destapa una mina → **pierde**.
   - El jugador descubre todas las celdas sin minas → **gana**.

---

### 🔁 Recomendaciones de implementación

- Utiliza funciones para:
  - Generar el tablero y colocar minas
  - Calcular minas adyacentes
  - Mostrar el tablero
  - Procesar las jugadas
- Usa recursión para destapar automáticamente las celdas con valor 0.
- Representa la matriz del usuario como una copia oculta que se va descubriendo.

---

### 🎲 Generación de números aleatorios

Recuerda inicializar la semilla con `srand(time(NULL));` para obtener secuencias diferentes en cada ejecución.

Ejemplo:
```cpp
srand(time(NULL));
int aleatorio = (rand() % (max - min)) + min;
```

---

### 📝 Requisitos

- Usar matrices bidimensionales
- No usar arreglos dinámicos ni bibliotecas adicionales
- Mostrar los datos de forma tabular
- Aplicar buenas prácticas y modularidad

---

### 📦 Entrega

- Archivo obligatorio: `buscaminas.cpp`

---

### 🧠 Tip adicional

Puedes usar funciones auxiliares como:

- `generar_minas()`
- `contar_adyacentes()`
- `mostrar_tablero()`
- `destapar()`

¡Buena suerte y que no explote nada! 💥
