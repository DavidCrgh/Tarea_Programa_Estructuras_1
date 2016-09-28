#ifndef LISTAGALLETAS_H
#define LISTAGALLETAS_H

#include "prototipos.h"

struct ListaGalletas{
    NodoEmpaque* primerEmpaque;

    ListaGalletas(){
        primerEmpaque = NULL;
    }

    void insertarTipoGalleta(QString pTipo, int pGalletasxEmpaque, int pCantidadxTiempo,
                             float pTiempoProduccion, float pProbabilidad){
        NodoEmpaque* empaqueGalleta = new NodoEmpaque(pTipo, pGalletasxEmpaque, pCantidadxTiempo, pTiempoProduccion,
                                                      pProbabilidad);
        if(primerEmpaque == NULL){
            primerEmpaque = empaqueGalleta;
            empaqueGalleta->siguiente = primerEmpaque;
            empaqueGalleta->anterior = primerEmpaque;
        } else {
            empaqueGalleta->siguiente = primerEmpaque;
            empaqueGalleta->anterior = primerEmpaque->anterior;
            primerEmpaque->anterior->siguiente = empaqueGalleta;
            primerEmpaque->anterior = empaqueGalleta;
            primerEmpaque = empaqueGalleta;
        }
    }

    void crearArregloProbabilidades(int probabilidades[]){

        NodoEmpaque* nodoActual= primerEmpaque;
        int largoGalletas= largoListaGalletas();
        int indice=0;

            while(indice<largoGalletas){
                probabilidades[indice]= nodoActual->probabilidad;
                nodoActual=nodoActual->siguiente;
                indice++;
            }

        }


    void crearArregloNombres(QString tipoEmpaques[]){
         NodoEmpaque* nodoActual=primerEmpaque;
         int largoGalletas= largoListaGalletas();
         int indice=0;

         while(indice<largoGalletas){
             tipoEmpaques[indice]= nodoActual->tipoEmpaque;
             nodoActual=nodoActual->siguiente;
             indice++;

         }
    }


    void insertion_sort(int arregloProbabilidades[],QString arregloTipoEmpaques[], int largoArreglo) {
     int i, j ,temporal1;
     QString temporal2;
     for (i = 1; i < largoArreglo; i++) {
         j = i;
         while (j > 0 && arregloProbabilidades[j - 1] > arregloProbabilidades[j]) {
             temporal1 = arregloProbabilidades[j];
             temporal2 = arregloTipoEmpaques[j];
             arregloProbabilidades[j] = arregloProbabilidades[j - 1];
             arregloTipoEmpaques[j] = arregloTipoEmpaques[j - 1];
             arregloProbabilidades[j - 1] = temporal1;
             arregloTipoEmpaques[j - 1] = temporal2;
             j--;
         }
     }
     )
    }


    NodoEmpaque* buscarEmpaque(QString pTipo){
        if(primerEmpaque == NULL){
            return NULL;
        } else if(primerEmpaque->tipoEmpaque == pTipo){
            return primerEmpaque;
        } else{
            NodoEmpaque* nodoActual = primerEmpaque->siguiente;

            while(nodoActual != primerEmpaque){
                if(nodoActual->tipoEmpaque == pTipo){
                    return nodoActual;
                }
                nodoActual = nodoActual->siguiente;
            }

            return NULL;
        }
    }

    int largoListaGalletas(){
        NodoEmpaque* nodoActual= primerEmpaque;
        int largo=0;
        while(nodoActual!=primerEmpaque){

            largo++;
            nodoActual= nodoActual->siguiente;

        }
        return largo;

    }

    float contarProbabilidades(){
        if(primerEmpaque == NULL){
            return 0.0;
        } else {
            float sumatoria = primerEmpaque->probabilidad;
            NodoEmpaque* nodoActual = primerEmpaque->siguiente;

            while(nodoActual != primerEmpaque){
                sumatoria += nodoActual->probabilidad;
                nodoActual = nodoActual->siguiente;
            }

            return sumatoria;
        }
    }

    MonticulosEmpaques* generarMonticulos(){
        if(primerEmpaque == NULL){
            return new MonticulosEmpaques();
        } else{
            MonticulosEmpaques* monticulosCreados = new MonticulosEmpaques();
            monticulosCreados->insertarMonticulo(primerEmpaque->tipoEmpaque);
            NodoEmpaque* nodoActual = primerEmpaque->siguiente;

            while(nodoActual != primerEmpaque){
                monticulosCreados->insertarMonticulo(nodoActual->tipoEmpaque);
                nodoActual = nodoActual->siguiente;
            }

            return monticulosCreados;
        }
    }

    ListaRangos* construirRangos(){
       ListaRangos* listaRangos= new ListaRangos();
       int probabilidades[largoListaGalletas()];
       QString tipoEmpaques[largoListaGalletas()];
       crearArregloProbabilidades(probabilidades);
       crearArregloNombres(tipoEmpaques);
       insertion_sort(probabilidades,tipoEmpaques,largoListaGalletas());
       float minimo=0;
       float maximo= probabilidades[0];
       listaRangos->insertarRango(minimo,maximo-1,tipoEmpaques[0]);

       for(int i=1;i<largoListaGalletas();i++){
           minimo=maximo;
           maximo=probabilidades[i]+minimo;
           listaRangos->insertarRango(minimo,maximo-1,tipoEmpaques[i]);
            }
        return listaRangos;
       }




};

struct NodoEmpaque{
    QString tipoEmpaque;
    int galletasxEmpaque;
    int cantidadxTiempo;
    float tiempoProduccion;
    float probabilidad;

    NodoEmpaque* siguiente;
    NodoEmpaque* anterior;

    NodoEmpaque(QString pTipo, int pGalletasxEmpaque, int pCantidadxTiempo, float pTiempo, float pProbabilidad){
        tipoEmpaque = pTipo;
        galletasxEmpaque = pGalletasxEmpaque;
        cantidadxTiempo = pCantidadxTiempo;
        tiempoProduccion = pTiempo;
        probabilidad = pProbabilidad;
        siguiente = NULL;
        anterior = NULL;
    }
};

#endif // LISTAGALLETAS_H
