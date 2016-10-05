#ifndef VENTANABANDEJA_H
#define VENTANABANDEJA_H

#include <QWidget>

#include "horno.h"

namespace Ui {
class VentanaBandeja;
}

class VentanaBandeja : public QWidget
{
    Q_OBJECT

public:
    explicit VentanaBandeja(QWidget *parent = 0, Bandeja* pBandeja = 0);
    ~VentanaBandeja();

public slots:
    void on_configurar_clicked();

    void on_aceptar_clicked();

    void actualizarVentana();

    void resetearVentana();

private:
    Ui::VentanaBandeja *ui;
    Bandeja* bandeja;
};

#endif // VENTANABANDEJA_H
