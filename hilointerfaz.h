#ifndef HILOINTERFAZ_H
#define HILOINTERFAZ_H
#include "prototipos.h"
#include "ventanaprincipal.h"
#include <QMutex>
#include <QObject>

class HiloInterfaz
{
public:
    bool pause;
    bool stop;
    QMutex mute;
    VentanaPrincipal* ventanaPrincipal;
    HiloInterfaz(QObject* parent=0, VentanaPrincipal* pVentanaPrincipal=0);
    void run();
};

#endif // HILOINTERFAZ_H
