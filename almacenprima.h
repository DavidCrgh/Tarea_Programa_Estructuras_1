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

    NodoPeticion* peek(){
        return frentePeticiones;
    }

    void insertarRealizada(NodoPeticion* nodoInsertado){
        if(inicioRealizadas == NULL){
            inicioRealizadas = nodoInsertado;
        } else {
            NodoPeticion* nodoActual = inicioRealizadas;

            while(nodoActual->siguiente != NULL){
                nodoActual = nodoActual->siguiente;
            }

            nodoActual->siguiente = nodoInsertado;
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

    QString imprimirLista(bool esRealizada){
        NodoPeticion* nodoActual;
        if(esRealizada){
            nodoActual = inicioRealizadas;
        } else {
            nodoActual = frentePeticiones;
        }

        if(nodoActual == NULL){
            return "Vacio";
        } else {
            QString mensaje = "";

            while(nodoActual != NULL){
                mensaje += "Tipo: " + nodoActual->tipo + "\n";
                mensaje += "Hecha por: " + nodoActual->maquinaOrigen + "\n";
                mensaje += "Cantidad: " + QString::number(nodoActual->cantidad) + "\n";
                mensaje += "-------------------------------------------------------\n";
                nodoActual = nodoActual->siguiente;
            }

            return mensaje;
        }
    }
};
#endif // ALMACENPRIMA_H
