#include <stdio.h>
#include <stdlib.h>

#include "pila.h"

int main(){

    printf("Inicio de programa");
    printf("\nCreo una pila vacia llamada P1");
    Pila P1 = pilaVacia();
    printf("\nLa pila esta vacia? (= Si): ");
    if(esPilaVacia(P1)){
        printf("Si");
    } else{
        printf("No");
    }
    printf("\nSe muestra el contenido de la Pila");
    mostrarPila(P1);
    printf("\nAgrego un 1 a la pila...");
    P1 = push(P1, 1);
    printf("\nLa pila esta vacia? (= No): ");
    if(esPilaVacia(P1)){
        printf("Si");
    } else{
        printf("No");
    }
    mostrarPila(P1);
    printf("\nAgrego un 2, 3 y 4 a la pila");
    P1 = push(P1, 2);
    P1 = push(P1, 3);
    P1 = push(P1, 4);
    mostrarPila(P1);
    printf("\nRealizo un pop...");
    P1 = pop(P1);
    mostrarPila(P1);
    printf("\nCual es el tope de la pila? (= 3): %d", top(P1));
    printf("\nCual es la altura de la pila? (= 3): %d", altura(P1));

    printf("\nHago Push de 5 en la pila P1");
    P1 = push(P1, 5);
    printf("\nCual es el tope de la pila? (= 5): %d", top(P1));
    printf("\nCual es la altura de la pila? (= 4): %d", altura(P1));
    mostrarPila(P1);

    printf("\nCreo una pila nueva llamada P2 con los items 1, 2 y 3");
    Pila P2 = pilaVacia();
    P2 = push(P2, 1);
    P2 = push(P2, 2);
    P2 = push(P2, 3);
    mostrarPila(P2);

    printf("\nLas pilas P1 y P2 son iguales? (= No): ");
    if(igualP(P1, P2)){
        printf("Si");
    } else {
        printf("No");
    }

    printf("\nHago Push de 5 en la pila P2");
    P2 = push(P2, 5);
    mostrarPila(P2);
    printf("\nLas pilas P1 y P2 son iguales? (= Si): ");
    if(igualP(P1, P2)){
        printf("Si");
    } else {
        printf("No");
    }

    printf("\nCual es el fondo del a pila P1 (= 1): %d", fondo(P1));
    printf("\nSaco el fondo de P1...");
    P1 = popf(P1);
    mostrarPila(P1);

    printf("\nHago un push de 5 al final de P1...");
    P1 = pushf(P1, 5);
    mostrarPila(P1);

    printf("\nApilo la P2 sobre P1");
    P1 = apila(P1, P2);
    mostrarPila(P1);

    P1 = liberarPila(P1);
    P2 = liberarPila(P2);


    getchar();
    return 0;
}