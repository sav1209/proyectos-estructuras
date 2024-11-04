#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "colasimple.h"

// Crea un nuevo nodo con liga nula.
NodoColaSim *crearNodoColaSim(int info) {
    NodoColaSim *nuevoNodo = (NodoColaSim *)malloc(sizeof(NodoColaSim));
    nuevoNodo->info = info;
    nuevoNodo->liga = NULL;
    return nuevoNodo;
}

// 1. ALGORITMO QUE REALICE LA OPERACIÓN PUSH (INSERTAR POR EL FINAL)
void pushColSim(NodoColaSim **frente, NodoColaSim **final, int info) {
    NodoColaSim *nuevoNodo = crearNodoColaSim(info);

    if (*final == NULL) {
        // Si la cola está vacía, el nuevo nodo es el primero y el último.
        *frente = *final = nuevoNodo;
    } else {
        // Si ya hay nodos en la cola, el último apunta al nuevo nodo.
        (*final)->liga = nuevoNodo;
        *final = nuevoNodo;
    }
    printf("Elemento insertado por el final de la cola.\n");
}

// 2. ALGORITMO QUE REALICE LA OPERACIÓN POP (ELIMINAR POR EL PRINCIPIO)
void popColSim(NodoColaSim **frente, NodoColaSim **final) {
    if (*frente == NULL) {
        printf("La cola está vacía.\n");
        return;
    }

    NodoColaSim *temp = *frente;
    *frente = (*frente)->liga;

    // Si eliminamos el último nodo, el puntero `final` también debe ser nulo.
    if (*frente == NULL) {
        *final = NULL;
    }

    free(temp);
    printf("Elemento eliminado del principio de la cola.\n");
}

// 3. ALGORITMO QUE IMPRIMA LOS ELEMENTOS DE LA COLA
void imprimirColSim(NodoColaSim *frente) {
    if (frente == NULL) {
        printf("La cola está vacía.\n");
    } else {
        NodoColaSim *temp = frente;
        while (temp != NULL) {
            printf("-> %d\n", temp->info);
            temp = temp->liga;
        }
    }
}

// Borra todos los nodos de una cola.
void borrarColSim(NodoColaSim **frente, NodoColaSim **final) {
    NodoColaSim *temp;
    while (*frente != NULL) {
        temp = *frente;
        *frente = (*frente)->liga;
        free(temp);
    }
    *final = NULL;
}

// MENU
void menuCola() {
    char confirmacion = 'n';
    int opcion, info;
    NodoColaSim *frente = NULL;
    NodoColaSim *final = NULL;

    do {
        system("cls");

        puts("==============================");
        puts("===== MENU COLAS SIMPLES =====");
        puts("==============================\n");
        puts("1. PUSH (INSERTAR POR EL FINAL)");
        puts("2. POP (ELIMINAR POR EL PRINCIPIO)");
        puts("3. IMPRIME LOS ELEMENTOS DE LA COLA");
        puts("4. REGRESAR AL MENU DE COLAS");

        printf("\nOpcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                printf("Ingrese el dato que desea agregar a la cola: ");
                scanf("%d", &info);
                pushColSim(&frente, &final, info);
                break;
            case 2:
                popColSim(&frente, &final);
                break;
            case 3:
                imprimirColSim(frente);
                break;
            case 4:
                do {
                    printf("¿Está seguro de regresar al menu de colas (s/n)? ");
                    scanf(" %c", &confirmacion);
                    confirmacion = tolower(confirmacion);
                    if (confirmacion != 's' && confirmacion != 'n') {
                        printf("Opción inválida, vuelva a ingresar.\n\n");
                    }
                } while (confirmacion != 's' && confirmacion != 'n');
                break;
            default:
                printf("Opción inválida, vuelva a intentar.\n");
        }
        putchar('\n');
        system("pause");
    } while (opcion != 4 || confirmacion == 'n');
    borrarColSim(&frente, &final);
}