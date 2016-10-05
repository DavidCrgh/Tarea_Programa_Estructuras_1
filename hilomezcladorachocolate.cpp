#include "hilomezcladorachocolate.h"

HiloMezcladoraChocolate::HiloMezcladoraChocolate(QObject* parent, MezcladoraChocolate* pMezcladora)
{
    mezcladoraChocolate = pMezcladora;
    stop = false;
    pause = true;
}

void HiloMezcladoraChocolate::run(){
    while(!stop){
        seguro = false;
        while(pause){
            seguro = true;
            msleep(100);
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
        if(mezcladoraChocolate->banda->estaLlena()){
            pause = true;
            mezcladoraChocolate->apagarMezcladora();
        }
        mute.unlock();

    }
}
