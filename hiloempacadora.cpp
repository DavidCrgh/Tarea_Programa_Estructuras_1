#include "hiloempacadora.h"

HiloEmpacadora::HiloEmpacadora(QObject* parent, Empacadora* pEmpacadora)
{
    empacadora=pEmpacadora;
    stop=false;
    pause=true;
}

void HiloEmpacadora::run(){
    while(!stop){
        seguro = false;
        while(pause){
            seguro = true;
            msleep(100);
        }
        NodoEmpaque* empaqueActual =  empacadora->elegirPaquete();

        if(empaqueActual != NULL){
            if(empacadora->galletasActuales >= (empaqueActual->galletasxEmpaque * empaqueActual->cantidadxTiempo)){
                msleep((empaqueActual->tiempoProduccion) * 1000);
                empacadora->empacarGalletas(empaqueActual);
            } else {
                msleep(100);
            }
        } else {
            msleep(100);
        }
    }
}
