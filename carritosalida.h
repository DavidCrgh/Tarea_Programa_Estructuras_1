#ifndef CARRITOSALIDA_H
#define CARRITOSALIDA_H

#include "prototipos.h"
#include "monticulosempaques.h"
#include "almacenterminal.h"
#include "empacadora.h"

struct CarritoSalida{

    QString nombrePaquete;
    float tiempoViaje;
    int capacidadMaxima;
    int cantidadTransportada;

    bool estaEntregando;

    NodoMonticulo* monticuloEmpacadora;
    NodoMonticulo* monticuloAlmacen;

    CarritoSalida(QString pNombre, NodoMonticulo* pMonticuloEmpacadora, NodoMonticulo* pMonticuloAlmacen){
        nombrePaquete = pNombre;
        tiempoViaje = 0.0;
        capacidadMaxima = 0.0;
        cantidadTransportada = 0.0;
        estaEntregando = false;
        monticuloEmpacadora = pMonticuloEmpacadora;
        monticuloAlmacen = pMonticuloAlmacen;
    }

    /*
     * Reestablece los parametros por defecto de la estructura.
     */
    void resetearCarritoSalida(){

        tiempoViaje = 0.0;
        capacidadMaxima = 0.0;
        cantidadTransportada = 0.0;
        estaEntregando = false;

    }

    /*
     * Carga el carrito con el correspondiente paquete de galletas y reduce la cantidad generada en los monticulos de la empacadora
     */

    void cargarCarrito(){
        if(monticuloEmpacadora->cantidadPaquetes + cantidadTransportada > capacidadMaxima){
            cantidadTransportada += capacidadMaxima - cantidadTransportada;
            monticuloEmpacadora->cantidadPaquetes -= capacidadMaxima - cantidadTransportada;
        } else {
            cantidadTransportada += monticuloEmpacadora->cantidadPaquetes;
            monticuloEmpacadora->cantidadPaquetes = 0;
        }
    }

    /*
     * Permite al carrito descargar su capacidad en el correspondiente monticulo del almacen terminal
     */

    void realizarEntrega(){
        if(!monticuloEmpacadora->estaLleno){
            monticuloAlmacen->cantidadPaquetes += cantidadTransportada;
            cantidadTransportada = 0;
        }
    }
};

#endif // CARRITOSALIDA_H
