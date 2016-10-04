#ifndef HILOMEZCLADORAMASA_H
#define HILOMEZCLADORAMASA_H

#include "prototipos.h"
#include "mezcladoramasa.h"

class HiloMezcladoraMasa : public QThread
{
    Q_OBJECT
public:
    bool stop;
    bool pause;
    bool seguro;
    QMutex mute;
    MezcladoraMasa* mezcladoraMasa;
    HiloMezcladoraMasa(QObject* parent = 0, MezcladoraMasa* pMezcladora = 0);
    void run();
};

#endif // HILOMEZCLADORAMASA_H
