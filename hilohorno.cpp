#include "hilohorno.h"

HiloHorno::HiloHorno(QObject* parent, Horno* pHorno)
{
    horno = pHorno;
    stop = false;
    pause = true;
}

void HiloHorno::run(){

    while(!stop){
        while(pause){
            msleep(100);
        }
        mute.lock();
        horno->alimentarHorno();
        msleep(100);
        mute.unlock();
    }
}
