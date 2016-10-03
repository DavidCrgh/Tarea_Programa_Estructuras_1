#ifndef CARRITOENTREGA_H
#define CARRITOENTREGA_H

#include "prototipos.h"
#include "almacenprima.h"

struct CarritoEntrega{
    float tiempoViaje;
    float capacidadMaxima;
    NodoPeticion* entrega;
    bool estaEntregando;

    AlmacenPrima* almacen;
    /*MezcladoraMasa* mezcladoraMasa1;
    MezcladoraMasa* mezcladoraMasa2;
    MezcladoraChocolate* mezcladoraChocolate;*/

    CarritoEntrega(/*MezcladoraMasa* mezcladora1, MezcladoraMasa* mezcladora2, MezcladoraChocolate* pMezcladoraChocolate,*/
                   AlmacenPrima* pAlmacen){
        tiempoViaje = 0.0;
        capacidadMaxima = 0.0;
        entrega = NULL;
        estaEntregando = false;
        /*mezcladoraMasa1 = mezcladora1;
        mezcladoraMasa2 = mezcladora2;
        mezcladoraChocolate = pMezcladoraChocolate;*/
        almacen = pAlmacen;
    }

    void cargarCarrito(){
        if((entrega == NULL) & !estaEntregando){
            entrega = almacen->peek();
            //qDebug("carrito cargado con nueva entrega");
        }
        //std::cout << "entrega: " << entrega << endl;
        //qDebug("entrega == null o esta entregando");
    }

    /*
     * cargar()
     * if(entrega != NULL & !estaEntregando)
     * realizarEntrega()
     * sleep(tiempo)
     * else
     * sleep(100
     * */
    void realizarEntrega(){
        estaEntregando = true;
        //qDebug("realizarEntrega()");
    }

    void vaciarCarrito(){
        entrega = NULL;
        estaEntregando = false;
        //qDebug("carrito vaciado");
    }

    QStringList imprimirCarrito(){
        QStringList mensaje;

        if(entrega != NULL){
            mensaje.append(entrega->maquinaOrigen);
            mensaje.append(QString::number(entrega->cantidad));
        } else {
            mensaje.append("Vacio");
            mensaje.append("Vacio");

        }

        return mensaje;
    }

    /*void entregarPeticion(){
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
    }*/

    /*void volveraAlmacen(){
        entrega = almacen->desencolarPeticion();
    }*/
};

#endif // CARRITOENTREGA_H
