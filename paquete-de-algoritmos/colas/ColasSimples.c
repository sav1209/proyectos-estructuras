#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// Estructura para cada nodo de la cola.
typedef struct NodoColaSim {
    int info;
    struct NodoColaSim *liga;
} NodoColaSim;

// Crea un nuevo nodo con liga nula.
NodoColaSim *crearNodoColaSim(int info) {
    NodoColaSim *nuevoNodo = (NodoColaSim *)malloc(sizeof(NodoColaSim));
    nuevoNodo->info = info;
    nuevoNodo->liga = NULL;
    return nuevoNodo;
}

// 1. ALGORITMO QUE REALICE LA OPERACIÓN PUSH (INSERTAR POR EL FINAL)
void push(NodoColaSim **frente, NodoColaSim **final, int info) {
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
void pop(NodoColaSim **frente, NodoColaSim **final) {
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
void imprimirCola(NodoColaSim *frente) {
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
void borrarCola(NodoColaSim **frente, NodoColaSim **final) {
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
        puts("======================");
        puts("===== MENU COLAS =====");
        puts("======================\n");
        puts("1. PUSH (INSERTAR POR EL FINAL)");
        puts("2. POP (ELIMINAR POR EL PRINCIPIO)");
        puts("3. IMPRIME LOS ELEMENTOS DE LA COLA");
        puts("4. REGRESAR AL MENU PRINCIPAL");

        printf("\nOpcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
        case 1:
            printf("Ingrese el dato que desea agregar a la cola: ");
            scanf("%d", &info);
            push(&frente, &final, info);
            break;
        case 2:
            pop(&frente, &final);
            break;
        case 3:
            imprimirCola(frente);
            break;
        case 4:
            do {
                printf("¿Está seguro de regresar al menú principal (s/n)? ");
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
    borrarCola(&frente, &final);
}

int main() {
    menuCola();
    return 0;
}

