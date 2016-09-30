#include "hilointerfaz.h"

HiloInterfaz::HiloInterfaz(QObject* parent, Simulacion* pSimulacion, VentanaPrincipal* pVentanaPrincipal)
{
    simulacion = pSimulacion;
    ventanaPrincipal = pVentanaPrincipal;
    stop = false;
    pause = false;
    connect(this, SIGNAL(actualizarAlmacenPrima(QStringList)),
            ventanaPrincipal->ventanaAlmacen, SLOT(actualizarVentana(QStringList)));
    connect(this,SIGNAL(actualizarVentanaCarrito(QStringList)),
            ventanaPrincipal->ventanaCarrito,SLOT(actualizarVentana(QStringList)));
}

void HiloInterfaz::run(){
    QStringList infoAlmacen;
    QStringList informacionCarritoEntrega;
    simulacion->almacenPrima->encolarPeticion("Nepe","Nepe",7.6);
    simulacion->carritoEntrega->cargarCarrito();

    while(!stop){
        while(pause){
            msleep(100);
        }
        msleep(100);
        infoAlmacen.clear();
        informacionCarritoEntrega.clear();

        infoAlmacen.append(simulacion->almacenPrima->imprimirLista(false));
        infoAlmacen.append(simulacion->almacenPrima->imprimirLista(true));

        informacionCarritoEntrega.append(simulacion->carritoEntrega->entrega->maquinaOrigen);
        informacionCarritoEntrega.append(QString::number(simulacion->carritoEntrega->entrega->cantidad));

        emit actualizarAlmacenPrima(infoAlmacen);
        emit actualizarVentanaCarrito(informacionCarritoEntrega);
    }
}
