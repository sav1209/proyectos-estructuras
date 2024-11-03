#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "listacircular.h"

// Crea un nuevo nodo con liga nula.
NodoLC* crearNodoLC(int info) {
    NodoLC* nuevoNodo = (NodoLC*) malloc(sizeof(NodoLC));
    nuevoNodo->info = info;
    nuevoNodo->liga = NULL;
    return nuevoNodo;
}


// CLASE 1

// 1. CREA UNA LISTA CIRCULAR POR EL FINAL
NodoLC* crearLCPorFinal() {
    int info;
    char opcion;

    // Lee el primer dato.
    printf("-> Ingrese el primero elemento: ");
    scanf("%d", &info);
    NodoLC* primero = crearNodoLC(info);

    NodoLC* temp = primero;
    // Sigue leyendo hasta que el usuario quiera.
    do {
        printf("¿Desea ingresar mas datos (s/n)? ");
        scanf(" %c", &opcion);
        opcion = tolower(opcion);
        switch (opcion) {
            case 's':
                printf("-> Nuevo elemento: ");
                scanf("%d", &info);
                temp->liga = crearNodoLC(info);
                temp = temp->liga;
                break;
            case 'n':
                break;
            default:
                puts("Opcion invalida, vuelva a intentar.");
        }
    } while (opcion != 'n');
    temp->liga = primero;

    return primero;
}

// 2. IMPRIME EL CONTENIDO DE UNA LISTA CIRCULAR
void imprimirLC(NodoLC* primero) {
    NodoLC* temp = primero;
    if (temp == NULL) {
        printf("La lista esta vacia.\n");
    } else {
        printf("-> %d\n", temp->info);
        temp = temp->liga;
        while (temp != primero) {
            printf("-> %d\n", temp->info);
            temp = temp->liga;
        }
    }
}

// 3. ELIMINA EL PRIMER ELEMENTO DE UNA LISTA CIRCULAR
void eliminarPrimerElementoLC(NodoLC** inicio) {
    if (*inicio == NULL) {
        printf("La lista está vacia \n");
        return;
    }

    NodoLC* temp = *inicio;

    if (temp->liga == *inicio) {
        free(*inicio);
        *inicio = NULL;
        printf("El unico elemento de la lista ha sido eliminado.\n");
        return;
    }

    NodoLC* ultimo = *inicio;
    while (ultimo->liga != *inicio) {
        ultimo = ultimo->liga;
    }

    *inicio = (*inicio)->liga;
    ultimo->liga = *inicio;

    free(temp);
    printf("El primer elemento ha sido eliminado.\n");
}


// 4. BUSCA UN ELEMENTO CON INFORMACIÓN DADA POR EL USUARIO EN UNA LISTA CIRCULAR Y QUE IMPRIMA LA DIRECCIÓN DEL ELEMENTO ANTECEDENTE Y LA INFORMACIÓN DEL ELEMENTO CONSECUENTE
void ImprimeAnterior_ImprimeInformacion(NodoLC** inicio, int info) {
    if (*inicio == NULL) {
        printf("\nLa lista es vacía\n");
        return;
    }

    NodoLC* temp = *inicio;
    NodoLC* anterior = NULL;


    if ((*inicio)->info == info) {
        anterior = *inicio;
        while (anterior->liga != *inicio) {
            anterior = anterior->liga;  
        }
        printf("La dirección del nodo anterior es: %p\n", (void*)anterior);
        printf("La información del nodo siguiente es: %d\n", (*inicio)->liga->info);
        return;
    }

    do {
        anterior = temp;  
        temp = temp->liga;  
    } while (temp != *inicio && temp->info != info);

    if (temp->info == info) {
        printf("La dirección del nodo anterior es: %p\n", (void*)anterior);
        printf("La información del nodo siguiente es: %d\n", temp->liga->info);
    } else {
        printf("No se encontró el elemento con la información %d en la lista.\n", info);
    }
}

// CLASE 2

// 1. INSERTA UN ELEMENTO ANTES DE UNO CON INFORMACIÓN DADA POR EL USUARIO EN UNA LISTA CIRCULAR
void insertarAntesDeNodoLC(NodoLC** inicio, int infoBuscar, int nuevoInfo) {

    if (*inicio == NULL) {
        printf("Lista esta vacia\n");
        return;
    }

    NodoLC* nuevoNodo = (NodoLC*)malloc(sizeof(NodoLC));
    nuevoNodo->info = nuevoInfo;

    if ((*inicio)->info == infoBuscar) {
        NodoLC* temp = *inicio;

        while (temp->liga != *inicio) {
            temp = temp->liga;
        }

        nuevoNodo->liga = *inicio;
        temp->liga = nuevoNodo;
        *inicio = nuevoNodo;  
        return;
    }

    NodoLC* actual = *inicio;
    NodoLC* anterior = NULL;

    do {
        anterior = actual;
        actual = actual->liga;
        if (actual->info == infoBuscar) {
            nuevoNodo->liga = actual;
            anterior->liga = nuevoNodo;
            return;
        }
    } while (actual != *inicio);

    printf("No se encontro el elemento %d en la lista.\n", infoBuscar);
}


// 2. INSERTA UN ELEMENTO AL PRINCIPIO EN UNA LISTA CIRCULAR 
void InsertarPrincipio (NodoLC** inicio,int info){
    NodoLC* nuevoNodo = crearNodoLC(info);

    if (*inicio == NULL) {
        *inicio = nuevoNodo;
        nuevoNodo->liga = nuevoNodo;
    } else {
        NodoLC* temp = *inicio;
        while (temp->liga != *inicio) {
            temp = temp->liga;
        }
        nuevoNodo->liga = *inicio;
        temp->liga = nuevoNodo;
        *inicio = nuevoNodo;
    }

    printf("Elemento insertado al principio de la lista.\n");
}

