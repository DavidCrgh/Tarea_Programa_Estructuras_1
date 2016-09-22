#ifndef ALMACENPRIMA_H
#define ALMACENPRIMA_H

#include <QtCore>

#include "carritoentrega.h"
#include "planificador.h"

struct AlmacenPrima{
    CarritoEntrega* carritoPrincipal;
    NodoPeticion* peticiones;
    NodoPeticion* realizadas;
};

struct NodoPeticion{
    String tipo;
    String maquinaOrigen;
    float cantidad;

    NodoPeticion* siguiente;
};

#endif // ALMACENPRIMA_H
