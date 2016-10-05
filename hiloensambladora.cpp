#include "hiloensambladora.h"

HiloEnsambladora::HiloEnsambladora(QObject* parent, Ensambladora* pEnsambladora)
{
    ensambladora = pEnsambladora;
    stop = false;
    pause = true;
}

void HiloEnsambladora::run(){
    while(!stop){
        seguro = false;
        while(pause){
            seguro = true;
            msleep(100);
        }
        mute.lock();
        ensambladora->alimentarEnsambladora();
        if(ensambladora->actualMasa >= ensambladora->masaRequerida && ensambladora->actualChocolate >= ensambladora->chocolateRequerido){
            msleep((ensambladora->tiempo) * 1000);
            ensambladora->ensamblarGalletas();
        } else {
            msleep(100);
        }
        if(ensambladora->bandaSalida->estaLlena()){
            pause = true;
        }
        mute.unlock();
    }
}
