#ifndef MEZCLADORACHOCOLATE_H
#define MEZCLADORACHOCOLATE_H

#include "prototipos.h"
#include "almacenprima.h"
#include "carritoentrega.h"

struct MezcladoraChocolate{
    float tiempo;
    float cantidadProcesada;
    float mezclaMinima;
    float mezclaMaxima;
    float mezclaActual;
    bool esperandoPeticion;
    QString nombreMaquina;

    Banda* banda;
    AlmacenPrima* almacen;
    CarritoEntrega* carrito;

    MezcladoraChocolate(QString pNombre, Banda* pBanda, AlmacenPrima* pAlmacen){
        nombreMaquina = pNombre;
        tiempo = 0.0;
        cantidadProcesada = 0.0;
        mezclaMinima = 0.0;
        mezclaMaxima = 0.0;
        mezclaActual = 0.0;
        banda = pBanda;
        almacen = pAlmacen;
        esperandoPeticion = false;
    }

    void revisarCarrito(){
        if((carrito->entrega != NULL) & (carrito->maquinaActual == nombreMaquina)){
            mezclaActual += carrito->entrega->cantidad;
            carrito->vaciarCarrito();
            esperandoPeticion = false;
        }
    }

    void realizarPeticion(){
        if(!esperandoPeticion && mezclaActual <= mezclaMinima){
            float cantidadSolicitada = mezclaMaxima - mezclaActual;

            if(cantidadSolicitada > carrito->capacidadMaxima){
                cantidadSolicitada = carrito->capacidadMaxima;
            }

            almacen->encolarPeticion("Chocolate", nombreMaquina, cantidadSolicitada);
            esperandoPeticion = true;
        }

    }

    void procesarChocolate(){
        mezclaActual -= cantidadProcesada;
        if(!(banda->estaLlena())){
            if(cantidadProcesada + banda->contenidoActual() > banda->limite){
                banda->encolarBanda((banda->limite) - (banda->contenidoActual()), "Chocolate");
            } else {
                banda->encolarBanda(cantidadProcesada, "Chocolate");
            }
        }
    }


};

#endif // MEZCLADORACHOCOLATE_H
