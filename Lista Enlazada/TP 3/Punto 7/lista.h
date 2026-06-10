#include <stdlib.h>
#include <stdio.h>

typedef int item;
const item indefinido = -999;

typedef struct Nodo{
    item dato;
    Nodo* siguiente;
}Nodo;

typedef struct Lista{

    int cantidad;
    Nodo* L;

}Lista;

Lista crearLista();
bool esListaVacia(Lista H);
void mostrar(Lista H);
item primerElemento(Lista H);
Lista insertar(Lista H, char x);
Lista borrar(Lista H);
int longitud(Lista H);
bool pertenece(Lista H, item x);
Lista insertarFinal(Lista H, item x);
item posicionK(Lista *H, int k);

Lista crearLista(){
    Lista nuevaL;
    nuevaL.L = NULL;
    nuevaL.cantidad = 0;
    return nuevaL;
}

bool esListaVacia(Lista H){
    if(H.L == NULL){
        return true;
    } else {
        return false;
    }
}

void mostrar(Lista H){
    while (H.L != NULL){
        printf("%c", H.L->dato);
        H.L = H.L->siguiente;
    }
}

item primerElemento(Lista H){
    if(H.L == NULL){
        return indefinido;
    }
    return H.L->dato;
}

Lista insertar(Lista H, char x){
    Nodo* nuevo = new Nodo;
    nuevo->dato = x;
    nuevo->siguiente = H.L;
    H.L = nuevo;
    H.cantidad++;
    return H;
}

Lista borrar(Lista H){
    if(H.L == NULL){
        return H;
    } else {
        Nodo *aux;
        aux = H.L;
        H.L = aux->siguiente;
        delete (aux);
        H.cantidad--;
        return H;
    }
}

int longitud(Lista H){
    return H.cantidad;
}

bool pertenece(Lista H, item x){
    if(H.L == NULL){
        return false;
    }
    while (H.L != NULL){
        if(H.L->dato == x){
            return true;
        }
        H.L = H.L->siguiente;
    }
    return false;
}

Lista insertarFinal(Lista H, item x){
    if(H.L == NULL){
        H = insertar(H, x);
    } else {
        Nodo *aux = H.L;
        while (aux->siguiente != NULL){
            aux = aux->siguiente;
        }
        Nodo *nuevoNodo = new Nodo;
        nuevoNodo->dato = x;
        nuevoNodo->siguiente = NULL;
        aux->siguiente = nuevoNodo;
        
        H.cantidad++;
    }
    return H;
}

item posicionK(Lista *H, int k){
    if(longitud(*H) > k){
        for (int i = 1; i < k; i++){
            *H = borrar(*H);
        }
        return primerElemento(*H);
    } else {
        return indefinido;
    }
}