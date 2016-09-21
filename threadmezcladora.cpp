#include "threadmezcladora.h"

ThreadMezcladora::ThreadMezcladora(QObject *parent, Mezcladora *pMezcladora)
{
    mezcladora=pMezcladora;
    bool pause=false;
    bool stop=true;
}

void ThreadMezcladora::run(){

    while(!stop){

        while(pause){
            msleep(100);
        }

    }
}
