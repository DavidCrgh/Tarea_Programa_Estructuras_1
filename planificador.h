#ifndef PLANIFICADOR_H
#define PLANIFICADOR_H

#include "listagalletas.h"
#include "empacadora.h"
#include "almacenterminal.h"

struct Planificador{
    int probabilidades;
    int totalGalletas;
    ListaGalletas* listaGalletas;
    Empacadora* empacadora;

    Planificador(ListaGalletas* pLista, Empacadora* pEmpacadora){
        probabilidades = 0;
        totalGalletas = 0;
        listaGalletas = pLista;
        empacadora = pEmpacadora;
    }
};

#endif // PLANIFICADOR_H
