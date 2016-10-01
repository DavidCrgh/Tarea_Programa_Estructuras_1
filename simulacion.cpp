#include "simulacion.h"

Simulacion::Simulacion(/*VentanaPrincipal *pInterfaz*/){
    bandaMasa = new Banda();
    bandaChocolate = new Banda();

    //Estructuras
    almacenPrima = new AlmacenPrima();
    carritoEntrega = new CarritoEntrega(almacenPrima);
    QString nombresMezcladora[] = {"Mezcladora 1", "Mezcladora 2"};
    for(int i = 0; i < 2; i++){
        mezcladorasMasa[i] = new MezcladoraMasa(nombresMezcladora[i], bandaMasa, almacenPrima,carritoEntrega);
    }
    mezcladoraChocolate = new MezcladoraChocolate("Mezcladora Chocolate", bandaChocolate, almacenPrima,carritoEntrega);

    //Hilos
    hiloCarritoEntrega = new HiloCarritoEntrega(NULL, carritoEntrega);
    hiloCarritoEntrega->start();
    for(int i = 0; i < 2; i++){
        hilosMezcladorasMasa[i] = new HiloMezcladoraMasa(NULL, mezcladorasMasa[i]);
        hilosMezcladorasMasa[i]->start();
    }
    hiloMezcladoraChocolate = new HiloMezcladoraChocolate(NULL, mezcladoraChocolate);
    hiloMezcladoraChocolate->start();
}

void Simulacion::iniciarHilos(){
    hiloCarritoEntrega->pause = false;
    for(int i = 0; i < 2; i++){
        hilosMezcladorasMasa[i]->pause = false;
    }
    hiloMezcladoraChocolate->pause = false;
}

void Simulacion::pausarHilos(){
    hiloCarritoEntrega->pause = true;
    for(int i = 0; i < 2; i++){
        hilosMezcladorasMasa[i]->pause = true;
    }
    hiloMezcladoraChocolate->pause = true;
}
