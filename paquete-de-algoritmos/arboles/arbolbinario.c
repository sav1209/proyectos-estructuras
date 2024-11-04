#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "arbolbinario.h"

// Crea un nuevo nodo con ligas nulas.
NodoArbol* crearNodoArbol(int info) {
    NodoArbol* nuevoNodo = (NodoArbol*) malloc(sizeof(NodoArbol));
    if (nuevoNodo == NULL) {
        printf("Error al asignar memoria.\n");
        exit(1);
    }
    nuevoNodo->info = info;
    nuevoNodo->ligaIzq = NULL;
    nuevoNodo->ligaDer = NULL;
    return nuevoNodo;
}

// Función para cargar el arbol
void Carga(NodoArbol* elemento) {
    char resp;
    int info;

    printf("Escribe la parte info del nodo: ");
    scanf("%d", &info);
    elemento->info = info;

    printf("¿El nodo con %d tiene hijo izquierdo (s/n)? ", info);
    scanf(" %c", &resp);
    if (resp == 's' || resp == 'S') {
        NodoArbol* otro = crearNodoArbol(0);
        elemento->ligaIzq = otro;
        Carga(otro);
    }

    printf("¿El nodo con %d tiene hijo derecho (s/n)? ", info);
    scanf(" %c", &resp);
    if (resp == 's' || resp == 'S') {
        NodoArbol* otro = crearNodoArbol(0);
        elemento->ligaDer = otro;
        Carga(otro);
    }
}

// Funcion para preorden.
void preorden(NodoArbol* elemento) {
    if (elemento != NULL) {
        printf("%d\n", elemento->info);
        preorden(elemento->ligaIzq);
        preorden(elemento->ligaDer);
    }
}

// Funcion para inorden
void inorden(NodoArbol* elemento) {
    if (elemento != NULL) {
        inorden(elemento->ligaIzq);
        printf("%d\n", elemento->info);
        inorden(elemento->ligaDer);
    }
}

//Funcion para posorden
void posorden(NodoArbol* elemento) {
    if (elemento != NULL) {
        posorden(elemento->ligaIzq);
        posorden(elemento->ligaDer);
        printf("%d\n", elemento->info);
    }
}

// Borra todos los nodos de un arbol binario.
void BorrarArbol(NodoArbol** raiz) {
    // No hay nada que borrar
    if (*raiz == NULL) {
        return;
    }

    BorrarArbol(&(*raiz)->ligaIzq);
    (*raiz)->ligaIzq = NULL;
    BorrarArbol(&(*raiz)->ligaDer);
    (*raiz)->ligaDer = NULL;
    free(*raiz);
    *raiz = NULL;
}

// Menú para trabajar con el árbol binario.
void menuArbolBinario() {
    char confirmacion = 'n';
    int opcion;
    NodoArbol* raiz = NULL;

    do {
        system("cls");

        puts("==========================");
        puts("=== MENU ARBOL BINARIO ===");
        puts("==========================\n");
        puts("1. CARGAR ELEMENTOS EN EL ARBOL");
        puts("2. IMPRESION EN PREORDEN");
        puts("3. IMPRESION EN INORDEN");
        puts("4. IMPRESION EN POSORDEN");
        puts("5. REGRESAR AL MENU DE ARBOLES");

        printf("\nOpcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (raiz == NULL) {
                    raiz = crearNodoArbol(0);
                }
                Carga(raiz);
                break;
            case 2:
                if (raiz == NULL) {
                    printf("No hay elementos en el arbol\n");
                } else {
                    preorden(raiz);
                }
                break;
            case 3:
                if (raiz == NULL) {
                    printf("No hay elementos en el arbol\n");
                } else {
                    inorden(raiz);
                }
                break;
            case 4:
                if (raiz == NULL) {
                    printf("No hay elementos en el arbol\n");
                } else {
                    posorden(raiz);
                }
                break;
            case 5:
                do {
                    printf("¿Está seguro de regresar al menu de arboles (s/n)? ");
                    scanf(" %c", &confirmacion);
                    confirmacion = tolower(confirmacion);
                    if (confirmacion != 's' && confirmacion != 'n') {
                        printf("Opcion invalida, vuelva a ingresar.\n\n");
                    }
                } while (confirmacion != 's' && confirmacion != 'n');
                break;

            default:
                printf("Opcion invalida, vuelva a intentar.\n");
        }

        putchar('\n');
        system("pause");
    } while (opcion != 5 || confirmacion == 'n');
    BorrarArbol(&raiz);
}