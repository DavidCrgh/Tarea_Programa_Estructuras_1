#ifndef CARRITOSALIDA_H
#define CARRITOSALIDA_H

#include "prototipos.h"
#include "monticulosempaques.h"
#include "almacenterminal.h"
#include "empacadora.h"

struct CarritoSalida{

    QString nombrePaquete;
    float tiempoViaje;
    int capacidadMaxima;
    int cantidadTransportada;

    bool estaEntregando;

    NodoMonticulo* monticuloEmpacadora;
    NodoMonticulo* monticuloAlmacen;

    Empacadora* empacadora;
    AlmacenTerminal* almacen;

    CarritoSalida(QString pNombre, float pTiempo, int pMaximo, Empacadora* pEmpacadora, AlmacenTerminal* pAlmacen){
        nombrePaquete = pNombre;
        tiempoViaje = pTiempo;
        capacidadMaxima = pMaximo;
        estaEntregando = false;
        empacadora = pEmpacadora;
        almacen = pAlmacen;
        monticuloEmpacadora = empacadora->monticulosEmpacadora->buscarMonticulo(nombrePaquete);
        monticuloAlmacen = almacen->depositos->buscarMonticulo(nombrePaquete);
    }

    void realizarEntrega(int cantidadActual){
        monticuloEmpacadora->cantidadPaquetes -= cantidadActual;
        monticuloAlmacen->cantidadPaquetes += cantidadActual;
    }
};

#endif // CARRITOSALIDA_H
