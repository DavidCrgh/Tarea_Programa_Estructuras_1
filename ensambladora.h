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
    Banda* bandaMasa;
    Banda* bandaChocolate;
    Banda* bandaSalida;

    Ensambladora(Banda* pBanda, Banda* pBandaMasa, Banda* pBandaChocolate){
        producidoxTanda = 0.0;
        tiempo = 0.0;
        masaRequerida = 0.0;
        chocolateRequerido = 0.0;
        actualMasa = 0;
        actualChocolate = 0;
        bandaSalida = pBanda;
        bandaMasa = pBandaMasa;
        bandaChocolate = pBandaChocolate;
        estaEnsamblando = false;
    }

    void recibirMasa(){
        if(bandaMasa->frenteBanda != NULL & !estaEnsamblando){
            actualMasa += (bandaMasa->desencolarBanda())->cantidad;
        }
    }

    void recibirChocolate(){
        if(bandaChocolate->frenteBanda != & !estaEnsamblando){
            actualChocolate += (bandaChocolate->desencolarBanda())->cantidad;
        }
    }

    void alimentarEnsambladora(){
        recibirMasa();
        recibirChocolate();
    }

    void ensamblarGalletas(){
        actualMasa -= masaRequerida;
        actualChocolate -= chocolateRequerido;
        if(!(bandaSalida->estaLlena())){
            if(producidoxTanda + bandaSalida->contenidoActual() > bandaSalida->limite){
                bandaSalida->encolarBanda((bandaSalida->limite - bandaSalida->contenidoActual()),"Galleta Cruda");
            } else {
                bandaSalida->encolarBanda(producidoxTanda, "Galleta Cruda");
            }
            estaEnsamblando = false;
        }
    }
};

#endif // ENSAMBLADORA_H
