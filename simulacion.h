#ifndef SIMULACION_H
#define SIMULACION_H

//#include "ventanaprincipal.h"

#include "almacenprima.h"
/*#include "carritoentrega.h"
#include "mezcladoramasa.h"
#include "mezcladorachocolate.h"
#include "banda.h"*/

#include "hilocarritoentrega.h"
#include "hilomezcladoramasa.h"
#include "hilomezcladorachocolate.h"
#include "hilobanda.h"
//#include "hilointerfaz.h"

struct Simulacion{

    //VentanaPrincipal* interfaz;

    AlmacenPrima* almacenPrima;
    CarritoEntrega* carritoEntrega;
    MezcladoraMasa* mezcladorasMasa[2];
    MezcladoraChocolate* mezcladoraChocolate;
    Banda* bandaMasa;
    Banda* bandaChocolate;

    HiloCarritoEntrega* hiloCarritoEntrega;
    HiloMezcladoraMasa* hilosMezcladorasMasa[2];
    HiloMezcladoraChocolate* hiloMezcladoraChocolate;
    /*HiloBanda* hiloBandaMezcladorasMasa[2];
    HiloBanda* hiloBandaMezcladorasChocolate;*/
    //HiloInterfaz* hiloInterfaz;

    Simulacion(/*VentanaPrincipal* pInterfaz*/);
};

#endif // SIMULACION_H
