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

    NodoEmpaque* determinarPaquete(){

    }
};
#endif // EMPACADORA_H
