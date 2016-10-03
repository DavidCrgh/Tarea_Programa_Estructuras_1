#include <QApplication>

#include <cstdlib>
#include <iostream>

#include "hilointerfaz.h"

using namespace std;

int main(int argc, char *argv[])
{
    //qDebug("1");
    Simulacion* simulacion = new Simulacion();
    //qDebug("2");
    QApplication a(argc, argv);
    //qDebug("3");
    VentanaPrincipal* ventana = new VentanaPrincipal(NULL,simulacion);
    //qDebug("4");
    HiloInterfaz* hiloInterfaz = new HiloInterfaz(NULL, simulacion, ventana);
    //qDebug("5");
    hiloInterfaz->start();

    //qDebug("6");
    ventana->show();
    //qDebug("7");
    return a.exec();
    //qDebug("Completado");
}
