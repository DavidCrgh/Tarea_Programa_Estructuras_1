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
        NodoEmpaque* empaqueActual =  empacadora->elegirPaquete();

        if(empacadora->galletasActuales >= (empaqueActual->galletasxEmpaque * empaqueActual->cantidadxTiempo)){
            msleep((empaqueActual->tiempoProduccion) * 1000);
            empacadora->empacarGalletas(empaqueActual);
        } else {
            msleep(100);
        }
    }
}
