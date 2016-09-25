#ifndef CARRITOSALIDA_H
#define CARRITOSALIDA_H

#include "prototipos.h"

struct CarritoSalida{

    std::string nombrePaquete;
    float tiempoViaje;
    int capacidadMaxima;
    int cantidadTransportado;

    Empacadora* empacadora;
    AlmacenTerminal* almacen;

    CarritoSalida(std::string pNombre, float pTiempo, int pMaximo, Empacadora* pEmpacadora, AlmacenTerminal* pAlmacen){
        nombrePaquete = pNombre;
        tiempoViaje = pTiempo;
        capacidadMaxima = pMaximo;
        empacadora = pEmpacadora;
        almacen = pAlmacen;
    }
};

#endif // CARRITOSALIDA_H
