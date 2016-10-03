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
            msleep(1000);
        }
        msleep(5000);
    }
}
