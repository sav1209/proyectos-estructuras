#ifndef ARBOLBINARIOBUSQUEDA_H
#define ARBOLBINARIOBUSQUEDA_H

typedef struct NodoABB {
    int info;
    struct NodoABB* ligaIzq;
    struct NodoABB* ligaDer;
} NodoABB;

// Crea un nuevo nodo con ligas nulas.
NodoABB* crearNodoABB(int info);

// ALGORITMO QUE INSERTE ELEMENTOS EN UN ABB
void InsertarEnABB(NodoABB** elemento, int info);

// ALGORITMO QUE IMPRIME LOS ELEMENTOS DEL ÁRBOL MEDIANTE UN RECORRIDO EN INORDEN
void ImprimirInorden(NodoABB* elemento);

// ALGORITMO QUE BUSQUE UN ELEMENTO EN UN ABB
void BuscarEnABB(NodoABB *elemento, int info);

// RETORNA EL NODO MÁS A LA IZQUIERDA
NodoABB* ExtremoIzquierdo(NodoABB* elemento);

// ALGORITMO QUE ELIMINA UN ELEMENTO EN UN ABB
void BorrarNodoABB(NodoABB** elemento, int info);

// Borra todos los nodos de un arbol binario.
void BorrarABB(NodoABB** raiz);

// Menú para trabajar con el ABB.
void menuABB();

#endif