#include <stdio.h>
#include <stdlib.h>

#include "pila.h"

int main(){

// -- PROGRAMA DE PRUEBA DE PILA CON FUNCIONES QUE RETORNAN LA PILA MODIFICADA

    printf("\nINICIO DEL PROGRAMA DE PRUEBA DE PILA CON FUNCIONES QUE RETORNAN LA PILA MODIFICADA\n");

    printf("\n1. Creo una pila, la inicializo en pila vacia y muestro su altura (= 0): ");
    Pila P;
    P = pilaVacia();
    printf("Altura = %d\n", altura(P));

    printf("\n2. Pruebo la funcion esPilaVacia. Mensaje esperado 'Pila Vacia': ");
    if(esPilaVacia(P))
        printf("Pila Vacia\n");
    else
        printf("Pila NO Vacia\n");

    printf("\n3. Escribo el valor del tope de una pila vacia (= %d): %d\n", indefinido, top(P));

    printf("\n4. Hago pop sobre una pila vacia y verifico que sigue vacia. Mensaje esperado 'Pila Vacia': ");
    P = pop(P);
    if(esPilaVacia(P))
        printf("Pila Vacia\n");
    else
        printf("Pila NO Vacia\n");

    printf("\n5. Hago push del valor 10 y muestro el tope (= 10): ");
    P = push(P, 10);
    printf("Tope = %d\n", top(P));

    printf("\n6. Pruebo la funcion esPilaVacia. Mensaje esperado 'Pila NO Vacia': ");
    if(esPilaVacia(P))
        printf("Pila Vacia\n");
    else
        printf("Pila NO Vacia\n");

    printf("\n7. Hago pop y verifico que la pila queda vacia. Mensaje esperado 'Pila Vacia': ");
    P = pop(P);
    if(esPilaVacia(P))
        printf("Pila Vacia\n");
    else
        printf("Pila NO Vacia\n");

    printf("\n8. Hago push de 5 valores (10, 20, 30, 40, 50) y muestro altura (= 5): ");
    P = push(P, 10);
    P = push(P, 20);
    P = push(P, 30);
    P = push(P, 40);
    P = push(P, 50);
    printf("Altura = %d\n", altura(P));

    printf("\n9. Escribo el valor del tope (= 50): %d\n", top(P));

    printf("\n10. Hago pop y muestro el nuevo tope (= 40): ");
    P = pop(P);
    printf("Tope = %d, Altura = %d\n", top(P), altura(P));

    printf("\n11. Creo una segunda pila P2 y le hago push de 3 valores (100, 200, 300).\n");
    Pila P2;
    P2 = pilaVacia();
    P2 = push(P2, 100);
    P2 = push(P2, 200);
    P2 = push(P2, 300);
    printf("     Tope de P2 (= 300): %d, Altura de P2 (= 3): %d\n", top(P2), altura(P2));

    printf("\n12. Pruebo igualP con P y P2. Mensaje esperado 'NO Son Iguales': ");
    if(igualP(P, P2))
        printf("Son Iguales\n");
    else
        printf("NO Son Iguales\n");

    printf("\n13. Creo una tercera pila P3 igual a P (push de 10,20,30,40) y pruebo igualP(P, P3). Mensaje esperado 'Son Iguales': ");
    Pila P3;
    P3 = pilaVacia();
    P3 = push(P3, 10);
    P3 = push(P3, 20);
    P3 = push(P3, 30);
    P3 = push(P3, 40);
    if(igualP(P, P3))
        printf("Son Iguales\n");
    else
        printf("NO Son Iguales\n");

    printf("\n14. Apilo P2 encima de P3 con apila(P3, P2). Altura esperada (= 7), Tope esperado (= 300):\n");
    printf("     Altura P3 (= 4): %d | Altura P2 (= 3): %d\n", altura(P3), altura(P2));
    Pila P4 = apila(P3, P2);
    printf("     Altura de P4 (= 7): %d\n", altura(P4));
    printf("     Tope de P4 (= 300): %d\n", top(P4));
    printf("     P2 queda vacia luego de apilar. Mensaje esperado 'Pila Vacia': ");
    if(esPilaVacia(P2))
        printf("Pila Vacia\n");
    else
        printf("Pila NO Vacia\n");

    printf("\n15. Recargo P2 con (100, 200, 300) y pruebo apila(vacia, P2). Altura esperada (= 3): ");
    P2 = push(P2, 100);
    P2 = push(P2, 200);
    P2 = push(P2, 300);
    Pila vacia = pilaVacia();
    Pila P5 = apila(vacia, P2);
    printf("%d\n", altura(P5));
    printf("     P2 queda vacia luego de apilar. Mensaje esperado 'Pila Vacia': ");
    if(esPilaVacia(P2))
        printf("Pila Vacia\n");
    else
        printf("Pila NO Vacia\n");

    printf("\n16. Pruebo apila(P, pilaVacia()). Altura esperada (= 4): ");
    Pila vacia2 = pilaVacia();
    Pila P6 = apila(P, vacia2);
    printf("%d\n", altura(P6));

    printf("\n17. Pruebo apila(pilaVacia(), pilaVacia()). Mensaje esperado 'Pila Vacia': ");
    Pila vacia3 = pilaVacia();
    Pila vacia4 = pilaVacia();
    Pila P7 = apila(vacia3, vacia4);
    if(esPilaVacia(P7))
        printf("Pila Vacia\n");
    else
        printf("Pila NO Vacia\n");

    printf("\n18. Libero la memoria de todas las pilas\n");
    while(!esPilaVacia(P))   P  = pop(P);
    // P2 ya fue vaciada por apila en test 15
    while(!esPilaVacia(P3))  P3 = pop(P3);
    while(!esPilaVacia(P4))  P4 = pop(P4);
    while(!esPilaVacia(P5))  P5 = pop(P5);
    while(!esPilaVacia(P6))  P6 = pop(P6);

    printf("\nFIN DEL PROGRAMA DE PRUEBA DE PILA CON FUNCIONES QUE RETORNAN LA PILA MODIFICADA\n");

    return 0;
}