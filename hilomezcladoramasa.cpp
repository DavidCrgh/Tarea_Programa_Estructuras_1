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
        mute.lock();
        //qDebug("Hilo masa: revisando carrito");
        mezcladoraMasa->revisarCarrito();

        //qDebug("Hilo masa: realizando peticion");
        mezcladoraMasa->realizarPeticion();
        if(mezcladoraMasa->masaActual >= mezcladoraMasa->masaMinima & mezcladoraMasa->masaActual>=mezcladoraMasa->cantidadxTanda){ //cambiar
            //qDebug("Hilo masa: procesandoMasa");
            msleep((mezcladoraMasa->tiempo) * 1000);
            mezcladoraMasa->procesarMasa();
        } else {
            msleep(1000);
        }
        /*if(mezcladoraMasa->banda->estaLlena()){
            pause=true;
            mezcladoraMasa->carrito->vaciarCarrito();
            mezcladoraMasa->almacen->desencolarPeticion();
            mezcladoraMasa->esperandoPeticion = false;
        }*/
        mute.unlock();
    }
}
