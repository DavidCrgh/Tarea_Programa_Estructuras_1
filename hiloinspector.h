#ifndef HILOINSPECTOR_H
#define HILOINSPECTOR_H
#include "bandainspectores.h"

class hiloInspector : public QThread
{
    Q_OBJECT
public:
    bool pause;
    bool stop;
    bool seguro;
    QMutex mute;
    Inspector* inspector;
    hiloInspector(QObject * parent=0,Inspector* pInspector=0);
    void run();
};

#endif // HILOINSPECTOR_H
