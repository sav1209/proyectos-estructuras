#ifndef COLAPRIORIDAD_H
#define COLAPRIORIDAD_H

// Estructura para cada nodo de la cola con prioridad
typedef struct NodoColaPrio {
    int info;
    int prioridad;
    struct NodoColaPrio *liga;
} NodoColaPrio;

// Crea un nuevo nodo con liga nula 
NodoColaPrio *crearNodoColaPrio(int info, int prioridad);

void pushColPrio(NodoColaPrio **inicio, int info, int prioridad);

void popColPrio(NodoColaPrio **inicio);

// IMPRIME LA COLA CON LA PRIORIDAD QUE TIENE CADA NODO
void imprimirColPrio(NodoColaPrio *inicio);

// BORRA TODOS LOS NODOS DE LA COLA CON PRIORIDAD
void borrarColPrio(NodoColaPrio **inicio);

// MENU DE LA COLA CON PRIORIDAD
void menuColaPrioridad();

#endif