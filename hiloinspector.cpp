#include "hiloinspector.h"

hiloInspector::hiloInspector(QObject* parent,Inspector* pInspector)
{
    inspector= pInspector;
    stop=false;
    pause=true;
}

void hiloInspector::run(){
    while(!stop){
        seguro = false;
        while(pause){
            seguro = true;
            msleep(100);
        }
        mute.lock();
        inspector->inspeccionar();
        msleep(5000);
        mute.unlock();
    }
}
