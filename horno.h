#ifndef HORNO_H
#define HORNO_H

#include "prototipos.h"

struct Horno{
    float minimoHorneado;

    Bandeja* bandeja1;
    Bandeja* bandeja2;
    Bandeja* bandeja3;
    Bandeja* bandeja4;
    Bandeja* bandeja5;
    Bandeja* bandeja6;

};

struct Bandeja{
    float capacidad;
    float tiempo;
};

#endif // HORNO_H
