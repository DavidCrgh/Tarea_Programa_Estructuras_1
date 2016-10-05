#include "hiloalmacenterminal.h"

HiloAlmacenTerminal::HiloAlmacenTerminal(QObject* parent, AlmacenTerminal* pAlmacen)
{
    almacen = pAlmacen;
    stop = false;
    pause = true;
}

void HiloAlmacenTerminal::run(){
    while(!stop){
        seguro = false;
        while(pause){
            seguro = true;
            msleep(100);
        }
        if(almacen->almacenLleno()){
            emit deternerSimulacion();
        }
        almacen->actualizarTotales();
        almacen->actualizarEstaLleno();
    }
}
