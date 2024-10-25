// ABB: ÁRBOL BINARIO DE BÚSQUEDA

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct NodoABB {
    int info;
    struct NodoABB* ligaIzq;
    struct NodoABB* ligaDer;
} NodoABB;

// Crea un nuevo nodo con liga nula.
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

// ALGORITMO QUE IMPRIME LOS ELEMENTOS DEL ÁRBOL MEDIANTE UN RECORRIDO EN PREORDEN
void ImprimirPreorden(NodoABB* elemento) {
    if (elemento != NULL) {
        printf("%d\n", elemento->info);
        ImprimirPreorden(elemento->ligaIzq);
        ImprimirPreorden(elemento->ligaDer);
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

//ALGORITMO QUE IMPRIME LOS ELEMENTOS DEL ÁRBOL MEDIANTE UN RECORRIDO EN POSORDEN
void ImprimirPosorden(NodoABB* elemento) {
    if (elemento != NULL) {
        ImprimirPosorden(elemento->ligaIzq);
        ImprimirPosorden(elemento->ligaDer);
        printf("%d\n", elemento->info);
    }
}


// ALGORITMO QUE BUSQUE UN ELEMENTO EN UN ABB


// ALGORITMO QUE ELIMINE UN ELEMENTO EN UN ABB


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

    puts("==========================================");
    puts("===== MENU ÁRBOL BINARIO DE BÚSQUEDA =====");
    puts("==========================================\n");
    puts("1. INSERTAR UN ELEMENTO EN EL ABB.");
    puts("2. BUSCA UN ELEMENTO EN EL ABB");
    puts("3. ELIMINA UN ELEMENTO DEL ABB");
    puts("4. IMPRESION EN PREORDEN");
    puts("5. IMPRESION EN INORDEN");
    puts("6. IMPRESION EN POSORDEN");
    puts("7. REGRESAR AL MENU PRINCIPAL");

    do {
        printf("\nOpcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("¿Que elemento desea ingresar? ");
                scanf("%d", &info);
                InsertarEnABB(&raiz, info);
                break;
            case 2:
                // Por implementar
                break;
            case 3:
                // Por implementar
                break;
            case 4:
                if (raiz == NULL) {
                    printf("No hay elementos en el arbol\n");
                } else {
                    ImprimirPreorden(raiz);
                }
                break;
            case 5:
                if (raiz == NULL) {
                    printf("No hay elementos en el arbol\n");
                } else {
                    ImprimirInorden(raiz);
                }
                break;
            case 6:
                if (raiz == NULL) {
                    printf("No hay elementos en el arbol\n");
                } else {
                    ImprimirPosorden(raiz);
                }
                break;
            case 7:
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
    } while (opcion != 7 || confirmacion == 'n');
    BorrarABB(&raiz);
}

int main() {
    menuABB();
    return 0;
}