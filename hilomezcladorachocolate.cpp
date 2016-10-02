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
        mezcladoraChocolate->revisarCarrito();
        mezcladoraChocolate->realizarPeticion();
        if(mezcladoraChocolate->mezclaActual >= mezcladoraChocolate->mezclaMinima & mezcladoraChocolate->mezclaActual>=mezcladoraChocolate->cantidadxTanda){
            msleep((mezcladoraChocolate->tiempo)*1000);
            mezcladoraChocolate->procesarChocolate();
        } else {
            msleep(100);
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
