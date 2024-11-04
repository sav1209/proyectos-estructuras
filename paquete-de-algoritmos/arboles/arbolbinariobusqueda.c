// ABB: ÁRBOL BINARIO DE BÚSQUEDA

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "arbolbinariobusqueda.h"

// Crea un nuevo nodo con ligas nulas.
NodoABB* crearNodoABB(int info) {
    NodoABB* nuevoNodo = (NodoABB*) malloc(sizeof(NodoABB));
    nuevoNodo->info = info;
    nuevoNodo->ligaIzq = NULL;
    nuevoNodo->ligaDer = NULL;
    return nuevoNodo;
}

// ALGORITMO QUE INSERTE ELEMENTOS EN UN ABB
void InsertarEnABB(NodoABB** elemento, int info) {
    if(*elemento != NULL) {
        if(info <= (*elemento)->info) {
            if ((*elemento)->ligaIzq == NULL) {
                (*elemento)->ligaIzq = crearNodoABB(info);
            } else {
                InsertarEnABB(&(*elemento)->ligaIzq, info);
            }
        } else {
            if ((*elemento)->ligaDer == NULL) {
                (*elemento)->ligaDer = crearNodoABB(info);
            } else {
                InsertarEnABB(&(*elemento)->ligaDer, info);
            }
        }
    } else {
        *elemento = crearNodoABB(info);
    }
}

// ALGORITMO QUE IMPRIME LOS ELEMENTOS DEL ÁRBOL MEDIANTE UN RECORRIDO EN INORDEN
void ImprimirInorden(NodoABB* elemento) {
    if (elemento != NULL) {
        ImprimirInorden(elemento->ligaIzq);
        printf("%d\n", elemento->info);
        ImprimirInorden(elemento->ligaDer);
    }
}

// ALGORITMO QUE BUSQUE UN ELEMENTO EN UN ABB
void BuscarEnABB(NodoABB *elemento, int info) {
    if(elemento != NULL) {
        if(info == elemento->info) {
            printf("Se encontro al elemento");
            return;
        }

        if(info < elemento->info) {
            if(elemento->ligaIzq == NULL) {
                printf("No se encontro el elemento.\n");
            } else {
                BuscarEnABB(elemento->ligaIzq, info);
            }
        } else {
            if(elemento->ligaDer == NULL) {
                printf("No se encontro el elemento.\n");
            } else {
                BuscarEnABB(elemento->ligaDer, info);
            }
        }
        return;
    }
}


// RETORNA EL NODO MÁS A LA IZQUIERDA
NodoABB* ExtremoIzquierdo(NodoABB* elemento) {
    if(elemento == NULL) return NULL;
    while(elemento->ligaIzq != NULL) {
        elemento = elemento->ligaIzq;
    }
    return elemento;
}

// ALGORITMO QUE ELIMINA UN ELEMENTO EN UN ABB
void BorrarNodoABB(NodoABB** elemento, int info) {
    if (*elemento == NULL) return;

    if (info < (*elemento)->info) {
        BorrarNodoABB(&(*elemento)->ligaIzq, info);
    } else if (info > (*elemento)->info) {
        BorrarNodoABB(&(*elemento)->ligaDer, info);
    } else {
        NodoABB* porEliminar = *elemento;

        // Caso 1: El nodo es una hoja
        if (porEliminar->ligaIzq == NULL && porEliminar->ligaDer == NULL) {
            *elemento = NULL;
            free(porEliminar);
        }
        // Caso 2: El nodo tiene un único hijo
        else if (porEliminar->ligaIzq == NULL || porEliminar->ligaDer == NULL) {
            *elemento = (porEliminar->ligaIzq != NULL) ? porEliminar->ligaIzq : porEliminar->ligaDer;
            free(porEliminar);
        }
        // Caso 3: El nodo tiene dos hijos
        else {
            NodoABB* sucesor = ExtremoIzquierdo(porEliminar->ligaDer);
            porEliminar->info = sucesor->info;
            BorrarNodoABB(&porEliminar->ligaDer, sucesor->info);
        }
    }
}


// Borra todos los nodos de un arbol binario.
void BorrarABB(NodoABB** raiz) {
    // No hay nada que borrar
    if (*raiz == NULL) {
        return;
    }
    BorrarABB(&(*raiz)->ligaIzq);
    (*raiz)->ligaIzq = NULL;
    BorrarABB(&(*raiz)->ligaDer);
    (*raiz)->ligaDer = NULL;
    free(*raiz);
    *raiz = NULL;
}

// Menú para trabajar con el ABB.
void menuABB() {
    char confirmacion = 'n';
    int opcion, info;
    NodoABB* raiz = NULL;
    
    do {
        system("cls");

        puts("==========================================");
        puts("===== MENU ÁRBOL BINARIO DE BÚSQUEDA =====");
        puts("==========================================\n");
        puts("1. INSERTAR UN ELEMENTO EN EL ABB.");
        puts("2. BUSCA UN ELEMENTO EN EL ABB");
        puts("3. ELIMINA UN ELEMENTO DEL ABB");
        puts("4. IMPRESION (EN INORDEN)");
        puts("5. REGRESAR AL MENU DE ARBOLES");

        printf("\nOpcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("¿Que elemento desea ingresar? ");
                scanf("%d", &info);
                InsertarEnABB(&raiz, info);
                break;
            case 2:
                if (raiz == NULL) {
                    printf("No hay elementos en el arbol.\n");
                } else {
                    printf("Ingrese el elemento que desea buscar: ");
                    scanf("%d", &info);
                    BuscarEnABB(raiz, info);
                }
                break;
            case 3:
                if (raiz == NULL) {
                    printf("No hay elementos en el arbol\n");
                } else {
                    printf("Ingrese la informacion del elemento a eliminar: ");
                    scanf("%d", &info);
                    NodoABB* raizTemp = crearNodoABB(info+1);
                    raizTemp->ligaIzq = raiz;
                    BorrarNodoABB(&raizTemp, info);
                    free(raizTemp);
                }
                break;
            case 4:
                if (raiz == NULL) {
                    printf("No hay elementos en el arbol\n");
                } else {
                    ImprimirInorden(raiz);
                }
                break;
            case 5:
                do {
                    printf("¿Está seguro de regresar al menu de arboles (s/n)? ");
                    scanf(" %c", &confirmacion);
                    confirmacion = tolower(confirmacion);
                    if (confirmacion != 's' && confirmacion != 'n') {
                        printf("Opcion invalida, vuelva a ingresar.\n");
                    }
                } while (confirmacion != 's' && confirmacion != 'n');
                break;

            default:
                printf("Opcion invalida, vuelva a intentar.\n");
        }
        
        putchar('\n');
        system("pause");
    } while (opcion != 5 || confirmacion == 'n');
    BorrarABB(&raiz);
}