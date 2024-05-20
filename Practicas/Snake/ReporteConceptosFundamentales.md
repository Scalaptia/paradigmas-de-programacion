# Elementos fundamentales de los lenguajes de programación.

-   **Clase:** Paradigmas de Programación
-   **Alumno:** Fernando Haro Calvo

## Indice

1. [Nombres y Entorno](#1-nombres-y-entorno)

    - 1.1 [Nombres y Objetos](#11-nombres-y-objetos)
    - 1.2 [Entornos y Bloques](#12-entornos-y-bloques)
    - 1.3 [Reglas de Alcance](#13-reglas-de-alcance)

2. [Administración de la Memoria](#2-administración-de-la-memoria)

    - 2.1 [Clases de Duración de Almacenamiento](#21-clases-de-duración-de-almacenamiento)
    - 2.2 [Semántica de Valor y Referencia](#22-semántica-de-valor-y-referencia)
    - 2.3 [Recolección de Basura](#23-recolección-de-basura)

3. [Estructuras de Control](#3-estructuras-de-control)

    - 3.1 [Expresiones](#31-expresiones)
    - 3.2 [Comandos y Secuencias](#32-comandos-y-secuencias)
    - 3.3 [Selección](#33-selección)
    - 3.4 [Iteración](#34-iteración)
    - 3.5 [Recursión](#35-recursión)
    - 3.6 [Excepciones](#36-excepciones)

4. [Subprogramas](#4-subprogramas)

    - 4.1 [Funciones](#41-funciones)
    - 4.2 [Procedimientos](#42-procedimientos)
    - 4.3 [Diferencias entre Funciones y Procedimientos](#43-diferencias-entre-funciones-y-procedimientos)

## 1. Nombres y Entorno

### 1.1 Nombres y Objetos

Los nombres se utilizan como una forma de abstracción para referirse a entidades en un programa. Por ejemplo, en el código `int x = 10;`, `x` es un nombre que hace referencia a un objeto entero con valor `10`.

Un nombre puede hacer referencia a diferentes entidades en diferentes contextos de código. Por ejemplo, en un bucle `for`, el nombre `i` puede hacer referencia a diferentes valores enteros en cada iteración.

Una entidad también puede tener varios nombres que hagan referencia a ella. Por ejemplo, después de `int y = x;`, tanto `x` como `y` hacen referencia al mismo objeto entero con valor `10`.

### 1.2 Entornos y Bloques

Los bloques son unidades fundamentales de organización de programas. Un bloque puede ser una función, un bucle, un bloque de código entre llaves, etc.

Cada bloque corresponde a un marco en el entorno, que contiene enlaces de nombres locales para ese bloque. Por ejemplo:

```c
int x = 10; // x se vincula en el entorno global

int foo() {
    int y = 20; // y se vincula en el entorno de la función foo
    printf("%d\n", x); // x se busca en el entorno global
    printf("%d\n", y); // y se busca en el entorno de la función foo
    return 0;
}
```

Las reglas de visibilidad de nombres dentro de bloques anidados determinan qué nombres son visibles y cuáles están ocultos. En general, los nombres locales ocultan los nombres globales del mismo nombre.

### 1.3 Reglas de Alcance

El alcance determina a qué entidad se refiere un nombre dentro del código fuente.
Existen dos esquemas principales de alcance: estático (léxico) y dinámico.

En el alcance estático, el entorno en cualquier punto se puede deducir de la estructura sintáctica del código. La mayoría de los lenguajes modernos utilizan alcance estático.

En el alcance dinámico, el entorno depende de cómo evoluciona la ejecución en tiempo de ejecución. Esto puede ser más flexible pero también más complejo y propenso a errores.

## 2. Administración de la Memoria

### 2.1 Clases de Duración de Almacenamiento

Los lenguajes distinguen entre la duración del almacenamiento de diferentes objetos:

-   **Estática:** para objetos accesibles en cualquier punto del programa, como variables globales y constantes.

-   **Automática:** para objetos asociados con variables locales dentro de un bloque de código, como funciones o bucles.

-   **De hilo local o subproceso:** para objetos locales a un subproceso específico en un programa multiproceso.

-   **Dinámica:** para objetos cuya vida útil no está vinculada a un fragmento de código específico. La memoria se asigna y libera explícitamente por el programador.

### 2.2 Semántica de Valor y Referencia

La semántica de valor significa que el almacenamiento de una variable es el mismo que el del objeto al que se refiere. Cuando se copia una variable de valor, se crea una copia independiente del objeto.

La semántica de referencia significa que una variable tiene una referencia indirecta a un objeto. Cuando se copia una variable de referencia, ambas variables apuntan al mismo objeto.

Por ejemplo, en C, las variables enteras usan semántica de valor, mientras que los punteros usan semántica de referencia.

### 2.3 Recolección de Basura

Algunos lenguajes gestionan automáticamente la destrucción de objetos mediante la recolección de basura. Las técnicas incluyen conteo de referencias y rastreo de recolección.

C no tiene recolección de basura integrada. El programador es responsable de asignar y liberar manualmente la memoria dinámica utilizando `malloc`, `calloc`, `realloc` y `free`. Esto puede conducir a errores como fugas de memoria (no liberar memoria asignada) y accesos de puntero no válidos.

## 3. Estructuras de Control

### 3.1 Expresiones

Una expresión es un constructo sintáctico que da como resultado un valor. Por ejemplo, en `x = 10 + 20`, 10 + 20 es una expresión que se evalúa a 30.
El orden de evaluación de subexpresiones es importante, especialmente en presencia de efectos secundarios. Por ejemplo, `en x = f() + g()`, la llamada a f podría realizarse antes o después de la llamada a g, lo que podría dar diferentes resultados.

### 3.2 Comandos y Secuencias

Las declaraciones (o comandos) tienen efectos secundarios, por lo que su orden de ejecución es fundamental. Por ejemplo:

```c
int x = 10;
printf("%d\n", x); // Imprime 10
x = 20;
printf("%d\n", x); // Imprime 20
```

Las declaraciones se agrupan en bloques o secuencias, que pueden aparecer donde se espera una sola declaración.

```c
if (x > 0) {
    printf("Positivo\n");
    y = x * 2; // Secuencia de dos declaraciones
} else {
    printf("No positivo\n");
}
```

### 3.3 Selección

Los constructos de selección, como `if` y `switch`, permiten la ejecución condicional de declaraciones.

`if` proporciona un mecanismo para ramificación binaria:

```c
if (x > 0) {
    printf("Positivo\n");
} else {
    printf("No positivo\n");
}
```

`switch` permite ramificación múltiple y manejo de casos especiales:

```c
switch (variable) {
    case valor1:
        // código
        break;
    case valor2:
        // código
        break;
    default:
        // código para casos no manejados
}
```

### 3.4 Iteración

Los bucles, como `while` y `for`, son mecanismos comunes de repetición en lenguajes imperativos. Permiten repetir un cálculo un número determinado de veces o hasta que se cumpla una condición.

`while` repite un bloque de código mientras se cumple una condición:

```c
while (x > 0) {
    printf("%d\n", x);
    x--;
}
```

`for` proporciona una forma más compacta de repetir un bloque de código un número determinado de veces:

```c
for (int i = 0; i < 10; i++) {
    printf("%d\n", i);
}
```

### 3.5 Recursión

La recursión es una técnica donde una función se llama a sí misma para resolver un problema. Es un mecanismo poderoso para expresar algoritmos iterativos de una manera elegante.

Por ejemplo, el cálculo del factorial de un número se puede expresar de forma recursiva:

```c
int factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * factorial(n - 1);
    }
}
```

### 3.6 Excepciones

Las excepciones proporcionan un mecanismo para implementar el manejo de errores de manera estructurada. Permiten separar la detección de errores de la recuperación, trasladando el control a un controlador de excepciones.

## 4. Subprogramas

### 4.1 Funciones

Las funciones son subprogramas que toman uno o más valores (argumentos) y producen un valor de resultado.

Pueden ser internas (integradas en el lenguaje) o externas (definidas por el usuario). Un ejemplo es la función `sum` que toma dos enteros y devuelve su suma:

```c
int sum(int a, int b) {
    return a + b;
}
```

### 4.2 Procedimientos

Los procedimientos son subprogramas que ejecutan un proceso específico, pero no devuelven un valor asociado. Pueden tener parámetros de entrada, salida o entrada/salida.

### 4.3 Diferencias entre Funciones y Procedimientos

Las funciones devuelven un valor, mientras que los procedimientos pueden devolver 0, 1 o múltiples valores.

Los procedimientos pueden tener parámetros de entrada, salida o entrada/salida, mientras que las funciones solo tienen parámetros de entrada.

Los procedimientos se utilizan para realizar tareas, mientras que las funciones se utilizan para realizar cálculos y devolver un valor.
