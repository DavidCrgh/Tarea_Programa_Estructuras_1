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
        mute.lock();
        //qDebug("Hilo chocolate: revisando carrito");
        //mute.lock();
        mezcladoraChocolate->revisarCarrito();
        //mute.unlock();
        //qDebug("Hilo chocolate: realizando peticion");
        mezcladoraChocolate->realizarPeticion();
        if(mezcladoraChocolate->mezclaActual >= mezcladoraChocolate->mezclaMinima & mezcladoraChocolate->mezclaActual>=mezcladoraChocolate->cantidadxTanda){
            //qDebug("Hilo masa: procesando chocolate");
            msleep((mezcladoraChocolate->tiempo)*1000);
            mezcladoraChocolate->procesarChocolate();
        } else {
            msleep(1000);
        }
        /*if(mezcladoraChocolate->banda->estaLlena()){
            pause=true;
            mezcladoraChocolate->carrito->vaciarCarrito();
            mezcladoraChocolate->almacen->desencolarPeticion();
            mezcladoraChocolate->esperandoPeticion = false;
        }*/
        mute.unlock();

    }
}
