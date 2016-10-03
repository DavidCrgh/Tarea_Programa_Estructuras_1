#ifndef VENTANAEMPACADORA_H
#define VENTANAEMPACADORA_H

#include <QWidget>

namespace Ui {
class VentanaEmpacadora;
}

class VentanaEmpacadora : public QWidget
{
    Q_OBJECT

public:
    explicit VentanaEmpacadora(QWidget *parent = 0);
    ~VentanaEmpacadora();

private:
    Ui::VentanaEmpacadora *ui;
};

#endif // VENTANAEMPACADORA_H
