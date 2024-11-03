#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#include "listasimple.h"

void menuListas() {

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

            case 2:
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
    } while (opcion != 2 || confirmacion == 'n');

    return 0;
}