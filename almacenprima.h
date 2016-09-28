#ifndef ALMACENPRIMA_H
#define ALMACENPRIMA_H

#include "prototipos.h"

struct NodoPeticion{
    QString tipo;
    QString maquinaOrigen;
    float cantidad;

    NodoPeticion* siguiente;

    NodoPeticion(QString pTipo, QString pMaquinaOrigen, float pCantidad){
        tipo = pTipo;
        maquinaOrigen = pMaquinaOrigen;
        cantidad = pCantidad;
        siguiente = NULL;
    }
};

struct AlmacenPrima{
    NodoPeticion* frentePeticiones;
    NodoPeticion* inicioRealizadas;

    AlmacenPrima(){
        frentePeticiones = NULL;
        inicioRealizadas = NULL;
    }

    void encolarPeticion(QString tipo, QString maquinaOrigen, float cantidad){
        NodoPeticion* nodoNuevo = new NodoPeticion(tipo, maquinaOrigen, cantidad);

        if(frentePeticiones == NULL){
            frentePeticiones = nodoNuevo;
        } else {
            NodoPeticion* nodoActual = frentePeticiones;

            while(nodoActual->siguiente != NULL){
                nodoActual = nodoActual->siguiente;
            }

            nodoActual->siguiente = nodoNuevo;
        }
    }

    NodoPeticion* desencolarPeticion(){
        if(frentePeticiones == NULL){
            return NULL;
        } else {
            NodoPeticion* nodoBorrado = frentePeticiones;
            frentePeticiones = frentePeticiones->siguiente;
            nodoBorrado->siguiente = NULL;
            return nodoBorrado;
        }
    }
};
#endif // ALMACENPRIMA_H
