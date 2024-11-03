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


void push(NodoCola **inicio, int info, int prioridad) {
    if(prioridad < 1 || prioridad > 5) {
        printf("Prioridad invalida, debe estar en [1,5]. No se agregara el elemento\n");
        return;
    }

    NodoCola *nuevoNodo = crearNodoCola(info, prioridad);
    if (*inicio == NULL) {
        *inicio = nuevoNodo;
        return;
    }

    NodoCola *actual = *inicio;
    NodoCola *anterior = NULL;
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


void pop(NodoCola **inicio) {
    if (*inicio == NULL) {
        printf("La cola está vacía.\n");
        return;
    }
    NodoCola *temp = *inicio;
    *inicio = (*inicio)->liga;
    printf("Elemento %d con prioridad %d eliminado.\n", temp->info, temp->prioridad);
    free(temp);
}


// IMPRIME LA COLA CON LA PRIORIDAD QUE TIENE CADA NODO
void imprimirCola(NodoCola *inicio) {
    if (inicio == NULL) {
        printf("La cola está vacía.\n");
        return;
    }
    printf("Contenido de la cola con prioridad:\n");
    NodoCola *actual = inicio;
    while (actual != NULL) {
        printf("-> Elemento: %d, Prioridad: %d\n", actual->info, actual->prioridad);
        actual = actual->liga;
    }
}


// BORRA TODOS LOS NODOS DE LA COLA CON PRIORIDAD
void borrarCola(NodoCola **inicio) {
    while (*inicio != NULL) {
        NodoCola *temp = *inicio;
        *inicio = (*inicio)->liga;
        free(temp);
    }
}

// MENU DE LA COLA CON PRIORIDAD
void menuColaPrioridad() {
    char confirmacion = 'n';
    int opcion, info, prioridad;
    NodoCola *cola = NULL;

    do {
        puts("==============================");
        puts("===== COLA CON PRIORIDAD =====");
        puts("==============================\n");
        puts("1. PUSH (AGREGAR ELEMENTO)");
        puts("2. POP (ELIMINAR ELEMENTO)");
        puts("3. IMPRIMIR ELEMENTOS");
        puts("4. REGRESAR AL MENU PRINCIPAL");

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
