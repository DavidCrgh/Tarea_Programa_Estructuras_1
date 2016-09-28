#ifndef VENTANACARRITOENTREGA_H
#define VENTANACARRITOENTREGA_H

#include <QMainWindow>

#include "carritoentrega.h"

namespace Ui {
class VentanaCarritoEntrega;
}

class VentanaCarritoEntrega : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaCarritoEntrega(QWidget *parent = 0, CarritoEntrega* pCarrito = 0);
    ~VentanaCarritoEntrega();

private slots:
    void on_configurar_clicked();

    void on_aceptar_clicked();

private:
    Ui::VentanaCarritoEntrega *ui;
    CarritoEntrega* carrito;
};

#endif // VENTANACARRITOENTREGA_H
