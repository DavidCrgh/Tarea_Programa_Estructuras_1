#ifndef SIMULACION_H
#define SIMULACION_H

#include "almacenprima.h"

#include "hilocarritoentrega.h"
#include "hilomezcladoramasa.h"
#include "hilomezcladorachocolate.h"
#include "hilobanda.h"

struct Simulacion{

    //VentanaPrincipal* interfaz;

    AlmacenPrima* almacenPrima;
    CarritoEntrega* carritoEntrega;
    MezcladoraMasa* mezcladorasMasa[2];
    MezcladoraChocolate* mezcladoraChocolate;
    Banda* bandaMasa;
    Banda* bandaChocolate;

    HiloCarritoEntrega* hiloCarritoEntrega;
    HiloMezcladoraMasa* hilosMezcladorasMasa[2];
    HiloMezcladoraChocolate* hiloMezcladoraChocolate;

    Simulacion();
};

#endif // SIMULACION_H
