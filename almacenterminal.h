#ifndef ALMACENTERMINAL_H
#define ALMACENTERMINAL_H

#include "prototipos.h"
#include "listagalletas.h"

struct AlmacenTerminal{
    MonticulosEmpaques* depositos;
    ListaGalletas* listaGalletas;

    AlmacenTerminal(ListaGalletas* pListaGalletas){
        listaGalletas = pListaGalletas;
        depositos = listaGalletas->generarMonticulos();
    }
};

#endif // ALMACENTERMINAL_H
