#ifndef PLANIFICADOR_H
#define PLANIFICADOR_H

#include "prototipos.h"

struct Planificador{
    ListaGalletas* listaGalletas;
    Ensambladora* ensambladora;

    Planificador(ListaGalletas* pListaGalletas, Ensambladora* pEnsambladora){
        listaGalletas = pListaGalletas;
        ensambladora = pEnsambladora;
    }
};

#endif // PLANIFICADOR_H
