#ifndef BANDA_H
#define BANDA_H

#include "prototipos.h"
//#include "ensambladora.h"
//#include "horno.h"

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

    //Ensambladora* ensambladora;
    //Horno* horno;

    Banda(QString pTipo){
        limite = 10000;//10000.0;
        frenteBanda = NULL;
        tipo=pTipo;
    }

    /*Banda(float pLimite, Ensambladora* pEnsambladora){
        limite = pLimite;
        ensambladora = pEnsambladora;
        horno = NULL;
        frenteBanda = NULL;
    }

    Banda(float pLimite, Horno* pHorno){
        limite = pLimite;
        ensambladora = NULL;
        horno = pHorno;
        frenteBanda = NULL;
    }*/

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

    /*void alimentarEnsambladora(){
        if(!(ensambladora->estaEnsamblando())){
            NodoContenido* nodoDesencolado = desencolarBanda();
            if(nodoDesencolado != NULL){
                if(nodoDesencolado->tipo == "Masa"){
                    ensambladora->actualMasa += nodoDesencolado->cantidad;
                } else {
                    ensambladora->actualChocolate += nodoDesencolado->cantidad;
                }
            }
        }
    }*/

    /*void alimentarHorno(int bandejasPrendidas){
        if(horno->tieneCamposDisponibles(bandejasPrendidas)){
            NodoContenido* tandaGalletas = desencolarBanda();
            if(tandaGalletas != NULL){
                float galletas = tandaGalletas->cantidad;

                for(int i = 0; i < bandejasPrendidas; i++){
                    bandejaActual = horno->bandejas[i];

                    if(bandejaActual->contenidoActual < bandejaActual->capacidad){
                        if(bandejaActual->contenidoActual + tandaGalletas > bandejaActual->capacidad){
                            float cantidad = bandejaActual->capacidad - bandejaActual->contenidoActual;
                            galletas -= cantidad;
                            bandejaActual->contenidoActual += cantidad;
                        } else {
                            bandejaActual->contenidoActual += galletas;
                            galletas = 0;

                        }
                    }
                }
            }
        }
    }*/

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
