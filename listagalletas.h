#ifndef LISTAGALLETAS_H
#define LISTAGALLETAS_H

#include "prototipos.h"

#include "monticulosempaques.h"
#include "listarangos.h"

struct NodoEmpaque{
    QString tipoEmpaque;
    int galletasxEmpaque;
    int cantidadxTiempo;
    float tiempoProduccion;
    float probabilidad;
    int cantidadRequerida;

    NodoEmpaque* siguiente;
    NodoEmpaque* anterior;

    NodoEmpaque(QString pTipo, int pGalletasxEmpaque, int pCantidadxTiempo, float pTiempo,
                float pProbabilidad, int pCantidadRequerida){
        tipoEmpaque = pTipo;
        galletasxEmpaque = pGalletasxEmpaque;
        cantidadxTiempo = pCantidadxTiempo;
        tiempoProduccion = pTiempo;
        probabilidad = pProbabilidad;
        cantidadRequerida = pCantidadRequerida;
        siguiente = NULL;
        anterior = NULL;
    }
};

struct ListaGalletas{
    NodoEmpaque* primerEmpaque;

    ListaGalletas(){
        primerEmpaque = NULL;
    }

    /*
     * Entradas:
     * Tipo: Tipo de empaque
     * Galletas por Empaque: Cantidad que irá en cada empaque
     * Cantidad Producidas por Tiempo: Cantidad de empaques generados por el tiempo especificado del usuario
     * Tiempo de Produccion: Cuanto durara en empacarse dicho tipo
     * Probabilidad: Probabildiad de que el empaque sea empacado
     * Cantidad Requerida: Cuantosse requieren para alcanzar el objetivo
     *
     *Inserta en la lista de galletas, un empaque de galleta con la informacion correspondiente
     */

