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

    printf("\n¿Pertenece el caracter a la lista H1?");
    bool perteneceLetra = perteneceRecursiva(H1, 'a');
    if(perteneceLetra){
        printf("\nSi pertenece el caracter");
    } else {
        printf("\nNo pertenece");
    }
    printf("\nH1 luego de usar el pertenece: ");
    mostrar(H1);
    char caracterPosicionK = posicionKRecursiva(H1, 3);
    printf("\nEl caracter de la posicion %d de la Lista H1 es: %c", 3, caracterPosicionK);
    printf("\nH1 luego de usar el posicionKRecursiva: ");
    mostrar(H1);

    
}