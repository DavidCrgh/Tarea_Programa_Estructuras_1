#ifndef BANDAINSPECTORES_H
#define BANDAINSPECTORES_H

#include "prototipos.h"

struct BandaInspectores{

    int cantidadActual;
    Inspector* inspector1;
    Inspector* inspector2;
    NodoContenido* frente;
};

struct Inspector{
    int desechadas;
    int aprobadas;
    Empacadora* empacadora;


};

#endif // BANDAINSPECTORES_H
