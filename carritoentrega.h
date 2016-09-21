#ifndef CARRITOENTREGA_H
#define CARRITOENTREGA_H

#include <QtCore>

#include "mezcladoramasa.h"
#include "mezcladorachocolate.h"

struct CarritoEntrega{
    float gramosMasa;
    float gramosChocolate;
    float tiempo;

    MezcladoraMasa* mezcladoraMasa1;
    MezcladoraMasa* mezcladoraMasa2;
    MezcladoraChocolate* mezcladoraChocolate;
};

#endif // CARRITOENTREGA_H
