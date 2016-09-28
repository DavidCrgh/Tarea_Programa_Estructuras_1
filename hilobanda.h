#ifndef HILOBANDA_H
#define HILOBANDA_H

#include "prototipos.h"
#include "banda.h"

class HiloBanda : public QThread
{
    Q_OBJECT
public:
    bool pause;
    bool stop;
    Banda* banda;
    QMutex mute;
    HiloBanda(QObject* parent = 0, Banda* pBanda = 0);
    void run();
};

#endif // HILOBANDA_H
