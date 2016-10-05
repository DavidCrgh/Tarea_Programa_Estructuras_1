#ifndef VENTANACARRITOENTREGA_H
#define VENTANACARRITOENTREGA_H

#include <QMainWindow>

#include "simulacion.h"

namespace Ui {
class VentanaCarritoEntrega;
}

class VentanaCarritoEntrega : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaCarritoEntrega(QWidget *parent = 0, Simulacion* pSimulacion = 0);
    ~VentanaCarritoEntrega();

public slots:
    void on_configurar_clicked();

    void on_aceptar_clicked();

    void actualizarVentana(QStringList pMensaje);

    void on_apagado_clicked();

    void on_encendido_clicked();

    void resetearVentana();

private:
    Ui::VentanaCarritoEntrega *ui;
    Simulacion* simulacion;
    CarritoEntrega* carrito;
};

#endif // VENTANACARRITOENTREGA_H
