#ifndef HILOENSAMBLADORA_H
#define HILOENSAMBLADORA_H

#include "ensambladora.h"

class HiloEnsambladora : public QThread
{
    Q_OBJECT
public:
    bool pause;
    bool stop;
    Ensambladora* ensambladora;
    QMutex mute;
    HiloEnsambladora(QObject* parent = 0, Ensambladora* pEnsambladora = 0);
    void run();
};

#endif // HILOENSAMBLADORA_H
