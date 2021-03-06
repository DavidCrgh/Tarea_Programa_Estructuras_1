#ifndef VENTANAHORNO_H
#define VENTANAHORNO_H

#include <QMainWindow>

#include "simulacion.h"
#include "ventanabandeja.h"

namespace Ui {
class VentanaHorno;
}

class VentanaHorno : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaHorno(QWidget *parent = 0, Simulacion* pSimulacion = 0);
    ~VentanaHorno();



public slots:

    void resetearVentana();

    void actualizarVentana();

    void toggleVentana(bool encender);

    void on_encendido_clicked();

    void on_apagado_clicked();

    void on_configurarBandeja1_clicked();

    void on_configurarBandeja6_clicked();

    void on_configurarBandeja2_clicked();

    void on_configurarBandeja3_clicked();

    void on_configurarBandeja4_clicked();

    void on_configurarBandeja5_clicked();

    void on_checkBandeja1_toggled(bool checked);

    void on_checkBandeja2_toggled(bool checked);

    void on_checkBandeja3_toggled(bool checked);

    void on_checkBandeja4_toggled(bool checked);

    void on_checkBandeja5_toggled(bool checked);

    void on_checkBandeja6_toggled(bool checked);

public:
    Ui::VentanaHorno *ui;
    Simulacion* simulacion;
    Horno* horno;
    VentanaBandeja* ventanasBandeja[6];

};

#endif // VENTANAHORNO_H
