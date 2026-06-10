#include<stdio.h>
#include<stdlib.h>

#include "lista.h"

int main(){

// -- PROGRAMA DE PRUEBA DE LISTA CON FUNCIONES QUE RETORNAN LA LISTA MODIFICADA

    printf("\nINICIO DEL PROGRAMA DE PRUEBA DE LISTA CON FUNCIONES QUE RETORNAN LA LISTA MODIFICADA\n");

	printf("\n1.Creo una lista, la inicializo en lista vacia y muestro la lista vacia por pantalla: ");
	Lista H;
	H=crearLista();
    mostrar(H);

    printf("\n2.Pruebo la funcion esListaVacia. Mensaje esperado 'Lista Vacia': ");
    if(esListaVacia(H))
		printf("Lista Vacia\n");
	else
	    printf("Lista NO Vacia\n");

    printf("\n3.Escribo la cantidad de elementos de una lista vacia (= 0): %d \n", longitud(H));

    printf("\n4.Escribo el valor del primer elemento de una lista vacia (= @): %c \n", primerElemento(H));

    printf("\n5.Inserto el caracter 'a' en la lista y muestro la lista por pantalla: ");
	H=insertar(H,'a');
    mostrar(H);

	printf("\n6.Pruebo la funcion esListaVacia. Mensaje esperado 'Lista NO Vacia': ");
    if(esListaVacia(H))
		printf("Lista Vacia\n");
	else
		printf("Lista NO Vacia\n");

	printf("\n7.Borro un elemento de la lista y muestro por pantala. Se espera lista vacia: ");
	H=borrar(H);
	mostrar(H);

	printf("\n8.Inserto 5 elementos ('a','d','#','t','z') en la lista y muestro la lista por pantalla: ");
	H=insertar(H,'a');
	H=insertar(H,'d');
	H=insertar(H,'#');
	H=insertar(H,'t');
	H=insertar(H,'z');
	mostrar(H);

    printf("\n9.Escribo la cantidad de elementos de la lista (= 5): %d \n", longitud(H));

    printf("\n10.Escribo el valor del primer elemento de la lista vacia (= z): %c \n", primerElemento(H));

	printf("\n11.Borro un elemento de la lista y muestro la lista por pantalla: ");
	H=borrar(H);
	mostrar(H);

    printf("\n12.Busco si pertenece el caracter $ en la lista. Mensaje esperado 'NO Pertenece': ");
    if(pertenece(H, '$'))
		printf("Pertenece\n");
	else
	    printf("NO Pertenece\n");

    printf("\n13.Busco si pertenece el caracter d en la lista. Mensaje esperado: 'Pertenece': ");

    if(pertenece(H, 'd'))
    		printf("Pertenece\n");
    	else
    	    printf("NO Pertenece\n");

    printf("\n14.Inserto el caracter ! al final de una lista vacia y muestro la lista por pantalla antes y despues de insertar:\n ");
    Lista H2;
    H2=crearLista();
    printf("\n     Lista ANTES de insertar al final: ");
    mostrar(H2);
    printf("\n     Lista DESPUES de insertar al final: ");
    H2=insertarFinal(H2, '!');
    mostrar(H2);

    printf("\n15.Inserto el caracter ! al final de una lista con varios elementos y muestro la lista por pantalla antes y despues de insertar ");
    printf("\n     Lista ANTES de insertar al final: ");
    mostrar(H);
    printf("\n     Lista DESPUES de insertar al final: ");
    H=insertarFinal(H, '!');
    mostrar(H);

    H2=insertar(H2,'x');
    H2=insertar(H2,'q');
    H2=insertar(H2,'t');
    H2=insertar(H2,'*');
    H2=insertar(H2,'&');
    H2=insertar(H2,'$');

    printf("\n16. Muestro la lista ANTES de invocar a la funcion externa posicionK: ");
    printf("\n     H2: ");
    mostrar(H2);

    printf("\n17. Escribo el caracter que se encuentra en la posición 3(= *): %c\n", posicionK(&H2, 3));

    printf("\n18. Muestro la lista DESPUES de invocar a la funcion externa posicionK: ");
    printf("\n     H2: ");
    mostrar(H2);

    printf("\n19. Escribo el caracter que se encuentra en la posición 100(= @): %c\n", posicionK(&H2, 100));

    printf("\n20. Muestro la lista DESPUES de invocar a la funcion externa posicionK: ");
    printf("\n     H2: ");
    mostrar(H2);


    printf("\n21.Libero la memoria reservada en forma dinamica\n");
    while(!esListaVacia(H))
    	H=borrar(H);

    printf("\nFIN DEL PROGRAMA DE PRUEBA DE LISTA CON FUNCIONES QUE MODIFICAN LA LISTA POR PARAMETRO\n");



// -----------------------------------------------------------------------------------------------------------------------
    return 0;
}