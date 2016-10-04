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
    connect(this,SIGNAL(actualizarBandas()),ventanaPrincipal->ventanaBandaMasa,SLOT(actualizarBandas()));

    connect(this,SIGNAL(actualizarBandas()),ventanaPrincipal->ventanaBandaChocolate,SLOT(actualizarBandas()));
    connect(this, SIGNAL(actualizarBandas()), ventanaPrincipal->ventanaBandaCrudas, SLOT(actualizarBandas()));
    connect(this,SIGNAL(actualizarEnsambladora()),ventanaPrincipal->ventanaEnsambladoraSimulador, SLOT(actualizarVentana()));
    connect(this, SIGNAL(actualizarHorno()), ventanaPrincipal->ventanaHorno, SLOT(actualizarVentana()));
    for(int i = 0; i < 6; i++){
        connect(this, SIGNAL(actualizarBandejas()), ventanaPrincipal->ventanaHorno->ventanasBandeja[i], SLOT(actualizarVentana()));
    connect(this,SIGNAL(actualizarBandas()),ventanaPrincipal->ventanaBandaInspectores,SLOT(actualizarBandas()));
    }
    connect(this, SIGNAL(actualizarInspectores()),ventanaPrincipal->ventanaInspector1,SLOT(actualizarVentana()));
    connect(this, SIGNAL(actualizarInspectores()),ventanaPrincipal->ventanaInspector2,SLOT(actualizarVentana()));
    connect(this, SIGNAL(actualizarEmpacadora()), ventanaPrincipal->ventanaEmpacadora, SLOT(actualizarVentana()));
    connect(this, SIGNAL(actualizarAlmacenTerminal()), ventanaPrincipal->ventanaAlmacenTerminal, SLOT(actualizarVentana()));
}

void HiloInterfaz::run(){
    while(!stop){
        while(pause){
            msleep(100);
        }
        msleep(500);

        emit actualizarAlmacenPrima(simulacion->almacenPrima->imprimirAlmacen());
        emit actualizarVentanaCarrito(simulacion->carritoEntrega->imprimirCarrito());
        emit actualizarMezcladoras();
        emit actualizarBandas();
        emit actualizarEnsambladora();
        emit actualizarHorno();
        emit actualizarBandejas();
        emit actualizarInspectores();
        emit actualizarEmpacadora();
        if(ventanaPrincipal->ventanaCarritosSalida != NULL){
            connect(this, SIGNAL(actualizarCarritosSalida()), ventanaPrincipal->ventanaCarritosSalida, SLOT(actualizarVentana()));
            emit actualizarCarritosSalida();
        }
        emit actualizarAlmacenTerminal();
    }
}
