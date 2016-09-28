#ifndef THREADMEZCLADORA_H
#define THREADMEZCLADORA_H

#include "prototipos.h"

class ThreadMezcladora : public QThread
{
    Q_OBJECT

public:
    ThreadMezcladora(QObject* parent=0, MezcladoraMasa* pMezcladora=0);//Revisar pMezcladora=0, no compila sin =0
    void run();
    bool pause;
    bool stop;
    MezcladoraMasa* mezcladora;
    QMutex mute;
};

#endif // THREADMEZCLADORA_H
