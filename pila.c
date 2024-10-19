// Se implementara la pila manejando la cola de una lista circular.

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct NodoLC {
    int info;
    struct NodoLC *liga;
} NodoLC;

// Crea un nuevo nodo con liga nula.
NodoLC *crearNodoLC(int info) {
    NodoLC *nuevoNodo = (NodoLC *)malloc(sizeof(NodoLC));
    nuevoNodo->info = info;
    nuevoNodo->liga = NULL;
    return nuevoNodo;
}

// 1. ALGORITMO QUE REALICE LA OPERACIÓN PUSH (INSERTAR POR EL FINAL)
void push(NodoLC **pila, int info) {
    if (*pila == NULL) {
        *pila = crearNodoLC(info);
        (*pila)->liga = *pila;
        return;
    }

    NodoLC *nuevoNodo = crearNodoLC(info);
    nuevoNodo->liga = (*pila)->liga;
    (*pila)->liga = nuevoNodo;
    *pila = (*pila)->liga;
}

// 2. ALGORITMO QUE REALICE LA OPERACIÓN POP (ELIMINAR POR EL FINAL)
void pop(NodoLC **inicio) {
    if (*inicio == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    NodoLC *temp = *inicio;

    if (temp->liga == *inicio) {
        free(temp);
        *inicio = NULL;
        printf("Se ha eliminado el único elemento de la lista.\n");
        return;
    }

    while (temp->liga != *inicio) {
        temp = temp->liga;
    }

    temp->liga = (*inicio)->liga;
    free(*inicio);
    *inicio = temp;

    printf("Elemento eliminado del final de la lista.\n");
}

// 3. ALGORITMO QUE IMPRIMA LOS ELEMENTOS DE LA PILA
void imprimirPila(NodoLC *pila) {
    if (pila == NULL) {
        printf("La lista esta vacia.\n");
    } else {
        NodoLC *temp = pila->liga;
        do {
            printf("-> %d\n", temp->info);
            temp = temp->liga;
        } while (temp != pila->liga);
    }
}

// MENU
void menuListasCirculares() {
    char confirmacion = 'n';
    int opcion, info;
    NodoLC *pila = NULL;

    puts("======================");
    puts("===== MENU PILAS =====");
    puts("======================\n");
    puts("1. PUSH (INSERTAR POR EL FINAL)");
    puts("2. POP (ELIMINAR POR EL FINAL)");
    puts("3. IMPRIME LOS ELEMENTOS DE LA PILA");
    puts("4. REGRESAR AL MENU PRINCIPAL");

    do {
        printf("\nOpcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
        case 1:
            printf("Ingrese el dato que desea agregar a la pila: ");
            scanf("%d", &info);
            push(&pila, info);
            break;
        case 2:
            pop(&pila);
            break;
        case 3:
            imprimirPila(pila);
            break;
        case 4:
            do {
                printf("¿Esta seguro de regresar al menu principal (s/n)? ");
                scanf(" %c", &confirmacion);
                confirmacion = tolower(confirmacion);
                if (confirmacion != 's' && confirmacion != 'n')
                {
                    printf("Opcion invalida, vuelva a ingresar.\n");
                }
            } while (confirmacion != 's' && confirmacion != 'n');
            break;
        default:
            printf("Opcion invalida, vuelva a intentar.\n");
        }
    } while (opcion != 4 || confirmacion == 'n');
}

int main() {

    menuListasCirculares();

    return 0;
}
