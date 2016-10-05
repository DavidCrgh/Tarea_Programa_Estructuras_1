#ifndef VENTANAEMPACADORA_H
#define VENTANAEMPACADORA_H

#include <QWidget>

#include "simulacion.h"

namespace Ui {
class VentanaEmpacadora;
}

class VentanaEmpacadora : public QWidget
{
    Q_OBJECT

public:
    explicit VentanaEmpacadora(QWidget *parent = 0,  Simulacion* pSimulacion = 0);
    ~VentanaEmpacadora();

public slots:
    void actualizarVentana();

    void resetearVentana();

private slots:
    void on_apagado_clicked();

    void on_encendido_clicked();

private:
    Ui::VentanaEmpacadora *ui;
    Simulacion* simulacion;
    Empacadora* empacadora;
};

#endif // VENTANAEMPACADORA_H
