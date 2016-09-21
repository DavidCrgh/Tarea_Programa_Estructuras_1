#ifndef THREADMEZCLADORA_H
#define THREADMEZCLADORA_H
#include "mezcladoramasa.h"
#include <QMutex>
#include <QObject>

class ThreadMezcladora : public QThread
{
    Q_OBJECT
public:
    ThreadMezcladora(QObject* parent=0, MezcladoraMasa* pMezcladora);
    void run();
    bool pause;
    bool stop;
    MezcladoraMasa* mezcladora;
    QMutex mute;
};

#endif // THREADMEZCLADORA_H
