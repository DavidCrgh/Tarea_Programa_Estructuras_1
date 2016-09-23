#ifndef BANDA_H
#define BANDA_H

#include "prototipos.h"

struct Banda{
    float limite;

    NodoContenido* frente;

    Ensambladora* ensambladora;
    Horno* horno;

    Banda(float pLimite, Ensambladora* pEnsambladora){
        limite = pLimite;
        ensambladora = pEnsambladora;
        horno = NULL;
        frente = NULL;
    }

    Banda(float pLimite, Horno* pHorno){
        limite = pLimite;
        ensambladora = NULL;
        horno = pHorno;
        frente = NULL;
    }
};

struct NodoContenido{
    float cantidad;

    NodoContenido* siguiente;

    NodoContenido(float pCantidad){
        cantidad = pCantidad;
        siguiente = NULL;
    }
};

#endif // BANDA_H
