#ifndef HILOBANDEJA_H
#define HILOBANDEJA_H

#include "horno.h"

class HiloBandeja : public QThread
{
    Q_OBJECT
public:
    bool pause;
    bool stop;
    bool seguro;
    Bandeja* bandeja;
    QMutex mute;
    HiloBandeja(QObject *parent=0, Bandeja* pBandeja = 0);
    void run();
};

#endif // HILOBANDEJA_H
