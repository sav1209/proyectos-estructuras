#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// LISTAS
#include "listas/listasimple.h"
#include "listas/listadoble.h"
#include "listas/listacircular.h"

// PILAS
#include "pilas/pila.h"

// COLAS
#include "colas/colasimple.h"
#include "colas/bicola.h"
#include "colas/colaprioridad.h"

// ARBOLES
#include "arboles/arbolbinario.h"
#include "arboles/arbolbinariobusqueda.h"

void menuListas() {
    char confirmacion = 'n';
    int opcion;

    do {
        system("cls");

        puts("==========================");
        puts("===== MENU DE LISTAS =====");
        puts("==========================\n");
        puts("1. LISTAS SIMPLES");
        puts("2. LISTAS DOBLEMENTE LIGADAS");
        puts("3. LISTAS CIRCULARES");
        puts("4. REGRESAR AL MENU PRINICIPAL");

        printf("\nOpcion: ");
        scanf("%d", &opcion);
        switch(opcion) {
            case 1:
                menuListasSimples();
                break;
            case 2:
                menu_listas_dobles();
                break;
            case 3:
                menuListasCirculares();
                break;
            case 4:
                do {
                    printf("¿Esta seguro de regresar al menu principal (s/n)? ");
                    scanf(" %c", &confirmacion);
                    confirmacion = tolower(confirmacion);
                    if (confirmacion != 's' && confirmacion != 'n') {
                        printf("Opcion invalida, vuelva a ingresar.\n\n");
                    }
                } while (confirmacion != 's' && confirmacion != 'n');
                break;
            default:
                printf("Opcion invalida, vuelva a intentar.\n\n");
                system("pause");
                break;
        }
    } while (opcion != 4 || confirmacion == 'n');
}

void menuColas() {
    char confirmacion = 'n';
    int opcion;

    do {
        system("cls");

        puts("=========================");
        puts("===== MENU DE COLAS =====");
        puts("=========================\n");
        puts("1. COLAS SIMPLES");
        puts("2. BICOLAS");
        puts("3. COLAS CON PRIORIDAD");
        puts("4. REGRESAR AL MENU PRINCIPAL");

        printf("\nOpcion: ");
        scanf("%d", &opcion);
        switch(opcion) {
            case 1:
                menuCola();
                break;
            case 2:
                menuBicolas();
                break;
            case 3:
                menuColaPrioridad();
                break;
            case 4:
                do {
                    printf("¿Esta seguro de regresar al menu principal (s/n)? ");
                    scanf(" %c", &confirmacion);
                    confirmacion = tolower(confirmacion);
                    if (confirmacion != 's' && confirmacion != 'n') {
                        printf("Opcion invalida, vuelva a ingresar.\n\n");
                    }
                } while (confirmacion != 's' && confirmacion != 'n');
                break;
            default:
                printf("Opcion invalida, vuelva a intentar.\n\n");
                system("pause");
                break;
        }
    } while (opcion != 4 || confirmacion == 'n');
}

void menuArboles() {
    char confirmacion = 'n';
    int opcion;

    do {
        system("cls");

        puts("===========================");
        puts("===== MENU DE ARBOLES =====");
        puts("===========================\n");
        puts("1. ARBOLES BINARIOS");
        puts("2. ARBOLES BINARIOS DE BUSQUEDA");
        puts("3. REGRESAR AL MENU PRINICIPAL");

        printf("\nOpcion: ");
        scanf("%d", &opcion);
        switch(opcion) {
            case 1:
                menuArbolBinario();
                break;
            case 2:
                menuABB();
                break;
            case 3:
                do {
                    printf("¿Esta seguro de regresar al menu principal (s/n)? ");
                    scanf(" %c", &confirmacion);
                    confirmacion = tolower(confirmacion);
                    if (confirmacion != 's' && confirmacion != 'n') {
                        printf("Opcion invalida, vuelva a ingresar.\n\n");
                    }
                } while (confirmacion != 's' && confirmacion != 'n');
                break;
            default:
                printf("Opcion invalida, vuelva a intentar.\n\n");
                system("pause");
                break;
        }
    } while (opcion != 3 || confirmacion == 'n');
}

int main() {
    char confirmacion = 'n';
    int opcion;

    do {
        system("cls");

        puts("===========================================");
        puts("===== PAQUETE DE ESTRUCTURAS DE DATOS =====");
        puts("===========================================\n");
        puts("1. LISTAS");
        puts("2. PILAS");
        puts("3. COLAS");
        puts("4. ARBOLES");
        puts("5. SALIR");

        printf("\nOpcion: ");
        scanf("%d", &opcion);
        switch(opcion) {
            case 1:
                menuListas();
                break;
            case 2:
                menuPilas();
                break;
            case 3:
                menuColas();
                break;
            case 4:
                menuArboles();
                break;
            case 5:
                do {
                    printf("¿Esta seguro de regresar salir del programa (s/n)? ");
                    scanf(" %c", &confirmacion);
                    confirmacion = tolower(confirmacion);
                    if (confirmacion != 's' && confirmacion != 'n') {
                        printf("Opcion invalida, vuelva a ingresar.\n\n");
                    }
                } while (confirmacion != 's' && confirmacion != 'n');
                break;
            default:
                printf("Opcion invalida, vuelva a intentar.\n\n");
                system("pause");
                break;
        }
    } while (opcion != 5 || confirmacion == 'n');

    return 0;
}