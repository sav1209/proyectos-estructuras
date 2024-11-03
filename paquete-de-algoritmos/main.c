#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

// LISTAS
#include "listasimple.h"
#include "listadoble.h"
#include "listacircular.h"

void menuListas() {
    char confirmacion = 'n';
    int opcion;

    do {
        system("cls");

        puts("==========================");
        puts("===== MENU DE LISTAS =====");
        puts("==========================\n");
        puts("1. LISTAS SIMPLES.");
        puts("2. LISTAS DOBLEMENTE LIGADAS");
        puts("3. LISTAS CIRCULARES");
        puts("4. REGRESAR AL MENU PRINICIPAL.");

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
                        printf("Opcion invalida, vuelva a ingresar.\n");
                    }
                } while (confirmacion != 's' && confirmacion != 'n');
                break;
            default:
                printf("Opcion invalida, vuelva a intentar.\n");
        }

        putchar('\n');
        system("pause");
    } while (opcion != 4 || confirmacion == 'n');
}

int main() {
    char confirmacion = 'n';
    int opcion;

    do {
        system("cls");

        puts("===========================================");
        puts("===== PAQUETE DE ESTRUCTURAS DE DATOS =====");
        puts("===========================================\n");
        puts("1. LISTAS.");
        puts("2. PILA");
        puts("3. COLAS");
        puts("4. ARBOLES");
        puts("5. SALIR.");

        printf("\nOpcion: ");
        scanf("%d", &opcion);
        switch(opcion) {
            case 1:
                menuListas();
                break;
            case 5:
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
    } while (opcion != 5 || confirmacion == 'n');

    return 0;
}