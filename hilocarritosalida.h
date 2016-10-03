#ifndef HILOCARRITOSALIDA_H
#define HILOCARRITOSALIDA_H

#include "carritosalida.h"

class HiloCarritoSalida : public QThread
{
    Q_OBJECT
public:
    bool pause;
    bool stop;
    CarritoSalida* carritoSalida;
    QMutex mute;
    HiloCarritoSalida(QObject* parent=0, CarritoSalida* pCarrito = 0);
    void run();
};

#endif // HILOCARRITOSALIDA_H
