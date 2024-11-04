#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>

#include "bicola.h"

// Crea un nuevo nodo con liga nula.
NodoBicola *crearNodoBicola(int info) {
    NodoBicola *nuevoNodo = (NodoBicola *) malloc(sizeof(NodoBicola));
    nuevoNodo->info = info;
    nuevoNodo->liga = NULL;
    return nuevoNodo;
}

// REALIZA LA OPERACIÓN PUSH INSERTANDO POR EL FRENTE
void push_front(NodoBicola **final, int info){
    NodoBicola *nuevoNodo = crearNodoBicola(info);
    
    if (*final == NULL) {
        *final = nuevoNodo;
        (*final)->liga = *final;
    } else {
        nuevoNodo->liga = (*final)->liga;
        (*final)->liga = nuevoNodo;
    }

    printf("Elemento %d insertado por frente de la bicola.\n", info);
}

// REALIZA LA OPERACIÓN PUSH INSERTANDO POR EL FINAL
void push_back(NodoBicola **final, int info) {
    // Si el último nodo apunta a NULL, no existe una bicola, por lo tanto el nodo a agregar será el primero.
    if (*final == NULL) {
        *final = crearNodoBicola(info);
        (*final)->liga = *final;
    } else {
        // Si ya hay nodos en la bicola, la liga del último nodo ('final') debe apuntar al nuevo nodo y se cambia nuevo nodo ahora debe ser el último.
        NodoBicola *nuevoNodo = crearNodoBicola(info);
        nuevoNodo->liga = (*final)->liga;
        (*final)->liga = nuevoNodo;
        *final = (*final)->liga;
    }

    printf("Elemento %d insertado por el final de la bicola.\n", info);
}

// REALIZA LA OPERACIÓN POP ELIMINANDO POR EL FRENTE
void pop_front(NodoBicola **final){
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

    NodoBicola *primero = (*final)->liga;  
    (*final)->liga = primero->liga;       
    free(primero);                         

    printf("El primer elemento se ha eliminado.\n");
}

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

    do {
        system("cls");

        puts("===============================================");
        puts("===== MENU BICOLAS DE ENTRADA RESTRINGIDA =====");
        puts("===============================================\n");
        puts("1. PUSH POR EL FINAL");
        puts("2. POP POR EL FRENTE");
        puts("3. POP POR EL FINAL");
        puts("4. IMPRIME LOS ELEMENTOS DE LA BICOLA");
        puts("5. REGRESAR AL MENU DE BICOLAS");

        printf("\nOpcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
        case 1:
            printf("Ingrese el dato que desea insertar al final de la bicola: ");
            scanf("%d", &info);
            push_back(&bicola, info);
            break;
        case 2:
            pop_front(&bicola);
            break;
        case 3:
            pop_back(&bicola);
            break;
        case 4:
            imprimirBicola(bicola);
            break;
        case 5:
            do {
                printf("¿Esta seguro de regresar al menu de bicolas (s/n)? ");
                scanf(" %c", &confirmacion);
                confirmacion = tolower(confirmacion);
                if (confirmacion != 's' && confirmacion != 'n')
                {
                    printf("Opcion invalida, vuelva a ingresar.\n\n");
                }
            } while (confirmacion != 's' && confirmacion != 'n');
            break;
        default:
            printf("Opcion invalida, vuelva a intentar.\n");
        }

        putchar('\n');
        system("pause");
    } while (opcion != 5 || confirmacion == 'n');
    borrarBicola(&bicola);
}

// MENU BICOLAS DE SALIDA RESTRINGIDA
void menuBicolaSalidaRestringida() {
    char confirmacion = 'n';
    int opcion, info;
    NodoBicola *bicola = NULL;

    do {
        system("cls");

        puts("===============================================");
        puts("===== MENU BICOLAS DE SALIDA RESTRINGIDA  =====");
        puts("===============================================\n");
        puts("1. PUSH POR EL FRENTE");
        puts("2. PUSH POR EL FINAL");
        puts("3. POP POR EL FINAL");
        puts("4. IMPRIME LOS ELEMENTOS DE LA BICOLA");
        puts("5. REGRESAR AL MENU DE BICOLAS");

        printf("\nOpcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
        case 1:
            printf("Ingrese el dato que desea agregar a la bicola por el frente: ");
            scanf("%d", &info);
            push_front(&bicola, info);
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
                printf("¿Esta seguro de regresar al menu de bicolas (s/n)? ");
                scanf(" %c", &confirmacion);
                confirmacion = tolower(confirmacion);
                if (confirmacion != 's' && confirmacion != 'n')
                {
                    printf("Opcion invalida, vuelva a ingresar.\n\n");
                }
            } while (confirmacion != 's' && confirmacion != 'n');
            break;
        default:
            printf("Opcion invalida, vuelva a intentar.\n");
        }

        putchar('\n');
        system("pause");
    } while (opcion != 5 || confirmacion == 'n');
    borrarBicola(&bicola);
}

// MENU BICOLAS
void menuBicolas() {
    char opBicola, confirmacion = 'n';

    do {
        system("cls");

        puts("========================");
        puts("===== MENU BICOLAS =====");
        puts("========================\n");
        puts("A) DE ENTRADA RESTRINGIDA");
        puts("B) DE SALIDA RESTRINGIDA");
        puts("C) REGRESAR AL MENU DE COLAS\n");

        printf("Opcion: ");
        scanf(" %c", &opBicola);
        opBicola = toupper(opBicola);

        switch (opBicola) {
            case 'A':
                menuBicolaEntradaRestringida();
                break;
            case 'B':
                menuBicolaSalidaRestringida();
                break;
            case 'C':
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
                printf("Opcion invalida, vuelva a intentar.\n\n");
                system("pause");
        }
    } while (opBicola != 'C' || confirmacion == 'n');
}