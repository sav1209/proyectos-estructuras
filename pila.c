// Se implementara la pila manejando la cola de una lista circular.

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct NodoPila {
    int info;
    struct NodoPila *liga;
} NodoPila;

// Crea un nuevo nodo con liga nula.
NodoPila *crearNodoPila(int info) {
    NodoPila *nuevoNodo = (NodoPila *)malloc(sizeof(NodoPila));
    nuevoNodo->info = info;
    nuevoNodo->liga = NULL;
    return nuevoNodo;
}

// 1. ALGORITMO QUE REALICE LA OPERACIÓN PUSH (INSERTAR POR EL FINAL)
void push(NodoPila **final, int info) {
    if (*final == NULL) {
        *final = crearNodoPila(info);
        (*final)->liga = *final;
        return;
    }

    NodoPila *nuevoNodo = crearNodoPila(info);
    nuevoNodo->liga = (*final)->liga;
    (*final)->liga = nuevoNodo;
    *final = (*final)->liga;
}

// 2. ALGORITMO QUE REALICE LA OPERACIÓN POP (ELIMINAR POR EL FINAL)
void pop(NodoPila **final) {
    if (*final == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    NodoPila *temp = *final;

    if (temp->liga == *final) {
        free(temp);
        *final = NULL;
        printf("Se ha eliminado el único elemento de la lista.\n");
        return;
    }

    while (temp->liga != *final) {
        temp = temp->liga;
    }

    temp->liga = (*final)->liga;
    free(*final);
    *final = temp;

    printf("Elemento eliminado del final de la pila.\n");
}

// 3. ALGORITMO QUE IMPRIMA LOS ELEMENTOS DE LA PILA
void imprimirPila(NodoPila *final) {
    if (final == NULL) {
        printf("La lista esta vacia.\n");
    } else {
        NodoPila *temp = final->liga;
        do {
            printf("-> %d\n", temp->info);
            temp = temp->liga;
        } while (temp != final->liga);
    }
}

// Borra todos los nodos de una pila.
void borrarPila(NodoPila **final) {
    if (*final == NULL) {
        return;
    }
    
    NodoPila *aEliminar;
    while ((*final)->liga != *final) {
        aEliminar = (*final)->liga;
        (*final)->liga = aEliminar->liga;
        free(aEliminar);
    }

    free(*final);
    *final = NULL;
}

// MENU
void menuListasCirculares() {
    char confirmacion = 'n';
    int opcion, info;
    NodoPila *pila = NULL;

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
    borrarPila(&pila);
    imprimirPila(pila);
}

int main() {

    menuListasCirculares();

    return 0;
}
