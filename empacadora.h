#ifndef EMPACADORA_H
#define EMPACADORA_H
#include "prototipos.h"
struct Empacadora{
    float galletasActuales;
    ListaGalletas* listaGalletas;
    ListaRangos* listaRangos;
    bool estaEmpacando;

    MonticulosEmpaques* monticulosEmpacadora;

    Empacadora(ListaGalletas* pListaGalletas){
        listaGalletas = pListaGalletas;
        monticulosEmpacadora = pListaGalletas->generarMonticulos();
        galletasActuales = 0.0;
        estaEmpacando = false;
        listaRangos= pListaGalletas->construirRangos();
    }

    NodoEmpaque* elegirPaquete(){
       int random= rand()%101;
       NodoRango* nodoActual=listaRangos->primerRango;
       for(int i=0;listaGalletas->largoListaGalletas();i++){
            if(nodoActual->minimo>=random & random<=nodoActual->maximo){
                NodoEmpaque* buscado= listaGalletas->buscarEmpaque(nodoActual->tipoEmpaque);
                return buscado;
            }
            nodoActual=nodoActual->siguiente;
       }
    }

    void empacarGalletas(NodoEmpaque* empaque){
        if(galletasActuales >= (empaque->galletasxEmpaque * empaque->cantidadxTiempo)){
            galletasActuales -= (empaque->galletasxEmpaque * empaque->cantidadxTiempo);
            NodoMonticulo* monticulo = monticulosEmpacadora->buscarMonticulo(empaque->tipoEmpaque);
            monticulo->cantidadPaquetes += empaque->cantidadxTiempo;
        }
    }
};
#endif // EMPACADORA_H
