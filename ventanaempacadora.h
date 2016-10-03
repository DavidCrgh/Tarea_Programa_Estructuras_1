#ifndef VENTANAEMPACADORA_H
#define VENTANAEMPACADORA_H

#include <QWidget>

#include "empacadora.h"

namespace Ui {
class VentanaEmpacadora;
}

class VentanaEmpacadora : public QWidget
{
    Q_OBJECT

public:
    explicit VentanaEmpacadora(QWidget *parent = 0, Empacadora* pEmpacadora = 0);
    ~VentanaEmpacadora();

public slots:
    void actualizarVentana();

private:
    Ui::VentanaEmpacadora *ui;
    Empacadora* empacadora;
};

#endif // VENTANAEMPACADORA_H
