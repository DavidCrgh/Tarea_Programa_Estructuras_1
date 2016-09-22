#ifndef ALMACENPRIMA_H
#define ALMACENPRIMA_H

#include "prototipos.h"

struct AlmacenPrima{
    CarritoEntrega* carritoPrincipal;
    NodoPeticion* peticiones;
    NodoPeticion* realizadas;
};

struct NodoPeticion{
    std::string tipo;
    std::string maquinaOrigen;
    float cantidad;

    NodoPeticion* siguiente;

    NodoPeticion(std::string pTipo, std::string pMaquinaOrigen, float pCantidad){
        tipo = pTipo;
        maquinaOrigen = pMaquinaOrigen;
        cantidad = pCantidad;
        siguiente = NULL;
    }
};

#endif // ALMACENPRIMA_H
