#ifndef BANDA_H
#define BANDA_H

#include "prototipos.h"

struct Banda{
    float limite;

    NodoContenido* frente;
    Ensambladora* ensambladora;
};

struct NodoContenido{
    float cantidad;

    NodoContenido* siguiente;
};

#endif // BANDA_H
