#ifndef ALMACENPRIMA_H
#define ALMACENPRIMA_H

#include "prototipos.h"

struct AlmacenPrima{
    NodoPeticion* frentePeticiones;
    NodoPeticion* inicioRealizadas;

    AlmacenPrima(){
        peticiones = NULL;
        realizadas = NULL;
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

#endif // ALMACENPRIMA_H
