#ifndef BANDA_H
#define BANDA_H

#include "prototipos.h"

struct NodoContenido{
    float cantidad;
    QString tipo;

    NodoContenido* siguiente;

    NodoContenido(float pCantidad, QString pTipo){
        cantidad = pCantidad;
        tipo = pTipo;
        siguiente = NULL;
    }
};

struct Banda{
    float limite;
    QString tipo;
    NodoContenido* frenteBanda;

    Banda(QString pTipo){
        limite = 0;//10000.0;
        frenteBanda = NULL;
        tipo=pTipo;
    }

    /*
     * Reestablece los parametros por defecto de la estructura.
     */
    void resetearBanda(){
        limite=0.0;
        frenteBanda=NULL;

    }

    void encolarBanda(float pCantidad, QString pTipo){
        NodoContenido* nodoNuevo = new NodoContenido(pCantidad, pTipo);

        if(frenteBanda == NULL){
            frenteBanda = nodoNuevo;
        } else {
            NodoContenido* nodoActual = frenteBanda;

            while(nodoActual->siguiente != NULL){
                nodoActual = nodoActual->siguiente;
            }

            nodoActual->siguiente = nodoNuevo;
        }
    }

    NodoContenido* desencolarBanda(){
        if(frenteBanda == NULL){
            return NULL;
        } else {
            NodoContenido* nodoBorrado = frenteBanda;
            frenteBanda = frenteBanda->siguiente;
            nodoBorrado->siguiente = NULL;
            return nodoBorrado;
        }
    }

    bool estaLlena(){
        return contenidoActual() >= limite;
    }

    float contenidoActual(){
        NodoContenido* nodoActual = frenteBanda;
        float sumatoria = 0.0;

        while(nodoActual != NULL){
            sumatoria += nodoActual->cantidad;
            nodoActual = nodoActual->siguiente;
        }

        return sumatoria;
    }

};
#endif // BANDA_H
