#ifndef EMPACADORA_H
#define EMPACADORA_H
#include "prototipos.h"

struct Empacadora{
    int galletasActuales;
    ListaGalletas* listaGalletas;

    MonticulosEmpaques* monticulosEmpacadora;

    Empacadora(ListaGalletas* pListaGalletas, MonticulosEmpaques* pMonticulo){
        listaGalletas = pListaGalletas;
        monticulosEmpacadora = pMonticulo;
        galletasActuales = 0;
    }
};
#endif // EMPACADORA_H
