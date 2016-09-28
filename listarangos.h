#ifndef LISTARANGOS_H
#define LISTARANGOS_H

#include "prototipos.h"

struct ListaRangos{

    NodoRango* primerRango;

    ListaRangos(){

        primerRango=NULL;
    }

    void insertarRango(float minimo,float maximo,QString nombre){

        if(primerRango == NULL){
            primerRango = new NodoRango(minimo,maximo,nombre);
        } else {
            NodoRango* nodoNuevo = new NodoRango(minimo,maximo,nombre);
            nodoNuevo->siguiente = primerRango;
            primerRango =  nodoNuevo;



    }

};

struct NodoRango{

    float minimo;
    float maximo;
    NodoRango*siguiente;
    QString tipoEmpaque;


    NodoRango(float pMinimo,float,pMaximo,QString pTipoEmpaque){
            minimo=pMinimo;
            maximo=pMaximo;
            tipoEmpaque=pTipoEmpaque;
            siguiente=NULL;



    }


};

#endif // LISTARANGOS_H
