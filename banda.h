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

    /*
     * Entradas:
     * Cantidad que se desea encolar.
     * Tipo de lo que se va a encolar.
     *
     * Encola un nodo en la banda (cola) correspondiente.
     */
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

    /*
     * Salidas:
     * Nodo que se ha borrado (desencolado)
     *
     * Desencola un nodo de la banda (cola) y retorna su direccion de memoria.
     */
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

    /*
     * Salidas:
     * Suma de todas las cantidades de todos los nodos de la cola.
     *
     * Itera sobre la banda y suma sus variables cantidad a una variable de
     * sumatoria que despues es retornadas.
     */
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
