#ifndef VENTANAALMACENTERMINAL_H
#define VENTANAALMACENTERMINAL_H

#include <QWidget>

#include "almacenterminal.h"

namespace Ui {
class VentanaAlmacenTerminal;
}

class VentanaAlmacenTerminal : public QWidget
{
    Q_OBJECT

public:
    explicit VentanaAlmacenTerminal(QWidget *parent = 0, AlmacenTerminal* pAlmacen = 0);
    ~VentanaAlmacenTerminal();

public slots:
    void actualizarVentana();

private:
    Ui::VentanaAlmacenTerminal *ui;
    AlmacenTerminal* almacenTerminal;
};

#endif // VENTANAALMACENTERMINAL_H
