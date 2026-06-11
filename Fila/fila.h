#include <stdio.h>
#include <stdlib.h>

typedef int item;
const item indefinido = -9999;

typedef struct Nodo{
    item dato;
    Nodo* siguiente;
}Nodo;

typedef struct Fila{

    int largo;
    Nodo* frente;
    Nodo* final;

}Fila;

Fila filaVacia(){
    Fila nuevaFila;
    nuevaFila.frente = NULL;
    nuevaFila.final = NULL;
    nuevaFila.largo = 0;
    return nuevaFila;
}

bool esFilaVacia(Fila fila){
    if (fila.largo == 0){
        return true;
    } else {
        return false;
    }
}

item frente(Fila fila){
    if(!esFilaVacia(fila)){
        return fila.frente->dato;
    } else {
        return indefinido;
    }
}

Fila enfila(Fila fila, item x){
    Nodo *nuevo = new Nodo;
    nuevo->dato = x;
    nuevo->siguiente = NULL;
    if(esFilaVacia(fila)){
        fila.frente = nuevo;
    } else {
        fila.final->siguiente = nuevo;
    }
    fila.final = nuevo;
    fila.largo++;
    return fila;
}

Fila defila(Fila fila){
    if(esFilaVacia(fila)){
        return filaVacia();
    } else {
        Nodo *aux = fila.frente;
        fila.frente = fila.frente->siguiente;
        if(fila.frente == NULL){
            fila.final = NULL;
        }
        free(aux);
        fila.largo--;
        return fila;
    }
}

int longitud(Fila fila){
    return fila.largo;
}

bool pertenece(Fila fila, item x){
    if(esFilaVacia(fila)){
        return false;
    } else {
        if(fila.frente->dato == x){
            return true;
        } else {
            fila.frente = fila.frente->siguiente;
            fila.largo--;
            return pertenece(fila, x);
        }
    }
}

bool igualF(Fila filaA, Fila filaB){
    if(esFilaVacia(filaA) && esFilaVacia(filaB)){
        return true;
    } else {
        if(esFilaVacia(filaA) || esFilaVacia(filaB)){
            return false;
        } else {
            if(frente(filaA) == frente(filaB)){
                filaA.frente = filaA.frente->siguiente;
                filaA.largo--;
                filaB.frente = filaB.frente->siguiente;
                filaB.largo--;
                return igualF(filaA, filaB);
            } else {
                return false;
            }
        }
    }
}

Fila concat(Fila filaA, Fila filaB){
    if(esFilaVacia(filaA) && esFilaVacia(filaB)){
        return filaVacia();
    } else {
        if(esFilaVacia(filaA)){
            return filaB;
        }
        if(esFilaVacia(filaB)){
            return filaA;
        }
        item x = frente(filaB);
        filaB.frente = filaB.frente->siguiente;
        filaB.largo--;
        return concat(enfila(filaA, x), filaB);
    }
}

Fila invertir(Fila fila){
    if(esFilaVacia(fila)){
        return filaVacia();
    } else {
        item x = frente(fila);
        fila.frente = fila.frente->siguiente;
        fila.largo--;
        return enfila(invertir(fila), x);
    }
}

void mostrar(Fila fila){
    printf("[");
    while(!esFilaVacia(fila)){
        printf(" %d ", fila.frente->dato);
        fila.frente = fila.frente->siguiente;
        fila.largo--;
    }
    printf("]");
}

void liberarFila(Fila fila){
    while(!esFilaVacia(fila)){
        fila = defila(fila);
    }
}

item final(Fila fila){
    return fila.final->dato;
}

Fila defilarN(Fila fila, int N){
    for (int i = 0; i < N; i++){
        fila = defila(fila);
    }
    return fila;
}

Fila singular(Fila fila){
    if(esFilaVacia(fila)){
        return filaVacia();
    } else {
        item x = frente(fila);
        fila.frente = fila.frente->siguiente;
        fila.largo--;
        if(pertenece(fila, x)){
            return singular(fila);
        } else {
            return concat(enfila(filaVacia(), x), singular(fila));
        }
    }
}