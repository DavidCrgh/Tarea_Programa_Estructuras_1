#ifndef CARRITOENTREGA_H
#define CARRITOENTREGA_H

#include "prototipos.h"
#include "almacenprima.h"

struct CarritoEntrega{
    float tiempoViaje;
    float capacidadMaxima;
    NodoPeticion* entrega;
    bool estaEntregando;

    AlmacenPrima* almacen;

    CarritoEntrega(AlmacenPrima* pAlmacen){
        tiempoViaje = 0.0;
        capacidadMaxima = 0.0;
        entrega = NULL;
        estaEntregando = false;
        almacen = pAlmacen;
    }

    void cargarCarrito(){
        if((entrega == NULL) & !estaEntregando){
            entrega = almacen->peek();
        }
    }

    void realizarEntrega(){
        estaEntregando = true;
    }

    void vaciarCarrito(){
        entrega = NULL;
        estaEntregando = false;
    }

    QStringList imprimirCarrito(){
        QStringList mensaje;

        if(entrega != NULL){
            mensaje.append(entrega->maquinaOrigen);
            mensaje.append(QString::number(entrega->cantidad));
        } else {
            mensaje.append("Vacio");
            mensaje.append("Vacio");

        }

        return mensaje;
    }
};

#endif // CARRITOENTREGA_H
