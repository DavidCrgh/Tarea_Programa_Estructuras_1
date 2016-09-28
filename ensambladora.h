#ifndef ENSAMBLADORA_H
#define ENSAMBLADORA_H

#include "prototipos.h"
#include "banda.h"

struct Ensambladora{
    float producidoxTanda;
    float tiempo;
    //Receta
    float masaRequerida;
    float chocolateRequerido;

    float actualMasa;
    float actualChocolate;

    bool estaEnsamblando;


    /*
     * nvlsActuales > req
     * estaEnsamblando = true
     * sleep(tiempo)
     * ensamblar();
     *
     * */
    Banda* bandaSalida;

    Ensambladora(float pCantidadProducida, float pTiempo, float pMinimoMasa, float pMinimoChocolate, Banda* pBanda){
        producidoxTanda = pCantidadProducida;
        tiempo = pTiempo;
        masaRequerida = pMinimoMasa;
        chocolateRequerido = pMinimoChocolate;
        actualMasa = 0;
        actualChocolate = 0;
        bandaSalida = pBanda;
        estaEnsamblando = false;
    }

    void ensamblarGalletas(){
        actualMasa -= masaRequerida;
        actualChocolate -= chocolateRequerido;
        if(!(bandaSalida->estaLlena())){
            if(producidoxTanda + bandaSalida->contenidoActual() > bandaSalida->limite){
                bandaSalida->encolarBanda(bandaSalida->limite - bandaSalida->contenidoActual);
            } else {
                bandaSalida->encolarBanda(producidoxTanda);
            }
            estaEnsamblando = false;
        }
    }
};

#endif // ENSAMBLADORA_H
