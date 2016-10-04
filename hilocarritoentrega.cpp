#include "hilocarritoentrega.h"

HiloCarritoEntrega::HiloCarritoEntrega(QObject* parent, CarritoEntrega* pCarrito)
{
    carritoEntrega = pCarrito;
    stop = false;
    pause = true;
}

void HiloCarritoEntrega::run(){
    while(!stop){
        while(pause){
            msleep(500);
        }
        mute.lock();
        carritoEntrega->cargarCarrito();
        if(carritoEntrega->entrega != NULL & !(carritoEntrega->estaEntregando)){
            msleep((carritoEntrega->tiempoViaje) * 1000);
            carritoEntrega->realizarEntrega();
        } else {
            msleep(100);
            if(carritoEntrega->entrega == NULL & carritoEntrega->estaEntregando){
                carritoEntrega->estaEntregando = false;
            }
        }
        mute.unlock();
    }

}
