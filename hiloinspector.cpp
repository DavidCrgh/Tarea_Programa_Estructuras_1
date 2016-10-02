#include "hiloinspector.h"

hiloInspector::hiloInspector(QObject* parent,Inspector* pInspector)
{
    inspector= pInspector;
    stop=false;
    pause=true;
}

void hiloInspector::run(){
    while(!stop){
        while(pause){
            msleep(100);
        }

        mute.lock();
        inspector->inspeccionar();
        msleep(100);
        mute.unlock();
    }
}
