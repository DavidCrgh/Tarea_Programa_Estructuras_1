#ifndef HILOEMPACADORA_H
#define HILOEMPACADORA_H

#include "empacadora.h"

class HiloEmpacadora : public QThread
{
    Q_OBJECT
public:
    bool pause;
    bool stop;
    Empacadora* empacadora;
    QMutex mute;
    HiloEmpacadora(QObject* parent=0, Empacadora* pEmpacadora = 0);
    void run();
};

#endif // HILOEMPACADORA_H
