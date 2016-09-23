#ifndef MONTICULOSEMPAQUES_H
#define MONTICULOSEMPAQUES_H

#include "prototipos.h"

struct MonticulosEmpaques{
    NodoMonticulo* primerNodo;

    MonticulosEmpaques(){
        primerNodo = NULL;
    }
};

struct NodoMonticulo{
    std::string nombre;
    int cantidad;

    NodoMonticulo* siguiente;

    NodoMonticulo(std::string pNombre, int pCantidad){
        nombre = pNombre;
        cantidad = pCantidad;
        siguiente = NULL;
    }
};

#endif // MONTICULOSEMPAQUES_H
