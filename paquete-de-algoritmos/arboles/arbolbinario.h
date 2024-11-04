#ifndef ARBOLBINARIO_H
#define ARBOLBINARIO_H

typedef struct NodoArbol {
    int info;
    struct NodoArbol* ligaIzq;
    struct NodoArbol* ligaDer;
} NodoArbol;

// Crea un nuevo nodo con ligas nulas.
NodoArbol* crearNodoArbol(int info);

// Función para cargar el arbol
void Carga(NodoArbol* elemento);

// Funcion para preorden.
void preorden(NodoArbol* elemento);

// Funcion para inorden
void inorden(NodoArbol* elemento);

//Funcion para posorden
void posorden(NodoArbol* elemento);

// Borra todos los nodos de un arbol binario.
void BorrarArbol(NodoArbol** raiz);

// Menú para trabajar con el árbol binario.
void menuArbolBinario();

#endif