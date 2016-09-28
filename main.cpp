#include "hilointerfaz.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    Simulacion* simulacion = new Simulacion();
    QApplication a(argc, argv);
    VentanaPrincipal* ventana = new VentanaPrincipal(NULL,simulacion);
    HiloInterfaz* hiloInterfaz = new HiloInterfaz(NULL, simulacion, ventana);
    //hiloInterfaz->start();
    ventana->show();

    return a.exec();
}
