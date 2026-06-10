#include<stdio.h>
#include<stdlib.h>

#include "lista.h"
#include "funciones.h"

int main(){

    // Creo dos listas
    printf("Creando las listas...");

    Lista H1 = crearLista();
    Lista H2 = crearLista();

    H1 = insertar(H1, 'a');
    H1 = insertar(H1, 'b');
    H1 = insertar(H1, 'c');
    H1 = insertar(H1, 'd');
    H1 = insertar(H1, 'e');

    H2 = insertar(H2, 'a');
    H2 = insertar(H2, 'b');
    H2 = insertar(H2, 'c');
    H2 = insertar(H2, 'd');
    H2 = insertar(H2, 'e');

    printf("\nPrimera lista: ");
    mostrar(H1);

    printf("\nSegunda lista: ");
    mostrar(H2);

    printf("\n Todos los elementos de la lista H1 estan contenidos en H2? (Si deberian): ");
    if(estaContenida(H1, H2)){
        printf("\nTodos los elementos de H1 se encuentran en H2!");
    } else {
        printf("\nNO todos los elementos de H1 se encuentran en H2!");
    }

    printf("\nBorro el primer elemento de H2");
    H2 = borrar(H2);
    printf("\nPrimera lista: ");
    mostrar(H1);

    printf("\nSegunda lista: ");
    mostrar(H2);
    
    printf("\n Todos los elementos de la lista H1 estan contenidos en H2? (No deberian): ");
    if(estaContenida(H1, H2)){
        printf("\nTodos los elementos de H1 se encuentran en H2!");
    } else {
        printf("\nNO todos los elementos de H1 se encuentran en H2!");
    }


    
}