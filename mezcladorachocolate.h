#ifndef MEZCLADORACHOCOLATE_H
#define MEZCLADORACHOCOLATE_H

#include "prototipos.h"

struct MezcladoraChocolate{
    float tiempo;
    float mezclaMinima;
    float mezclaMaxima;
    float mezclaActual;

    Banda* banda;
    AlmacenPrima* almacen;

    MezcladoraChocolate(float pTiempo, float pMinima, float pMaxima, Banda* pBanda, AlmacenPrima* pAlmacen){
        tiempo = pTiempo;
        mezclaMinima = pMinima;
        mezclaMaxima = pMaxima;
        mezclaActual = 0;
        banda = pBanda;
        almacen = pAlmacen;
    }
};

#endif // MEZCLADORACHOCOLATE_H
