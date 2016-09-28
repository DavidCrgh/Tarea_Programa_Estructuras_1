#include "simulacion.h"

Simulacion::Simulacion(VentanaPrincipal *pInterfaz){
    interfaz = pInterfaz;

    bandaMasa = new Banda();
    bandaChocolate = new Banda();

    almacenPrima = new AlmacenPrima();
    carritoEntrega = new CarritoEntrega(almacenPrima);
    QString nombresMezcladora[] = {"Mezcladora 1", "Mezcladora 2"};
    for(int i = 0; i < 2; i++){
        mezcladorasMasa[i] = new MezcladoraMasa(nombresMezcladora[i], bandaMasa, almacenPrima);
    }
    mezcladoraChocolate = new MezcladoraChocolate("Mezcladora Chocolate", bandaChocolate, almacenPrima);

    hiloCarritoEntrega = new HiloCarritoEntrega(NULL, carritoEntrega);
    for(int i = 0; i < 2; i++){
        hilosMezcladorasMasa[i] = new HiloMezcladoraMasa(NULL, mezcladorasMasa[i]);
    }
    hiloMezcladoraChocolate = new HiloMezcladoraChocolate(NULL, mezcladoraChocolate);
    //hiloBandaMezcladorasMasa = new HiloBanda(NULL, bandaMasa);
    //hiloBandaMezcladorasChocolate = new HiloBanda(NULL, bandaChocolate);
}
