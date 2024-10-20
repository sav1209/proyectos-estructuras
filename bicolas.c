#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

// Estructura para cada nodo de la bicola.
typedef struct NodoBicola {
    int info;
    struct NodoBicola *liga;
} NodoBicola;

// Crea un nuevo nodo con liga nula.
NodoBicola *crearNodoBicola(int info) {
    NodoBicola *nuevoNodo = (NodoBicola *) malloc(sizeof(NodoBicola));
    nuevoNodo->info = info;
    nuevoNodo->liga = NULL;
    return nuevoNodo;
}

// REALIZA LA OPERACIÓN PUSH INSERTANDO POR EL FRENTE
// push_front(NodoBicola **final)

// REALIZA LA OPERACIÓN PUSH INSERTANDO POR EL FINAL
void push_back(NodoBicola **final, int info) {
    // Si el último nodo apunta a NULL, no existe una bicola, por lo tanto el nodo a agregar será el primero.
    if (*final == NULL) {
        *final = crearNodoBicola(info);
        (*final)->liga = *final;
        return;
    }

    // Si ya hay nodos en la bicola, la liga del último nodo ('final') debe apuntar al nuevo nodo y se cambia nuevo nodo ahora debe ser el último.
    NodoBicola *nuevoNodo = crearNodoBicola(info);
    nuevoNodo->liga = (*final)->liga;
    (*final)->liga = nuevoNodo;
    *final = (*final)->liga;
}

// REALIZA LA OPERACIÓN POP ELIMINANDO POR EL FRENTE
// pop_front(NodoBicola **final)

// REALIZA LA OPERACIÓN POP ELIMINANDO POR EL FINAL
void pop_back(NodoBicola **final) {
    if (*final == NULL) {
        printf("La bicola está vacía.\n");
        return;
    }

    if ((*final)->liga == *final) {
        free(*final);
        *final = NULL;
        printf("Se ha eliminado el único elemento de la bicola.\n");
        return;
    }

    NodoBicola *temp = *final;
    // Se itera hasta el penúltimo nodo de la bicola.
    while (temp->liga != *final) {
        temp = temp->liga;
    }

    // Se elimina el último nodo y el penúltimo pasa a ser el último.
    temp->liga = (*final)->liga;
    free(*final);
    *final = temp;

    printf("Elemento eliminado del final de la bicola.\n");
}

// ALGORITMO QUE IMPRIMA LOS ELEMENTOS DE LA BICOLA
void imprimirBicola(NodoBicola *final) {
    if (final == NULL) {
        printf("La bicola esta vacia.\n");
    } else {
        // Se apunta utiliza un puntero auxiliar al primer nodo de la bicola y se imprime cada nodo hasta que el puntero auxilar vuelva a ser el primero.
        NodoBicola *temp = final->liga;
        do {
            printf("-> %d\n", temp->info);
            temp = temp->liga;
        } while (temp != final->liga);
    }
}

// Borra todos los nodos de una bicola.
void borrarBicola(NodoBicola **final) {
    // Si no hay bicola, no hay nada que borrar.
    if (*final == NULL) {
        return;
    }
    
    // Borra el primer nodo de la bicola hasta que solo quede el nodo final.
    NodoBicola *aEliminar;
    while ((*final)->liga != *final) {
        aEliminar = (*final)->liga;
        (*final)->liga = aEliminar->liga;
        free(aEliminar);
    }
    // Se borra también el primer nodo y se indica que la bicola esta vacía.
    free(*final);
    *final = NULL;
}

// MENU BICOLAS DE ENTRADA RESTRINGIDA
void menuBicolaEntradaRestringida() {
    char confirmacion = 'n';
    int opcion, info;
    NodoBicola *bicola = NULL;

    puts("===============================================");
    puts("===== MENU BICOLAS DE ENTRADA RESTRINGIDA =====");
    puts("===============================================\n");
    puts("1. PUSH POR EL FINAL");
    puts("2. POP POR EL FRENTE");
    puts("3. POP POR EL FINAL");
    puts("4. IMPRIME LOS ELEMENTOS DE LA BICOLA");
    puts("5. REGRESAR AL MENU PRINCIPAL");

    do {
        printf("\nOpcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
        case 1:
            printf("Ingrese el dato que desea agregar a la bicola por el final: ");
            scanf("%d", &info);
            push_back(&bicola, info);
            break;
        case 2:
            // pop_front(&bicola);
            break;
        case 3:
            pop_back(&bicola);
            break;
        case 4:
            imprimirBicola(bicola);
            break;
        case 5:
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
    } while (opcion != 5 || confirmacion == 'n');
    borrarBicola(&bicola);
}

// MENU BICOLAS DE SALIDA RESTRINGIDA
void menuBicolaSalidaRestringida() {
    char confirmacion = 'n';
    int opcion, info;
    NodoBicola *bicola = NULL;

    puts("===============================================");
    puts("===== MENU BICOLAS DE SALIDA RESTRINGIDA  =====");
    puts("===============================================\n");
    puts("1. PUSH POR EL FRENTE");
    puts("2. PUSH POR EL FINAL");
    puts("3. POP POR EL FINAL");
    puts("4. IMPRIME LOS ELEMENTOS DE LA BICOLA");
    puts("5. REGRESAR AL MENU PRINCIPAL");

    do {
        printf("\nOpcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
        case 1:
            printf("Ingrese el dato que desea agregar a la bicola por el frente: ");
            scanf("%d", &info);
            // push_front(&bicola, info);
            break;
        case 2:
            printf("Ingrese el dato que desea agregar a la bicola por el final: ");
            scanf("%d", &info);
            push_back(&bicola, info);
            break;
        case 3:
            pop_back(&bicola);
            break;
        case 4:
            imprimirBicola(bicola);
            break;
        case 5:
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
    } while (opcion != 5 || confirmacion == 'n');
    borrarBicola(&bicola);
}

// MENU BICOLAS
void menuBicolas() {
    char opBicola;

    puts("========================");
    puts("===== MENU BICOLAS =====");
    puts("========================\n");
    puts("A) DE ENTRADA RESTRINGIDA");
    puts("B) DE SALIDA RESTRINGIDA");

    do {
        printf("\n¿Con que bicola desea trabajar (A/B)? ");
        scanf(" %c", &opBicola);
        opBicola = toupper(opBicola);

        switch (opBicola) {
        case 'A':
            menuBicolaEntradaRestringida();
            break;
        case 'B':
            menuBicolaSalidaRestringida();
            break;
        default:
            printf("Opcion invalida, vuelva a intentar.\n");
        }
    } while (opBicola != 'A' && opBicola != 'B');
}

int main() {

    menuBicolas();

    return 0;
}
