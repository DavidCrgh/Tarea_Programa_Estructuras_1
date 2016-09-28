#ifndef HILOMEZCLADORACHOCOLATE_H
#define HILOMEZCLADORACHOCOLATE_H

#include "prototipos.h"
#include "mezcladorachocolate.h"

class HiloMezcladoraChocolate : public QThread
{
    Q_OBJECT
public:
    bool stop;
    bool pause;
    QMutex mute;
    MezcladoraChocolate* mezcladoraChocolate;
    HiloMezcladoraChocolate(QObject* parent = 0, MezcladoraChocolate* pMezcladora = 0);
    void run();
};

#endif // HILOMEZCLADORACHOCOLATE_H
