#include "hilomezcladoramasa.h"

HiloMezcladoraMasa::HiloMezcladoraMasa(QObject* parent, MezcladoraMasa* pMezcladora)
{
    mezcladoraMasa = pMezcladora;
    stop = false;
    pause = true;
}

void HiloMezcladoraMasa::run(){
    while(!stop){
        while(pause){
            msleep(100);
        }
        qDebug("Hilo masa: revisando carrito");
        mezcladoraMasa->revisarCarrito();
        qDebug("Hilo masa: realizando peticion");
        mezcladoraMasa->realizarPeticion();
        if(mezcladoraMasa->masaActual >= mezcladoraMasa->cantidadxTanda){
            qDebug("Hilo masa: procesandoMasa");
            msleep((mezcladoraMasa->tiempo)*1000);
            mezcladoraMasa->procesarMasa();
        } else {
            msleep(100);
        }
    }
}
