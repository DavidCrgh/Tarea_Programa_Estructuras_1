#ifndef LISTARANGOS_H
#define LISTARANGOS_H

#include "prototipos.h"

struct NodoRango{

    float minimo;
    float maximo;
    NodoRango*siguiente;
    QString tipoEmpaque;


    NodoRango(float pMinimo,float pMaximo, QString pTipoEmpaque){
            minimo=pMinimo;
            maximo=pMaximo;
            tipoEmpaque=pTipoEmpaque;
            siguiente=NULL;
    }
};


struct ListaRangos{

    NodoRango* primerRango;

    ListaRangos(){

        primerRango = NULL;
    }

    void insertarRango(float minimo,float maximo,QString nombre){
        if(primerRango == NULL){
            primerRango = new NodoRango(minimo,maximo,nombre);
        } else {
            NodoRango* nodoNuevo = new NodoRango(minimo,maximo,nombre);
            nodoNuevo->siguiente = primerRango;
            primerRango =  nodoNuevo;
        }
    }

    QString imprimirRangos(){
        if(primerRango == NULL){
            return "Vacio";
        } else {
            QString mensaje = "";

            NodoRango* nodoActual = primerRango;

            while(nodoActual != NULL){
                mensaje += "Rango " + nodoActual->tipoEmpaque + ": (" + QString::number(nodoActual->minimo) + "," + QString::number(nodoActual->maximo) + ")\n";
                nodoActual = nodoActual->siguiente;
            }

            return mensaje;
        }
    }
};


#endif // LISTARANGOS_H
