#ifndef MEZCLADORA_H
#define MEZCLADORA_H

#include <QtCore>

#include "almacenprima.h"

struct MezcladoraMasa{
    float tiempo;
    float masaMinima;
    float masaMaxima;
    float masaActual;

    AlmacenPrima* almacen;
};

#endif // MEZCLADORA_H
