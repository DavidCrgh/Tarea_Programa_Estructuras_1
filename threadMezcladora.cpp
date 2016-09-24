#include "threadmezcladoramasa1.h"

ThreadMezcladora::ThreadMezcladora(QObject* parent, MezcladoraMasa* pMezcladora)
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
