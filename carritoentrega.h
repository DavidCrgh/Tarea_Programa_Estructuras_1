#ifndef CARRITOENTREGA_H
#define CARRITOENTREGA_H

#include "prototipos.h"

struct CarritoEntrega{

    float tiempo;
    NodoPeticion* entrega;

    MezcladoraMasa* mezcladoraMasa1;
    MezcladoraMasa* mezcladoraMasa2;
    MezcladoraChocolate* mezcladoraChocolate;
};

#endif // CARRITOENTREGA_H
