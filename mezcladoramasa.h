#ifndef MEZCLADORAMASA_H
#define MEZCLADORAMASA_H

#include "prototipos.h"
#include "carritoentrega.h"
#include "almacenprima.h"
#include "banda.h"

struct MezcladoraMasa{
    float tiempo;
    float cantidadxTanda;
    float masaMinima;
    float masaMaxima;
    float masaActual;
    bool esperandoPeticion;
    float cantidadProcesada;
    QString nombreMaquina;

    Banda* banda;
    AlmacenPrima* almacen;
    CarritoEntrega* carrito;

    MezcladoraMasa(QString pNombre, Banda* pBanda, AlmacenPrima* pAlmacen,CarritoEntrega*pCarrito){
        nombreMaquina = pNombre;
        tiempo = 0.0;
        cantidadxTanda = 0.0;
        masaMinima = 0.0;
        masaMaxima = 0.0;
        masaActual = 0;
        cantidadProcesada = 0.0;
        banda = pBanda;
        almacen = pAlmacen;
        esperandoPeticion = false;
        carrito=pCarrito;
    }

    void apagarMezcladora(){
        esperandoPeticion = false;
        almacen->eliminarPeticiones(nombreMaquina);
        carrito->vaciarCarrito();
    }

    void revisarCarrito(){
        if((carrito->entrega != NULL) && (carrito->estaEntregando) &&(carrito->entrega->maquinaOrigen == nombreMaquina)){
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
        masaActual -= cantidadxTanda;
        if(!(banda->estaLlena())){
            if(cantidadxTanda + banda->contenidoActual() > banda->limite){
                banda->encolarBanda((banda->limite) - (banda->contenidoActual()), "Masa");
                cantidadProcesada += (banda->limite) - (banda->contenidoActual());
            } else {
                banda->encolarBanda(cantidadxTanda, "Masa");
                cantidadProcesada += cantidadxTanda;
            }
        }
    }

    QStringList imprimirMezcladora(){
        QStringList mensaje;

        mensaje.append(QString::number(masaActual));
        mensaje.append(QString::number(cantidadProcesada));

        return mensaje;
    }
};

#endif // MEZCLADORAMASA_H
