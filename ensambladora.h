#ifndef ENSAMBLADORA_H
#define ENSAMBLADORA_H

#include "prototipos.h"

struct Ensambladora{
    float cantidadxTiempo;
    //Receta
    float minimoMasa;
    float minimoChocolate;

    float actualMasa;
    float actualChocolate;

    Banda* bandaSalida;

    Ensambladora(float pCantidadxTiempo, float pMinimoMasa, float pMinimoChocolate, Banda* pBanda){
        cantidadxTiempo = pCantidadxTiempo;
        minimoMasa = pMinimoMasa;
        minimoChocolate = pMinimoChocolate;
        actualMasa = 0;
        actualChocolate = 0;
        bandaSalida = pBanda;
    }
};

#endif // ENSAMBLADORA_H
