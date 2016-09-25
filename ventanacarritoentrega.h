#ifndef VENTANACARRITOENTREGA_H
#define VENTANACARRITOENTREGA_H
#include "prototipos.h"
#include <QMainWindow>

namespace Ui {
class VentanaCarritoEntrega;
}

class VentanaCarritoEntrega : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaCarritoEntrega(QWidget *parent = 0/*,CarritoEntrega* pCarrito*/);
    ~VentanaCarritoEntrega();

private slots:
    void on_configurar_clicked();

    void on_aceptar_clicked();

private:
    Ui::VentanaCarritoEntrega *ui;
    //CarritoEntrega* carrito;
};

#endif // VENTANACARRITOENTREGA_H
