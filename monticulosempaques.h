#ifndef MONTICULOSEMPAQUES_H
#define MONTICULOSEMPAQUES_H

#include "prototipos.h"

struct NodoMonticulo{
    QString nombre;
    int cantidadPaquetes;
    int totalGalletas;
    bool estaLleno;

    NodoMonticulo* siguiente;

    NodoMonticulo(QString pNombre){
        nombre = pNombre;
        cantidadPaquetes = 0;
        totalGalletas = 0;
        estaLleno = false;
        siguiente = NULL;
    }
};

struct MonticulosEmpaques{
    NodoMonticulo* primerNodo;

    MonticulosEmpaques(){
        primerNodo = NULL;
    }

    /*
     * Entradas:
     * Tipo de paquete que esta asociado al monticulo
     *
     * Inserta un monticulo a la lista.
     */
    void insertarMonticulo(QString pTipo){
        if(primerNodo == NULL){
            primerNodo = new NodoMonticulo(pTipo);
        } else {
            NodoMonticulo* nodoNuevo = new NodoMonticulo(pTipo);
            nodoNuevo->siguiente = primerNodo;
            primerNodo =  nodoNuevo;
        }
    }


    /*
     * Entradas:
     * Tipo/Nombre del empaque cuyo monticulo se desea buscar.
     * Salidas:
     * Monticulo encontrado
     *
     * Itera sobre la lista y pregunta si el nombre encontrado es igual
     * al monticulo actual. Si se cumple la condicion se retorna el nodo
     * actual.
     */
    NodoMonticulo* buscarMonticulo(QString pNombre){
        if(primerNodo == NULL){
            return NULL;
        } else {
            NodoMonticulo* nodoActual = primerNodo;

            while(nodoActual != NULL){
                if(nodoActual->nombre == pNombre){
                    return nodoActual;
                }
                nodoActual = nodoActual->siguiente;
            }
            return NULL;
        }
    }

    /*
     * Salidas:
     * QString con la informacion de todos los monticulos.
     *
     * Itera sobre la lista de monticulos y agrega sus datos a un QString
     * que despues es retornado.
     */
    QString imprimirMonticulos(){
        if(primerNodo == NULL){
            return "";
        } else {
            QString mensaje = "";

            NodoMonticulo* nodoActual = primerNodo;

            while(nodoActual != NULL){
                mensaje += "Nombre: " + nodoActual->nombre + "\n";
                mensaje += "Cantidad Actual: " + QString::number(nodoActual->cantidadPaquetes) + "\n";
                mensaje += "Total de Galletas: " + QString::number(nodoActual->totalGalletas) + "\n";
                mensaje += "--------------------------------------------------------\n";
                nodoActual = nodoActual->siguiente;
            }

            return mensaje;
        }
    }
};
#endif // MONTICULOSEMPAQUES_H
