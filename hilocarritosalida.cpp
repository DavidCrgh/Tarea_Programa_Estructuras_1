#include "hilocarritosalida.h"

HiloCarritoSalida::HiloCarritoSalida(QObject* parent, CarritoSalida* pCarrito)
{
    carritoSalida = pCarrito;
    stop = false;
    pause = true;
}

void HiloCarritoSalida::run(){
    while(!stop){
        while(pause){
            msleep(100);
        }
    }
}
