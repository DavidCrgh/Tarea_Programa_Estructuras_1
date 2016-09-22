#ifndef ALMACENPRIMA_H
#define ALMACENPRIMA_H

#include "prototipos.h"

struct AlmacenPrima{
    CarritoEntrega* carritoPrincipal;
    NodoPeticion* peticiones;
    NodoPeticion* realizadas;

    void encolar(NodoPeticion* nodo){

    }
};

struct NodoPeticion{
    std::string tipo;
    std::string maquinaOrigen;
    float cantidad;

    NodoPeticion* siguiente;
};

#endif // ALMACENPRIMA_H
