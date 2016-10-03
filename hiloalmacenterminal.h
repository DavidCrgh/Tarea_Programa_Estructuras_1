#ifndef HILOALMACENTERMINAL_H
#define HILOALMACENTERMINAL_H

#include "almacenterminal.h"

class HiloAlmacenTerminal : public QThread
{
    Q_OBJECT
public:
    bool pause;
    bool stop;
    AlmacenTerminal* almacen;
    QMutex mute;
    HiloAlmacenTerminal(QObject* parent = 0, AlmacenTerminal* pAlmacen = 0);
    void run();
};

#endif // HILOALMACENTERMINAL_H
