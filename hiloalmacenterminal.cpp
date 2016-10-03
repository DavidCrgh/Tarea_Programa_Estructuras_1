#include "hiloalmacenterminal.h"

HiloAlmacenTerminal::HiloAlmacenTerminal(QObject* parent, AlmacenTerminal* pAlmacen)
{
    almacen = pAlmacen;
}

void HiloAlmacenTerminal::run(){
    while(!stop){
        while(pause){
            msleep(100);
        }
    }
}
