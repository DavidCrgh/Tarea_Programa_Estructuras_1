#ifndef BANDAINSPECTORES_H
#define BANDAINSPECTORES_H

#include "prototipos.h"
#include "banda.h"
#include "empacadora.h"
/*
struct BandaInspectores{
    float limite;

    //Inspector inspector1;
    //Inspector inspector2;

    NodoContenido* frenteInspectores;

    BandaInspectores(/*float pLimite, Inspector* pInspector1, Inspector* pInspector2){
        limite = 0.0;
        //inspector1 = pInspector1;
        //inspector2 = pInspector2;
        frenteInspectores = NULL;
    }

    void encolarBanda(float cantidad){
        NodoContenido* nodoNuevo = new NodoContenido(cantidad, "Galletas Cocinadas");

        if(frenteInspectores == NULL){
            frenteInspectores = nodoNuevo;
        } else {
            NodoContenido* nodoActual = frenteInspectores;

            while(nodoActual->siguiente != NULL){
                nodoActual = nodoActual->siguiente;
            }

            nodoActual->siguiente = nodoNuevo;
        }
    }

    NodoContenido* desencolarBanda(){
        if(frenteInspectores == NULL){
            return NULL;
        } else {
            NodoContenido* nodoBorrado = frenteInspectores;
            frenteInspectores = frenteInspectores->siguiente;
            nodoBorrado->siguiente = NULL;
            return nodoBorrado;
        }
    }

    bool estaLlena(){
        return contenidoActual() >= limite;
    }

    float contenidoActual(){
        NodoContenido* nodoActual = frenteInspectores;
        float sumatoria = 0.0;

        while(nodoActual != NULL){
            sumatoria += nodoActual->cantidad;
            nodoActual= nodoActual->siguiente;
        }

        return sumatoria;
    }
};*/

struct Inspector{
    float desechadas;
    float aprobadas;
    float probabilidadRechazo;
    Banda* bandaInspector;
    Empacadora* empacadora;

    Inspector(Empacadora* pEmpacadora, Banda* pBanda){
        empacadora = pEmpacadora;
        bandaInspector = pBanda;
        probabilidadRechazo = 0.0;
        desechadas = 0.0;
        aprobadas = 0.0;
    }

    void inspeccionar(){
        if(!(empacadora->estaEmpacando)){

            NodoContenido* tandaGalletas = bandaInspector->desencolarBanda();
            if(tandaGalletas != NULL){
                int cantidadGalletas = tandaGalletas->cantidad;
                std::cout << "cantidad de galletas: " << cantidadGalletas << std::endl;
                if(seDesecha()){
                    int galletasDesechadas = rand()%(cantidadGalletas + 1);
                    std::cout << "Galletas desechadas: " << galletasDesechadas << std::endl;
                    empacadora->galletasActuales += (cantidadGalletas - galletasDesechadas);
                    aprobadas += (cantidadGalletas - galletasDesechadas);
                    desechadas += galletasDesechadas;
                    std::cout << "Valor actual de aprobadas: " << aprobadas << std::endl;
                    std::cout << "Valor actual de desechadas: " << desechadas << std::endl;
                } else {
                    empacadora->galletasActuales += cantidadGalletas;
                    aprobadas += cantidadGalletas;
                    std::cout << "Valor actual de aprobadas: " << aprobadas << std::endl;
                    std::cout << "Valor actual de desechadas: " << desechadas << std::endl;
                }
            }

        }
    }


    bool seDesecha(){
        int random = rand()% 101;
        std::cout << "Valor random: " << random << std::endl;
        return random <= probabilidadRechazo;
    }
};

#endif // BANDAINSPECTORES_H
