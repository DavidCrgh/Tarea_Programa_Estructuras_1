#include "hilointerfaz.h"

HiloInterfaz::HiloInterfaz(QObject* parent, Simulacion* pSimulacion, VentanaPrincipal* pVentanaPrincipal)
{
    simulacion = pSimulacion;
    ventanaPrincipal = pVentanaPrincipal;
    stop = false;
    pause = false;
}

void HiloInterfaz::run(){
    while(!stop){
        while(pause){
            msleep(100);
        }
        msleep(1000);
        QString infoPeticiones[2];
        infoPeticiones[0] = simulacion->almacenPrima->imprimirLista(false);
        infoPeticiones[1] = simulacion->almacenPrima->imprimirLista(true);
        ventanaPrincipal->ventanaAlmacen->actualizarCuadroEspera(infoPeticiones[0]);
        ventanaPrincipal->ventanaAlmacen->actualizarCuadroRealizadas(infoPeticiones[1]);
    }
}
