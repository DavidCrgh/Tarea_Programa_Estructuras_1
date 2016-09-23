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

    Horno(float minimo, Bandeja* bandejas[6]){
        minimoHorneado = minimo;
        bandeja1 = bandejas[0];
        bandeja2 = bandejas[1];
        bandeja3 = bandejas[2];
        bandeja4 = bandejas[3];
        bandeja5 = bandejas[4];
        bandeja6 = bandejas[5];
    }

};

struct Bandeja{
    float capacidad;
    float tiempo;
    BandaInspectores* bandaSalida;

    Bandeja(float pCapacidad, float pTiempo, BandaInspectores* pBanda){
        capacidad = pCapacidad;
        tiempo = pTiempo;
        bandaSalida = pBanda;
    }
};

#endif // HORNO_H
