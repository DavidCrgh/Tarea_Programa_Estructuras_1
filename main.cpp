#include "ventanaprincipal.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    VentanaPrincipal* ventana = new VentanaPrincipal(0);
    ventana->show();

    return a.exec();
}
