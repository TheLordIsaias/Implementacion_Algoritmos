#include<stdio.h>
#include<stdlib.h>

bool estaContenida(Lista H1, Lista H2){
    if(esListaVacia(H1)){
        return true;
    } else {
        if(esListaVacia(H2)){
            return false;
        } else {
            if(pertenece(H2, primerElemento(H1))){
                H1.L = H1.L->siguiente;
                return estaContenida(H1, H2);
            } else {
                return false;
            }
        }
    }
}