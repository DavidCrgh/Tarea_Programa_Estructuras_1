#ifndef LISTAGALLETAS_H
#define LISTAGALLETAS_H


#include "prototipos.h"

struct ListaGalletas{
    NodoEmpaque* nodoInsercion;

    ListaGalletas(){
        nodoInsercion = NULL;
    }
};

struct NodoEmpaque{
    std::string tipoEmpaque;
    int galletasxEmpaque;
    int cantidadxTiempo;

    NodoEmpaque* siguiente;
    NodoEmpaque* anterior;

    NodoEmpaque(std::string pTipo, int pGalletasxEmpaque, int pCantidadxTiempo){
        tipoEmpaque = pTipo;
        galletasxEmpaque = pGalletasxEmpaque;
        cantidadxTiempo = pCantidadxTiempo;
        siguiente = NULL;
        anterior = NULL;
    }
};

#endif // LISTAGALLETAS_H
