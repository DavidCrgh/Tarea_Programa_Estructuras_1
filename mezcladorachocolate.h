#ifndef MEZCLADORACHOCOLATE_H
#define MEZCLADORACHOCOLATE_H

#include "prototipos.h"

struct MezcladoraChocolate{
    float tiempo;
    float cantidadProcesada;
    float mezclaMinima;
    float mezclaMaxima;
    float mezclaActual;
    bool esperandoPeticion;

    Banda* banda;
    AlmacenPrima* almacen;
    CarritoEntrega* carrito;

    MezcladoraChocolate(float pTiempo, float pCantidad, float pMinima, float pMaxima, Banda* pBanda
                        , AlmacenPrima* pAlmacen){
        tiempo = pTiempo;
        cantidadProcesada = pCantidad;
        mezclaMinima = pMinima;
        mezclaMaxima = pMaxima;
        mezclaActual = 0;
        banda = pBanda;
        almacen = pAlmacen;
        esperandoPeticion = false;
    }

    void realizarPeticion(){
        float cantidadSolicitada = mezclaMaxima - mezclaActual;

        if(cantidadSolicitada > carrito->capacidadMaxima){
            cantidadSolicitada = carrito->capacidadMaxima;
        }

        almacen->encolarPeticion("Mezcla", "Mezcladora1",cantidadSolicitada);
        esperandoPeticion = true;
    }

    void procesarChocolate(){
        mezclaActual -= cantidadProcesada;
        if(!(banda->estaLlena())){
            if(cantidadProcesada + banda->contenidoActual() > banda->limite){
                banda->encolarBanda(banda->limite - banda->contenidoActual);
            } else {
                banda->encolarBanda(cantidadProcesada);
            }
        }
    }
};

#endif // MEZCLADORACHOCOLATE_H
