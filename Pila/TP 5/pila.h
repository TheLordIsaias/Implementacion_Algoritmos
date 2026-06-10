#include <stdio.h>
#include <stdlib.h>

typedef int item;
const item indefinido = -9999;

typedef struct Nodo{
    item dato;
    Nodo* siguiente;
}Nodo;

typedef struct Pila{

    int altura;
    Nodo* fondo;
    Nodo* tope;

}Pila;

Pila pilaVacia();
Pila push(Pila pila, item x);
bool esPilaVacia(Pila pila);
Pila pop(Pila pila);
item top(Pila pila);
int altura(Pila pila);
bool igualP(Pila pilaA, Pila pilaB);
Pila apila(Pila pilaA, Pila *pilaB);

Pila pilaVacia(){
    Pila nuevaPila;
    nuevaPila.altura = 0;
    nuevaPila.fondo = NULL;
    nuevaPila.tope = NULL;
    return nuevaPila;
}

Pila push(Pila pila, item x){
    Nodo* nuevo = new Nodo;
    nuevo->dato = x;
    nuevo->siguiente = pila.tope;
    if(esPilaVacia(pila)){
        pila.fondo = nuevo;
    }
    pila.tope = nuevo;
    pila.altura++;
    return pila;
}

bool esPilaVacia(Pila pila){
    if(pila.altura == 0){
        return true;
    } else {
        return false;
    }
}

Pila pop(Pila pila){
    if(!esPilaVacia(pila)){
        Nodo* aux = pila.tope;
        if(pila.tope == pila.fondo){
            pila.fondo = NULL;
        }
        pila.tope = pila.tope->siguiente;
        free(aux);
        pila.altura--;
        return pila;
    } else {
        return pilaVacia();
    }
}

item top(Pila pila){
    if(!esPilaVacia(pila)){
        return pila.tope->dato;
    } else {
        return indefinido;
    }
}

int altura(Pila pila){
    return pila.altura;
}

bool igualP(Pila pilaA, Pila pilaB){
    if(esPilaVacia(pilaA) && esPilaVacia(pilaB)){
        return true;
    }
    if(esPilaVacia(pilaA) || esPilaVacia(pilaB)){
        return false;
    }

    return (top(pilaA) == top(pilaB)) && igualP(pop(pilaA), pop(pilaB));
}

Pila apila(Pila pilaA, Pila pilaB){
    if(esPilaVacia(pilaA) && esPilaVacia(pilaB)){
        return pilaVacia();
    }
    if(esPilaVacia(pilaA)){
        return pilaB;
    }
    if(esPilaVacia(pilaB)){
        return pilaA;
    }
    int topPilaB = top(pilaB);
    pilaB = pop(pilaB);
    return push(apila(pilaA, pilaB), topPilaB);
}
