#ifndef HILOINTERFAZ_H
#define HILOINTERFAZ_H
#include "prototipos.h"
#include <QMutex>
#include <QObject>

class HiloInterfaz
{
public:
    bool pause;
    bool stop;
    HiloInterfaz();
    void run();
};

#endif // HILOINTERFAZ_H
