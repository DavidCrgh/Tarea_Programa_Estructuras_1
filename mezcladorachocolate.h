#ifndef MEZCLADORACHOCOLATE_H
#define MEZCLADORACHOCOLATE_H

#include <QtCore>

struct MezcladoraChocolate{
    float tiempo;
    float masaMinima;
    float masaMaxima;
    float masaActual;

    AlmacenPrima* almacen;
};

#endif // MEZCLADORACHOCOLATE_H
