// ABB: ÁRBOL BINARIO DE BÚSQUEDA

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct NodoABB {
    int info;
    struct NodoABB* ligaIzq;
    struct NodoABB* ligaDer;
} NodoABB;

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

// RETORNA LA DIRECCIÓN DEL PADRE DEL NODO MÁS A LA IZQUIERDA
NodoABB* ExtremoIzquierdo(NodoABB* elemento, NodoABB* padre) {
    if(elemento->ligaIzq == NULL) {
        return padre;
    }
    else {
        return ExtremoIzquierdo(elemento->ligaIzq, elemento);
    }
}


// ALGORITMO QUE ELIMINE UN ELEMENTO EN UN ABB
void BorrarNodoABB(NodoABB** elemento, int info, NodoABB* padre) {
    if((*elemento) != NULL) {
        if(info == (*elemento)->info) {
            NodoABB *porEliminar = *elemento;
            // EL ELEMENTO A BORRAR ES UNA HOJA, SIMPLEMENTE SE SUPRIME
            if((porEliminar->ligaIzq == NULL) && (porEliminar->ligaDer == NULL)) {
                if(padre->ligaIzq == porEliminar) {
                    padre->ligaIzq = NULL;
                } else {
                    padre->ligaDer = NULL;
                }
                free(porEliminar);
                return;
            }

            // EL ELEMENTO A BORRAR TIENE UN SOLO DESCENDIENTE, ENTONCES SUSTITUIRSE POR ESE DESCENDIENTE
            if(((porEliminar->ligaIzq == NULL) && (porEliminar->ligaDer != NULL)) || ((porEliminar->ligaIzq != NULL) && (porEliminar->ligaDer == NULL))) {
                NodoABB *hijo = (porEliminar->ligaIzq != NULL) ? (porEliminar->ligaIzq) : (porEliminar->ligaDer);
                if(padre->ligaIzq == porEliminar) {
                    padre->ligaIzq = hijo;
                } else {
                    padre->ligaDer = hijo;
                }
                free(porEliminar);
                return;
            }

            // EL ELEMENTO A BORRAR TIENE DOS DESCENDIENTES
            NodoABB* padreExtIzq = ExtremoIzquierdo(porEliminar->ligaDer, NULL);
            if(padreExtIzq != NULL) {
                NodoABB* subarbolDer = padreExtIzq->ligaIzq->ligaDer;
                porEliminar->info = padreExtIzq->ligaIzq->info;
                free(padreExtIzq->ligaIzq);
                padreExtIzq->ligaIzq = subarbolDer;
                return;
            } else {
                NodoABB* subarbolDer = porEliminar->ligaDer->ligaDer;
                porEliminar->info = porEliminar->ligaDer->info;
                free(porEliminar->ligaDer);
                porEliminar->ligaDer = subarbolDer;
                return;
            }
        }

        if(info < (*elemento)->info) {
            if((*elemento)->ligaIzq != NULL) {
                BorrarNodoABB(&(*elemento)->ligaIzq, info, *elemento);
            }
        } else {
            if((*elemento)->ligaDer != NULL) {
                BorrarNodoABB(&(*elemento)->ligaDer, info, *elemento);
            }
        }

        return;
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
        puts("==========================================");
        puts("===== MENU ÁRBOL BINARIO DE BÚSQUEDA =====");
        puts("==========================================\n");
        puts("1. INSERTAR UN ELEMENTO EN EL ABB.");
        puts("2. BUSCA UN ELEMENTO EN EL ABB");
        puts("3. ELIMINA UN ELEMENTO DEL ABB");
        puts("4. IMPRESION (EN INORDEN)");
        puts("5. REGRESAR AL MENU PRINCIPAL");

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
                    BorrarNodoABB(&raiz, info, NULL);
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
                    printf("¿Está seguro de regresar al menú principal (s/n)? ");
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
    } while (opcion != 5 || confirmacion == 'n');
    BorrarABB(&raiz);
}

int main() {
    menuABB();
    return 0;
}