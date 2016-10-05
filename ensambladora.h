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

    float cantidadProcesada;

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
        cantidadProcesada = 0;
        bandaSalida = pBanda;
        bandaMasa = pBandaMasa;
        bandaChocolate = pBandaChocolate;
    }

    /*
     * Reestablece los parametros por defecto de la estructura.
     */
    void resetearEnsambladora(){

        producidoxTanda = 0.0;
        tiempo = 0.0;
        masaRequerida = 0.0;
        chocolateRequerido = 0.0;
        actualMasa = 0;
        actualChocolate = 0;
        cantidadProcesada = 0;

    }

    /*
     * Desencola de la banda de la mezcla de masa e incrementa la cantidad de masa en la piscina
     */
    void recibirMasa(){
        if(bandaMasa->frenteBanda != NULL){
            actualMasa += (bandaMasa->desencolarBanda())->cantidad;
        }
    }

    /*
     * Desencola de la banda de la mezcla de masa e incrementa la cantidad de masa en la piscina
     */
    void recibirChocolate(){
        if(bandaChocolate->frenteBanda != NULL){
            actualChocolate += (bandaChocolate->desencolarBanda())->cantidad;
        }
    }

    /*
     * Pone a trabajar la ensambladora
     */

    void alimentarEnsambladora(){
        recibirMasa();
        recibirChocolate();
    }

    /*
     * Revisa en la receta de la ensambladora si las cantidades son las optimas para crear la tanda de galletas especificadas
     */
    void ensamblarGalletas(){
        actualMasa -= masaRequerida;
        actualChocolate -= chocolateRequerido;
        if(producidoxTanda + bandaSalida->contenidoActual() > bandaSalida->limite){
            bandaSalida->encolarBanda((bandaSalida->limite - bandaSalida->contenidoActual()),"Galleta Cruda");
            cantidadProcesada+=bandaSalida->limite - bandaSalida->contenidoActual();
        } else {
            bandaSalida->encolarBanda(producidoxTanda, "Galleta Cruda");
            cantidadProcesada+=producidoxTanda;
        }
    }
};

#endif // ENSAMBLADORA_H
