#include <stdlib.h>
#include <stdio.h>

typedef char objeto;
const objeto indefinido = '@';

typedef struct Nodo{
    objeto item;
    Nodo* siguiente;
}Nodo;

typedef struct Baul{
    int capacidad;
    int ocupado;
    Nodo* L;
    Nodo* primero;
}Baul;


Baul baulVacio(int capacidad){
    Baul baul;
    baul.L = NULL;
    baul.primero = NULL;
    baul.capacidad = capacidad;
    baul.ocupado = 0;
    return baul;
}

Baul guardar(Baul baul, objeto item){ // OCULTO PARA EL USUARIO
    Nodo* nuevoItem = new Nodo();
    nuevoItem->item = item;
    nuevoItem->siguiente = baul.L;
    if(baul.L != NULL && baul.L->siguiente == NULL){
        baul.primero = baul.L;
    }
    baul.L = nuevoItem;
    baul.ocupado++;
    return baul;
}

Baul agregar(Baul baul, objeto item){
    if(baul.capacidad != baul.ocupado){
        baul = guardar(baul, item);
    } else {
        printf("\nEl Baul esta lleno, no se pueden guardar mas items");
    }
    return baul;
}

int capacidad(Baul baul){
    return baul.capacidad;
}

bool estaVacio(Baul baul){
    if(baul.ocupado == 0){
        return true;
    } else {
        return false;
    }
}

objeto ultimo(Baul baul){
    if(baul.L != NULL){
        return baul.L->item;
    } else {
        return indefinido;
    }
    
}

objeto primero(Baul baul){
    return baul.primero->item;
}

Baul quitarUltimo(Baul baul){
    Nodo* aux = baul.L;
    baul.L = baul.L->siguiente;
    baul.ocupado--;
    free(aux);
    return baul;
}

Baul vaciar(Baul baul){
    while(!estaVacio(baul)){
        Nodo* aux = baul.L;
        baul.L = baul.L->siguiente;
        free(aux);
        baul.ocupado--;
    }
    baul.ocupado = 0;
    return baul;
}

bool contiene(Baul baul, objeto item){
    Baul aux = baul;
    while(aux.L != NULL){
        if(aux.L->item == item){
            return true;
        } else {
            aux.L = aux.L->siguiente;
        }
    }
    return false;
}

int ocupado(Baul baul){
    return baul.ocupado;
}

int disponible(Baul baul){
    return baul.capacidad - baul.ocupado;
}