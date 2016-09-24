#ifndef CARRITOENTREGA_H
#define CARRITOENTREGA_H

#include "prototipos.h"

struct CarritoEntrega{
    float tiempoViaje;
    float capacidadMaxima;
    NodoPeticion* entrega;

    AlmacenPrima* almacen;
    MezcladoraMasa* mezcladoraMasa1;
    MezcladoraMasa* mezcladoraMasa2;
    MezcladoraChocolate* mezcladoraChocolate;

    CarritoEntrega(float tiempo, MezcladoraMasa* mezcladora1, MezcladoraMasa* mezcladora2,
                   MezcladoraChocolate* pMezcladoraChocolate, AlmacenPrima* pAlmacen){
        tiempoViaje = tiempo;
        mezcladoraMasa1 = mezcladora1;
        mezcladoraMasa2 = mezcladora2;
        mezcladoraChocolate = pMezcladoraChocolate;
        almacen = pAlmacen;
    }

    void entregarPeticion(){
        if(entrega != NULL){
            if(entrega->maquinaOrigen == "Mezcladora1"){
                mezcladoraMasa1->masaActual += entrega->cantidad;
                mezcladoraMasa1->esperandoPeticion = false;
            } else if(entrega->maquinaOrigen == "Mezcladora2"){
                mezcladoraMasa2->masaActual += entrega->cantidad;
                mezcladoraMasa2->esperandoPeticion = false;
            } else {
                mezcladoraChocolate->mezclaActual += entrega->cantidad;
                mezcladoraChocolate->esperandoPeticion = false;
            }
            entrega->cantidad = 0;
        }
    }

    void volveraAlmacen(){
        entrega = almacen->desencolarPeticion();
    }
};

#endif // CARRITOENTREGA_H
