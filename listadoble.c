#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Definición de un nodo de la lista doblemente ligada
typedef struct NodoLD {
    int dato;
    struct NodoLD* siguiente;
    struct NodoLD* anterior;
} NodoLD;

// Definición de la estructura de la lista doblemente ligada
typedef struct {
    NodoLD* inicio;
    NodoLD* final;
} ListaDoble;


// Borra todos los nodos de una lista simple.
void borrarLD(ListaDoble** lista) {
    if (*lista == NULL) {
        return;
    }

    NodoLD* temp = (*lista)->inicio;
    while (temp != NULL) {
        (*lista)->inicio = temp->siguiente;
        free(temp);
        temp = (*lista)->inicio;
    }
}


// CLASE 1

// 1. CREA UNA LISTA DOBLEMENTE LIGADA INSERTANDO A CADA ELEMENTO POR EL FINAL
ListaDoble* crearLDPorFinal() {
    char eleccion;
    ListaDoble* lista = malloc(sizeof(ListaDoble));
    NodoLD *inicio, *final;

    inicio = malloc(sizeof(NodoLD));
    inicio->anterior = NULL;
    inicio->siguiente = NULL;
    final = inicio;

    printf("Ingrese el primer dato: ");
    scanf("%d", &final->dato);

    do {
        printf("¿Desea insertar otro dato? (s/n) ");
        scanf(" %c", &eleccion);
        eleccion = tolower(eleccion);
        switch (eleccion) {
            case 's':
                final->siguiente = malloc(sizeof(NodoLD));
                final->siguiente->anterior = final;
                final->siguiente->siguiente = NULL;
                final = final->siguiente;
                printf("Nuevo dato: ");
                scanf("%d", &final->dato);
                break;
            case 'n':
                break;
            default:
                puts("Opcion invalida, vuelva a intentar.");
        }
    } while (eleccion != 'n');

    lista->inicio = inicio;
    lista->final = final;

    return lista;
}

// 2. IMPRIME EL CONTENIDO DE UNA LISTA DOBLEMENTE LIGADA
void imprimirLDIzqADer(ListaDoble* lista) {
    NodoLD* inicio = lista->inicio;

    if (inicio == NULL) {
        printf("La lista es vacia\n");
        return;
    }

    NodoLD* temp = inicio;
    printf("Lista de izquierda a derecha:\n");
    while (temp != NULL) {
        printf("%d  ", temp->dato);
        temp = temp->siguiente;
    }
    printf("\n");
}

void imprimirLDDerAIzq(ListaDoble* lista) {
    NodoLD* final = lista->final;
    if (final == NULL) {
        printf("La lista es vacia\n");
        return;
    }

    NodoLD* temp = final;
    printf("Lista de derecha a izquierda:\n");
    while (temp != NULL) {
        printf("%d  ", temp->dato);
        temp = temp->anterior;
    }
    printf("\n");
}

void imprimirLD(ListaDoble* lista) {
    int opcion;
    do {
        puts("¿Cómo desea imprimir la lista?");
        puts("1. De izquierda a derecha.");
        puts("2. De derecha a izquierda.");
        printf("Opción: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                imprimirLDIzqADer(lista);
                break;
            case 2:
                imprimirLDDerAIzq(lista);
                break;
            default:
                puts("Opcion invalida, vuelva a intentar.");
                break;
        }
    } while (opcion < 1 || opcion > 2);
}

// 3. ELIMINA EL ÚLTIMO ELEMENTO DE UNA LISTA DOBLEMENTE LIGADA
void eliminarFinalLD(ListaDoble** lista) {
    NodoLD* final = (*lista)->final;
    if (final == NULL) {
        printf("La lista esta vacia.\n");
        return;
    }

    if (final->anterior == NULL) {
        free(final);
        (*lista)->inicio = NULL;
        (*lista)->final = NULL;
    } else {
        final = final->anterior;
        free(final->siguiente);
        final->siguiente = NULL;
        (*lista)->final = final;
    }
}

// 4. ELIMINA UN ELEMENTO CON INFORMACIÓN DADA POR EL USUARIO EN UNA LISTA DOBLEMENTE LIGADA
void eliminarNodoLD(ListaDoble** lista) {
    int x;
    NodoLD* inicio = (*lista)->inicio;
    NodoLD* final = (*lista)->final;

    if (inicio == NULL) {
        printf("La lista esta vacia.\n");
        return;
    }

    printf("¿Cual es el elemento que desea eliminar? ");
    scanf("%d", &x);

    NodoLD* temp = inicio;
    while (temp != NULL && temp->dato != x) {
        temp = temp->siguiente;
    }

    if (temp == NULL) {
        printf("No se encontro el elemento.\n");
        return;
    }

    // Si es el ultimo o es el unico elemento.
    if (temp == final) {
        eliminarFinalLD(lista);
        return;
    }

    if (temp == inicio) {
        (*lista)->inicio = inicio->siguiente;
        (*lista)->inicio->anterior = NULL;
        free(temp);
        return;
    }

    temp->anterior->siguiente = temp->siguiente;
    temp->siguiente->anterior = temp->anterior;
    free(temp);

}


// CLASE 2

