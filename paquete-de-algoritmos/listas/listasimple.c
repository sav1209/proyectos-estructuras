#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "listasimple.h"

// Crea un nuevo nodo con liga nula.
NodoLS* crearNodoLS(int info) {
    NodoLS* nuevoNodo = (NodoLS*) malloc(sizeof(NodoLS));
    nuevoNodo->info = info;
    nuevoNodo->liga = NULL;
    return nuevoNodo;
}

// Borra todos los nodos de una lista simple.
void borrarLS(NodoLS** primero) {
    NodoLS* temp = *primero;
    while (temp != NULL) {
        *primero = temp->liga;
        free(temp);
        temp = *primero;
    }
}

// 1. CREA UNA LISTA SIMPLE AGREGANDO CADA NUEVO NODO AL INICIO DE LA LISTA
NodoLS* crearLSPorPrincipio() {
    NodoLS* primero = (NodoLS*) malloc(sizeof(NodoLS));
    NodoLS* temp;
    char opcion;

    printf("-> Ingrese el primer elemento: ");
    scanf("%d", &primero->info);
    primero->liga = NULL;

    do {
        printf("¿Desea ingresar mas datos (s/n)? ");
        scanf(" %c", &opcion);
        opcion = tolower(opcion);
        switch (opcion) {
            case 's':
                temp = primero;
                primero = (NodoLS*) malloc(sizeof(NodoLS));
                printf("-> Nuevo elemento: ");
                scanf("%d", &primero->info);
                primero->liga = temp;
                break;
            case 'n':
                break;
            default:
                puts("Opcion invalida, vuelva a intentar.");
        }
    } while (opcion != 'n');

    return primero;
}

// 2. IMPRIME UNA LISTA SIMPLE
void imprimirLS(NodoLS* primero) {
    NodoLS* temp = primero;
    if (temp == NULL) {
        printf("La lista esta vacia.\n");
    } else {
        while (temp != NULL) {
            printf("-> %d\n", temp->info);
            temp = temp->liga;
        }
    }
}

// 3. ELIMINA EL ÚLTIMO ELEMENTO
void eliminarUltimoLS(NodoLS** primero) {
    if (*primero == NULL) {
        printf("La lista esta vacia.\n");
        return;
    }

    if ((*primero)->liga == NULL) {
        free(*primero);
        *primero = NULL;
    } else {
        NodoLS* temp = *primero;
        while (temp->liga->liga != NULL) {
            temp = temp->liga;
        }

        free(temp->liga); 
        temp->liga = NULL;
    }
    printf("El ultimo elemento se ha eliminado satisfactoriamente.\n");
}

// 4. CREA UNA LISTA SIMPLE AGREGANDO CADA NUEVO NODO AL FINAL DE LA LISTA 
NodoLS* crearLSPorFinal() {
    NodoLS* primero = (NodoLS*) malloc(sizeof(NodoLS));
    NodoLS* temp = primero;
    char opcion;

    // Lee el primer dato.
    printf("-> Ingrese el primero elemento: ");
    scanf("%d", &temp->info);
    temp->liga = NULL;

    // Sigue leyendo hasta que el usuario quiera.
    do {
        printf("¿Desea ingresar mas datos (s/n)? ");
        scanf(" %c", &opcion);
        opcion = tolower(opcion);
        switch (opcion) {
            case 's':
                temp->liga = (NodoLS*) malloc(sizeof(NodoLS));
                temp = temp->liga;
                printf("-> Nuevo elemento: ");
                scanf("%d", &temp->info);
                break;
            case 'n':
                break;
            default:
                puts("Opcion invalida, vuelva a intentar.");
        }
    } while (opcion != 'n');

    return primero;
}

// 5. BUSCA UN ELEMENTO DENTRO DE UNA LISTA. 
int buscarElementoLS(NodoLS* primero, int valor) {
    NodoLS* temp = primero;

    if (temp == NULL) {
        printf("La lista esta vacia.\n");
        return 0;
    }

    while ((temp != NULL) && (temp->info != valor)) {
        temp = temp->liga;
    }

    if (temp == NULL) {
        printf("No se encontro el elemento.\n");
        return 0;
    } else {
        printf("Se encontro el elemento.\n");
        return 1;
    }
}

// 6. INSERTE ELEMENTOS POR EL INICIO DE UNA LISTA EXISTENTE.
void insertarAlInicioLS(NodoLS** primero, int info) {
    NodoLS* nuevoNodo = crearNodoLS(info);
    nuevoNodo->liga = *primero; 
    *primero = nuevoNodo;
    printf("El elemento se ha insertado al inicio satisfactoriamente.\n");
}

// 7. INSERTE ELEMENTOS POR EL FINAL DE UNA LISTA EXISTENTE. 
void insertarAlFinalLS(NodoLS** primero, int info) {
    if (*primero == NULL) {
        *primero = crearNodoLS(info);
    } else {
        NodoLS* temp = *primero;
        while (temp->liga != NULL) {
            temp = temp->liga;
        }
        temp->liga = crearNodoLS(info);
    }
    printf("El elemento se ha insertado al final satisfactoriamente.\n");
}

