#ifndef VENTANACARRITOS_H
#define VENTANACARRITOS_H

#include <QWidget>

#include "simulacion.h"

namespace Ui {
class VentanaCarritos;
}

class VentanaCarritos : public QWidget
{
    Q_OBJECT

public:
    explicit VentanaCarritos(QWidget *parent = 0, Simulacion* pSimulacio = 0);
    ~VentanaCarritos();

private slots:
    void on_flechaIzquierda_clicked();

    void on_flechaDerecha_clicked();

    void actualizarVentana();

private:
    Ui::VentanaCarritos *ui;
    CarritoSalida** carritosSalida;
    Simulacion* simulacion;
    int indiceCarrito;
};

#endif // VENTANACARRITOS_H
