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

    Banda* banda;
};

#endif // ENSAMBLADORA_H