    void insertarTipoGalleta(QString pTipo, int pGalletasxEmpaque, int pCantidadxTiempo,
                             float pTiempoProduccion, float pProbabilidad, int pCantidadRequerida){
        NodoEmpaque* empaqueGalleta = new NodoEmpaque(pTipo, pGalletasxEmpaque, pCantidadxTiempo,
                                                      pTiempoProduccion, pProbabilidad, pCantidadRequerida);
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

    /*
     * Reestablece los parametros por defecto de la estructura.
     */
    void resetearListaGalletas(){

         primerEmpaque = NULL;

    }

    /*
     * Entradas:
     * Arreglo de las probabilidades de todos los nodos empaque de la lista.
     *
     * Itera sobre la lista de galletas y agrega sus probabilidades de empaque
     * a un arreglo que despues es retornado.
     */
    void crearArregloProbabilidades(float probabilidades[]){
        NodoEmpaque* nodoActual = primerEmpaque;
        int largoGalletas= largoListaGalletas();
        int indice=0;
        while(indice<largoGalletas){
            probabilidades[indice]= nodoActual->probabilidad;
            nodoActual=nodoActual->siguiente;
            indice++;
        }
    }

    /*
     * Crea un arreglo con los nombres de cada paquete de galletas
     */
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


    /*
     *
     * Entradas:
     * Arreglo de probabilidades generado por crearArregloProbabilidades
     * Arreglo de tipos de empaque generado por crearArregloNombres
     * Largo de los arreglos, es correspondiente al largo de la lista de
     * galletas.
     *
     * Utiliza el algoritmo de insertion sort para ordenar el arreglo de probabilidades
     * de menor a mayor y paralelamente ordena el arreglo de tipos para que sus posiciones
     * correspondan.
     */
    void insertion_sort(float arregloProbabilidades[],QString arregloTipoEmpaques[], int largoArreglo) {
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
    }

    /*
     *Entradas:
     *Tipo: Nombre del empaque
     *Salidas: El empaque buscado
     *  Busca en la lista de galletas, el empaque con el nombre correspondiente y lo retorna
     */
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

    /*
     * Salidas:
     * Largo de la lista de galletas
     *
     * Itera sobre la lista de galletas y en cada iteracion suma 1
     * a un contador que es retornado al final.
     */
    int largoListaGalletas(){
        if(primerEmpaque == NULL){
            return 0;
        } else {
            int largo = 1;
            NodoEmpaque* nodoActual = primerEmpaque->siguiente;

            while(nodoActual != primerEmpaque){
                largo++;
                nodoActual = nodoActual->siguiente;
            }

            return largo;
        }
    }

    /*
     *Retorna la suma de los valores de probabilidades establecidos en cada uno de los paquetes de galletas
     */

    float contarProbabilidades(){
        if(primerEmpaque == NULL){
            return 0;
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

    /*
     * Salidas:
     * Total de cantidades de galletas requeridas por la simulacion
     *
     * Itera sobre la lista de galletas y suma el producto de la cantidad
     * requerida de empaques de cada nodo por las galletas de cada empaque.
     * Al final retorna la sumatoria.
     */
    int contarTotalRequerido(){
        if(primerEmpaque == NULL){
            return 0;
        } else {
            int sumatoria = (primerEmpaque->cantidadRequerida) * (primerEmpaque->galletasxEmpaque);
            NodoEmpaque* nodoActual = primerEmpaque->siguiente;

            while(nodoActual != primerEmpaque){
                sumatoria += (nodoActual->cantidadRequerida) * (nodoActual->galletasxEmpaque);
                nodoActual = nodoActual->siguiente;
            }

            return sumatoria;
        }
    }

    /*
     * Se utiliza la lista de galletas generada por el planificador para poder determinar la cantidad de monticulos que se generará en la empacadora y en el almacén terminal
     */

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

    /*
     * Salidas:
     * Lista simple con los rangos entre 0 y 99 de las probabilidades de
     * los empaques de la lista.
     *
     * Bota las probabilidades y los tipos en dos arreglos, los ordena con un insertion
     * sort, y despues itera sobre estos arreglos para crear los rangos de probabilidad
     * de cada emopaque.
     * El minimo del primer rango siempre es  y el maximo es el primer elemento del arreglo
     * menos 1, a partir de este, el minimo es igual al maximo del rango anterior y el
     * maximo es igual al elemento actual del arreglo mas el minimo menos 1.
     */
    ListaRangos* construirRangos(){
        if(primerEmpaque == NULL){
            return new ListaRangos();
        } else{
            ListaRangos* listaRangos= new ListaRangos();
            int largoLista = largoListaGalletas();
            float *probabilidades = new float[largoLista];
            QString *tipoEmpaques = new QString[largoLista];
            crearArregloProbabilidades(probabilidades);
            crearArregloNombres(tipoEmpaques);
            insertion_sort(probabilidades,tipoEmpaques,largoLista);
            float minimo = 0;
            float maximo = probabilidades[0];
            listaRangos->insertarRango(minimo, maximo-1, tipoEmpaques[0]);

            for(int i=1;i<largoLista;i++){
                minimo=maximo;
                maximo=probabilidades[i]+minimo;
                listaRangos->insertarRango(minimo,maximo-1,tipoEmpaques[i]);
            }
            return listaRangos;
        }
    }

    /*
     * Retorna un String con toda la informacion correspondiente a la lsita de galletas
     */

    QString imprimirLista(){
        if(primerEmpaque == NULL){
            return "";
        } else {
            QString mensaje = "";

            mensaje += "Nombre: " + primerEmpaque->tipoEmpaque + "\n";
            mensaje += "Galletas: " + QString::number(primerEmpaque->galletasxEmpaque) + "\n";
            mensaje += "Cantidad de Producción: " + QString::number(primerEmpaque->cantidadxTiempo) + "\n";
            mensaje += "Tiempo: " + QString::number(primerEmpaque->tiempoProduccion) + "\n";
            mensaje += "Probabilidad de empaque: " + QString::number(primerEmpaque->probabilidad) + "%\n";
            mensaje += "Cantidad Requerida: " + QString::number(primerEmpaque->cantidadRequerida) + "\n";
            mensaje += "--------------------------------------------------------------------------------------\n";

            NodoEmpaque* nodoActual = primerEmpaque->siguiente;

            while(nodoActual != primerEmpaque){
                mensaje += "Nombre: " + nodoActual->tipoEmpaque + "\n";
                mensaje += "Galletas: " + QString::number(nodoActual->galletasxEmpaque) + "\n";
                mensaje += "Cantidad de Producción: " + QString::number(nodoActual->cantidadxTiempo) + "\n";
                mensaje += "Tiempo: " + QString::number(nodoActual->tiempoProduccion) + "\n";
                mensaje += "Probabilidad de empaque: " + QString::number(nodoActual->probabilidad) + "%\n";
                mensaje += "Cantidad Requerida: " + QString::number(nodoActual->cantidadRequerida) + "\n";
                mensaje += "-----------------------------------------------------------------------------------\n";
                nodoActual = nodoActual->siguiente;
            }

            return mensaje;
        }
    }
};

#endif // LISTAGALLETAS_H
