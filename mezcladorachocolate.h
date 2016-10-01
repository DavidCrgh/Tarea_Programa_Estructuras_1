#ifndef MEZCLADORACHOCOLATE_H
#define MEZCLADORACHOCOLATE_H

#include "prototipos.h"
#include "carritoentrega.h"
#include "almacenprima.h"
#include "banda.h"

struct MezcladoraChocolate{
    float tiempo;
    float cantidadxTanda;
    float mezclaMinima;
    float mezclaMaxima;
    float mezclaActual;
    bool esperandoPeticion;
    float cantidadProcesada;
    QString nombreMaquina;

    Banda* banda;
    AlmacenPrima* almacen;
    CarritoEntrega* carrito;

    MezcladoraChocolate(QString pNombre, Banda* pBanda, AlmacenPrima* pAlmacen,CarritoEntrega* pCarrito){
        nombreMaquina = pNombre;
        tiempo = 0.0;
        cantidadxTanda = 0.0;
        mezclaMinima = 0.0;
        mezclaMaxima = 0.0;
        mezclaActual = 0.0;
        cantidadProcesada = 0.0;
        banda = pBanda;
        almacen = pAlmacen;
        esperandoPeticion = false;
        carrito=pCarrito;
    }

    void revisarCarrito(){
        if((carrito->entrega != NULL) && (carrito->estaEntregando) && (carrito->entrega->maquinaOrigen == nombreMaquina)){
            mezclaActual += carrito->entrega->cantidad;
            almacen->insertarRealizada(almacen->desencolarPeticion());
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
        mezclaActual -= cantidadxTanda;
        if(!(banda->estaLlena())){
            if(cantidadxTanda + banda->contenidoActual() > banda->limite){
                banda->encolarBanda((banda->limite) - (banda->contenidoActual()), "Chocolate");
                cantidadProcesada += (banda->limite) - (banda->contenidoActual());
            } else {
                banda->encolarBanda(cantidadxTanda, "Chocolate");
                cantidadProcesada += cantidadxTanda;
            }
        }
    }

    QStringList imprimirMezcladora(){
        QStringList mensaje;

        mensaje.append(QString::number(mezclaActual));
        mensaje.append(QString::number(cantidadProcesada));

        return mensaje;
    }
};

#endif // MEZCLADORACHOCOLATE_H