// 8. ELIMINE EL PRIMER ELEMENTO DE UNA LISTA
void eliminarPrimeroLS(NodoLS** primero) {
    if (*primero == NULL) {
        printf("La lista esta vacia.\n");
        return;
    }

    NodoLS* temp = *primero;
    *primero = temp->liga;
    free(temp);
    printf("El primer elemento se ha eliminado satisfactoriamente.\n");
}

// 9. ELIMINA UN NODO QUE COINCIDA CON CIERTA INFORMACIÓN 
void eliminarNodoLS(NodoLS** principio, int valor) {
    if (*principio == NULL) {
        printf("La lista esta vacia.\n");
        return;
    }

    NodoLS* actual = *principio;
    NodoLS* previo = NULL;
    while ((actual != NULL) && (actual->info != valor)) {
        previo = actual;
        actual = actual->liga;
    }

    if (actual == NULL) {
        printf("Nodo con valor %d no encontrado.\n", valor);
        return;
    }

    // Si es el primer elemento.
    if (actual == *principio) {
        *principio = (*principio)->liga;
        free(actual);
    } else {
        previo->liga = actual->liga;
        free(actual);
    }
    printf("El elemento con %d se ha eliminado satisfactoriamente.\n", valor);
}

// 10. INSERTA UN NODO ANTES DE UN NODO ESPECÍFICO
void insertarAntesDeNodoLS(NodoLS** primero, int valorObjetivo, int nuevoValor) {
    if (*primero == NULL) {
        printf("La lista esta vacia.\n");
        return;
    }

    NodoLS* temp = *primero;
    NodoLS* anterior = NULL;
    while (temp != NULL && temp->info != valorObjetivo) {
        anterior = temp;
        temp = temp->liga;
    }

    if (temp == NULL) {
        printf("Nodo con valor %d no encontrado.\n", valorObjetivo);
    } else {
        NodoLS* nuevoNodo = crearNodoLS(nuevoValor);
        nuevoNodo->liga = temp;
        if (temp == *primero) {
            *primero = nuevoNodo;
        } else {
            anterior->liga = nuevoNodo;
        }
        printf("El nodo con %d se ha insertado correctamente.\n", nuevoValor);
    }
}

// 11. INSERTA UN NODO DESPUÉS DE UN NODO ESPECÍFICO
void insertarDespuesDeNodoLS(NodoLS** primero, int valorObjetivo, int nuevoValor) {
    if (*primero == NULL) {
        printf("La lista está vacia.\n");
        return;
    }

    NodoLS* temp = *primero;
    while (temp != NULL && temp->info != valorObjetivo) {
        temp = temp->liga;
    }

    if (temp == NULL) {
        printf("Nodo con valor %d no encontrado.\n", valorObjetivo);
    } else {
        NodoLS* nuevoNodo = crearNodoLS(nuevoValor);
        nuevoNodo->liga = temp->liga;
        temp->liga = nuevoNodo;
        printf("El nodo con %d se ha insertado correctamente.\n", nuevoValor);
    }
}

// 12. ELIMINA UN NODO ANTES DE UN NODO ESPECÍFICO
void eliminarAntesDeNodoLS(NodoLS** primero, int valorObjetivo) {
    if (*primero == NULL) {
        printf("La lista está vacia.\n");
        return;
    }

    if ((*primero)->info == valorObjetivo) {
        printf("No hay nodo para eliminar antes del valor %d.\n", valorObjetivo);
        return;
    }

    NodoLS* anterior = *primero;
    NodoLS* anteAnterior = NULL;
    while (anterior->liga != NULL && anterior->liga->info != valorObjetivo) {
        anteAnterior = anterior;
        anterior = anterior->liga;
    }

    if (anterior->liga == NULL) {
        printf("Nodo con el valor %d no encontrado.\n", valorObjetivo);
    } else {
        if (anterior == *primero) {// Si el elemento a eliminar es el primero.
            *primero = (*primero)->liga;
        } else { // Si no es el primero.
            anteAnterior->liga = anterior->liga;
        }
        free(anterior);
        printf("Nodo antes de %d eliminado.\n", valorObjetivo);
    }
}

// 13. ELIMINA UN NODO DESPUÉS DE UN NODO ESPECÍFICO
void eliminarDespuesDeNodoLS(NodoLS** primero, int valorObjetivo) {
    if (*primero == NULL) {
        printf("La lista está vacia.\n");
        return;
    }

    NodoLS* temp = *primero;
    while (temp != NULL && temp->info != valorObjetivo) {
        temp = temp->liga;
    }

    if (temp == NULL || temp->liga == NULL) {
        printf("No se encontro el nodo o no hay nodo para eliminar despues del valor %d.\n", valorObjetivo);
    } else {
        NodoLS* nodoAEliminar = temp->liga;
        temp->liga = nodoAEliminar->liga;
        free(nodoAEliminar);
        printf("Nodo despues de %d eliminado.\n", valorObjetivo);
    }
}

