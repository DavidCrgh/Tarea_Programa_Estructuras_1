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
            qDebug("hilo ensambladora: pausado");
        }
        msleep(1000);
        qDebug("hilo ensambladora: corriendo");
    }
}
