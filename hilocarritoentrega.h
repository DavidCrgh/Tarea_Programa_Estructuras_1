#ifndef HILOCARRITOENTREGA_H
#define HILOCARRITOENTREGA_H

#include "carritoentrega.h"

class HiloCarritoEntrega : public QThread
{
    Q_OBJECT
public:
    bool pause;
    bool stop;
    bool seguro;
    CarritoEntrega* carritoEntrega;
    QMutex mute;
    HiloCarritoEntrega(QObject* parent=0, CarritoEntrega* pCarrito = 0);
    void run();
};

#endif // HILOCARRITOENTREGA_H
