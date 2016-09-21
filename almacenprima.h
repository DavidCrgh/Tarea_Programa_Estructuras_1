#ifndef ALMACENPRIMA_H
#define ALMACENPRIMA_H

#include <QtCore>

#include "carritoentrega.h"
#include "planificador.h"

struct AlmacenPrima{
    CarritoEntrega* carritoPrincipal;
    //Planificador* planificador;
    NodoPeticion* tope;
};

struct NodoPeticion{

};

#endif // ALMACENPRIMA_H
