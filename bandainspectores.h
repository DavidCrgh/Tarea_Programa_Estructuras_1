#ifndef BANDAINSPECTORES_H
#define BANDAINSPECTORES_H

#include "prototipos.h"

struct BandaInspectores{

    Inspector* inspector1;
    Inspector* inspector2;
    NodoContenido* frente;

    BandaInspectores(Inspector* pInspector1, Inpector* pInspector2){
        inspector1 = pInspector1;
        inspector2 = pInspector2;
        frente = NULL;
    }
};

struct Inspector{
    int desechadas;
    int aprobadas;
    Empacadora* empacadora;

    Inspector(Empacadora* pEmpcadora){
        empacadora = pEmpcadora;
    }
};

#endif // BANDAINSPECTORES_H
