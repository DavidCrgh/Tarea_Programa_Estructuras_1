#ifndef MONTICULOSEMPAQUES_H
#define MONTICULOSEMPAQUES_H

#include "prototipos.h"

struct MonticulosEmpaques{
    NodoMonticulo* primerNodo;
};

struct NodoMonticulo{
    std::string nombre;
    int cantidad;
};

#endif // MONTICULOSEMPAQUES_H
