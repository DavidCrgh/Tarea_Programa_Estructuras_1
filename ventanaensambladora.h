#ifndef VENTANAENSAMBLADORA_H
#define VENTANAENSAMBLADORA_H

#include <QMainWindow>

#include "simulacion.h"

namespace Ui {
class ventanaEnsambladora;
}

class ventanaEnsambladora : public QMainWindow
{
    Q_OBJECT

public:
    explicit ventanaEnsambladora(QWidget *parent = 0, Simulacion* pSimulacion = 0);
    ~ventanaEnsambladora();

private slots:
    void on_configurar_clicked();

    void on_aceptar_clicked();

    void actualizarVentana();

    void on_apagado_clicked();

    void on_encendido_clicked();

private:
    Ui::ventanaEnsambladora *ui;
    Simulacion* simulacion;
    Ensambladora* ensambladora;
};

#endif // VENTANAENSAMBLADORA_H
