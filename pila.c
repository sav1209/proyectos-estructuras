// Se implementara la pila con una lista circular y manipulando el último nodo de la misma.
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// Estructura para cada nodo de la pila.
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
    // Si el último nodo apunta a NULL, no existe una pila, por lo tanto el nodo a agregar será el primero.
    if (*final == NULL) {
        *final = crearNodoPila(info);
        (*final)->liga = *final;
        return;
    }

    // Si ya hay nodos en la pila, la liga del último nodo ('final') debe apuntar al nuevo nodo y se cambia nuevo nodo ahora debe ser el último.
    NodoPila *nuevoNodo = crearNodoPila(info);
    nuevoNodo->liga = (*final)->liga;
    (*final)->liga = nuevoNodo;
    *final = (*final)->liga;
}

// 2. ALGORITMO QUE REALICE LA OPERACIÓN POP (ELIMINAR POR EL FINAL)
void pop(NodoPila **final) {
    if (*final == NULL) {
        printf("La pila está vacía.\n");
        return;
    }

    if ((*final)->liga == *final) {
        free(*final);
        *final = NULL;
        printf("Se ha eliminado el único elemento de la pila.\n");
        return;
    }

    NodoPila *temp = *final;
    // Se itera hasta el penúltimo nodo de la pila.
    while (temp->liga != *final) {
        temp = temp->liga;
    }

    // Se elimina el último nodo y el penúltimo pasa a ser el último.
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
        // Se apunta utiliza un puntero auxiliar al primer nodo de la pila y se imprime cada nodo hasta que el puntero auxilar vuelva a ser el primero.
        NodoPila *temp = final->liga;
        do {
            printf("-> %d\n", temp->info);
            temp = temp->liga;
        } while (temp != final->liga);
    }
}

// Borra todos los nodos de una pila.
void borrarPila(NodoPila **final) {
    // Si no hay pila, no hay nada que borrar.
    if (*final == NULL) {
        return;
    }
    
    // Borra el primer nodo de la pila hasta que solo quede el nodo final.
    NodoPila *aEliminar;
    while ((*final)->liga != *final) {
        aEliminar = (*final)->liga;
        (*final)->liga = aEliminar->liga;
        free(aEliminar);
    }
    // Se borra también el primer nodo y se indica que la pila esta vacía.
    free(*final);
    *final = NULL;
}

// MENU
void menuPilas() {
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
}

int main() {

    menuListasCirculares();

    return 0;
}
