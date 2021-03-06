#ifndef HILOALMACENTERMINAL_H
#define HILOALMACENTERMINAL_H

#include "almacenterminal.h"

class HiloAlmacenTerminal : public QThread
{
    Q_OBJECT
public:
    bool pause;
    bool stop;
    bool seguro;
    AlmacenTerminal* almacen;
    QMutex mute;
    HiloAlmacenTerminal(QObject* parent = 0, AlmacenTerminal* pAlmacen = 0);
    void run();

signals:
    void deternerSimulacion();
};

#endif // HILOALMACENTERMINAL_H
