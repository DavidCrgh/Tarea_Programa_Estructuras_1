#include "hiloempacadora.h"

HiloEmpacadora::HiloEmpacadora(QObject* parent, Empacadora* pEmpacadora)
{
    empacadora=pEmpacadora;
    stop=false;
    pause=true;
}

void HiloEmpacadora::run(){
    while(!stop){
        while(pause){
            msleep(100);
        }
        msleep(100);
    }
}
