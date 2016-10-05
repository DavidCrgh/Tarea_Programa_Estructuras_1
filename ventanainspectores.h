#ifndef VENTANAINSPECTORES_H
#define VENTANAINSPECTORES_H

#include <QMainWindow>
#include "simulacion.h"

namespace Ui {
class ventanaInspectores;
}

class ventanaInspectores : public QMainWindow
{
    Q_OBJECT

public:
    explicit ventanaInspectores(QWidget *parent = 0, Inspector* pInspector = 0, Simulacion* pSimulacion = 0);
    ~ventanaInspectores();


public slots:
    void resetearVentana();

private slots:
    void on_Aceptar_clicked();

    void on_configurar_clicked();

    void actualizarVentana();

    void on_encendido_clicked();

    void on_apagado_clicked();

private:
    Ui::ventanaInspectores *ui;
    Simulacion* simulacion;
    Inspector* inspector;

};

#endif // VENTANAINSPECTORES_H
