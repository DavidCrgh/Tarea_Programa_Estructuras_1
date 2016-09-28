#ifndef MEZCLADORAMASA_H
#define MEZCLADORAMASA_H

#include "prototipos.h"
#include "carritoentrega.h"
#include "almacenprima.h"
#include "banda.h"

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

    MezcladoraMasa(QString pNombre, Banda* pBanda, AlmacenPrima* pAlmacen){
        nombreMaquina = pNombre;
        tiempo = 0.0;
        cantidad = 0.0;
        masaMinima = 0.0;
        masaMaxima = 0.0;
        masaActual = 0;
        banda = pBanda;
        almacen = pAlmacen;
        esperandoPeticion = false;
    }

    void revisarCarrito(){
        if((carrito->entrega != NULL) & (carrito->maquinaActual == nombreMaquina)){
            masaActual += carrito->entrega->cantidad;
            almacen->insertarRealizada(almacen->desencolarPeticion());
            carrito->vaciarCarrito();
            esperandoPeticion = false;
        }
    }

    void realizarPeticion(){
        if(!esperandoPeticion && masaActual <= masaMinima){
            float cantidadSolicitada = masaMaxima - masaActual;

            if(cantidadSolicitada > carrito->capacidadMaxima){
                cantidadSolicitada = carrito->capacidadMaxima;
            }

            almacen->encolarPeticion("Masa", nombreMaquina, cantidadSolicitada);
            esperandoPeticion = true;
        }
    }

    void procesarMasa(){
        masaActual -= cantidad;
        if(!(banda->estaLlena())){
            if(cantidad + banda->contenidoActual() > banda->limite){
                banda->encolarBanda((banda->limite) - (banda->contenidoActual()), "Masa");
            } else {
                banda->encolarBanda(cantidad, "Masa");
            }
        }
    }
};

#endif // MEZCLADORAMASA_H
