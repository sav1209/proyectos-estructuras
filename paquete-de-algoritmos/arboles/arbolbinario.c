#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct NodoArbol {
    int info;
    struct NodoArbol* ligaIzq;
    struct NodoArbol* ligaDer;
} NodoArbol;

// Crea un nuevo nodo con liga nula.
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

    printf("¿El nodo tiene hijo izquierdo (s/n)? ");
    scanf(" %c", &resp);
    if (resp == 's' || resp == 'S') {
        NodoArbol* otro = crearNodoArbol(0);
        elemento->ligaIzq = otro;
        Carga(otro);
    }

    printf("¿El nodo tiene hijo derecho (s/n)? ");
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

// Menú para trabajar con el árbol binario.
void menuArbolBinario() {
    char confirmacion = 'n';
    int opcion;
    NodoArbol* raiz = NULL;

    puts("========================");
    puts("== MENU Arbol Binario ==");
    puts("========================\n");
    puts("1. LECTURA EN PREORDEN");
    puts("2. LECTURA EN INORDEN");
    puts("3. LECTURA EN POSORDEN");
    puts("4. CARGAR ELEMENTOS EN EL ARBOL");
    puts("5. REGRESAR AL MENU PRINCIPAL");

    do {
        printf("\nOpcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                if (raiz == NULL) {
                    printf("No hay elementos en el arbol\n");
                } else {
                    preorden(raiz);
                }
                break;

            case 2:
                printf("Función inorden aún no implementada.\n");
                break;

            case 3:
                printf("Función posorden aún no implementada.\n");
                break;

            case 4:
                if (raiz == NULL) {
                    raiz = crearNodoArbol(0);
                }
                Carga(raiz);
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
}

int main() {
    menuArbolBinario();
    return 0;
}
