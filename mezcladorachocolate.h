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
};

#endif // MEZCLADORACHOCOLATE_H
