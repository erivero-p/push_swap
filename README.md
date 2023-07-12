# push_swap
Push_swap es un proyecto de algoritmia simple. Se nos pide que ordenemos datos contando con: un conjunto de enteros, dos stacks, y una serie de instrucciones para la manipulación. El objetivo es ordenar los datos utilizando el menor número de instrucciones posibles. El programa deberá mostrar por pantalla la lista de instrucciones realizadas.

El programa puede realizarse con arrays o con listas, y recurriendo a diferentes algoritmos de ordenación. En mi caso, utilizo arrays y una versión del InsertionSort.

# Project Tree

```c
.
├── Makefile
├── include
│   └── push_swap.h
├── libft/
└── src
    ├── big_sorter.c
    ├── check_arg.c
    ├── checker
    │   ├── checker.c
    │   ├── chk_push.c
    │   ├── chk_r.c
    │   ├── chk_rr.c
    │   └── chk_swap.c
    ├── chunk_sorter.c
    ├── main.c
    ├── manage_stacks.c
    ├── push.c
    ├── reverse_rotate.c
    ├── rotate.c
    ├── small_sorter.c
    └── swap.c
```

# Proyect Basics

Voy a necesitar funciones para:

- Chequear la validez de los argumentos recibidos
- Inicializar los stacks y guardar los argumentos en el stack_a
- Hacer los movimientos de cada instrucción
- El/los algoritmo/s de ordenación
- Cerrar el programa correctamente tanto en caso de éxito como de error

# Argument check

Los argumentos recibidos deberán pasar por tres comprobaciones: 

- Todos deben ser números
- Todos deben caber en un entero
- No puede haber repeticiones

Si cualquiera de estos casos dejara de cumplirse, el programa deberá mostrar ‘Error\n’ por pantalla, liberar la memoria alojada hasta el momento, y cerrarse.

# Stack Management

Una vez hayamos comprobado que los argumentos sean válidos, inicializaremos dos estructuras, una para cada stack. Éstas, deberán contener, mínimo, un array de enteros  y un entero con la última posición ocupada de ese array (`top`). Top deberá irse modificando en caso de que nuestra cantidad de números en un stack disminuya o aumente.

Como en un principio desconocemos el total de números que va a haber en cada stack, al inicializar el array elegimos el número máximo de enteros que puede haber en un array, 1024. Dejaremos el stack_b vacío, y en el stack_a guardaremos los números recibidos por argumento.

# Instruction Management

Las instrucciones que podemos ejecutar para mover los números en los stacks serán de cuatro tipos:

- Swap:  intercambia los dos primeros elementos de un stack.
- Push: Toma el primer elemento de un stack y lo coloca encima del otro.
- Rotate: Coloca el primer elemento de un stack al final, y desplaza el resto una posición hacia arriba.
- Reverse Rotate: Coloca el último elemento de un stack al principio, y desplaza el resto una posición hacia abajo.

Para las funciones dedicadas a ejecutar cada una de estas acciones habrá que tener en cuenta que, además de estar moviendo el contenido del array de números, también deberemos actualizar el valor de `top`. 

# Algorithms

El objetivo de nuestro algoritmo es ordenar los números en el mayor número posible de movimientos. Nos dan la condición de que para cinco números, el máximo de movimientos sean 12. En mi caso he hecho dos algoritmos, uno para cantidades de hasta 6 números, y otro para cantidades mayores. 

## Small_sorter

Deberá ser capaz de ordenar desde 2 hasta 6 números. 

- 2 Números: En caso de que no estén ya en orden, hacemos un swap.
- 3 Números: Se tendrá en cuenta cada una de las 5 combinaciones posibles para realizar los movimientos más convenientes en cada caso.
- 4 Números: Buscaremos el número más pequeño y lo rotaremos (con rotate o reverse_rotate, en función de lo que sea más conveniente) hasta arriba para después hacer un push a b. Ordenaremos los otros tres con la función anterior, y pushearemos el número más pequeño de vuelta a a.
- Con 5 y 6 números: llamaremos dos y tres veces a la función que pushea el número más pequeño, para después ordenar los tres restantes.

## Big_sorter

El algoritmo realiza una ordenación en dos pasos. Primero, se pasarán los números del stack A al B en bloques o chunks, de forma que, dentro del mismo bloque de números éstos no estén ordenados entre sí, pero todos los números del primer bloque sean menores a los del segundo y así sucesivamente. El segundo paso será pushear los números de vuelta al stack A ya ordenados.

### Primer paso: Ordenación por bloques o chunks

Considerando el total de números que podemos encontrar en el stack (cosa que calcularemos restando el menor número al de mayor valor), haremos bloques de tamaño equivalente que dividirán todo el rango de posibilidades. De esta forma, iremos revisando si en el stack hay algún número del primer chunk, y en caso afirmativo lo pushearemos al stack_b. Cuando no queden más números de ese chunk, pasaremos a mirar el siguiente.

Para mejorar la eficiencia a la hora de hacer el push a b, tomo tanto la primera como la última aparición de un número del chunk, calculando el coste de pushear cada uno, para poder elegir el menos costoso.

### Segundo paso: Ordenación y push de vuelta al stack A

Deberemos ir devolviendo los números al stack A del más grande al más pequeño, para que queden ordenados. Por tanto, mi programa busca el número más grande, y en función de si se encuentra en la primera o en la segunda mitad del stack, hace rotaciones o rotaciones reversas para pushearlo de vuelta a A.
