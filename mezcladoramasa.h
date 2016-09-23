#ifndef MEZCLADORAMASA_H
#define MEZCLADORAMASA_H

#include "prototipos.h"

struct MezcladoraMasa{
    float tiempo;
    float masaMinima;
    float masaMaxima;
    float masaActual;

    Banda* banda;
    AlmacenPrima* almacen;

    MezcladoraMasa(float pTiempo, float pMinima, float pMaxima, Banda* pBanda, AlmacenPrima* pAlmacen){
        tiempo = pTiempo;
        masaMinima = pMinima;
        masaMaxima = pMaxima;
        masaActual = 0;
        banda = pBanda;
        almacen = pAlmacen;
    }
};

#endif // MEZCLADORA_H
