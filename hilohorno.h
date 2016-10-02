#ifndef HILOHORNO_H
#define HILOHORNO_H

#include "horno.h"

class HiloHorno : public QThread
{
    Q_OBJECT
public:
    bool pause;
    bool stop;
    Horno* horno;
    QMutex mute;
    HiloHorno(QObject *parent = 0, Horno* pHorno = 0);
    void run();
};

#endif // HILOHORNO_H
