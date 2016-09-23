#ifndef CARRITOENTREGA_H
#define CARRITOENTREGA_H

#include "prototipos.h"

struct CarritoEntrega{

    float tiempoViaje;
    NodoPeticion* entrega;

    MezcladoraMasa* mezcladoraMasa1;
    MezcladoraMasa* mezcladoraMasa2;
    MezcladoraChocolate* mezcladoraChocolate;

    CarritoEntrega(float tiempo, MezcladoraMasa* mezcladora1, MezcladoraMasa* mezcladora2,
                   MezcladoraChocolate* pMezcladoraChocolate){
        tiempoViaje = tiempo;
        mezcladoraMasa1 = mezcladora1;
        mezcladoraMasa2 = mezcladora2;
        mezcladoraChocolate = pMezcladoraChocolate;
    }
};

#endif // CARRITOENTREGA_H
