#ifndef BANDAINSPECTORES_H
#define BANDAINSPECTORES_H

#include "prototipos.h"

struct BandaInspectores{
    float limite;

    /*Inspector* inspector1;
    Inspector* inspector2;*/
    NodoContenido* frenteInspectores;

    BandaInspectores(float pLimite, Inspector* pInspector1, Inpector* pInspector2){
        limite = pLimite;
        inspector1 = pInspector1;
        inspector2 = pInspector2;
        frente = NULL;
    }

    void encolarBanda(float cantidad){
        NodoContenido* nodoNuevo = new NodoContenido(cantidad);

        if(frenteInspectores == NULL){
            frenteInspectores = nodoNuevo;
        } else {
            NodoContenido* nodoActual = frenteInspectores;

            while(nodoActual->siguiente != NULL){
                nodoActual = nodoActual->siguiente;
            }

            nodoActual->siguiente = nodoNuevo;
        }
    }

    NodoContenido* desencolarBanda(){
        if(frenteInspectores == NULL){
            return NULL;
        } else {
            NodoContenido* nodoBorrado = frenteInspectores;
            frenteInspectores = frenteInspectores->siguiente;
            nodoBorrado->siguiente = NULL;
            return nodoBorrado;
        }
    }

    bool estaLlena(){
        return contenidoActual() >= limite;
    }

    float contenidoActual(){
        NodoContenido* nodoActual = frenteInspectores;
        float sumatoria = 0.0;

        while(nodoActual != NULL){
            sumatoria += nodoActual->cantidad;
        }

        return sumatoria;
    }
};

struct Inspector{
    int desechadas;
    int aprobadas;
    BandaInspectores* bandaInspector;
    Empacadora* empacadora;

    Inspector(Empacadora* pEmpcadora){
        empacadora = pEmpcadora;
    }

    void inspeccionar(){
        if(!(empacadora->estaEmpacando)){
            NodoContenido* tandaGalletas = bandaInspector->desencolarBanda();
            if(tandaGalletas != NULL){
                float cantidadGalletas = tandaGalletas->cantidad;
                if(seDesecha()){
                    int galletasDesechadas = rand()%(cantidadGalletas + 1);
                    empacadora->galletasActuales += (cantidadGalletas - galletasDesechadas);
                } else {
                    empacadora->galletasActuales += cantidadGalletas;
                }
            }
        }
    }

    bool seDesecha(){
        return rand()%2 == 1;
    }
};

#endif // BANDAINSPECTORES_H
