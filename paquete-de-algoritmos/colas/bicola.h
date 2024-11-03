#ifndef BICOLA_H
#define BICOLA_H

// Estructura para cada nodo de la bicola.
typedef struct NodoBicola {
    int info;
    struct NodoBicola *liga;
} NodoBicola;

// Crea un nuevo nodo con liga nula.
NodoBicola *crearNodoBicola(int info);

// REALIZA LA OPERACIÓN PUSH INSERTANDO POR EL FRENTE
void push_front(NodoBicola **final, int info);

// REALIZA LA OPERACIÓN PUSH INSERTANDO POR EL FINAL
void push_back(NodoBicola **final, int info);

// REALIZA LA OPERACIÓN POP ELIMINANDO POR EL FRENTE
void pop_front(NodoBicola **final);

// REALIZA LA OPERACIÓN POP ELIMINANDO POR EL FINAL
void pop_back(NodoBicola **final);

// ALGORITMO QUE IMPRIMA LOS ELEMENTOS DE LA BICOLA
void imprimirBicola(NodoBicola *final);

// Borra todos los nodos de una bicola.
void borrarBicola(NodoBicola **final);

// MENU BICOLAS DE ENTRADA RESTRINGIDA
void menuBicolaEntradaRestringida();

// MENU BICOLAS DE SALIDA RESTRINGIDA
void menuBicolaSalidaRestringida();

// MENU BICOLAS
void menuBicolas();

#endif