#ifndef THREADMEZCLADORA_H
#define THREADMEZCLADORA_H
#include "mezcladora.h"
#include <QMutex>
#include <QObject>

class ThreadMezcladora : public QThread
{
    Q_OBJECT
public:
    ThreadMezcladora(QObject* parent=0, Mezcladora* pMezcladora);
    void run();
    bool pause;
    bool stop;
    Mezcladora* mezcladora;
    QMutex mute;
};

#endif // THREADMEZCLADORA_H
