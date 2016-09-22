#ifndef LISTAGALLETAS_H
#define LISTAGALLETAS_H


#include "prototipos.h"

struct ListaGalletas{
    NodoEmpaque* nodoInsercion;
};

struct NodoEmpaque{
    std::string tipoEmpaque;
    int cantidadxEmpaque;
    int cantidadTiempo;
};

#endif // LISTAGALLETAS_H
