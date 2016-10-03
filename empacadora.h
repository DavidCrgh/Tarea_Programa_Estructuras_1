#ifndef EMPACADORA_H
#define EMPACADORA_H

#include "prototipos.h"
#include "listagalletas.h"
//#include "monticulosempaques.h"

struct Empacadora{
    float galletasActuales;
    ListaGalletas* listaGalletas;
    ListaRangos* listaRangos;
    bool estaEmpacando;

    MonticulosEmpaques* monticulosEmpacadora;

    Empacadora(ListaGalletas* pListaGalletas){
        galletasActuales = 0.0;
        listaGalletas = pListaGalletas;
        monticulosEmpacadora = listaGalletas->generarMonticulos();
        listaRangos = NULL;
        estaEmpacando = false;
    }

    NodoEmpaque* elegirPaquete(){
       int random= rand()%100;
       NodoRango* nodoActual = listaRangos->primerRango;
       for(int i=0; i < listaGalletas->largoListaGalletas() ;i++){
            if((nodoActual->minimo<=random) & (random<=nodoActual->maximo)){
                NodoEmpaque* buscado= listaGalletas->buscarEmpaque(nodoActual->tipoEmpaque);
                return buscado;
            }
            nodoActual = nodoActual->siguiente;
       }
    }

    void empacarGalletas(NodoEmpaque* empaque){
        //if(galletasActuales >= (empaque->galletasxEmpaque * empaque->cantidadxTiempo)){
        galletasActuales -= (empaque->galletasxEmpaque * empaque->cantidadxTiempo);
        NodoMonticulo* monticulo = monticulosEmpacadora->buscarMonticulo(empaque->tipoEmpaque);
        monticulo->cantidadPaquetes += empaque->cantidadxTiempo;
        monticulo->totalGalletas += (empaque->cantidadxTiempo) * (empaque->galletasxEmpaque);
    }
};
#endif // EMPACADORA_H
