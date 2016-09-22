#ifndef MEZCLADORACHOCOLATE_H
#define MEZCLADORACHOCOLATE_H

#include "prototipos.h"

struct MezcladoraChocolate{
    float tiempo;
    float masaMinima;
    float masaMaxima;
    float masaActual;

    Banda* banda;
    AlmacenPrima* almacen;
};

#endif // MEZCLADORACHOCOLATE_H
