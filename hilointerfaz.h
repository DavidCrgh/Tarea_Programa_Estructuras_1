#ifndef HILOINTERFAZ_H
#define HILOINTERFAZ_H

#include "prototipos.h"
#include "ventanaprincipal.h"

class HiloInterfaz : public QThread
{
    Q_OBJECT
public:
    bool pause;
    bool stop;
    Simulacion* simulacion;
    VentanaPrincipal* ventanaPrincipal;
    QMutex mute;
    HiloInterfaz(QObject* parent = 0, Simulacion* pSimulacion = 0, VentanaPrincipal* pVentanaPrincipal=0);
    void run();
};

#endif // HILOINTERFAZ_H
