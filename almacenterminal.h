#ifndef ALMACENTERMINAL_H
#define ALMACENTERMINAL_H

#include "prototipos.h"

struct AlmacenTerminal{
    MonticulosEmpaques* depositos;
    ListaGalletas* listaGalletas;

    AlmacenTerminal(MonticulosEmpaques* pDepositos, ListaGalletas* pListaGalletas){
        depositos = pDepositos;
        listaGalletas = pListaGalletas;
    }
};

#endif // ALMACENTERMINAL_H
