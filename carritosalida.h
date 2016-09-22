#ifndef CARRITOSALIDA_H
#define CARRITOSALIDA_H

#include "prototipos.h"

struct CarritoSalida{
    std::string nombrePaquete;
    float tiempoViaje;
    int maximo;
    int cantidadTransportado;
    int cantidadxPaquete;

    Empacadora* empacadora;
    AlmacenSalida* almacen;
};

#endif // CARRITOSALIDA_H
