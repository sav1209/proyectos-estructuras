#ifndef LISTACIRCULAR_H
#define LISTACIRCULAR_H

typedef struct NodoLC {
    int info;
    struct NodoLC* liga;
} NodoLC;


// Crea un nuevo nodo con liga nula.
NodoLC* crearNodoLC(int info);


// CLASE 1

// 1. CREA UNA LISTA CIRCULAR POR EL FINAL
NodoLC* crearLCPorFinal();

// 2. IMPRIME EL CONTENIDO DE UNA LISTA CIRCULAR
void imprimirLC(NodoLC* primero);

// 3. ELIMINA EL PRIMER ELEMENTO DE UNA LISTA CIRCULAR
void eliminarPrimerElementoLC(NodoLC** inicio);

// 4. BUSCA UN ELEMENTO CON INFORMACIÓN DADA POR EL USUARIO EN UNA LISTA CIRCULAR Y QUE IMPRIMA LA DIRECCIÓN DEL ELEMENTO ANTECEDENTE Y LA INFORMACIÓN DEL ELEMENTO CONSECUENTE
void ImprimeAnterior_ImprimeInformacion(NodoLC** inicio, int info);


// CLASE 2

// 1. INSERTA UN ELEMENTO ANTES DE UNO CON INFORMACIÓN DADA POR EL USUARIO EN UNA LISTA CIRCULAR
void insertarAntesDeNodoLC(NodoLC** inicio, int infoBuscar, int nuevoInfo);

// 2. INSERTA UN ELEMENTO AL PRINCIPIO EN UNA LISTA CIRCULAR 
void InsertarPrincipio (NodoLC** inicio,int info);

// 3. ELIMINA UN ELEMENTO AL FINAL DE UNA LISTA CIRCULAR
void EliminaFinal(NodoLC** inicio);

// 4. ELIMINA UN ELEMENTO DESPUÉS DE UNO CON INFORMACIÓN DADA POR EL USUARIO EN UNA LISTA CIRCULAR
void eliminarDespuesDeNodoLC(NodoLC** inicio, int info);

// Borra todos los nodos de una lista circular.
void borraLC(NodoLC** inicio);

// MENU
void menuListasCirculares();

#endif