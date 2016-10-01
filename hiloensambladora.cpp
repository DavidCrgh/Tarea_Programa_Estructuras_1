#include "hiloensambladora.h"

HiloEnsambladora::HiloEnsambladora(QObject* parent, Ensambladora* pEnsambladora)
{
    ensambladora = pEnsambladora;
    stop = false;
    pause = true;
}

void HiloEnsambladora::run(){
    while(!stop){
        while(pause){
            msleep(1000);
        }
        ensambladora->alimentarEnsambladora();
        if(ensambladora->actualMasa >= ensambladora->masaRequerida && ensambladora->actualChocolate >= ensambladora->chocolateRequerido){
            msleep((ensambladora->tiempo) * 1000);
            ensambladora->ensamblarGalletas();
        } else {
            msleep(100);
        }
    }
}
