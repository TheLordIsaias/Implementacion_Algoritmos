#include <stdio.h>
#include <stdlib.h>

#include "ab.h"

int main (){

    printf("Creo un arbol izquierdo A y uno derecho B para poder armar el arbol ab1 con item C");
    AB izq = ABVacio();
    izq = armarAB(ABVacio(), 'A', ABVacio());
    AB der = ABVacio();
    der = armarAB(ABVacio(), 'B', ABVacio());

    AB ab1 = ABVacio();
    ab1 = armarAB(izq, 'C', der);

    printf("\nMostrando arbol en orden simetrico (= <A C B>): ");
    printf("\n<");
    ordenSimetrico(ab1);
    printf(">");

    printf("\nPertenece C al arbol C? (= Si): ");
    if(pertenece(ab1, 'C')){
        printf("Si");
    } else {
        printf("No");
    }

    printf("\nPertenece X al arbol C? (= No): ");
    if(pertenece(ab1, 'X')){
        printf("Si");
    } else {
        printf("No");
    }

    printf("\nEs C arbol hoja? (= No): ");
    if(esArbolHoja(ab1)){
        printf("Si");
    } else {
        printf("No");
    }

    printf("\nEs A arbol hoja? (= Si): ");
    if(esArbolHoja(izquierdo(ab1))){
        printf("Si");
    } else {
        printf("No");
    }

    printf("\nCantidad de Hojas del Arbol C (= 2): %d", numeroHojas(ab1));

    printf("\nCantidad de veces que aparece el item A (=1): %d", cuenta(ab1, 'A'));

    printf("\nCreo la variable de arbol ab2 y la armo con un arbol hoja D y E, con el item F");
    AB ab2 = ABVacio();
    izq = armarAB(ABVacio(), 'D', ABVacio());
    der = armarAB(ABVacio(), 'E', ABVacio());
    ab2 = armarAB(izq, 'F', der);
    printf("\nMostrando arbol F (= < D F E >)");
    printf("\n<");
    ordenSimetrico(ab2);
    printf(">");
    printf("\nCreo la variable de arbol ab2 y la armo con el arbol C y el arbol F, y el item G");
    AB ab3 = ABVacio();
    ab3 = armarAB(ab1, 'G', ab2);

    printf("\nMostrando arbol G (=< A C B G D F E >)");
    printf("\n<");
    ordenSimetrico(ab3);
    printf(">");

    printf("\nRaiz de G (= G): %c", raiz(ab3));
    printf("\nAltura de G (= 2): %d", altura(ab3));

    printf("\nLos arboles C y F son iguales? (= No): ");
    if(iguales(ab1, ab2)){
        printf("Si");
    } else {
        printf("No");
    }
    printf("\nCreo la variable de arbol ab4 y la armo con el arbol C y el arbol F, y el item G");
    AB ab4 = ABVacio();
    izq = armarAB(ABVacio(), 'D', ABVacio());
    der = armarAB(ABVacio(), 'E', ABVacio());
    ab4 = armarAB(izq, 'F', der);

    printf("\nMostrando arbol F(ab4) (=< D F E >)");
    printf("\n<");
    ordenSimetrico(ab4);
    printf(">");

    printf("\nLos arboles F(ab2) y F(ab4) son iguales? (= Si): ");
    if(iguales(ab2, ab4)){
        printf("Si");
    } else {
        printf("No");
    }

    printf("\nPodo las hojas de G...");
    ab3 = podarHojas(ab3);
    printf("\nMostrando arbol G podado (=< C G F >)");
    printf("\n<");
    ordenSimetrico(ab3);
    printf(">");

    getchar();

    return 0;
}