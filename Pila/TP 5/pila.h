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
Pila apila(Pila pilaA, Pila pilaB);

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
    int topeA = top(pilaA);
    pilaA.tope = pilaA.tope->siguiente;
    pilaA.altura--;
    int topeB = top(pilaB);
    pilaB.tope = pilaB.tope->siguiente;
    pilaB.altura--;
    return ((topeA == topeB) && igualP(pilaA, pilaB));
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
    pilaB.tope = pilaB.tope->siguiente;
    pilaB.altura--;
    return push(apila(pilaA, pilaB), topPilaB);
}

item fondo(Pila pila){
    return pila.fondo->dato;
}

Pila popf(Pila pila){
    if(esPilaVacia(pila)){
        return pilaVacia();
    }
    if(pila.tope == pila.fondo){
        return pilaVacia();
    }
    Nodo *aux = pila.tope;
    while(aux->siguiente != pila.fondo){
        aux = aux->siguiente;
    }

    free(pila.fondo);
    aux->siguiente = NULL;
    pila.fondo = aux;
    pila.altura--;

    return pila;
}

Pila pushf(Pila pila, item x){
    Nodo *nuevo = new Nodo;
    nuevo->dato = x;
    nuevo->siguiente = NULL;
    if(esPilaVacia(pila)){
        pila.tope = nuevo;
        pila.fondo = nuevo;
    } else {
        pila.fondo->siguiente = nuevo;
        pila.altura++;
    }
    
    return pila;
}

void mostrarPila(Pila pila){
    printf("\nTope\n_____\n|   |");
    while(!esPilaVacia(pila)){
        printf("\n| %d |", pila.tope->dato);
        pila.tope = pila.tope->siguiente;
        pila.altura--;
    }
    printf("\n|___|\n\nFondo");
}

Pila liberarPila(Pila pila){
    Nodo *aux;
    while(!esPilaVacia(pila)){
        aux = pila.tope;
        pila.tope = pila.tope->siguiente;
        free(aux);
        pila.altura--;
    }
    return pilaVacia();
}
