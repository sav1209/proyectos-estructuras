#ifndef LISTADOBLE_H
#define LISTADOBLE_H

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
void borrarLD(ListaDoble** lista);


// CLASE 1

// 1. CREA UNA LISTA DOBLEMENTE LIGADA INSERTANDO A CADA ELEMENTO POR EL FINAL
ListaDoble* crearLDPorFinal();

// 2. IMPRIME EL CONTENIDO DE UNA LISTA DOBLEMENTE LIGADA
void imprimirLDIzqADer(ListaDoble* lista);
void imprimirLDDerAIzq(ListaDoble* lista);
void imprimirLD(ListaDoble* lista);

// 3. ELIMINA EL ÚLTIMO ELEMENTO DE UNA LISTA DOBLEMENTE LIGADA
void eliminarFinalLD(ListaDoble** lista);

// 4. ELIMINA UN ELEMENTO CON INFORMACIÓN DADA POR EL USUARIO EN UNA LISTA DOBLEMENTE LIGADA
void eliminarNodoLD(ListaDoble** lista);


// CLASE 2

// 1. ELIMINA UN ELEMENTO ANTES DE UNO CON INFORMACIÓN DADA POR EL USUSARIO EN UNA LISTA DOBLEMENTE LIGADA
 void eliminarAntesDeNodoLD(ListaDoble** lista);

// 2. INSERTA UN ELEMENTO AL PRINCIPIO DE UNA LISTA DOBLEMENTE LIGADA
void insertar_al_principio_LD(ListaDoble** lista);

// 3. INSERTA UN ELEMENTO DESPUÉS DE UNO CON INFORMACIÓN DADA POR EL USUARIO EN UNA LISTA DOBLEMENTE LIGADA
void insertar_despues_LD(ListaDoble** lista);

// 4. DETERMINAR SI UNA LISTAS DOBLE ES O NO UN PALÍNDROMO
int es_palindromo(ListaDoble* lista);

void menu_listas_dobles();

#endif