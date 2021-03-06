#include "hilocarritosalida.h"

HiloCarritoSalida::HiloCarritoSalida(QObject* parent, CarritoSalida* pCarrito)
{
    carritoSalida = pCarrito;
    stop = false;
    pause = true;
}

void HiloCarritoSalida::run(){
    while(!stop){
        seguro = false;
        while(pause){
            seguro = true;
            msleep(100);
        }
        mute.lock();
        carritoSalida->cargarCarrito();
        if(carritoSalida->cantidadTransportada == carritoSalida->capacidadMaxima){
            msleep((carritoSalida->tiempoViaje) * 1000);
            carritoSalida->realizarEntrega();
        } else {
            msleep(1000);
        }
        mute.unlock();
    }
}
