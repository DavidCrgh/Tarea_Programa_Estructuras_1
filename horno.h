#ifndef HORNO_H
#define HORNO_H

#include "prototipos.h"
#include "banda.h"
//#include "bandainspectores.h"

struct Bandeja{
    float capacidad;
    float contenidoActual;
    float tiempo;
    float cantidadProcesada;
    bool estaActiva;
    Banda* bandaSalida;

    Bandeja(Banda* pBanda){
        capacidad = 0.0;
        contenidoActual = 0.0;
        tiempo = 0.0;
        cantidadProcesada = 0.0;
        estaActiva = false;
        bandaSalida = pBanda;
    }

    /*
     * Reestablece los parametros por defecto de la estructura.
     */
    void resetearBandeja(){

        capacidad = 0.0;
        contenidoActual = 0.0;
        tiempo = 0.0;
        cantidadProcesada = 0.0;
        estaActiva = false;

    }

    /*
     * Suma la cantidad que tiene cargada la bandeja actualmente a la banda de salida.
     */
    void hornear(){
        float contenidoActualBanda= bandaSalida->contenidoActual();
        if(contenidoActual + contenidoActualBanda > bandaSalida->limite){
            bandaSalida->encolarBanda((bandaSalida->limite - contenidoActualBanda),"Galletas Cocinadas");
            cantidadProcesada += (bandaSalida->limite - contenidoActualBanda);
        } else {
            bandaSalida->encolarBanda(contenidoActual, "Galletas Cocinadas");
            cantidadProcesada += contenidoActual;
        }
        contenidoActual = 0;
    }
};

struct Horno{
    Banda* bandaEntrada;
    Bandeja* bandejas[6];
    int bandejasPrendidas;

    Horno(Bandeja* pBandejas[6], Banda* pBandaCrudas){
        for(int i = 0; i < 6; i++){
            bandejas[i] = pBandejas[i];
        }
        bandaEntrada = pBandaCrudas;
        bandejasPrendidas = 0.0;
    }

    /*
     * Reestablece los parametros por defecto de la estructura.
     */
    void resetearHorno(){

        bandejasPrendidas = 0.0;

    }

    /*
     * Salidas:
     * True si alguna de las seis bandejas ACTIVAS tienen campo disponible,
     * falso de lo contrario.
     *
     * Itera sobre el arreglo de bandejas para revisar si alguna se ellas
     * estan activas y tienen campo.
     */
    bool tieneCamposDisponibles(){
        Bandeja* bandejaActual;
        for(int i = 0; i < 6; i++){
            bandejaActual = bandejas[i];
            if(bandejaActual->estaActiva && bandejaActual->contenidoActual < bandejaActual->capacidad){
                return true;
            }
        }
        return false;
    }

    /*
     * Revisa si el horno tiene campos disponibles y desencola un nodo de la banda de
     * entrada. Despues itera sobre las bandejas para meter galletas hasta que la can-
     * tidad que se habia desencolado llega a 0.
     */
    void alimentarHorno(){
        if(tieneCamposDisponibles()){
            NodoContenido* tandaGalletas = bandaEntrada->desencolarBanda();
            if(tandaGalletas != NULL){
                float galletas = tandaGalletas->cantidad;
                Bandeja* bandejaActual;
                for(int i = 0; i < 6; i++){
                    bandejaActual =bandejas[i];

                    if(bandejaActual->estaActiva && bandejaActual->contenidoActual < bandejaActual->capacidad){
                        if(bandejaActual->contenidoActual + galletas > bandejaActual->capacidad){
                            float cantidad = bandejaActual->capacidad - bandejaActual->contenidoActual;
                            galletas -= cantidad;
                            bandejaActual->contenidoActual += cantidad;
                        } else {
                            bandejaActual->contenidoActual += galletas;
                            galletas = 0;
                        }
                    }
                }
            }
        }
    }

};
#endif // HORNO_H
