#include "hilointerfaz.h"

HiloInterfaz::HiloInterfaz(QObject* parent, Simulacion* pSimulacion, VentanaPrincipal* pVentanaPrincipal)
{
    simulacion = pSimulacion;
    ventanaPrincipal = pVentanaPrincipal;
    stop = false;
    pause = false;
    connect(this, SIGNAL(actualizarAlmacenPrima(QStringList)),
            ventanaPrincipal->ventanaAlmacen, SLOT(actualizarVentana(QStringList)));
}

void HiloInterfaz::run(){
    while(!stop){
        while(pause){
            msleep(100);
        }
        msleep(100);
        QStringList infoPeticiones;
        infoPeticiones.append(simulacion->almacenPrima->imprimirLista(false));
        infoPeticiones.append(simulacion->almacenPrima->imprimirLista(true));
        emit actualizarAlmacenPrima(infoPeticiones);
    }
}
