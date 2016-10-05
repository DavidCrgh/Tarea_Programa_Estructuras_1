#ifndef EMPACADORA_H
#define EMPACADORA_H

#include "prototipos.h"
#include "listagalletas.h"

struct Empacadora{
    float galletasActuales;
    ListaGalletas* listaGalletas;
    ListaRangos* listaRangos;
    bool estaEmpacando;
    bool estaActiva;

    MonticulosEmpaques* monticulosEmpacadora;

    Empacadora(ListaGalletas* pListaGalletas){
        galletasActuales = 0.0;
        listaGalletas = pListaGalletas;
        monticulosEmpacadora = listaGalletas->generarMonticulos();
        listaRangos = listaGalletas->construirRangos();
        estaEmpacando = false;
        estaActiva = false;
    }

    /*
     * Reestablece los parametros por defecto de la estructura.
     */
    void resetearEmpacadora(){
        galletasActuales = 0.0;
        monticulosEmpacadora = listaGalletas->generarMonticulos();
        estaEmpacando = false;
        estaActiva = false;
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
        galletasActuales -= (empaque->galletasxEmpaque * empaque->cantidadxTiempo);
        NodoMonticulo* monticulo = monticulosEmpacadora->buscarMonticulo(empaque->tipoEmpaque);
        monticulo->cantidadPaquetes += empaque->cantidadxTiempo;
        monticulo->totalGalletas += (empaque->cantidadxTiempo) * (empaque->galletasxEmpaque);
    }
};
#endif // EMPACADORA_H
