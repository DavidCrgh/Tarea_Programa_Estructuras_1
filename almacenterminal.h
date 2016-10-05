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

    /*
     * Reestablece los parametros por defecto de la estructura.
     */
    void resetearAlmacen(){
        depositos = listaGalletas->generarMonticulos();
    }

    /*
     * Itera sobre los monticulos/depositos del almacen y actualiza sus totales
     * de galletas contenidas consultando a la listaGalletas para hacer el cal-
     * culo.
     */
    void actualizarTotales(){
        NodoMonticulo* monticuloActual = depositos->primerNodo;

        while(monticuloActual != NULL){
            float multiplicador = (listaGalletas->buscarEmpaque(monticuloActual->nombre))->galletasxEmpaque;
            monticuloActual->totalGalletas = monticuloActual->cantidadPaquetes * multiplicador;
            monticuloActual = monticuloActual->siguiente;
        }
    }

    /*
     * Itera sobre los monticulos/depositos del almacen y actualiza sus banderas
     * de estaLleno consultando a la listaGalletas para determinar el estado.
     */
    void actualizarEstaLleno(){
        NodoMonticulo* monticuloActual = depositos->primerNodo;

        while(monticuloActual != NULL){
            NodoEmpaque* nodoBuscado = listaGalletas->buscarEmpaque(monticuloActual->nombre);
            if(monticuloActual->cantidadPaquetes >= nodoBuscado->cantidadRequerida){
                monticuloActual->estaLleno = true;
            }
            monticuloActual = monticuloActual->siguiente;
        }
    }

    /*
     * Salidas:
     * True si todos los monticulos del almacen estan en la cantidad estipulada
     * por el planificador
     * False de lo contrario
     *
     * Itera sobre los monticulos/depositos y revisa sus banderas de estaLleno.
     */
    bool almacenLleno(){
        NodoMonticulo* monticuloActual = depositos->primerNodo;

        while(monticuloActual != NULL){
            if(!monticuloActual->estaLleno){
                return false;
            }
            monticuloActual = monticuloActual->siguiente;
        }
        return true;
    }

    /*
     * Salidas:
     * Total de la cantidad de galletas que contienen todos
     * los depositos
     *
     * Itera sobre los depositos para agergar sus valores totales
     * a la sumatoria que depues es retornada.
     */
    int determinarTotal(){
        int sumatoria = 0;
        NodoMonticulo* monticuloActual = depositos->primerNodo;

        while(monticuloActual != NULL){
            sumatoria += monticuloActual->totalGalletas;
            monticuloActual = monticuloActual->siguiente;
        }

        return sumatoria;
    }
};

#endif // ALMACENTERMINAL_H
