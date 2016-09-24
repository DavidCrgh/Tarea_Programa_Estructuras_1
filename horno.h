#ifndef HORNO_H
#define HORNO_H

#include "prototipos.h"

struct Horno{
    Bandeja* bandejas[6];

    Horno(Bandeja* pBandejas[6]){
        for(int i = 0; i < 6; i++){
            bandejas[i] = pBandejas[i];
        }
    }

    bool tieneCamposDisponibles(int bandejasPrendidas){
        Bandeja* bandejaActual;
        for(int i = 0; i < bandejasPrendidas; i++){
            bandejaActual = bandejas[i];
            if(bandejaActual->contenidoActual < bandejaActual->capacidad){
                return true;
            }
        }
    }

};

struct Bandeja{
    float capacidad;
    float contenidoActual;
    float tiempo;
    BandaInspectores* bandaSalida;

    Bandeja(float pCapacidad, float pTiempo, BandaInspectores* pBanda){
        capacidad = pCapacidad;
        tiempo = pTiempo;
        bandaSalida = pBanda;
    }

    void hornear(){
        if(!(bandaSalida->estaLlena())){
            if(contenidoActual + bandaSalida->contenidoActual() > bandaSalida->limite){
                bandaSalida->encolarBanda(bandaSalida->limite - bandaSalida->contenidoActual);
            } else {
                bandaSalida->encolarBanda(contenidoActual);
            }
            contenidoActual = 0;
        }
    }
};

#endif // HORNO_H
