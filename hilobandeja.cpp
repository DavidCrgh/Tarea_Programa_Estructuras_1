#include "hilobandeja.h"

HiloBandeja::HiloBandeja(QObject* parent, Bandeja* pBandeja)
{
    bandeja = pBandeja;
    stop = false;
    pause = true;
}

void HiloBandeja::run(){
    while(!stop){
        while(pause){
            msleep(100);
        }
        mute.lock();
        if(bandeja->contenidoActual==bandeja->capacidad){
            msleep((bandeja->tiempo)*1000);
            bandeja->hornear();
        }
        else{
            msleep(100);
        }
        mute.unlock();
    }
}
