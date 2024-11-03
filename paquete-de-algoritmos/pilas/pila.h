#ifndef PILA_H
#define PILA_H

// Estructura para cada nodo de la pila.
typedef struct NodoPila {
    int info;
    struct NodoPila *liga;
} NodoPila;


// Crea un nuevo nodo con liga nula.
NodoPila *crearNodoPila(int info);


// 1. ALGORITMO QUE REALICE LA OPERACIÓN PUSH (INSERTAR POR EL FINAL)
void push(NodoPila **final, int info);

// 2. ALGORITMO QUE REALICE LA OPERACIÓN POP (ELIMINAR POR EL FINAL)
void pop(NodoPila **final);

// 3. ALGORITMO QUE IMPRIMA LOS ELEMENTOS DE LA PILA
void imprimirPila(NodoPila *final);

// Borra todos los nodos de una pila.
void borrarPila(NodoPila **final);

// MENU
void menuPilas();

#endif