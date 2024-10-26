#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// Estructura para cada nodo de la cola.
typedef struct NodoCola {
    int info;
    struct NodoCola *liga;
} NodoCola;

// Crea un nuevo nodo con liga nula.
NodoCola *crearNodoCola(int info) {
    NodoCola *nuevoNodo = (NodoCola *)malloc(sizeof(NodoCola));
    nuevoNodo->info = info;
    nuevoNodo->liga = NULL;
    return nuevoNodo;
}

// 1. ALGORITMO QUE REALICE LA OPERACIÓN PUSH (INSERTAR POR EL FINAL)
void push(NodoCola **frente, NodoCola **final, int info) {
    NodoCola *nuevoNodo = crearNodoCola(info);

    if (*final == NULL) {
        // Si la cola está vacía, el nuevo nodo es el primero y el último.
        *frente = *final = nuevoNodo;
    } else {
        // Si ya hay nodos en la cola, el último apunta al nuevo nodo.
        (*final)->liga = nuevoNodo;
        *final = nuevoNodo;
    }
}

// 2. ALGORITMO QUE REALICE LA OPERACIÓN POP (ELIMINAR POR EL PRINCIPIO)
void pop(NodoCola **frente, NodoCola **final) {
    if (*frente == NULL) {
        printf("La cola está vacía.\n");
        return;
    }

    NodoCola *temp = *frente;
    *frente = (*frente)->liga;

    // Si eliminamos el último nodo, el puntero `final` también debe ser nulo.
    if (*frente == NULL) {
        *final = NULL;
    }

    free(temp);
    printf("Elemento eliminado del principio de la cola.\n");
}

// 3. ALGORITMO QUE IMPRIMA LOS ELEMENTOS DE LA COLA
void imprimirCola(NodoCola *frente) {
    if (frente == NULL) {
        printf("La cola está vacía.\n");
    } else {
        NodoCola *temp = frente;
        while (temp != NULL) {
            printf("-> %d\n", temp->info);
            temp = temp->liga;
        }
    }
}

// Borra todos los nodos de una cola.
void borrarCola(NodoCola **frente, NodoCola **final) {
    NodoCola *temp;
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
    NodoCola *frente = NULL;
    NodoCola *final = NULL;

    puts("======================");
    puts("===== MENU COLAS =====");
    puts("======================\n");
    puts("1. PUSH (INSERTAR POR EL FINAL)");
    puts("2. POP (ELIMINAR POR EL PRINCIPIO)");
    puts("3. IMPRIME LOS ELEMENTOS DE LA COLA");
    puts("4. REGRESAR AL MENU PRINCIPAL");

    do {
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

