#ifndef VENTANAALMACENTERMINAL_H
#define VENTANAALMACENTERMINAL_H

#include <QWidget>

#include "simulacion.h"

namespace Ui {
class VentanaAlmacenTerminal;
}

class VentanaAlmacenTerminal : public QWidget
{
    Q_OBJECT

public:
    explicit VentanaAlmacenTerminal(QWidget *parent = 0, Simulacion* pSimulacion = 0);
    ~VentanaAlmacenTerminal();

public slots:
    void actualizarVentana();

    void resetearVentana();

private:
    Ui::VentanaAlmacenTerminal *ui;
    Simulacion* simulacion;
    AlmacenTerminal* almacenTerminal;
};

#endif // VENTANAALMACENTERMINAL_H
