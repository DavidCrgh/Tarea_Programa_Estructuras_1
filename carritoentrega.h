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

    CarritoEntrega(AlmacenPrima* pAlmacen){
        tiempoViaje = 0.0;
        capacidadMaxima = 0.0;
        entrega = NULL;
        estaEntregando = false;
        almacen = pAlmacen;
    }

    /*
     * Reestablece los parametros por defecto de la estructura.
     */
    void resetearCarritoEntrega(){

        tiempoViaje = 0.0;
        capacidadMaxima = 0.0;
        entrega = NULL;
        estaEntregando = false;

    }

    /*
     * Toma la direccion de memoria del primer nodo peticion del almacen
     * y se lo setea a la variable entrega.
     */
    void cargarCarrito(){
        if((entrega == NULL) & !estaEntregando){
            entrega = almacen->peek();
        }
    }

    /*
     * Pone la bandera de estaEntregando en true. Esto hace que la mezcladora correspondiente,
     * sepa que ya puede llamar a vaciarCarrito().
     */
    void realizarEntrega(){
        estaEntregando = true;
    }

    /*
     * Pone la entrega en NULL y pone la bandera estaEntregando en false. Esto hace que el carrito
     * este listo para cargar una nueva peticion.
     */
    void vaciarCarrito(){
        entrega = NULL;
        estaEntregando = false;
    }

    /*
     * Salidas:
     * Lista de QStrings con la informacion actual del carrito.
     *
     * Utilizada para actualizar la interfaz con la informacion del carrito.
     */
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
};

#endif // CARRITOENTREGA_H
