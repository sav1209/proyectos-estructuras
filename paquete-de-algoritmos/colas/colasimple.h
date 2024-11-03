#ifndef COLASIMPLE_H
#define COLASIMPLE_H

// Estructura para cada nodo de la cola.
typedef struct NodoColaSim {
    int info;
    struct NodoColaSim *liga;
} NodoColaSim;

// Crea un nuevo nodo con liga nula.
NodoColaSim *crearNodoColaSim(int info);

// 1. ALGORITMO QUE REALICE LA OPERACIÓN PUSH (INSERTAR POR EL FINAL)
void pushColSim(NodoColaSim **frente, NodoColaSim **final, int info);

// 2. ALGORITMO QUE REALICE LA OPERACIÓN POP (ELIMINAR POR EL PRINCIPIO)
void popColSim(NodoColaSim **frente, NodoColaSim **final);

// 3. ALGORITMO QUE IMPRIMA LOS ELEMENTOS DE LA COLA
void imprimirColSim(NodoColaSim *frente);

// Borra todos los nodos de una cola.
void borrarColSim(NodoColaSim **frente, NodoColaSim **final);

// MENU
void menuCola();

#endif