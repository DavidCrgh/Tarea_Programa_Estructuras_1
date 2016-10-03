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
signals:
    void actualizarAlmacenPrima(QStringList mensaje);
    void actualizarVentanaCarrito(QStringList mensaje);
    void actualizarMezcladoras();
    void actualizarBandas();
    void actualizarEnsambladora();
    void actualizarBandejas();
    void actualizarInspectores();
    void actualizarEmpacadora();
};

#endif // HILOINTERFAZ_H
