#ifndef CARRITOSALIDA_H
#define CARRITOSALIDA_H

#include "prototipos.h"

struct CarritoSalida{

    std::string nombrePaquete;
    float tiempoViaje;
    int maximo;
    int cantidadTransportado;

    Empacadora* empacadora;
    AlmacenTerminal* almacen;

    CarritoSalida(std::string pNombre, float pTiempo, int pMaximo, Empacadora* pEmpacadora, AlmacenTerminal* pAlmacen){
        nombrePaquete = pNombre;
        tiempoViaje = pTiempo;
        maximo = pMaximo;
        empacadora = pEmpacadora;
        almacen = pAlmacen;
    }
};

#endif // CARRITOSALIDA_H
