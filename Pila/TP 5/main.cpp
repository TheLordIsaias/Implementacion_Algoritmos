#include <stdio.h>
#include <stdlib.h>

#include "pila.h"

int main(){

    printf("\nINICIO DEL PROGRAMA DE PRUEBA DE PILA\n");

    // ---- pilaVacia, esPilaVacia, altura, top ----

    printf("\n=== BLOQUE 1: pilaVacia, esPilaVacia, altura, top ===\n");

    printf("\n1.  Creo una pila vacia. Mensaje esperado 'Pila Vacia': ");
    Pila P = pilaVacia();
    if(esPilaVacia(P)) printf("Pila Vacia\n");
    else               printf("Pila NO Vacia\n");

    printf("\n2.  Altura de pila vacia (= 0): %d\n", altura(P));

    printf("\n3.  Top de pila vacia (= %d): %d\n", indefinido, top(P));

    printf("\n4.  Pop sobre pila vacia, sigue vacia. Mensaje esperado 'Pila Vacia': ");
    P = pop(P);
    if(esPilaVacia(P)) printf("Pila Vacia\n");
    else               printf("Pila NO Vacia\n");

    // ---- push ----

    printf("\n=== BLOQUE 2: push ===\n");

    printf("\n5.  Push de un solo elemento (10). Top esperado (= 10): ");
    P = push(P, 10);
    printf("%d\n", top(P));

    printf("\n6.  Altura luego de 1 push (= 1): %d\n", altura(P));

    printf("\n7.  Mensaje esperado 'Pila NO Vacia': ");
    if(esPilaVacia(P)) printf("Pila Vacia\n");
    else               printf("Pila NO Vacia\n");

    printf("\n8.  Push de 4 valores mas (20,30,40,50). Altura esperada (= 5), Top esperado (= 50):\n");
    P = push(P, 20);
    P = push(P, 30);
    P = push(P, 40);
    P = push(P, 50);
    printf("     Altura = %d | Top = %d\n", altura(P), top(P));

    // ---- pop ----

    printf("\n=== BLOQUE 3: pop ===\n");

    printf("\n9.  Pop una vez. Top esperado (= 40), Altura esperada (= 4): ");
    P = pop(P);
    printf("Top = %d | Altura = %d\n", top(P), altura(P));

    printf("\n10. Pop hasta vaciar la pila. Mensaje esperado 'Pila Vacia': ");
    P = pop(P);
    P = pop(P);
    P = pop(P);
    P = pop(P);
    if(esPilaVacia(P)) printf("Pila Vacia\n");
    else               printf("Pila NO Vacia\n");

    printf("\n11. Pop sobre pila recien vaciada. Mensaje esperado 'Pila Vacia': ");
    P = pop(P);
    if(esPilaVacia(P)) printf("Pila Vacia\n");
    else               printf("Pila NO Vacia\n");

    // ---- igualP ----

    printf("\n=== BLOQUE 4: igualP ===\n");

    printf("\n12. igualP de dos pilas vacias. Mensaje esperado 'Son Iguales': ");
    Pila PA = pilaVacia();
    Pila PB = pilaVacia();
    if(igualP(PA, PB)) printf("Son Iguales\n");
    else               printf("NO Son Iguales\n");

    printf("\n13. igualP(vacia, noVacia). Mensaje esperado 'NO Son Iguales': ");
    PB = push(PB, 1);
    if(igualP(PA, PB)) printf("Son Iguales\n");
    else               printf("NO Son Iguales\n");

    printf("\n14. igualP(noVacia, vacia). Mensaje esperado 'NO Son Iguales': ");
    if(igualP(PB, PA)) printf("Son Iguales\n");
    else               printf("NO Son Iguales\n");

    printf("\n15. igualP de dos pilas identicas (10,20,30). Mensaje esperado 'Son Iguales': ");
    PA = push(PA, 10);
    PA = push(PA, 20);
    PA = push(PA, 30);
    PB = pilaVacia();
    PB = push(PB, 10);
    PB = push(PB, 20);
    PB = push(PB, 30);
    if(igualP(PA, PB)) printf("Son Iguales\n");
    else               printf("NO Son Iguales\n");

    printf("\n16. igualP de pilas con mismo tamanio pero tope distinto. Mensaje esperado 'NO Son Iguales': ");
    Pila PC = pilaVacia();
    PC = push(PC, 10);
    PC = push(PC, 20);
    PC = push(PC, 99);
    if(igualP(PA, PC)) printf("Son Iguales\n");
    else               printf("NO Son Iguales\n");

    printf("\n17. igualP de pilas con distinto tamanio. Mensaje esperado 'NO Son Iguales': ");
    Pila PD = pilaVacia();
    PD = push(PD, 10);
    PD = push(PD, 20);
    if(igualP(PA, PD)) printf("Son Iguales\n");
    else               printf("NO Son Iguales\n");

    printf("\n18. PA y PB NO fueron modificadas por igualP. Alturas esperadas (= 3):\n");
    printf("     Altura PA (= 3): %d | Top PA (= 30): %d\n", altura(PA), top(PA));
    printf("     Altura PB (= 3): %d | Top PB (= 30): %d\n", altura(PB), top(PB));

    // ---- apila ----

    printf("\n=== BLOQUE 5: apila ===\n");

    printf("\n19. apila(pilaVacia, pilaVacia). Mensaje esperado 'Pila Vacia': ");
    Pila V1 = pilaVacia();
    Pila V2 = pilaVacia();
    Pila R = apila(V1, V2);
    if(esPilaVacia(R)) printf("Pila Vacia\n");
    else               printf("Pila NO Vacia\n");

    printf("\n20. apila(PA, pilaVacia). Altura esperada (= 3), Top esperado (= 30): ");
    Pila V3 = pilaVacia();
    R = apila(PA, V3);
    printf("Altura = %d | Top = %d\n", altura(R), top(R));
    printf("     PA NO fue modificada. Altura esperada (= 3): %d | Top esperado (= 30): %d\n", altura(PA), top(PA));

    printf("\n21. apila(pilaVacia, PB). Altura esperada (= 3), Top esperado (= 30): ");
    Pila V4 = pilaVacia();
    R = apila(V4, PB);
    printf("Altura = %d | Top = %d\n", altura(R), top(R));
    printf("     PB NO fue modificada. Altura esperada (= 3): %d | Top esperado (= 30): %d\n", altura(PB), top(PB));

    printf("\n22. apila(PA, PB): apilo PB encima de PA. Altura esperada (= 6), Top esperado (= 30):\n");
    R = apila(PA, PB);
    printf("     Altura R (= 6): %d | Top R (= 30): %d\n", altura(R), top(R));
    printf("     PA NO fue modificada. Altura esperada (= 3): %d | Top esperado (= 30): %d\n", altura(PA), top(PA));
    printf("     PB NO fue modificada. Altura esperada (= 3): %d | Top esperado (= 30): %d\n", altura(PB), top(PB));

    printf("\n23. apila con pilas de distinto contenido. PA=(10,20,30), PE=(100,200).\n");
    printf("     Altura esperada (= 5), Top esperado (= 30):\n");
    Pila PE = pilaVacia();
    PE = push(PE, 100);
    PE = push(PE, 200);
    R = apila(PE, PA);
    printf("     Altura R (= 5): %d | Top R (= 30): %d\n", altura(R), top(R));
    printf("     PE NO fue modificada. Altura esperada (= 2): %d | Top esperado (= 200): %d\n", altura(PE), top(PE));
    printf("     PA NO fue modificada. Altura esperada (= 3): %d | Top esperado (= 30): %d\n", altura(PA), top(PA));

    // ---- liberacion ----

    printf("\n=== BLOQUE 6: liberacion de memoria ===\n");
    printf("\n24. Libero todas las pilas\n");
    while(!esPilaVacia(P))  P  = pop(P);
    while(!esPilaVacia(PA)) PA = pop(PA);
    while(!esPilaVacia(PB)) PB = pop(PB);
    while(!esPilaVacia(PC)) PC = pop(PC);
    while(!esPilaVacia(PD)) PD = pop(PD);
    while(!esPilaVacia(PE)) PE = pop(PE);
    while(!esPilaVacia(R))  R  = pop(R);
    printf("     Memoria liberada correctamente\n");

    printf("\nFIN DEL PROGRAMA DE PRUEBA DE PILA\n");

    return 0;
}