// Menu de operaciones listas simples.
void menuListasSimples() {
    char confirmacion = 'n';
    int opcion, info, temp;
    NodoLS* listaSimple = NULL;

    do {
        system("cls");
        printf("===============================\n");
        printf("===== MENU LISTAS SIMPLES =====\n");
        printf("===============================\n\n");
        printf(" 1. CREAR LISTA SIMPLE AGREGANDO CADA NUEVO NODO AL INICIO DE LA LISTA.\n");
        printf(" 2. IMPRIMIR LISTA SIMPLE.\n");
        printf(" 3. ELIMINAR EL ULTIMO ELEMENTO.\n");
        printf(" 4. CREAR UNA LISTA SIMPLE AGREGANDO CADA NUEVO NODO AL FINAL DE LA LISTA.\n");
        printf(" 5. BUSCAR UN ELEMENTO DENTRO DE UNA LISTA.\n");
        printf(" 6. INSERTAR ELEMENTOS POR EL INICIO DE UNA LISTA EXISTENTE.\n");
        printf(" 7. INSERTAR ELEMENTOS POR EL FINAL DE UNA LISTA EXISTENTE.\n");
        printf(" 8. ELIMINAR EL PRIMER ELEMENTO DE UNA LISTA.\n");
        printf(" 9. ELIMINAR UN NODO QUE COINCIDA CON CIERTA INFORMACION.\n");
        printf("10. INSERTAR UN NODO ANTES DE UN NODO ESPECÍFICO.\n");
        printf("11. INSERTAR UN NODO DESPUÉS DE UN NODO ESPECÍFICO.\n");
        printf("12. ELIMINAR UN NODO ANTES DE UN NODO ESPECÍFICO.\n");
        printf("13. ELIMINAR UN NODO DESPUÉS DE UN NODO ESPECÍFICO.\n");
        printf("14. REGRESAR AL MENU PRINICIPAL.\n");

        printf("\nOpcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                borrarLS(&listaSimple);
                listaSimple = crearLSPorPrincipio();
                break;
            case 2:
                imprimirLS(listaSimple);
                break;
            case 3:
                eliminarUltimoLS(&listaSimple);
                break;
            case 4:
                borrarLS(&listaSimple);
                listaSimple = crearLSPorFinal();
                break;
            case 5:
                printf("¿Que elemento desea buscar? ");
                scanf("%d", &info);
                buscarElementoLS(listaSimple, info);
                break;
            case 6:
                printf("¿Que elemento desea insertar? ");
                scanf("%d", &info);
                insertarAlInicioLS(&listaSimple, info);
                break;
            case 7:
                printf("¿Que elemento desea insertar? ");
                scanf("%d", &info);
                insertarAlFinalLS(&listaSimple, info);
                break;
            case 8:
                eliminarPrimeroLS(&listaSimple);
                break;
            case 9:
                printf("¿Cual es la informacion del nodo que desea eliminar? ");
                scanf("%d", &info);
                eliminarNodoLS(&listaSimple, info);
                break;
            case 10:
                printf("¿Cual es la informacion del nodo del cual desea insertar el nuevo elemento antes? ");
                scanf("%d", &temp);
                printf("¿Que informacion desea insertar? ");
                scanf("%d", &info);
                insertarAntesDeNodoLS(&listaSimple, temp, info);
                break;
            case 11:
                printf("¿Cual es la informacion del nodo del cual desea insertar el nuevo elemento despues? ");
                scanf("%d", &temp);
                printf("¿Que informacion desea insertar? ");
                scanf("%d", &info);
                insertarDespuesDeNodoLS(&listaSimple, temp, info);
                break;
            case 12:
                printf("¿Cual es la informacion del nodo del cual desea eliminar el anterior? ");
                scanf("%d", &info);
                eliminarAntesDeNodoLS(&listaSimple, info);
                break;
            case 13:
                printf("¿Cual es la informacion del nodo del cual desea eliminar el siguiente? ");
                scanf("%d", &info);
                eliminarDespuesDeNodoLS(&listaSimple, info);
                break;
            case 14:
                do {
                    printf("¿Esta seguro de regresar al menu principal (s/n)? ");
                    scanf(" %c", &confirmacion);
                    confirmacion = tolower(confirmacion);
                    if (confirmacion != 's' && confirmacion != 'n') {
                        printf("Opcion invalida, vuelva a ingresar.\n");
                    }
                } while (confirmacion != 's' && confirmacion != 'n');
                break;
            default:
                printf("Opcion invalida, vuelva a intentar.\n");
        }
        putchar('\n');
        system("pause");
    } while (opcion != 14 || confirmacion == 'n');
    borrarLS(&listaSimple);
}