// 1. ELIMINA UN ELEMENTO ANTES DE UNO CON INFORMACIÓN DADA POR EL USUSARIO EN UNA LISTA DOBLEMENTE LIGADA
 void eliminarAntesDeNodoLD(ListaDoble** lista) {
    int x;
    NodoLD* inicio = (*lista)->inicio;

    if (inicio == NULL) {
        printf("La lista esta vacia.\n");
        return;
    }

    printf("¿Cual es el elemento antes del cual desea eliminar uno? ");
    scanf("%d", &x);

    NodoLD* temp = inicio;
    while (temp != NULL && temp->dato != x) {
        temp = temp->siguiente;
    }

    if (temp == NULL) {
        printf("No se encontro el elemento %d en la lista.\n", x);
        return;
    }

    if (temp->anterior == NULL) {
        printf("No se puede eliminar un nodo antes del primer elemento.\n");
        return;
    }
    NodoLD* nodoAEliminar = temp->anterior;

    if (nodoAEliminar->anterior != NULL) {
        nodoAEliminar->anterior->siguiente = temp;
    } else {

        (*lista)->inicio = temp;
    }
    temp->anterior = nodoAEliminar->anterior;

    free(nodoAEliminar);
    printf("Elemento antes de %d eliminado.\n", x);
}

// 2. INSERTA UN ELEMENTO AL PRINCIPIO DE UNA LISTA DOBLEMENTE LIGADA
void insertar_al_principio_LD(ListaDoble** lista){
    NodoLD* inicio = (*lista)->inicio;
    NodoLD* temp = malloc(sizeof(NodoLD));

    printf("Ingrese el dato a insertar al principio: ");
    scanf("%d", &temp->dato);

    temp->anterior = NULL;
    temp->siguiente = inicio;
    inicio->anterior = temp;

    (*lista)->inicio = temp;
}

// 3. INSERTA UN ELEMENTO DESPUÉS DE UNO CON INFORMACIÓN DADA POR EL USUARIO EN UNA LISTA DOBLEMENTE LIGADA
void insertar_despues_LD(ListaDoble** lista){
    int x;
    NodoLD* inicio = (*lista)->inicio;
    NodoLD* final = (*lista)->final;


    if (inicio == NULL) {
        printf("La lista esta vacia.\n");
        return;
    } else {   
        printf("¿Cual es el elemento que deseas buscar? ");
        scanf("%d", &x);

        NodoLD* temp = inicio;
        while (temp != NULL && temp->dato != x) {
            temp = temp->siguiente;
        }

        if (temp == NULL) {
            printf("El dato no se localizo\n");
            return;
        }

        NodoLD* temp2 = malloc(sizeof(NodoLD));
        printf("Ingrese el dato a insertar: ");
        scanf("%d", &temp2->dato);

        if (temp == final) {
            temp2->siguiente = NULL;
            temp2->anterior = temp;
            temp->siguiente = temp2;
            (*lista)->final = temp2;
        } else {
            temp2->siguiente = temp->siguiente;
            temp2->anterior = temp;
            temp->siguiente->anterior = temp2;
            temp->siguiente = temp2;
        }
    }
}

// 4. DETERMINAR SI UNA LISTAS DOBLE ES O NO UN PALÍNDROMO
int es_palindromo(ListaDoble* lista) {
    NodoLD* p = lista->inicio;
    NodoLD* q = lista->final;

    while (p != q && p->siguiente != q) {
        if (p->dato != q->dato) {
            return 0;
        }
        p = p->siguiente;
        q = q->anterior;
    }
    return 1;
}

void menu_listas_dobles() {
    char confirmacion = 'n';
    int opcion;
    ListaDoble* lista_doble = NULL;

    puts("==========================================");
    puts("===== MENU LISTAS DOBLEMENTE LIGADAS =====");
    puts("==========================================\n");
    puts("1. CREA UNA LISTA DOBLEMENTE LIGADA INSERTANDO A CADA ELEMENTO POR EL FINAL");
    puts("2. IMPRIMIR EL CONTENIDO DE LA LISTA DOBLEMENTE LIGADA");
    puts("3. ELIMINA EL ÚLTIMO ELEMENTO DE UNA LISTA DOBLEMENTE LIGADA");
    puts("4. ELIMINA UN ELEMENTO CON INFORMACIÓN DADA EN UNA LISTA DOBLEMENTE LIGADA");
    puts("5. ELIMINA UN ELEMENTO ANTES DE UNO CON INFORMACIÓN DADA");
    puts("6. INSERTE UN ELEMENTO AL PRINCIPIO DE UNA LISTA DOBLEMENTE LIGADA");
    puts("7. INSERTE UN ELEMENTO DESPUES DE UNO CON INFORMACION DADA POR EL USUARIO EN UNA LISTA DOBLEMENTE LIGADA");
    puts("8. DETERMINAR SI UNA LISTA DOBLE ES O NO UN PALINDROMO");
    puts("9. REGRESAR AL MENU PRINCIPAL");

    do {
        printf("\nOpcion: ");
        scanf("%d", &opcion);

        switch (opcion) {
            case 1:
                borrarLD(&lista_doble);
                lista_doble = crearLDPorFinal();
                break;
            case 2:
                imprimirLD(lista_doble);
                break;
            case 3:
                eliminarFinalLD(&lista_doble);
                break;
            case 4:
                eliminarNodoLD(&lista_doble);
                break;
            case 5:
                eliminarAntesDeNodoLD(&lista_doble);
                break;
            case 6:
                insertar_al_principio_LD(&lista_doble);
                break;
            case 7:
                insertar_despues_LD(&lista_doble);
                break;
            case 8:
                if(es_palindromo(lista_doble)) {
                    printf("La lista es un palindromo.\n");
                } else {
                    printf("La lista no es un palindromo.\n");
                }
                break;
            case 9:
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
                puts("Opcion invalida.");
                break;
        }
    } while (opcion != 9 || confirmacion == 'n');
    borrarLD(&lista_doble);
}



int main() {

    menu_listas_dobles();

    return 0;
}