#include <stdlib.h>
#include <stdio.h>

#include "funciones.h"

int main(){
// Creo dos listas
    printf("Creando los baules con una capacidad de 10...");

    Baul B1 = baulVacio(10);
    Baul B2 = baulVacio(10);

    printf("\nEl Baul B1 esta vacio? (= Si):");
    if(estaVacio(B1)){
        printf("Si");
    } else {
        printf("No");
    }

    printf("\nEl Baul B2 esta vacio? (= Si):");
    if(estaVacio(B2)){
        printf("Si");
    } else {
        printf("No");
    }

    printf("\nAgrego valores a los dos baules...");

    B1 = agregar(B1, 'f');
    B1 = agregar(B1, 'g');
    B1 = agregar(B1, 'h');
    B1 = agregar(B1, 'i');
    B1 = agregar(B1, 'j');

    B2 = agregar(B2, 'a');
    B2 = agregar(B2, 'b');
    B2 = agregar(B2, 'c');
    B2 = agregar(B2, 'd');
    B2 = agregar(B2, 'e');

    printf("\nEl Baul B1 esta vacio? (= No):");
    if(estaVacio(B1)){
        printf("Si");
    } else {
        printf("No");
    }

    printf("\nEl Baul B2 esta vacio? (= No):");
    if(estaVacio(B2)){
        printf("Si");
    } else {
        printf("No");
    }

    printf("\nCapacidad de B1 (= 10): %d\nCapacidad de B2 (= 10): %d", capacidad(B1), capacidad(B2));
    printf("\nUltimo elemento de B1 (= j): %c\nUltimo elemento de B2 (= e): %c", ultimo(B1), ultimo(B2));
    printf("\nQuito los ultimos elementos de cada lista...");
    B1 = quitarUltimo(B1);
    B2 = quitarUltimo(B2);
    printf("\nUltimo elemento de B1 (= i): %c\nUltimo elemento de B2 (= d): %c", ultimo(B1), ultimo(B2));
    printf("\nPrimer elemento de B1 (= f): %c\nPrimer elemento de B2 (= a): %c", primero(B1), primero(B2));
    printf("\nLa lista B1 contiene el objeto a? (= No): ");
    if(contiene(B1, 'a')){
        printf("Si");
    } else {
        printf("No");
    }
    printf("\nLa lista B2 contiene el objeto b? (= Si): ");
    if(contiene(B2, 'b')){
        printf("Si");
    } else {
        printf("No");
    }
    printf("\nCantidad de objetos en B1 (= 4): %d\nCantidad de objetos en B2 (= 4): %d", ocupado(B1), ocupado(B2));
    printf("\nEspacio disponible en B1 (= 6): %d\nEspacio disponible en B1 (= 6): %d", disponible(B1), disponible(B2));

    printf("\nMuevo todos los objetos del baul B1 a B2");
    int cantidadItemsMovidos = moverObjetos(&B1, &B2);
    printf("\nSe movieron %d objetos del baul B1 a B2", cantidadItemsMovidos);

    printf("\nEl Baul B1 esta vacio? (= Si):");
    if(estaVacio(B1)){
        printf("Si");
    } else {
        printf("No");
    }

    printf("\nEl Baul B2 esta vacio? (= No):");
    if(estaVacio(B2)){
        printf("Si");
    } else {
        printf("No");
    }

    printf("\nCreando un baul con una capacidad de 10...");
    Baul B3 = baulVacio(10);
    printf("\nLlenando el baul...");
    B3 = agregar(B3, 'a');
    B3 = agregar(B3, 'b');
    B3 = agregar(B3, 'c');
    B3 = agregar(B3, 'd');
    B3 = agregar(B3, 'e');
    B3 = agregar(B3, 'f');
    B3 = agregar(B3, 'g');
    B3 = agregar(B3, 'h');
    B3 = agregar(B3, 'i');
    B3 = agregar(B3, 'j');
    printf("\nCantidad de objetos en B3 (= 10): %d\nEspacio disponible en B3 (= 0): %d", ocupado(B3), disponible(B3));
    printf("\nIntento agregar un objeto mas... (No deberia ser posible)");
    B3 = agregar(B3, 'k');
    printf("\nMuevo todos los objetos del baul B3 a B2 (No deberia de ser posible)");
    cantidadItemsMovidos = moverObjetos(&B3, &B2);
    printf("\nSe movieron %d objetos del baul B3 a B2", cantidadItemsMovidos);


    return 0;
}