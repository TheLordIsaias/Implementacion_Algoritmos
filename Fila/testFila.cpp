#include <stdio.h>
#include <stdlib.h>

#include "fila.h"

Fila extraerNEsimo(Fila fila, int n);

int main(){

    printf("---------------------- Inicio test de Fila ----------------------");
    printf("\nCreo una fila vacia llamada F1");
    Fila F1 = filaVacia();
    printf("\nLa fila esta vacia? (= Esta vacia): ");
    if(esFilaVacia(F1)){
        printf("Esta vacia");
    } else {
        printf("NO esta vacia");
    }
    printf("\nQue tan larga es la fila? (=0): %d\nCual es el frente de la fila? (= -9999): %d", longitud(F1), frente(F1));
    
    printf("\nEnfilo los elementos [1 2 3 4] en F1");
    F1 = enfila(F1, 1);
    F1 = enfila(F1, 2);
    F1 = enfila(F1, 3);
    F1 = enfila(F1, 4);
    printf("\nMostrando contenido de F1 (= [ 1 2 3 4 ]): ");
    mostrar(F1);
    printf("\nVacio la Fila F1...");
    while(!esFilaVacia(F1)){
        F1 = defila(F1);
    }
    printf("\nMostrando contenido de F1 (= []): ");
    mostrar(F1);

    printf("\nEnfilo los elementos [5 6 7 8] en F1");
    F1 = enfila(F1, 5);
    F1 = enfila(F1, 6);
    F1 = enfila(F1, 7);
    F1 = enfila(F1, 8);
    printf("\nMostrando contenido de F1 (= [ 5 6 7 8 ]): ");
    mostrar(F1);
    printf("\nLa fila esta vacia? (= NO esta vacia): ");
    if(esFilaVacia(F1)){
        printf("Esta vacia");
    } else {
        printf("NO esta vacia");
    }
    printf("\nQue tan larga es la fila? (=4): %d\nCual es el frente de la fila? (= 5): %d", longitud(F1), frente(F1));


    printf("\nCreo una fila vacia llamada F2");
    Fila F2 = filaVacia();
    printf("\nLa fila esta vacia? (= Esta vacia): ");
    if(esFilaVacia(F2)){
        printf("Esta vacia");
    } else {
        printf("NO esta vacia");
    }
    printf("\nQue tan larga es la fila? (=0): %d\nCual es el frente de la fila? (= -9999): %d", longitud(F2), frente(F2));
    printf("\nEnfilo los elementos [1 2 3 4] en F2");
    F2 = enfila(F2, 1);
    F2 = enfila(F2, 2);
    F2 = enfila(F2, 3);
    F2 = enfila(F2, 4);
    printf("\nMostrando contenido de F2 (= [ 1 2 3 4 ]): ");
    mostrar(F2);
    printf("\nEl item 9 se encuentra en la fila F1? (= No): ");
    if(pertenece(F1, 9)){
        printf("Si");
    } else {
        printf("No");
    }
    printf("\nAgrego el elemento 9 a la fila F1...");
    F1 = enfila(F1, 9);
    printf("\nMostrando contenido de F1 (= [ 5 6 7 8 9 ]): ");
    mostrar(F1);
    printf("\nEl item 9 se encuentra en la fila F1? (= Si): ");
    if(pertenece(F1, 9)){
        printf("Si");
    } else {
        printf("No");
    }
    printf("\nSon las filas F1 y F2 iguales? (= No): ");
    if(igualF(F1, F2)){
        printf("Si");
    } else {
        printf("No");
    }
    printf("\nCreo una lista F3 con los elementos [ 1 2 3 4 ]");
    Fila F3 = filaVacia();
    F3 = enfila(F3, 1);
    F3 = enfila(F3, 2);
    F3 = enfila(F3, 3);
    F3 = enfila(F3, 4);
    printf("\nMostrando contenido de F3 (= [ 1 2 3 4 ]): ");
    mostrar(F3);
    printf("\nSon las filas F2 y F3 iguales? (= Si): ");
    if(igualF(F2, F3)){
        printf("Si");
    } else {
        printf("No");
    }
    printf("\nConcatenamos F1 a F2...");
    F2 = concat(F2, F1);
    printf("\nMostrando contenido de F2 (= [ 1 2 3 4 5 6 7 8 9]): ");
    mostrar(F2);
    printf("\nInvierto F2... (= [ 9 8 7 6 5 4 3 2 1 ]): ");
    F2 = invertir(F2);
    mostrar(F2);

    printf("\nAplico extraerNEsimo con n = 5 en F2 (= [ 9 8 7 6 4 3 2 1 ]): ");
    F2 = extraerNEsimo(F2, 5);
    mostrar(F2);

    printf("\nAplico extraerNEsimo con n = 2 en F2 (= [ 9 7 6 4 3 2 1 ]): ");
    F2 = extraerNEsimo(F2, 2);
    mostrar(F2);

    printf("\nCreo una fila F4 y le agrego cinco 1's y tres 2's");
    Fila F4 = filaVacia();
    F4 = enfila(F4, 1);
    F4 = enfila(F4, 1);
    F4 = enfila(F4, 1);
    F4 = enfila(F4, 1);
    F4 = enfila(F4, 1);
    F4 = enfila(F4, 2);
    F4 = enfila(F4, 2);
    F4 = enfila(F4, 2);
    printf("\nMostrando contenido de F4 (= [ 1 1 1 1 1 2 2 2 ]): ");
    mostrar(F4);
    printf("\nAplica singular a F4 (= [ 1 2 ])");
    F4 = singular(F4);
    mostrar(F4);

    printf("\nLiberando memoria de las filas F1, F2, F3 y F4...");
    liberarFila(F1);
    liberarFila(F2);
    liberarFila(F3);
    liberarFila(F4);
    printf("\nMemoria liberada, fin del programa!");
    return 0;
}

Fila extraerNEsimo(Fila fila, int n){
    if(esFilaVacia(fila)){
        return filaVacia();
    } else {
        if(n == 1){
            return defila(fila);
        } else {
            item frenteDeFila = frente(fila);
            fila.frente = fila.frente->siguiente;
            fila.largo--;
            return concat(enfila(filaVacia(), frenteDeFila), extraerNEsimo(fila, n-1));
        }
    }
}