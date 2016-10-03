#include "hiloalmacenterminal.h"

HiloAlmacenTerminal::HiloAlmacenTerminal(QObject* parent, AlmacenTerminal* pAlmacen)
{
    almacen = pAlmacen;
    stop = false;
    pause = true;
}

void HiloAlmacenTerminal::run(){
    while(!stop){
        while(pause){
            msleep(100);
        }
        almacen->actualizarTotales();
        almacen->actualizarEstaLleno();
    }
}
