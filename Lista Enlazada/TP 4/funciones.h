#include "baul.h"

int moverObjetos(Baul *baulA, Baul *baulB){
    int cantidadDeObjetos = 0;
    if(disponible(*baulB) > ocupado(*baulA)){
        cantidadDeObjetos = baulA->ocupado;
        Baul *aux = baulA;
        while(baulA->ocupado > 0){
            *baulB = agregar(*baulB, ultimo(*baulA));
            *baulA = quitarUltimo(*baulA);
        }
    } else {
        printf("\nNo hay espacio para guardar los objetos del primer baul en el segundo!");
    } 
    return cantidadDeObjetos;
}