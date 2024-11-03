#ifndef LISTASIMPLE_H
#define LISTASIMPLE_H

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct NodoLS {
    int info;
    struct NodoLS* liga;
} NodoLS;


// Crea un nuevo nodo con liga nula.
NodoLS* crearNodoLS(int info);

// Borra todos los nodos de una lista simple.
void borrarLS(NodoLS** primero);

// 1. CREA UNA LISTA SIMPLE AGREGANDO CADA NUEVO NODO AL INICIO DE LA LISTA
NodoLS* crearLSPorPrincipio();

// 2. IMPRIME UNA LISTA SIMPLE
void imprimirLS(NodoLS* primero);

// 3. ELIMINA EL ÚLTIMO ELEMENTO
void eliminarUltimoLS(NodoLS** primero);

// 4. CREA UNA LISTA SIMPLE AGREGANDO CADA NUEVO NODO AL FINAL DE LA LISTA 
NodoLS* crearLSPorFinal();

// 5. BUSCA UN ELEMENTO DENTRO DE UNA LISTA. 
int buscarElementoLS(NodoLS* primero, int valor);

// 6. INSERTE ELEMENTOS POR EL INICIO DE UNA LISTA EXISTENTE.
void insertarAlInicioLS(NodoLS** primero, int info);

// 7. INSERTE ELEMENTOS POR EL FINAL DE UNA LISTA EXISTENTE. 
void insertarAlFinalLS(NodoLS** primero, int info);

// 8. ELIMINE EL PRIMER ELEMENTO DE UNA LISTA
void eliminarPrimeroLS(NodoLS** primero);

// 9. ELIMINA UN NODO QUE COINCIDA CON CIERTA INFORMACIÓN 
void eliminarNodoLS(NodoLS** principio, int valor);

// 10. INSERTA UN NODO ANTES DE UN NODO ESPECÍFICO
void insertarAntesDeNodoLS(NodoLS** primero, int valorObjetivo, int nuevoValor);

// 11. INSERTA UN NODO DESPUÉS DE UN NODO ESPECÍFICO
void insertarDespuesDeNodoLS(NodoLS** primero, int valorObjetivo, int nuevoValor);

// 12. ELIMINA UN NODO ANTES DE UN NODO ESPECÍFICO
void eliminarAntesDeNodoLS(NodoLS** primero, int valorObjetivo);

// 13. ELIMINA UN NODO DESPUÉS DE UN NODO ESPECÍFICO
void eliminarDespuesDeNodoLS(NodoLS** primero, int valorObjetivo);

// Menu de operaciones listas simples.
void menuListasSimples();

#endif