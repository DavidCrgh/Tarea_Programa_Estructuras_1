#ifndef VENTANABANDA_H
#define VENTANABANDA_H

#include <QWidget>

#include "banda.h"

namespace Ui {
class VentanaBanda;
}

class VentanaBanda : public QWidget
{
    Q_OBJECT

public:
    explicit VentanaBanda(QWidget *parent = 0, Banda* pBanda = 0);
    ~VentanaBanda();

private slots:
    void on_configurar_clicked();

    void on_aceptar_clicked();

    void actualizarBandas();

private:
    Ui::VentanaBanda *ui;
    Banda* banda;
};

#endif // VENTANABANDA_H
