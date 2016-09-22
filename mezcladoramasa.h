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
};

#endif // MEZCLADORA_H
