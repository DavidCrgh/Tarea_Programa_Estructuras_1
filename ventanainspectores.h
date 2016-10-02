#ifndef VENTANAINSPECTORES_H
#define VENTANAINSPECTORES_H

#include <QMainWindow>
#include "bandainspectores.h"

namespace Ui {
class ventanaInspectores;
}

class ventanaInspectores : public QMainWindow
{
    Q_OBJECT

public:
    explicit ventanaInspectores(QWidget *parent = 0,Inspector* pInspector=0);
    ~ventanaInspectores();

private slots:
    void on_Aceptar_clicked();

    void on_configurar_clicked();

    void actualizarVentana();

private:
    Ui::ventanaInspectores *ui;
    Inspector* inspector;

};

#endif // VENTANAINSPECTORES_H