// 3. ELIMINA UN ELEMENTO AL FINAL DE UNA LISTA CIRCULAR
void EliminaFinal(NodoLC** inicio) {
    if (*inicio == NULL) {
        printf("La lista está vacía.\n");
        return;
    }

    NodoLC* temp = *inicio;
    NodoLC* anterior = NULL;

    if (temp->liga == *inicio) {
        free(temp);
        *inicio = NULL;
        printf("Se ha eliminado el único elemento de la lista.\n");
        return;
    }

    while (temp->liga != *inicio) {
        anterior = temp;
        temp = temp->liga;
    }

    anterior->liga = *inicio;
    free(temp);

    printf("Elemento eliminado del final de la lista.\n");
}

// 4. ELIMINA UN ELEMENTO DESPUÉS DE UNO CON INFORMACIÓN DADA POR EL USUARIO EN UNA LISTA CIRCULAR
void eliminarDespuesDeNodoLC(NodoLC** inicio, int info) {
    if (*inicio == NULL) {
        printf("La lista esta vacia.\n");
        return;
    }

    NodoLC* temp = *inicio;
    while (temp->liga != *inicio && temp->info != info) {
        temp = temp->liga;
    }

    if (temp->info != info) {
        printf("No se encontro el elemento %d en la lista\n", info);
        return;
    }

    // Si el elemnto se encontro y es unico
    if (temp->liga == temp) {
        free(*inicio);
        *inicio = NULL;
        return;
    }

    NodoLC* aEliminar = temp->liga;
    temp->liga = aEliminar->liga;
    if (aEliminar == *inicio) {
        *inicio = (*inicio)->liga;
    }
    free(aEliminar);
}

// Borra todos los nodos de una lista circular.
void borraLC(NodoLC** inicio) {
    if (*inicio == NULL) {
        return;
    }

    NodoLC *aEliminar;
    while ((*inicio)->liga != *inicio) {
        aEliminar = (*inicio)->liga;
        (*inicio)->liga = aEliminar->liga;
        free(aEliminar);
    }
    free(*inicio);
    *inicio = NULL;
}

// MENU
void menuListasCirculares() {
    char confirmacion = 'n';
    int opcion, info, info2;
    NodoLC* listaCircular = NULL;

    do {
        system("cls");

        puts("==================================");
        puts("===== MENU LISTAS CIRCULARES =====");
        puts("==================================\n");
        puts("1. CREA UNA LISTA CIRCULAR POR EL FINAL");
        puts("2. IMPRIME EL CONTENIDO DE UNA LISTA CIRCULAR");
        puts("3. ELIMINA EL PRIMER ELEMENTO DE UNA LISTA CIRCULAR");
        puts("4. BUSCA UN ELEMENTO CON INFORMACIÓN DADA POR EL USUARIO EN UNA LISTA CIRCULAR Y QUE IMPRIMA LA DIRECCIÓN DEL ELEMENTO ANTECEDENTE Y LA INFORMACIÓN DEL ELEMENTO CONSECUENTE");
        puts("5. INSERTA UN ELEMENTO ANTES DE UNO CON INFORMACIÓN DADA POR EL USUARIO EN UNA LISTA CIRCULAR");
        puts("6. INSERTA UN ELEMENTO AL PRINCIPIO EN UNA LISTA CIRCULAR ");
        puts("7. ELIMINA UN ELEMENTO AL FINAL DE UNA LISTA CIRCULAR");
        puts("8. ELIMINA UN ELEMENTO DESPUÉS DE UNO CON INFORMACIÓN DADA POR EL USUARIO EN UNA LISTA CIRCULAR");
        puts("9. REGRESAR AL MENU DE LISTAS");

        printf("\nOpcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                listaCircular = crearLCPorFinal();
                break;
            case 2:
                imprimirLC(listaCircular);
                break;
            case 3:
                eliminarPrimerElementoLC(&listaCircular);
                break;
            case 4:
                printf("¿Cual es la informacion del nodo que deseas buscar? ");
                scanf("%d", &info);
                ImprimeAnterior_ImprimeInformacion(&listaCircular, info);
                break;
                break;
            case 5:
                printf("¿Cual es la informacion del nodo del cual desea insertar antes? ");
                scanf("%d", &info);
                printf("Escribe la informacion del nodo que deseas agregar: ");
                scanf("%d", &info2);
                insertarAntesDeNodoLC(&listaCircular,info,info2);
                break;
            case 6:
                printf("Escribe la informacion del nodo que deseas agregar: ");
                scanf("%d", &info);
                InsertarPrincipio(&listaCircular,info);
                break;
            case 7:
                EliminaFinal(&listaCircular);
                break;
            case 8:
                printf("¿Cual es la informacion del nodo del cual desea eliminar el siguiente? ");
                scanf("%d", &info);
                eliminarDespuesDeNodoLC(&listaCircular, info);
                break;
            case 9:
                do {
                    printf("¿Esta seguro de regresar al menu de listas (s/n)? ");
                    scanf(" %c", &confirmacion);
                    confirmacion = tolower(confirmacion);
                    if (confirmacion != 's' && confirmacion != 'n') {
                        printf("Opcion invalida, vuelva a ingresar.\n");
                    }
                } while (confirmacion != 's' && confirmacion != 'n');
                break;
            default:
                printf("Opcion invalida, vuelva a intentar.\n");
                break;
        }
        
        putchar('\n');
        system("pause");
    } while (opcion != 9 || confirmacion == 'n');
    borraLC(&listaCircular);
}