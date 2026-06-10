#include<stdio.h>
#include<stdlib.h>

bool perteneceRecursiva(Lista H, item x){
    if(H.L == NULL){
        return false;
    }

    if(H.L->dato == x){
        return true;
    } else {
        H.L = H.L->siguiente;
        perteneceRecursiva(H, x);
    }
}

item posicionKRecursiva(Lista H, int k){
    if(esListaVacia(H)){
        return indefinido;
    } else {
        if(k == 1){
            return primerElemento(H);
        } else {
            H.L = H.L->siguiente;
            return posicionKRecursiva(H, k-1);
        }
    }
}