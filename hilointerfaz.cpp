#include "hilointerfaz.h"

HiloInterfaz::HiloInterfaz(QObject* parent, Simulacion* pSimulacion, VentanaPrincipal* pVentanaPrincipal)
{
    //qRegisterMetaType<QString[]>("QString[]");
    simulacion = pSimulacion;
    ventanaPrincipal = pVentanaPrincipal;
    stop = false;
    pause = false;
    connect(this, SIGNAL(actualizarAlmacenPrima(std::string[])),
            ventanaPrincipal->ventanaAlmacen, SLOT(actualizarVentana(std::string[])));
}

void HiloInterfaz::run(){
    while(!stop){
        while(pause){
            msleep(100);
        }
        msleep(1000);
        std::string infoPeticiones[2];
        infoPeticiones[0] = QString::toLatin1(simulacion->almacenPrima->imprimirLista(false));
        infoPeticiones[1] = simulacion->almacenPrima->imprimirLista(true);
        emit actualizarAlmacenPrima(infoPeticiones);
    }
}
