# 🔄 Push Swap

**Push Swap** es un proyecto centrado en la lógica algorítmica y la optimización. El objetivo es ordenar una lista de enteros usando un conjunto limitado de operaciones sobre dos pilas: `a` y `b`. El reto es diseñar un programa que calcule y ejecute la secuencia más eficiente de movimientos posibles para ordenar la lista.

Este proyecto pone a prueba las habilidades en estructuras de datos, manipulación de listas, diseño de algoritmos eficientes y control de errores.

## 🎯 Objetivos del proyecto

- Implementar un programa que ordene números con el menor número de movimientos posibles
- Diseñar un algoritmo que seleccione eficientemente qué operaciones aplicar
- Cumplir con restricciones estrictas de operaciones permitidas

## 🚀 Funcionalidades principales

- ✅ Uso exclusivo de operaciones limitadas:
  - `sa`, `sb`, `ss`: intercambios en pila
  - `pa`, `pb`: push entre pilas
  - `ra`, `rb`, `rr`: rotaciones hacia arriba
  - `rra`, `rrb`, `rrr`: rotaciones hacia abajo
- ✅ Validación y parsing de argumentos
- ✅ Gestión de errores:
  - Duplicados
  - Inputs no válidos
- ✅ Implementación de algoritmos de ordenación:
  - Resolución directa para listas pequeñas (casos de 3, 5 elementos)
  - Algoritmo eficiente basado en **Radix adaptado a pilas** para listas largas
- ✅ Optimización del número de operaciones

## 🧠 Tecnologías y conceptos utilizados

- Lenguaje C
- Estructuras de datos: **listas enlazadas** para representar pilas
- Diseño de algoritmos personalizados
- Parsing de argumentos
- Control de errores y validaciones
- Optimización de rendimiento y uso de memoria
