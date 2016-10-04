#include "hilohorno.h"

HiloHorno::HiloHorno(QObject* parent, Horno* pHorno)
{
    horno = pHorno;
    stop = false;
    pause = true;
}

void HiloHorno::run(){

    while(!stop){
        seguro = false;
        while(pause){
            seguro = true;
            msleep(100);
        }
        mute.lock();
        horno->alimentarHorno();
        msleep(1000);
        mute.unlock();
    }
}
