#ifndef ALMACENPRIMA_H
#define ALMACENPRIMA_H

#include "prototipos.h"

struct NodoPeticion{
    QString tipo;
    QString maquinaOrigen;
    float cantidad;

    NodoPeticion* siguiente;

    NodoPeticion(QString pTipo, QString pMaquinaOrigen, float pCantidad){
        tipo = pTipo;
        maquinaOrigen = pMaquinaOrigen;
        cantidad = pCantidad;
        siguiente = NULL;
    }
};

struct AlmacenPrima{
    NodoPeticion* frentePeticiones;
    NodoPeticion* inicioRealizadas;

    AlmacenPrima(){
        frentePeticiones = NULL;
        inicioRealizadas = NULL;
    }

    /*
     * Reestablece los parametros por defecto de la estructura.
     */
    void resetearAlmacen(){
        frentePeticiones = NULL;
        inicioRealizadas = NULL;

    }

    /*
     * Entradas:
     * Tipo de Peticion (Chocolate, masa, etc)
     * Maquina que realizo la peticion
     * Cantidad solicitada
     *
     * Agrega una nueva peticion a la cola del almacen.
     */
    void encolarPeticion(QString tipo, QString maquinaOrigen, float cantidad){
        NodoPeticion* nodoNuevo = new NodoPeticion(tipo, maquinaOrigen, cantidad);

        if(frentePeticiones == NULL){
            frentePeticiones = nodoNuevo;
        } else {
            NodoPeticion* nodoActual = frentePeticiones;

            while(nodoActual->siguiente != NULL){
                nodoActual = nodoActual->siguiente;
            }

            nodoActual->siguiente = nodoNuevo;
        }
    }

    NodoPeticion* peek(){
        return frentePeticiones;
    }

    /*
     * Entradas:
     * Nodo a ser insertado
     *
     * Inserta un nodo de tipo peticion a la lista de peitciones realizadas
     */
    void insertarRealizada(NodoPeticion* nodoInsertado){
        if(inicioRealizadas == NULL){
            inicioRealizadas = nodoInsertado;
        } else {
            NodoPeticion* nodoActual = inicioRealizadas;

            while(nodoActual->siguiente != NULL){
                nodoActual = nodoActual->siguiente;
            }

            nodoActual->siguiente = nodoInsertado;
        }
    }

    /*
     * Salidas:
     * Nodo que se desencolo
     *
     * Retira la peticion de la cola.
     */
    NodoPeticion* desencolarPeticion(){
        if(frentePeticiones == NULL){
            return NULL;
        } else {
            NodoPeticion* nodoBorrado = frentePeticiones;
            frentePeticiones = frentePeticiones->siguiente;
            nodoBorrado->siguiente = NULL;
            return nodoBorrado;
        }
    }

    /*
     * Entradas:
     * Nombre de la maquina cuyas peticiones van a ser eliminadas
     *
     * Utiliza en nombre ingresado para recorrer la cola de peticiones y
     * crear una nueva sin las peticiones de esa maquina. Al final le a-
     * signa el frente de esa cola al frente de las peticiones del almacen.
     */
    void eliminarPeticiones(QString pMaquina){
        NodoPeticion* nodoActual = frentePeticiones;
        AlmacenPrima* almacenTemporal = new AlmacenPrima();

        while(nodoActual != NULL){
            if(nodoActual->maquinaOrigen != pMaquina){
                almacenTemporal->encolarPeticion(nodoActual->tipo,
                                                 nodoActual->maquinaOrigen,
                                                 nodoActual->cantidad);
            }
            nodoActual = nodoActual->siguiente;
        }

        frentePeticiones = almacenTemporal->frentePeticiones;
    }


    /*
     * Entradas:
     * verdadero si se quiere imprimir las peticiones realizadas
     * falso si se quiere imprimir las peticione pendientes
     *
     * Salidas:
     * String con la informacion de todos los nodos de la lista/cole
     *
     * Itera sobre la lista seleccionada y agrega los datos de cada nodo
     * a un string que despues se retorna.
     */
    QString imprimirLista(bool esRealizada){
        NodoPeticion* nodoActual;
        if(esRealizada){
            nodoActual = inicioRealizadas;
        } else {
            nodoActual = frentePeticiones;
        }

        if(nodoActual == NULL){
            return "Vacio";
        } else {
            QString mensaje = "";

            while(nodoActual != NULL){
                mensaje += "Tipo: " + nodoActual->tipo + "\n";
                mensaje += "Hecha por: " + nodoActual->maquinaOrigen + "\n";
                mensaje += "Cantidad: " + QString::number(nodoActual->cantidad) + "\n";
                mensaje += "-------------------------------------------------------\n";
                nodoActual = nodoActual->siguiente;
            }

            return mensaje;
        }
    }

    /*
     * Salidas:
     * lista de qstring con la informacion de ambas listas del almacen
     *
     * Llama a imprimirLista() con ambos valores posibles y los agrega a una
     * lista de qstrings que despue es retornada.
     */
    QStringList imprimirAlmacen(){
        QStringList mensaje;
        mensaje.append(imprimirLista(false));
        mensaje.append(imprimirLista(true));
        return mensaje;
    }
};
#endif // ALMACENPRIMA_H
