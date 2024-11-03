#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "colaprioridad.h"

// Crea un nuevo nodo con liga nula 
NodoColaPrio *crearNodoColaPrio(int info, int prioridad) {
    NodoColaPrio *nuevoNodo = (NodoColaPrio *)malloc(sizeof(NodoColaPrio));
    nuevoNodo->info = info;
    nuevoNodo->prioridad = prioridad;
    nuevoNodo->liga = NULL;
    return nuevoNodo;
}


void pushColPrio(NodoColaPrio **inicio, int info, int prioridad) {
    if(prioridad < 1 || prioridad > 5) {
        printf("Prioridad invalida, debe estar en [1,5]. No se agregara el elemento\n");
        return;
    }

    NodoColaPrio *nuevoNodo = crearNodoColaPrio(info, prioridad);
    if (*inicio == NULL) {
        *inicio = nuevoNodo;
        return;
    }

    NodoColaPrio *actual = *inicio;
    NodoColaPrio *anterior = NULL;
    while (actual != NULL && actual->prioridad <= prioridad) {
        anterior = actual;
        actual = actual->liga;
    }

    if (anterior == NULL) {
        nuevoNodo->liga = *inicio;
        *inicio = nuevoNodo;
    } else {
        anterior->liga = nuevoNodo;
        nuevoNodo->liga = actual;
    }
    printf("Elemento %d con prioridad %d agregado.\n", info, prioridad);
}


void popColPrio(NodoColaPrio **inicio) {
    if (*inicio == NULL) {
        printf("La cola está vacía.\n");
        return;
    }
    NodoColaPrio *temp = *inicio;
    *inicio = (*inicio)->liga;
    printf("Elemento %d con prioridad %d eliminado.\n", temp->info, temp->prioridad);
    free(temp);
}


// IMPRIME LA COLA CON LA PRIORIDAD QUE TIENE CADA NODO
void imprimirColPrio(NodoColaPrio *inicio) {
    if (inicio == NULL) {
        printf("La cola está vacía.\n");
        return;
    }
    printf("Contenido de la cola con prioridad:\n");
    NodoColaPrio *actual = inicio;
    while (actual != NULL) {
        printf("-> Elemento: %d, Prioridad: %d\n", actual->info, actual->prioridad);
        actual = actual->liga;
    }
}


// BORRA TODOS LOS NODOS DE LA COLA CON PRIORIDAD
void borrarColPrio(NodoColaPrio **inicio) {
    while (*inicio != NULL) {
        NodoColaPrio *temp = *inicio;
        *inicio = (*inicio)->liga;
        free(temp);
    }
}

// MENU DE LA COLA CON PRIORIDAD
void menuColaPrioridad() {
    char confirmacion = 'n';
    int opcion, info, prioridad;
    NodoColaPrio *cola = NULL;

    do {
        puts("==============================");
        puts("===== COLA CON PRIORIDAD =====");
        puts("==============================\n");
        puts("1. PUSH (AGREGAR ELEMENTO)");
        puts("2. POP (ELIMINAR ELEMENTO)");
        puts("3. IMPRIMIR ELEMENTOS");
        puts("4. REGRESAR AL MENU DE COLAS");

        printf("\nOpcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
        case 1:
            printf("Ingrese el valor del elemento: ");
            scanf("%d", &info);
            printf("Ingrese la prioridad del elemento: ");
            scanf("%d", &prioridad);
            pushColPrio(&cola, info, prioridad);
            break;
        case 2:
            popColPrio(&cola);
            break;
        case 3:
            imprimirColPrio(cola);
            break;
        case 4:
            do {
                printf("¿Está seguro de regresar al menu de colas (s/n)? ");
                scanf(" %c", &confirmacion);
                confirmacion = tolower(confirmacion);
                if (confirmacion != 's' && confirmacion != 'n') {
                    printf("Opción inválida, vuelva a ingresar.\n");
                }
            } while (confirmacion != 's' && confirmacion != 'n');
            break;
        default:
            printf("Opción inválida, vuelva a intentar.\n");
        }
    } while (opcion != 4 || confirmacion == 'n');

    borrarColPrio(&cola);
}