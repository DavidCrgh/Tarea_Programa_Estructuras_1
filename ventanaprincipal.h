#ifndef VENTANAPRINCIPAL_H
#define VENTANAPRINCIPAL_H

#include <QMainWindow>

#include "ventanacarritoentrega.h"
#include "ventanamezcladoras.h"
#include  "ventanaensambladora.h"
#include "ventanaalmacenprima.h"
namespace Ui {
class VentanaPrincipal;
}

class VentanaPrincipal : public QMainWindow
{
    Q_OBJECT

public:
    explicit VentanaPrincipal(QWidget *parent = 0);
    ~VentanaPrincipal();

public slots:
    void openNewWindow();

private slots:
    void on_botonCarritoEntrega_clicked();

    void on_botonMezcladora1_clicked();

    void on_botonMezcladora2_clicked();

    void on_botonMezcladoraChocolate_clicked();

    void on_botonEnsambladora_clicked();

    void on_botonAlmacenPrima_clicked();

private:
    Ui::VentanaPrincipal *ui;
    VentanaCarritoEntrega* ventanaCarrito;
    VentanaMezcladoras* ventanaMezcladora1;
    VentanaMezcladoras* ventanaMezcladora2;
    VentanaMezcladoras* ventanaMezcladoraChocolate;
    ventanaEnsambladora* ventanaEnsambladoraSimulador;
    VentanaAlmacenPrima* ventanaAlmacen;
};

#endif // VENTANAPRINCIPAL_H
