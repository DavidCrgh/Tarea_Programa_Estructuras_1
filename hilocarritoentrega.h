#ifndef HILOCARRITOENTREGA_H
#define HILOCARRITOENTREGA_H
#include "prototipos.h"

class HiloCarritoEntrega : public QThread
{
    Q_OBJECT
public:
    HiloCarritoEntrega(QObject* parent=0, CarritoEntrega* pCarrito=0);
    void run();
    bool pause;
    bool stop;
    CarritoEntrega* carritoEntrega;
    QMutex mute;
};

#endif // HILOCARRITOENTREGA_H
