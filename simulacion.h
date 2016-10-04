#ifndef SIMULACION_H
#define SIMULACION_H

#include "almacenprima.h"

#include "hilocarritoentrega.h"
#include "hilomezcladoramasa.h"
#include "hilomezcladorachocolate.h"
#include "hiloensambladora.h"
#include "hilohorno.h"
#include "hilobandeja.h"
#include "hiloinspector.h"
#include "hiloempacadora.h"
#include "hilocarritosalida.h"
#include "hiloalmacenterminal.h"

#include "listagalletas.h"

struct Simulacion{

    AlmacenPrima* almacenPrima;
    CarritoEntrega* carritoEntrega;
    MezcladoraMasa* mezcladorasMasa[2];
    MezcladoraChocolate* mezcladoraChocolate;
    Banda* bandaMasa;
    Banda* bandaChocolate;
    Banda* bandaGalletasCrudas;
    Ensambladora* ensambladora;
    Horno* horno;
    Bandeja* bandejas[6];
    Banda* bandaInspectores;
    Inspector* inspector1;
    Inspector* inspector2;
    Empacadora* empacadora;
    ListaGalletas* listaGalletas;
    Planificador* planificador;
    CarritoSalida** carritosSalida;
    AlmacenTerminal* almacenTerminal;

    HiloCarritoEntrega* hiloCarritoEntrega;
    HiloMezcladoraMasa* hilosMezcladorasMasa[2];
    HiloMezcladoraChocolate* hiloMezcladoraChocolate;
    HiloEnsambladora* hiloEnsambladora;
    HiloBandeja* hilosBandeja[6];
    HiloHorno* hiloHorno;
    hiloInspector* hiloInspector1;
    hiloInspector* hiloInspector2;
    HiloEmpacadora* hiloEmpacadora;
    HiloCarritoSalida** hilosCarritoSalida;
    HiloAlmacenTerminal* hiloAlmacenTerminal;

    Simulacion();

    void iniciarHilos();
    void pausarHilos();
    void crearHilosCarritoSalida();
    void resetearSimulacion();
    bool hilosSeguros();
};

#endif // SIMULACION_H
