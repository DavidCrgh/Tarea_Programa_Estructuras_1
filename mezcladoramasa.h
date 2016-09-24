#ifndef MEZCLADORAMASA_H
#define MEZCLADORAMASA_H

#include "prototipos.h"

struct MezcladoraMasa{
    float tiempo;
    float cantidad;
    float masaMinima;
    float masaMaxima;
    float masaActual;
    bool esperandoPeticion;
    QString nombreMaquina;

    Banda* banda;
    AlmacenPrima* almacen;
    CarritoEntrega* carrito;

    MezcladoraMasa(float pTiempo, float pCantidad, float pMinima, float pMaxima, Banda* pBanda,
                   AlmacenPrima* pAlmacen){
        tiempo = pTiempo;
        cantidad = pCantidad;
        masaMinima = pMinima;
        masaMaxima = pMaxima;
        masaActual = 0;
        banda = pBanda;
        almacen = pAlmacen;
        esperandoPeticion = false;
    }

    void realizarPeticion(){
        float cantidadSolicitada = masaMaxima - masaActual;

        if(cantidadSolicitada > carrito->capacidadMaxima){
            cantidadSolicitada = carrito->capacidadMaxima;
        }

        almacen->encolarPeticion("Mezcla", "Mezcladora1",cantidadSolicitada);
        esperandoPeticion = true;
    }

    void procesarMasa(){
        masaActual -= cantidad;
        if(!(banda->estaLlena())){
            if(cantidad + banda->contenidoActual() > banda->limite){
                banda->encolarBanda(banda->limite - banda->contenidoActual);
            } else {
                banda->encolarBanda(cantidad);
            }
        }
    }
};

#endif // MEZCLADORAMASA_H
