#include <stdio.h>
#include <stdlib.h>

typedef char itemAB;
const itemAB indefinido = '@';

typedef struct NodoAB{
    itemAB raiz;
    NodoAB* izq;
    NodoAB* der;
}NodoAB;

typedef struct NodoAB* AB;

AB ABVacio(){
    return NULL;
}

AB armarAB(AB izq, itemAB x, AB der){
    NodoAB *nuevo = new NodoAB;
    nuevo->raiz = x;
    nuevo->izq = izq;
    nuevo->der = der;
    return nuevo;
}

bool esABVacio(AB T){
    return T == NULL;
}

AB izquierdo(AB T){
    if(!esABVacio(T)){
        return T->izq;
    } else {
        return ABVacio();
    }
}

itemAB raiz(AB T){
    if(!esABVacio(T)){
        return T->raiz;
    } else {
        return indefinido;
    }
}

AB derecho(AB T){
    if(!esABVacio(T)){
        return T->der;
    } else {
        return ABVacio();
    }
}

bool pertenece(AB T, itemAB x){
    if(esABVacio(T)){
        return false;
    } else {
        if(raiz(T) == x){
            return true;
        } else {
            return (pertenece(T->izq, x) || pertenece(T->der, x));
        }
    }
}

void ordenSimetrico(AB T){ 
    if(!esABVacio(T)){
        ordenSimetrico(izquierdo(T));
        printf(" %c ", raiz(T));
        ordenSimetrico(derecho(T));
    }
}

bool esArbolHoja(AB T){
    if(esABVacio(T)){
        return false;
    } else {
        return esABVacio(izquierdo(T)) && esABVacio(derecho(T));
    }
}

int numeroHojas(AB T){
    if(esABVacio(T)){
        return 0;
    } else {
        if(esArbolHoja(T)){
            return 1;
        } else {
            return numeroHojas(izquierdo(T)) + numeroHojas(derecho(T));
        }
    }
}

int cuenta(AB T, itemAB x){
    if(esABVacio(T)){
        return 0;
    } else {
        if(raiz(T) == x){
            return 1 + cuenta(izquierdo(T), x) + cuenta(derecho(T), x);
        } else {
            return cuenta(izquierdo(T), x) + cuenta(derecho(T), x);
        }
    }
}

int altura(AB T){
    if(esArbolHoja(T)){
        return 0;
    } else {
        int altIzq = altura(izquierdo(T));
        int altDer = altura(derecho(T));
        if(altIzq > altDer){
            return 1 + altIzq;
        } else {
            return 1 + altDer;
        }
    }
}

bool iguales(AB T1, AB T2){
    if(esABVacio(T1) && esABVacio(T2)){
        return true;
    } else {
        if(esABVacio(T1) || esABVacio(T2)){
            return false;
        } else {
            if(raiz(T1) != raiz(T2)){
                return false;
            } else {
                return iguales(izquierdo(T1), izquierdo(T2)) && iguales(derecho(T1), derecho(T2));
            }
        }
    }
}

AB podarHojas(AB T){
    if(esABVacio(T)){
        return ABVacio();
    } else {
        if(esABVacio(T->izq) && esABVacio(T->der)){
            return ABVacio();
        } else {
            return armarAB(podarHojas(T->izq), raiz(T), podarHojas(T->der));
        }
    }
}