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
    connect(this, SIGNAL(actualizarMezcladoras()),
            ventanaPrincipal->ventanaMezcladora1, SLOT(actualizarVentana()));
    connect(this, SIGNAL(actualizarMezcladoras()),
            ventanaPrincipal->ventanaMezcladora2, SLOT(actualizarVentana()));
    connect(this, SIGNAL(actualizarMezcladoras()),
            ventanaPrincipal->ventanaMezcladoraChocolate, SLOT(actualizarVentana()));
}

void HiloInterfaz::run(){
    while(!stop){
        while(pause){
            msleep(100);
        }
        msleep(1000);

        emit actualizarAlmacenPrima(simulacion->almacenPrima->imprimirAlmacen());
        emit actualizarVentanaCarrito(simulacion->carritoEntrega->imprimirCarrito());
        emit actualizarMezcladoras();
        QString contenidoBandeja1 = QString::number(simulacion->bandaMasa->contenidoActual());
        QString contenidoBandeja2 = QString::number(simulacion->bandaChocolate->contenidoActual());
        qDebug("BMasa: " + contenidoBandeja1.toLatin1());
        qDebug("BChocolate: " + contenidoBandeja2.toLatin1());
    }
}
