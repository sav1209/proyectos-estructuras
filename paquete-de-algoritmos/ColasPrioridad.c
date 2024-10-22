#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// Estructura para cada nodo de la cola con prioridad
typedef struct NodoCola {
    int info;
    int prioridad;
    struct NodoCola *liga;
} NodoCola;

// Crea un nuevo nodo con liga nula 
NodoCola *crearNodoCola(int info, int prioridad) {
    NodoCola *nuevoNodo = (NodoCola *)malloc(sizeof(NodoCola));
    nuevoNodo->info = info;
    nuevoNodo->prioridad = prioridad;
    nuevoNodo->liga = NULL;
    return nuevoNodo;
}

// PUSH POR EL FINAL 
void push(NodoCola **final, int info, int prioridad) {
    NodoCola *nuevoNodo = crearNodoCola(info, prioridad);
    if (*final == NULL) {
        *final = nuevoNodo;
        return;
    }

    NodoCola *actual = *final;
    NodoCola *anterior = NULL;
    while (actual != NULL && actual->prioridad <= prioridad) {
        anterior = actual;
        actual = actual->liga;
    }

    if (anterior == NULL) {
        nuevoNodo->liga = *final;
        *final = nuevoNodo;
    } else {
        anterior->liga = nuevoNodo;
        nuevoNodo->liga = actual;
    }
    printf("Elemento %d con prioridad %d agregado.\n", info, prioridad);
}

// POP POR O EL INICIO
void pop(NodoCola **final) {
    if (*final == NULL) {
        printf("La cola está vacía.\n");
        return;
    }
    NodoCola *temp = *final;
    *final = (*final)->liga;
    printf("Elemento %d eliminado.\n", temp->info);
    free(temp);
}

// IMPRIME LA COLA CON LA PRIORIDAD QUE TIENE CADA NODO
void imprimirCola(NodoCola *final) {
    if (final == NULL) {
        printf("La cola está vacía.\n");
        return;
    }
    printf("Contenido de la cola con prioridad:\n");
    NodoCola *actual = final;
    while (actual != NULL) {
        printf("Elemento: %d, Prioridad: %d\n", actual->info, actual->prioridad);
        actual = actual->liga;
    }
}

// BORRA TODOS LOS NODOS DE LA COLA CON PRIORIDAD
void borrarCola(NodoCola **final) {
    while (*final != NULL) {
        NodoCola *temp = *final;
        *final = (*final)->liga;
        free(temp);
    }
    printf("Memoria liberada.\n");
}

// MENU DE LA COLA CON PRIORIDAD
void menuColaPrioridad() {
    char confirmacion = 'n';
    int opcion, info, prioridad;
    NodoCola *cola = NULL;

    puts("===========================");
    puts("===== COLA CON PRIORIDAD =====");
    puts("===========================\n");
    puts("1. PUSH (AGREGAR ELEMENTO)");
    puts("2. POP (ELIMINAR ELEMENTO)");
    puts("3. IMPRIMIR ELEMENTOS");
    puts("4. SALIR");

    do {
        printf("\nOpcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
        case 1:
            printf("Ingrese el valor del elemento: ");
            scanf("%d", &info);
            printf("Ingrese la prioridad del elemento: ");
            scanf("%d", &prioridad);
            push(&cola, info, prioridad);
            break;
        case 2:
            pop(&cola);
            break;
        case 3:
            imprimirCola(cola);
            break;
        case 4:
            do {
                printf("¿Está seguro de salir (s/n)? ");
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

    borrarCola(&cola);
}

int main() {
    menuColaPrioridad();
    return 0;
}
