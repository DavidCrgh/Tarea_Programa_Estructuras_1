#ifndef MONTICULOSEMPAQUES_H
#define MONTICULOSEMPAQUES_H

#include "prototipos.h"

struct MonticulosEmpaques{
    NodoMonticulo* primerNodo;

    MonticulosEmpaques(){
        primerNodo = NULL;
    }

    void insertarMonticulo(QString pTipo){
        if(primerNodo == NULL){
            primerNodo = new NodoMonticulo(pTipo);
        } else {
            NodoMonticulo* nodoNuevo = new NodoMonticulo(pTipo);
            nodoNuevo->siguiente = primerNodo;
            primerNodo =  nodoNuevo;
        }
    }
};

struct NodoMonticulo{
    QString nombre;
    int cantidadPaquetes;

    NodoMonticulo* siguiente;

    NodoMonticulo(QString pNombre){
        nombre = pNombre;
        cantidadPaquetes = 0;
        siguiente = NULL;
    }
};

#endif // MONTICULOSEMPAQUES_H
