#ifndef BANDAINSPECTORES_H
#define BANDAINSPECTORES_H

#include "prototipos.h"
#include "banda.h"
#include "empacadora.h"

struct Inspector{
    float desechadas;
    float aprobadas;
    float probabilidadRechazo;
    Banda* bandaInspector;
    Empacadora* empacadora;

    Inspector(Empacadora* pEmpacadora, Banda* pBanda){
        empacadora = pEmpacadora;
        bandaInspector = pBanda;
        probabilidadRechazo = 0.0;
        desechadas = 0.0;
        aprobadas = 0.0;
    }

    /*
     * Reestablece los parametros por defecto de la estructura.
     */
    void resetearInspector(){

        probabilidadRechazo = 0.0;
        desechadas = 0.0;
        aprobadas = 0.0;

    }
    void inspeccionar(){
        if(!(empacadora->estaEmpacando) & (empacadora->estaActiva)){

            NodoContenido* tandaGalletas = bandaInspector->desencolarBanda();
            if(tandaGalletas != NULL){
                int cantidadGalletas = tandaGalletas->cantidad;
                if(seDesecha()){
                    int galletasDesechadas = rand()%(cantidadGalletas + 1);
                    empacadora->galletasActuales += (cantidadGalletas - galletasDesechadas);
                    aprobadas += (cantidadGalletas - galletasDesechadas);
                    desechadas += galletasDesechadas;
                } else {
                    empacadora->galletasActuales += cantidadGalletas;
                    aprobadas += cantidadGalletas;
                }
            }
        }
    }

    bool seDesecha(){
        int random = rand()% 101;
        return random <= probabilidadRechazo;
    }
};

#endif // BANDAINSPECTORES_H
