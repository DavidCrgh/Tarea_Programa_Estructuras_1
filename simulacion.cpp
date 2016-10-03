#include "simulacion.h"

Simulacion::Simulacion(/*VentanaPrincipal *pInterfaz*/){
    //Bandas
    bandaMasa = new Banda("Masa");
    bandaChocolate = new Banda("Chocolate");
    bandaGalletasCrudas = new Banda("Galletas Crudas");
    bandaInspectores = new Banda("Galletas Cocinadas");

    //Estructuras
    almacenPrima = new AlmacenPrima();
    carritoEntrega = new CarritoEntrega(almacenPrima);
    QString nombresMezcladora[] = {"Mezcladora 1", "Mezcladora 2"};
    for(int i = 0; i < 2; i++){
        mezcladorasMasa[i] = new MezcladoraMasa(nombresMezcladora[i], bandaMasa, almacenPrima,carritoEntrega);
    }
    mezcladoraChocolate = new MezcladoraChocolate("Mezcladora Chocolate", bandaChocolate, almacenPrima,carritoEntrega);
    ensambladora = new Ensambladora(bandaGalletasCrudas, bandaMasa, bandaChocolate);
    for(int j = 0; j < 6; j++){
        bandejas[j] = new Bandeja(bandaInspectores);
    }
    horno = new Horno(bandejas, bandaGalletasCrudas);
    listaGalletas = new ListaGalletas();
    empacadora = new Empacadora(listaGalletas);
    inspector1 = new Inspector(empacadora, bandaInspectores);
    inspector2 = new Inspector(empacadora, bandaInspectores);
    almacenTerminal = new AlmacenTerminal(listaGalletas);
    carritosSalida = NULL;

    //Hilos
    hiloCarritoEntrega = new HiloCarritoEntrega(NULL, carritoEntrega);
    hiloCarritoEntrega->start();
    for(int i = 0; i < 2; i++){
        hilosMezcladorasMasa[i] = new HiloMezcladoraMasa(NULL, mezcladorasMasa[i]);
        hilosMezcladorasMasa[i]->start();
    }
    hiloMezcladoraChocolate = new HiloMezcladoraChocolate(NULL, mezcladoraChocolate);
    hiloMezcladoraChocolate->start();
    hiloEnsambladora = new HiloEnsambladora(NULL, ensambladora);
    hiloEnsambladora->start();
    hiloHorno = new HiloHorno(NULL, horno);
    hiloHorno->start();
    for(int i = 0; i < 6; i++){
        hilosBandeja[i] = new HiloBandeja(NULL, bandejas[i]);
        hilosBandeja[i]->start();
    }
    hiloInspector1 = new hiloInspector(NULL, inspector1);
    hiloInspector1->start();
    hiloInspector2 = new hiloInspector(NULL, inspector2);
    hiloInspector2->start();
    hiloEmpacadora = new HiloEmpacadora(NULL, empacadora);
    hiloEmpacadora->start();
    hilosCarritoSalida = NULL;
    hiloAlmacenTerminal = new HiloAlmacenTerminal(NULL, almacenTerminal);
    hiloAlmacenTerminal->start();
}

void Simulacion::iniciarHilos(){
    hiloCarritoEntrega->pause = false;
    for(int i = 0; i < 2; i++){
        hilosMezcladorasMasa[i]->pause = false;
    }
    hiloMezcladoraChocolate->pause = false;
    hiloEnsambladora->pause = false;
    hiloHorno->pause = false;
    for(int i = 0; i < 6; i++){
        hilosBandeja[i]->pause = false;
    }
    hiloInspector1->pause=false;
    hiloInspector2->pause=false;
    hiloEmpacadora->pause=false;
    if(hilosCarritoSalida != NULL){
        for(int i = 0; i < listaGalletas->largoListaGalletas(); i++){
            hilosCarritoSalida[i]->pause = false;
        }
    }
    hiloAlmacenTerminal->pause = false;
}

void Simulacion::pausarHilos(){
    hiloCarritoEntrega->pause = true;
    for(int i = 0; i < 2; i++){
        hilosMezcladorasMasa[i]->pause = true;
    }
    hiloMezcladoraChocolate->pause = true;
    hiloEnsambladora->pause = true;
    hiloHorno->pause = true;
    for(int i = 0; i < 6; i++){
        hilosBandeja[i]->pause = true;
    }
    hiloInspector1->pause = true;
    hiloInspector2->pause = true;
    hiloEmpacadora->pause = true;
    if(hilosCarritoSalida != NULL){
        for(int i = 0; i < listaGalletas->largoListaGalletas(); i++){
            hilosCarritoSalida[i]->pause = true;
        }
    }
    hiloAlmacenTerminal->pause = true;
}

void Simulacion::crearHilosCarritoSalida(){
    carritosSalida = new CarritoSalida*[listaGalletas->largoListaGalletas()];
    hilosCarritoSalida = new HiloCarritoSalida*[listaGalletas->largoListaGalletas()];

    NodoMonticulo* actualEmpacadora = empacadora->monticulosEmpacadora->primerNodo;
    NodoMonticulo* actualAlmacen = almacenTerminal->depositos->primerNodo;

    for(int i = 0; i < listaGalletas->largoListaGalletas(); i++){
        carritosSalida[i] = new CarritoSalida(actualAlmacen->nombre, actualEmpacadora, actualAlmacen);
        HiloCarritoSalida* nuevoHilo = new HiloCarritoSalida(NULL, carritosSalida[i]);
        hilosCarritoSalida[i] = nuevoHilo;
        nuevoHilo->start();
        actualEmpacadora = actualEmpacadora->siguiente;
        actualAlmacen = actualAlmacen->siguiente;
    }
}
