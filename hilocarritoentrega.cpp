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
            msleep(100);
        }
        msleep(1000);

    }

}
