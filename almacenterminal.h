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

    void actualizarTotales(){
        NodoMonticulo* monticuloActual = depositos->primerNodo;

        while(monticuloActual != NULL){
            float multiplicador = (listaGalletas->buscarEmpaque(monticuloActual->nombre))->galletasxEmpaque;
            monticuloActual->totalGalletas = monticuloActual->cantidadPaquetes * multiplicador;
            monticuloActual = monticuloActual->siguiente;
        }
    }

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
