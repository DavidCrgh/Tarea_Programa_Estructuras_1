#include "hilomezcladorachocolate.h"

HiloMezcladoraChocolate::HiloMezcladoraChocolate(QObject* parent, MezcladoraChocolate* pMezcladora)
{
    mezcladoraChocolate = pMezcladora;
    stop = false;
    pause = true;
}

void HiloMezcladoraChocolate::run(){
    while(!stop){
        while(pause){
            msleep(500);
        }
        qDebug("Hilo chocolate: revisando carrito");
        mezcladoraChocolate->revisarCarrito();
        qDebug("Hilo chocolate: realizando peticion");
        mezcladoraChocolate->realizarPeticion();
        if(mezcladoraChocolate->mezclaActual >= mezcladoraChocolate->cantidadxTanda){
            qDebug("Hilo masa: procesando chocolate");
            msleep((mezcladoraChocolate->tiempo)*1000);
            mezcladoraChocolate->procesarChocolate();
        } else {
            msleep(100);
        }
    }
}
